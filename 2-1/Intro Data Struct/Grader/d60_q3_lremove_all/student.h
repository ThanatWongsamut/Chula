#ifndef __STUDENT_H_
#define __STUDENT_H_

template<typename T>
void CP::list<T>::remove_all(const T &value) {
    auto it = begin();

    while (it != end()) {
        if (*it == value) {
            auto tmp = it;
            it++;
            tmp.ptr->prev->next = tmp.ptr->next;
            tmp.ptr->next->prev = tmp.ptr->prev;
            delete tmp.ptr;
            mSize--;
        } else {
            it++;
        }
    }
}

#endif
