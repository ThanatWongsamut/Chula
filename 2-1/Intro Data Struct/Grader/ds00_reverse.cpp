//
// Created by TitorPs360 on 17/8/2022 AD.
//

#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v,int a,int b) {
    while(b>a) { swap(v[a], v[b]); a++; b--;}
}

int main() {
    //read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    //call function
    reverse(v,a,b);
    //display content of the vector
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}