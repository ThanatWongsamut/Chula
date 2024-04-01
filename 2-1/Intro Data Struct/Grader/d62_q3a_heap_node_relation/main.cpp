#include <iostream>

using namespace std;

bool parent_check(int parent, int child) {
    while (child > parent) {
        child = (child - 1) / 2;
        if (child == parent) return true;
    }

    return false;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;

        if (a == b) {
            cout << "a and b are the same node" << endl;
            continue;
        }

        if (parent_check(a, b)) {
            cout << "a is an ancestor of b" << endl;
        } else if (parent_check(b, a)) {
            cout << "b is an ancestor of a" << endl;
        } else {
            cout << "a and b are not related" << endl;
        }
    }
}