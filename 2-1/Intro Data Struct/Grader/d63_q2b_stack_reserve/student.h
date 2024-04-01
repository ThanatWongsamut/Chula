#ifndef __STUDENT_H_
#define __STUDENT_H_

template<typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    if (this->mCap - this->mSize == other.mCap - other.mSize) {
        return 0;
    } else if (this->mCap - this->mSize > other.mCap - other.mSize) {
        return 1;
    } else {
        return -1;
    }
}

#endif
