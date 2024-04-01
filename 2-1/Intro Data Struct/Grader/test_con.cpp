//
// Created by TitorPs360 on 22/8/2022 AD.
//

//#include <stdio.h>

#include <iostream>

using namespace std;

int main() {
    int x, y, z;
    int *a, *b;

    x = 10;
    y = 20;
    z = 30;

    cout << "&x: " << &x << endl;
    cout << "&y: " << &y << endl;
    cout << "&z: " << &z << endl;

    a = &y + 1;
    b = &y - 1;

    cout << "*a(&y + 1): " << *a << endl;
    cout << "*b(&y - 1): " << *b << endl;
}