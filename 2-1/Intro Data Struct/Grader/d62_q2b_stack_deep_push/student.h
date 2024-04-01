#ifndef __STUDENT_H_
#define __STUDENT_H_


template<typename T>
void CP::stack<T>::deep_push(size_t pos, const T &value) {
    ensureCapacity(mSize + 1);

    for (int i = mSize; i > mSize - pos; i--) {
        mData[i] = mData[i - 1];
    }

    mSize += 1;
    mData[mSize - 1 - pos] = value;
}

#endif
