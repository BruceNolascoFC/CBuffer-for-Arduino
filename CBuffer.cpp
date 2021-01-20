#include "Arduino.h"
#include "CBuffer.h"
#include <cmath>

CBuffer::CBuffer(int size)
{
  _A = new float[size];
  _head = 0;
  _size = size;
}

void CBuffer::push(float x)
{
  _A[_head] = x;
  _head = (_head+1)%_size;
}

float CBuffer::get(int index)
{
  return _A[(_head-index)%_size];
}

void CBuffer::set(int index,float x)
{
  _A[(_head-index)%_size] = x;
}

float CBuffer::autoMean(int delay)
{
  if(delay>=0)
  {
    float s = 0;
    for(int i = 0; i<_size-delay; i++)
    {
      s += get(i-delay);
    }
    s = s/(_size-delay);
    return s;
  }
  else
    return 0;
}

float CBuffer::autoVar(int delay)
{
  if(delay>=0)
  {
    float s = 0;
    for(int i = 0; i<_size-delay; i++)
    {
      s += get(i-delay)*get(i-delay);
    }
    s = s/(_size-delay-1);
    return s;
  }
  else
    return 0;
}

float CBuffer::autoStd(int delay)
{
  return sqrt(autoVar(delay));
}

float CBuffer::autoCov(int delay)
{
  if(delay>=0)
  {
    float s = 0;
    for(int i = 0; i<_size-delay; i++)
    {
      s += get(i)*get(i-delay);
    }
    s = s/(_size-delay);
    return s-autoMean(0)*autoMean(delay);
  }
  else
    return 0;
}

float CBuffer::autoCorr(int delay)
{
  if(delay>=0)
  {
    float s = 0;
    for(int i = 0; i<_size-delay; i++)
    {
      s += get(i)*get(i-delay);
    }
    s = s/(_size-delay);
    return (s-autoMean(0)*autoMean(delay))/(autoStd(0)*autoStd(delay));
  }
  else
    return 0;
}

float CBuffer::getPeriod()
{
  int first, second;
  first = 0;
  second  = 0;
  float past,present,next;
  past = autoCorr(0);
  present = autoCorr(1);
  for(int i = 1;i<_size;i++)
  {
    next = autoCorr(i+1);
    if(present<past && present < next)
    {
      if(first == 0)
        first = i;
      else if (second == 0) {
        second = i;
      }
      else
        return (i-first)/2;
    }
    past = present;
    present = next;
  }
  return 0;
}
