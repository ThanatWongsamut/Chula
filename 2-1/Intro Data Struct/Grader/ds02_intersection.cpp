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

    for (int a: v1) {
        auto it = find(v2.begin(), v2.end(), a);
        auto it2 = find(res.begin(), res.end(), a);
        if (it != v2.end() && it2 == res.end()) {
            res.push_back(a);
            v2.erase(it);
        }
    }

    sort(res.begin(), res.end());

    for (int re: res) {
        cout << re << " ";
    }

    return 0;
}