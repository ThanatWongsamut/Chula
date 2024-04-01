#ifndef __STUDENT_H_
#define __STUDENT_H_


template<typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
    std::vector<T> res;

    for (int i = 0; i < k; i++) {
        res.push_back(mData[(mFront + i) % mCap]);
    }

    return res;
}

template<typename T>
CP::queue<T>::queue(iterator from, iterator to) {
    int cap = to - from;
    int i = 0;
    mData = new T[cap]();
    mCap = cap;

    while (i < cap) {
        mData[i] = *(from + i);
        i++;
    }
    
    mSize = cap;
    mFront = 0;
}

#endif
