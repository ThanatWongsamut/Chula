#ifndef __STUDENT_H_
#define __STUDENT_H_

template<typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
    for (int i = 0; i < mSize; i++) {
        if (mData + i == it) {
            return true;
        }
    }
    return false;
}

#endif
