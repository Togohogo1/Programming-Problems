#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    int c = (N-1)/2;

    for (int i = 2; i < ceil(sqrt(N+1)); i++) {
        if (i*i % 2 == 1)
            c--;
    }

    cout << c << '\n';
}
