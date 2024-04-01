#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

map<string, vector<int>> sscore;
map<string, vector<int>> tscore;

int main() {
    int n;
    string subject;
    string teacher;
    int score;

    cout << fixed << setprecision(2);

    cin >> n;

    while (n--) {
        cin >> subject >> teacher >> score;
        sscore[subject].push_back(score);
        tscore[teacher].push_back(score);
    }

    for (auto s: sscore) {
        double sum = 0.0;
        for (auto i: s.second) {
            sum += i;
        }
        sum /= s.second.size();

        cout << s.first << " " << sum << endl;
    }

    for (auto t: tscore) {
        double sum = 0.0;
        for (auto i: t.second) {
            sum += i;
        }
        sum /= t.second.size();

        cout << t.first << " " << sum << endl;
    }
}