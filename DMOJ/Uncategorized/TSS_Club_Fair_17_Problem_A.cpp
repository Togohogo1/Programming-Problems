#include <bits/stdc++.h>

using namespace std;

int N;
string a, b, c;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;

        if (a == b || a == c)
            cout << a << "\n";
        else if (b == c)
            cout << b << "\n";
        else
            cout << "???\n";
    }
}
