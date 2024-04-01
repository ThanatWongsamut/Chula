#include <iostream>

using namespace std;

int main() {
    long long n, k;
    int i = 0;
    long long j = 1;
    long long sum = 1;
    cin >> n >> k;

    if (k == 1) {
        cout << (n - 1) << '\n';
        return 0;
    }

    while (sum < n) {
        i += 1;
        j *= k;
        sum += j;
    }

    cout << i;
}