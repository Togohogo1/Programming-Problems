#include <bits/stdc++.h>

using namespace std;

int S, I, E;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> S >> I >> E;

    if (E <= S + I)
        cout << S + I << '\n';
    else if (E <= S + 2*I)
        cout << S + 2*I << '\n';
    else if (E <= S + 3*I)
        cout << S + 3*I << '\n';
    else
        cout << "Who knows...\n";
}
