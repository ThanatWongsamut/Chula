#ifndef __STUDENT_H_
#define __STUDENT_H_


template<typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    T *arr = new T[mSize - pos.size()]();

    int erased = 0;

    for (int i = 0; i < mSize; i++) {
        if (i == pos[erased] && erased < pos.size()) {
            erased += 1;
        } else {
            arr[i - erased] = mData[i];
        }
    }

    delete[] mData;
    mData = arr;
    mSize = mSize - pos.size();
    mCap = mSize;
}

#endif
