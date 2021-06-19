#include <bits/stdc++.h>

int A, N, k;

int main() {
    scanf("%d %d", &A, &N);

    while (N--) {
        scanf("%d", &k);
        printf(abs(A-k) > 100 ? "go away! 3:<\n" : "fite me! >:3\n");
    }
}
