#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    map<string, int> a;

    cin >> n;

    while (n--) {
        string x;
        cin >> x;
        if (!a.count(x)) {
            a[x] = 1;
        } else {
            a[x]++;
        }
    }

    for (auto k: a) {
        if (k.second > 1) {
            cout << k.first << " " << k.second << endl;
        }
    }

    return 0;
}