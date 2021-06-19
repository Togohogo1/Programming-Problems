#include<bits/stdc++.h>

using namespace std;

int c = 1, m = 1, curr;
string dna;

int main() {
    cin >> dna;
    curr = dna[0];

    for (int i = 1; i < dna.size(); i++) {
        if (dna[i] == curr)
            c++;
        else {
            curr = dna[i];
            c = 1;
        }

        m = max(m, c);
    }

    cout << m << "\n";
}
