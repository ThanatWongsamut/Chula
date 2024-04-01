#ifndef __STUDENT_H_
#define __STUDENT_H_

template<typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
    for (int i = 0; i < mSize; i++) {
        if (i >= other.size()) return false;
        if (mData[i] < other[i]) return true;
        if (mData[i] > other[i]) return false;
    }

    if (mSize < other.size()) return true;

    return false;
}

#endif
