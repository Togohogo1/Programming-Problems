#include <bits/stdc++.h>

using namespace std;

int Uc, Um, k;

int main() {
    scanf("%d %d %d", &Uc, &Um, &k);
    printf("%d\n", max(Uc, Um) * k);
}
