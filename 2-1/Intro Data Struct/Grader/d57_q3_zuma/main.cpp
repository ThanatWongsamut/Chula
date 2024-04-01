#include <stdio.h>

int N, L, R, S, i;
short A[1000003];

int main() {
    scanf("%d%d%d", &N, &L, &R);
    for (++N, ++L, i = 1; i <= N; i++)
        i == L ? A[i] = R : scanf("%d", &A[i]);
    for (R = L; L && A[L] == A[R]; S = ++R - L--) {
        while (A[L - 1] == A[L]) L--;
        while (A[R + 1] == A[R]) R++;
        if (R - L - S < 2) break;
    }
    for (i = 1; i <= N; i++)
        if (i <= L || i >= R)
            printf("%d ", A[i]);
}
