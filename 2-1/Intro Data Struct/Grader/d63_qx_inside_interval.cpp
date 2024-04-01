#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    int a, b;
    int x;
    map<int, int> scopes;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    while (n--) {
        cin >> a >> b;

        scopes[b] = scopes[b] < a ? a : scopes[b];
    }

    while (m--) {
        cin >> x;
        cout << (scopes.lower_bound(x)->second <= x && scopes.lower_bound(x) != scopes.end()) << " ";
    }

    return 0;
}