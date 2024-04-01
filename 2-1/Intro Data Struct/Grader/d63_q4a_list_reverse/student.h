#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template<typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
    auto rit = a;
    while (a != b) {
        b--;

        if (b == a) break;
        
        std::swap(*a, *b);
        a++;
    }
    return rit;
}

#endif
