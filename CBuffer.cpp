#include "Arduino.h"
#include "CBuffer.h"

CBuffer :: CBuffer(int size)
{
  _A = new float[size];
  _head = 0;
  _size = size;
}

void CBuffer::push(float x)
{
  _A[head] = x;
  _head = (_head+1)%_size;
}

float CBuffer::get(int index)
{
  return _A[(_head-index)%_size];
}

void CBuffer::set(int index)
{
  _A[(_head-index)%_size] = x;
}

float CBuffer::autoCorr(int delay)
{
  if(delay>=0)
  {
    float s = 0;
    for(int i = 0; i<_size-delay; i++)
      s += this.get(i)*this.get(i-delay);
    s = s/(_size-delay);
    return s;
  }
  else
    return 0;
}
