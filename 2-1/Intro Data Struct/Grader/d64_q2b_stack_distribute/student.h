#ifndef __STUDENT_H__
#define __STUDENT_H__

template<typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
    std::vector<std::vector<T>> res(k);
    int m = mSize % k;
    int p = mSize - 1;
    for (int i = 0; i < k; i++) {
        int need = mSize / k;
        if (i < m) need++;
        while (need--) res[i].push_back(mData[p--]);
    }

    return res;
}

#endif
