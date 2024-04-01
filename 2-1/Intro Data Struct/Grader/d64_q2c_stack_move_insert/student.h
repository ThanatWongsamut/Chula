#ifndef __STUDENT_H__
#define __STUDENT_H__

template<typename T>
void CP::stack<T>::moveInsert(int k, CP::stack<T> &s2, int m) {
    std::vector<T> tmp;

    m = m > s2.size() ? s2.size() : m;

    for (int i = 0; i < k; i++) {
        tmp.push_back(top());
        pop();
    }

    for (int i = 0; i < m; i++) {
        tmp.push_back(s2.top());
        s2.pop();
    }

    for (int i = tmp.size() - 1; i >= 0; i--) {
        push(tmp[i]);
    }
}

#endif
