#include <bits/stdc++.h>

using namespace std;

int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (i != j)
                ans += i*j;
        }
    }

    cout << ans << '\n';
}
