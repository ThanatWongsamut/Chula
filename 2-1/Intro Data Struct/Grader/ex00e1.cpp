//
// Created by Thanat Wongsamut on 10/8/2022 AD.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int H, M;
    int X;

    cin >> H >> M;
    cin >> X;

    M = M + X;
    H = H + (M / 60);
    M = M % 60;
    H = H % 24;

    cout << setfill('0') << setw(2) <<  H << ' ' << setw(2) << M << endl;
}