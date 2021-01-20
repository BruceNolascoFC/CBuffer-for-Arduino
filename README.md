# CBuffer-for-Arduino

A simple class that implements a circular buffer in C++ for Arduino. 
The main class is CBuffer.

`CBuffer(int size)`

The class contructor. size indicates the number of registers allowed in the buffer.
By default numbers are stored as floats.

`void push(float x)`

Adds a new register to the buffer. This new element has the 0 index.

`float get(int i)`

Returns the number stored in the i-th index, which is the i-th most recent register.

`void set(int i, float x)`

Sets the number stored in the i-th index to x.

`float autoMean(int delay)`

Computes the mean of the delayed signal by delay indexes.

`float autoVar(int delay)`

Computes the variance of the delayed signal by delay indexes.

`float autoStd(int delay)`

Computes the standar deviation of the delayed signal by delay indexes.

`float autoCov(int delay)`

Computes the autocovariance of the registers with respect to the delayed signal by delay indexes.

`float autoCorr(int delay)`

Computes the autocorrelation of the registers with respect to the delayed signal by delay indexes.

`float getPeriod()`

Approximates the period of the signal stored in the buffer using the autocorrelation function. If no period is found returns 0.
