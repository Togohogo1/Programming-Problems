#include <bits/stdc++.h>

int P, N, R;

int main() {
    scanf("%d %d %d", &P, &N, &R);
    int curr = N, count = 0, total = N;

    while (total <= P) {
        curr *= R;
        total += curr;
        count++;
    }

    printf("%d", count);
}
