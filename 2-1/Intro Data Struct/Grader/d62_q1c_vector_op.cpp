#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::string o;
    int x;
    std::vector<int> a;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> o;

        if (o == "pb") {
            std::cin >> x;
            a.push_back(x);
        } else if (o == "sa") {
            std::sort(a.begin(), a.end());
        } else if (o == "sd") {
            std::sort(a.rbegin(), a.rend());
        } else if (o == "r") {
            std::reverse(a.begin(), a.end());
        } else if (o == "d") {
            std::cin >> x;
            a.erase(a.begin() + x);
        }
    }

    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}