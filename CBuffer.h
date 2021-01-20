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
    void set(int index);
    void autoCorr(int delay)
  private:
    float* _A;
    int _head;
    int _size;
};

#endif
