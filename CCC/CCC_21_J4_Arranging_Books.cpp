#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int cL, cM, cS, LM, LS, ML, aux;
string str, L, M, S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> str;

    cL = count(all(str), 'L');
    cM = count(all(str), 'M');
    cS = count(all(str), 'S');

    L = str.substr(0, cL);
    M = str.substr(cL, cM);
    S = str.substr(cL+cM);

    LM = count(all(L), 'M');
    LS = count(all(L), 'S');
    ML = count(all(M), 'L');
    aux = count(all(M), 'S') + (ML <= LM ? 0 : ML - LM);

    cout << LM + LS + aux << '\n';
}
