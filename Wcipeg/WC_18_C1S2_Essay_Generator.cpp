#include <bits/stdc++.h>

using namespace std;

string s = "abcdefghijklmnopqrstuvwxyz";
int W, idx = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> W;

    for (int i = 0; i < 26; i++) {
        cout << s[i] << ' ';
        idx++;

        if (idx >= W) {
            cout << '\n';
            return 0;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            cout << s[i] << s[j] << ' ';
            idx++;

            if (idx >= W) {
                cout << '\n';
                return 0;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                cout << s[i] << s[j] << s[k] << ' ';
                idx++;

                if (idx >= W) {
                    cout << '\n';
                    return 0;
                }
            }
        }
    }
}
