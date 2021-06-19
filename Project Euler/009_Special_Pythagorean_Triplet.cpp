#include <bits/stdc++.h>

using namespace std;

int isPy(int a, int b, int c) {
    return a*a + b*b == c*c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 1; i < 332; i++) {
        for (int j = i+1; j < (1000-i)/2; j++) {
            int k = 1000 - i - j;

            if (isPy(i, j, k))
                cout << i*j*k << '\n';
        }
    }
}
