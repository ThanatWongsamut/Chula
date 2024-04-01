//
// Created by TitorPs360 on 22/8/2022 AD.
//

//#include <stdio.h>

#include <iostream>

using namespace std;

class test {
public:
    test() : data() { cout << "created" << endl; }

    ~test() { cout << "destroyed" << endl; }

    int data;
};

int main() {
    test *a;
    a = new test[4];

    a[0].data = 10;
    a[1].data = 20;
    a[2].data = 30;
    a[3].data = 40;

    cout << "&a[0]: " << &a[0] << ", a[0].data: " << a[0].data << ", *(a+0): " << (a + 0)->data << endl;
    cout << "&a[1]: " << &a[1] << ", a[1].data: " << a[1].data << ", *(a+1): " << (a + 1)->data << endl;
    cout << "&a[2]: " << &a[2] << ", a[2].data: " << a[2].data << ", *(a+2): " << (a + 2)->data << endl;
    cout << "&a[3]: " << &a[3] << ", a[3].data: " << a[3].data << ", *(a+3): " << (a + 3)->data << endl;
}