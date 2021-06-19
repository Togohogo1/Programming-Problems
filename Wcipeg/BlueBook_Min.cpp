#include<bits/stdc++.h>

using namespace std;

int N;
float x, ans = 99999;

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%f", &x);
        ans = min(ans, x);
    }

    printf("%.2f", ans);
}
