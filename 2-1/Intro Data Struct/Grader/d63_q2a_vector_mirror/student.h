#ifndef __STUDENT_H_
#define __STUDENT_H_

template<typename T>
void CP::vector<T>::mirror() {
    T *arr = new T[mSize * 2]();


    for (size_t i = 0; i < mSize; i++) {
        arr[i] = mData[i];
        arr[mSize * 2 - i - 1] = mData[i];
    }

    delete[] mData;
    mData = arr;
    mSize = mSize * 2;
    mCap = mSize;
}

#endif
