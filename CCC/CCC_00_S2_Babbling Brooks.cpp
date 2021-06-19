#include <bits/stdc++.h>

using namespace std;

int N, D, n;
double tmp;
vector<double> riv;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> D;
        riv.push_back(D);
    }

    while (true) {
        cin >> n;

        if (n == 77)
            break;

        else if (n == 99) {
            int spl, per;
            cin >> spl >> per;

            tmp = riv[spl-1];
            riv[spl-1] *= per/100.0;
            riv.insert(riv.begin()+spl, tmp*(1-per/100.0));
        }

        else if (n == 88) {
            int comb;
            cin >> comb;

            tmp = riv[comb];
            riv.erase(riv.begin() + comb);
            riv[comb-1] += tmp;
        }
    }

    for (double i : riv) {
        cout << round(i) << " ";
    }
}
