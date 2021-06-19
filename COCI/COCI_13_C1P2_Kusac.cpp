#include <bits/stdc++.h>

int N, M, ans;

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N*M; i++) {
        if (i % N == 0 && i % M != 0)
            ans++;
    }

    printf("%d\n", ans);
}
