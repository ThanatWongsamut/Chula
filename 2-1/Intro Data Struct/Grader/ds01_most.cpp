//
// Created by TitorPs360 on 31/8/2022 AD.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    string x;
    cin >> n;
    map<string, int> a;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (a.find(x) != a.end()) {
            a[x] += 1;
        } else {
            a[x] = 1;
        }
    }

    string keyMax;
    int valMax = 0;

    for (auto it = a.begin(); it != a.end(); it++) {
        if (it->second >= valMax) {
            keyMax = it->first;
            valMax = it->second;
        }
    }

    cout << keyMax << " " << valMax << endl;

    return 0;
}