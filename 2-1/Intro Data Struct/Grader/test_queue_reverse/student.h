#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED

#include "queue.h"

template<typename T>
void CP::queue<T>::reverse() {
    // Your code here
    for (int i = 0; i < mSize / 2; i++) {
        std::swap(mData[(mFront + i) % mCap], mData[(mFront + mSize - 1 - i) % mCap]);
    }
}

#endif