#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    int x;

    map<int, int> atk;

    cin >> n >> m;

    while (n--) {
        cin >> x;
        atk[x] += 1;
    }

    int k = 1;
    bool lose = false;

    while (k <= m) {
        int c, p;
        cin >> c;

        for (int i = 0; i < c; i++) {
            cin >> p;

            auto it = atk.upper_bound(p);

            if (it == atk.end() || it->first == p) {
                lose = true;
                break;
            }

            it->second--;

            if (it->second == 0) {
                atk.erase(it);
            }
        }

        if (lose) {
            break;
        }

        k++;
    }

    cout << k;
}