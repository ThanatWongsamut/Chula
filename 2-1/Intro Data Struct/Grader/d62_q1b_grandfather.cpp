//
// Created by TitorPs360 on 1/9/2022 AD.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    long long f, s, a, b;
    map<long long, long long> re;

    cin >> n >> m;

    while (n--) {
        cin >> f >> s;
        re[s] = f;
    }

    while (m--) {
        cin >> a >> b;
        if (a != b && re.find(a) != re.end() && re.find(b) != re.end()) {
            long long fa = re[a];
            long long fb = re[b];

            if (re.find(fa) != re.end() && re.find(fb) != re.end()) {
                long long ga = re[fa];
                long long gb = re[fb];

                if (ga == gb) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}
