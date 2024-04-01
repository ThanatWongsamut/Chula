#ifndef __STUDENT_H_
#define __STUDENT_H_


template<typename T>
void CP::stack<T>::multi_pop(size_t K) {
    while (!empty() && K != 0) {
        pop();
        K--;
    }
}

template<typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
    std::stack<T> a;
    std::stack<T> result;

    while (!empty() && K != 0) {
        a.push(top());
        pop();
        K--;
    }

    while (!a.empty()) {
        result.push(a.top());
        a.pop();
    }

    return result;
}

#endif
