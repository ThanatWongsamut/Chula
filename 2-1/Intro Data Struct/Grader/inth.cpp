//
// Created by TitorPs360 on 24/8/2022 AD.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, a, b, s;
    s = 0;
    vector<pair<int, int>> m;
    cin >> n;
    while (n--) {
        scanf("%d %d", &a, &b);
        m.push_back({a, b});

        for (auto t = m.begin(); t != m.end(); t++) {
            cout << t->first << t->second << a << b << endl;
            cout << (a > t->first && t->second > b) << endl;
            if (a > t->first && t->second > b) {
                s += t->first + a;
            }
        }

    }

    cout << s;
}