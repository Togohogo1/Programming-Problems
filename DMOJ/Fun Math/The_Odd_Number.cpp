#include <stdio.h>

int N, x, ans;

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        ans ^= x;
    }

    printf("%d\n", ans);
}
