#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template<typename T>
void CP::list<T>::extract(const T &value, iterator a, iterator b, CP::list<T> &output) {
    auto it = output.begin();
    
    while (a != b) {
        if (*a == value) {

            node *n = new node(value, it.ptr->prev, it.ptr);
            it.ptr->prev->next = n;
            it.ptr->prev = n;
            output.mSize++;

            auto tmp = a;
            a++;

            tmp.ptr->prev->next = tmp.ptr->next;
            tmp.ptr->next->prev = tmp.ptr->prev;
            delete tmp.ptr;
            mSize--;
        } else {
            a++;
        }
    }
}

#endif
