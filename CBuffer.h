/*
  CBuffer.h
*/
#ifndef CBuffer_h
#define CBuffer_h

#include "Arduino.h"

class CBuffer
{
  public:
    CBuffer(int size);
    void push(float x);
    float get(int index);
    void set(int index, float x);
    float autoMean(int delay);
    float autoVar(int delay);
    float autoStd(int delay);
    float autoCov(int delay);
    float autoCorr(int delay);
    float getPeriod();
  private:
    float* _A;
    int _head;
    int _size;
};

#endif
