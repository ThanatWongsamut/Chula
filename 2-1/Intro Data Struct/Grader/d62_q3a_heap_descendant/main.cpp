#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_child(int index, int n, vector<int> &v) {
    int l, r;
    l = (2 * (index + 1)) - 1;
    r = (2 * (index + 1));

    if (l >= n) {
        return;
    }

    if (l < n) {
        v.push_back(l);
    }

    if (r >= n) {
        return;
    }

    if (r < n) {
        v.push_back(r);
    }

    print_child(l, n, v);
    print_child(r, n, v);
}

int main() {
    int n, a;
    vector<int> v;

    cin >> n >> a;


    print_child(a, n, v);

    sort(v.begin(), v.end());

    cout << v.size() + 1 << endl;

    cout << a;

    for (auto x: v) {
        cout << " " << x;
    }
}