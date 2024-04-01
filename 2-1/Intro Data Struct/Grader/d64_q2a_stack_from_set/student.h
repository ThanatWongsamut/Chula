#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__

#include "stack.h"

//DO NOT INCLUDE ANYTHING


template<typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first, typename std::set<T>::iterator last) {
    int cap = 0;

    typename std::set<T>::iterator it = first;
    while (it != last) {
        cap++;
        it++;
    }

    mData = new T[cap]();
    mCap = cap;
    mSize = cap;

    it = first;
    while (cap > 0) {
        mData[cap - 1] = *(it++);
        cap--;
    }
}

#endif
