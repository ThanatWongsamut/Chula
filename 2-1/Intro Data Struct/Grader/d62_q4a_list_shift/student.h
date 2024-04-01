#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template<typename T>
void CP::list<T>::shift_left() {
    auto a = mHeader->next;
    auto b = mHeader->next->next;
    auto c = mHeader->prev;

    mHeader->next = b;
    mHeader->prev = a;

    a->next = mHeader;
    a->prev = c;

    b->prev = mHeader;

    c->next = a;
}

#endif
