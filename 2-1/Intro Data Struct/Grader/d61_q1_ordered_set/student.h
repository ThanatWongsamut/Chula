#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template<typename T>
vector<T> Union(const vector<T> &A, const vector<T> &B) {
    vector<T> v(A);
    set<T> c(A.begin(), A.end());

    for (auto i: B) {
        if (c.find(i) == c.end()) {
            v.push_back(i);
        }
    }
    return v;
}

template<typename T>
vector<T> Intersect(const vector<T> &A, const vector<T> &B) {
    vector<T> v;
    set<T> c(B.begin(), B.end());

    for (auto i: A) {
        if (c.find(i) != c.end()) {
            v.push_back(i);
        }
    }
    return v;
}