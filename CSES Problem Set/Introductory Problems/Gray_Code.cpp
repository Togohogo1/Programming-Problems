#include<bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

int n;
vs rev, vec = {"0", "1"};

void gray(int gen) {
    if (!gen) {
        for (auto i : vec) {
            cout << i << '\n';
        }

        return;
    }

    rev = vec;
    reverse(rev.begin(), rev.end());

    for (int i = 0; i < rev.size(); i++) {
        vec[i] = "0" + vec[i];
        vec.push_back("1"+rev[i]);
    }

    gray(gen-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    gray(n-1);
}
