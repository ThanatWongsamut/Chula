#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int, int> > v) {
    stack<int> a;

    for (auto i: v) {
        if (i.first == 1) {
            a.push(i.second);
        } else {
            int x, y, r;
            x = a.top();
            a.pop();
            y = a.top();
            a.pop();

            if (i.second == 0) {
                r = y + x;
            } else if (i.second == 1) {
                r = y - x;
            } else if (i.second == 2) {
                r = y * x;
            } else if (i.second == 3) {
                r = y / x;
            }

            a.push(r);
        }
    }

    return a.top();
}

#endif
