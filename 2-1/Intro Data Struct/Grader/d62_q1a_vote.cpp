//
// Created by TitorPs360 on 1/9/2022 AD.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    string name;

    map<string, int> votes;
    vector<int> score;

    cin >> n >> k;

    while (n--) {
        cin >> name;

        if (votes.find(name) != votes.end()) {
            votes[name] += 1;
        } else {
            votes[name] = 1;
        }
    }

    for (auto vote: votes) {
        score.push_back(vote.second);
    }

    sort(score.rbegin(), score.rend());

    if (votes.size() > k) {
        int i = 0;
        int pre = 0;

        while (true) {
//            cout << "score: " << score[i] << " k: " << k << endl;
            if (k <= 0) {
                i--;
                break;
            } else if (score[i] != pre && k > 0) {
                k--;
                pre = score[i];
                i++;
            } else if (score[i] == pre) {
                k--;
                i++;
            }
        }

        cout << score[i] << endl;
    } else {
        cout << score[score.size() - 1] << endl;
    }

    return 0;
}