#include <iostream>
#include <set>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    int x, y;

    set<pair<int, int>> s;
    s.insert({-1, -1});

    cin >> n >> m;

    while (n--) {
        cin >> x >> y;
        s.insert({x, y});
    }

    while (m--) {
        cin >> x >> y;
        pair<int, int> c = {x, y};

        auto it = --s.upper_bound(c);

        if (*it == c) {
            cout << "0 0 ";
        } else {
            cout << it->first << " " << it->second << " ";
        }
    }

    return 0;
}