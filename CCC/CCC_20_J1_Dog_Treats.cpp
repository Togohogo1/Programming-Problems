#include <bits/stdc++.h>

int S, M, L;

int main() {
    scanf("%d %d %d", &S, &M, &L);
    printf(S + 2*M + 3*L >= 10 ? "happy\n" : "sad\n");
}
