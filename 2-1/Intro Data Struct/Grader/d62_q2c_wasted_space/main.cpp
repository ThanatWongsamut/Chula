#include <iostream>

using namespace std;

int main() {
    int n;
    int i = 1;
    cin >> n;

    while (true) {
        if (i >= n) {
            cout << i - n << endl;
            break;
        }

        i *= 2;
    }
}
