//
// Created by TitorPs360 on 31/8/2022 AD.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m;
    vector<int> v1, v2, res;

    while (n--) {
        cin >> x;
        v1.push_back(x);
    }

    while (m--) {
        cin >> x;
        v2.push_back(x);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int j = 0;

    for (int i = 0; i < v1.size(); i++) {
        if (i > 0 && v1[i] == v1[i - 1]) {
            continue;
        }

        while (j < v2.size() && v1[i] > v2[j]) {
            j++;
        }

        if (j < v2.size() && v1[i] == v2[j]) {
            cout << v1[i] << " ";
        }
    }

    cout << endl;

    return 0;
}