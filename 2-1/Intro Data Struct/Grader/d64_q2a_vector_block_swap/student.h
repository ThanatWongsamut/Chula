#ifndef __STUDENT_H_
#define __STUDENT_H_

template<typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
    if (!m || std::abs(a - b) < m || a < mData || b < mData || a >= end() || b >= end() || a + m - 1 >= end() ||
        b + m - 1 >= end())
        return false;

    for (size_t i = 0; i < m; i++) {
        std::swap(*(a + i), *(b + i));
    }

    return true;
}

#endif
