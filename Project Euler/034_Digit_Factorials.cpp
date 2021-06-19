#include <bits/stdc++.h>

using namespace std;

int ans, fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // 7 * 9! < 9999999
    for (int i = 10; i < 3e6; i++) {
        int digSum = 0;

        for (char i : to_string(i)) {
            digSum += fact[(int)i-48];
        }

        if (digSum == i)
            ans += i;
    }

    cout << ans << "\n";
}
