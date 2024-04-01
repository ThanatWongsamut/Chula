#ifndef __STUDENT_H_
#define __STUDENT_H_


template<typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
    T *arr = new T[mSize + (last - first)];

    for (int i = 0; i < position - this->begin(); i++) {
        arr[i] = mData[i];
    }

    for (int i = 0; i < last - first; i++) {
        arr[i + position - this->begin()] = *(first + i);
    }

    for (int i = position - this->begin(); i < mSize; i++) {
        arr[i + last - first] = mData[i];
    }

    delete[] mData;
    mData = arr;
    mSize = mSize + last - first;
    mCap = mSize;
}

#endif
