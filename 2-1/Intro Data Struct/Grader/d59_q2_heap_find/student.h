#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template<typename T, typename Comp>
bool CP::priority_queue<T, Comp>::find(T k) const {
    for (int i = 0; i < mSize; i++) {
        if (k == mData[i]) return true;
    }
    return false;
}

template<typename T, typename Comp>
int CP::priority_queue<T, Comp>::find_level(T k) const {
    int position = -1;
    for (int i = 0; i < mSize; i++) {
        if (k == mData[i]) position = i;
    }

    if (position == -1) return -1;

    int c = 0;

    while (position > 0) {
        position = (position - 1) / 2;
        c++;
    }

    return c;
}

#endif

