#include <bits/stdc++.h>

using namespace std;

int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            ans += i;
    }

    cout << ans << "\n";
}
