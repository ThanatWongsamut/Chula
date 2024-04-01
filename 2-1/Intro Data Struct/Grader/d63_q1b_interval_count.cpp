#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    int x;
    vector<int> s;
    s.reserve(200000);

    cin >> n >> m >> k;

    while (n--) {
        cin >> x;
        s.push_back(x);
    }

    sort(s.begin(), s.end());

    while (m--) {
        cin >> x;
        cout << upper_bound(s.begin(), s.end(), x + k) - lower_bound(s.begin(), s.end(), x - k) << " ";
    }
}
