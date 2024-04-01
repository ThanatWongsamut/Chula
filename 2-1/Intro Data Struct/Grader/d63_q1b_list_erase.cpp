#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void list_erase(vector<int> &v, vector<int> &pos) {
    for (auto p: pos) {
        *(v.begin() + p) = INT32_MAX;
    }

    v.erase(remove(v.begin(), v.end(), INT32_MAX), v.end());
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n), pos(m);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < m; i++) cin >> pos[i];
    list_erase(v, pos);
    cout << "After call list_erase" << endl << "Size = " << v.size() << endl;
    for (auto &x: v) cout << x << " ";
    cout << endl;
}