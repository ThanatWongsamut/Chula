#include<stdio.h>

using namespace std;

int main() {
    int n, inp;
    scanf("%d", &n);
    int s = ((n + 1) * n) / 2;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp);
        if (inp <= 0 || inp > n) break;
        s -= inp;
    }
    if (s == 0) printf("YES");
    else printf("NO");
}
