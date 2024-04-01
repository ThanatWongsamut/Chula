#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template<typename T>
std::vector<std::pair<T, size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    std::vector<std::pair<T, size_t>> result;
    std::map<T, size_t> counter;

    for (auto a: k) {
//        result.push_back(std::make_pair(a, 0));
        counter[a] = 0;
    }

    for (int i = 0; i < mSize; i++) {
        if (counter.find(mData[(mFront + i) % mCap]) != counter.end()) {
            counter[mData[(mFront + i) % mCap]]++;
        }
    }

    for (auto b: k) {
        result.push_back(std::make_pair(b, counter[b]));
    }

    return result;
}

#endif
