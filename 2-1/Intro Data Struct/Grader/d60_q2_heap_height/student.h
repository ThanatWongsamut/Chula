#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template<typename T, typename Comp>
int CP::priority_queue<T, Comp>::height() const {
    if (mSize == 0) return -1;

    int c = 0;
    int n = mSize - 1;

    while (n > 0) {
        n = (n - 1) / 2;
        c++;
    }

    return c;
}

#endif

