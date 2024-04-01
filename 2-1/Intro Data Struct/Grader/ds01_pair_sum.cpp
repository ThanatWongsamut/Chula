#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x;
    bool found = false;
    cin >> n >> m;
    vector<int> ar;

    while (n--) {
        cin >> x;
        ar.push_back(x);
    }

    sort(ar.begin(), ar.end());

    while (m--) {
        cin >> x;

        for (auto i = ar.begin(); i < ar.end() - 1; i++) {
            found = false;

//            cout << *i << *(ar.end() - 1) << x - *i << binary_search(i + 1, ar.end(), x - *i) << endl;

            if (binary_search(i + 1, ar.end(), x - *i)) {
                found = true;
                break;
            }
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

//#include <stdio.h>
//#include <unordered_map>
////#include <bits/stdc++.h>
//
//using namespace std;
//
//void checkPair(int arr[], int a, int sum, unordered_map<int, int> m) {
//    if (m[sum] == 1) {
//        printf("YES\n");
//        return;
//    }
//    if (m[sum] == -1) {
//        printf("NO\n");
//        return;
//    }
//    for (int i = 0; i < a; i++) {
//        int r = sum - arr[i];
//
//        if (m.find(r) != m.end()) {
//            m[sum] = 1;
//            printf("YES\n");
//            return;
//        } else {
//            m[arr[i]]++;
//        }
//    }
//    m[sum] = -1;
//    printf("NO\n");
//    return;
//}
//
//int main() {
//    int N, M, sum;
//    unordered_map<int, int> m;
//    scanf("%d %d", &N, &M);
//    int arr[N];
//    printf("receiving array");
//    for (int i = 0; i < N; i++) {
//        scanf("%d", &arr[i]);
//    }
//    printf("receiving sum");
//    printf("%d", sizeof(arr) / sizeof(arr[0]));
//    for (int i = 0; i < M; i++) {
//        scanf("%d", &sum);
////        printf("&d", i);
////        cout << i << endl;
//        checkPair(arr, N, sum, m);
//    }
//
//    return 0;
//}
