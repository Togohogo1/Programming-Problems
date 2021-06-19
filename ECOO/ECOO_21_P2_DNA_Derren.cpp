#include <bits/stdc++.h>

using namespace std;

string dna, tmp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> dna;
    dna = "_" + dna + "_";

    for (int i = 1; i < dna.size() - 1; i++) {
        if ((dna[i] != 'A' && dna[i-1] != 'A') || (dna[i] == 'A' && dna[i-1] == 'A')) {
            cout << tmp << ' ';
            tmp = dna[i];
        } else
            tmp += dna[i];
    }

    cout << tmp << '\n';
}
