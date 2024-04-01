#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <set>

//you can include any other file here
//you are allow to use any data structure


template<typename T>
void CP::vector<T>::uniq() {
    std::set<T> c;
    T *arr = new T[mCap];
    int j = 0;

    for (int i = 0; i < mSize; i++) {
        if (c.find(mData[i]) == c.end()) {
            arr[j] = mData[i];
            c.insert(mData[i]);
            j += 1;
        }
    }

    delete[] mData;
    mData = arr;
    mSize = j;
}

#endif
