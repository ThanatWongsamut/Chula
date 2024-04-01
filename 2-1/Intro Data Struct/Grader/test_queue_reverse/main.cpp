#include <iostream>
#include <vector>
#include "queue.h"
#include "student.h"
#include <stdio.h>

int main() {
    CP::queue<int> q;

    for (int i = 0; i < 50; i++) {
        q.push(i);
    }

    q.pop();
    q.pop();
    q.pop();

    q.push(999999);
    q.push(111111);
    q.pop();
    q.push(333333);

    q.reverse();
    q.reverse();
    q.reverse();

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
}

4 1 2 3

1 2 3
3 2 1
3 2 1 4