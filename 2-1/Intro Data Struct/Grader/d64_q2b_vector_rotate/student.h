#ifndef __STUDENT_H_
#define __STUDENT_H_

template<typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
    int s = last - first;
    if (s == 0 || k == 0) return;

    k %= s;

    T *arr = new T[k];

    for (int i = 0; i < k; i++) {
        arr[i] = *(first + i);
    }

    for (int i = 0; i < s - k; i++) {
        *(first + i) = *(first + i + k);
    }

    for (int i = 0; i < k; i++) {
        *(first + i + s - k) = arr[i];
    }

    delete[] arr;
}

#endif