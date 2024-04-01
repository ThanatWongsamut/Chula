#ifndef __STUDENT_H_
#define __STUDENT_H_

template<typename T>
CP::list<T> CP::list<T>::split(iterator it, size_t pos) {
    CP::list<T> result;

    if (it == end()) return result;

    node *list2_begin = it.ptr;
    node *list2_end = mHeader->prev;
    node *list1_end = it.ptr->prev;

    list1_end->next = mHeader;
    mHeader->prev = list1_end;

    list2_end->next = result.mHeader;
    list2_begin->prev = result.mHeader;
    result.mHeader->next = list2_begin;
    result.mHeader->prev = list2_end;

    result.mSize = mSize - pos;
    mSize = pos;

    return result;
}

#endif
