#include<bits/stdc++.h>

using namespace std;

int N;
string word, names[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<string> side[2];

int index(string v) {
    auto it = find(names, names+8, v);
    return it != end(names) ? distance(names, it) : -1;
}

bool check() {
    for (int i = 0; i < N; i++) {
        if (abs(index(side[0][i])-index(side[1][i])) != 1)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> word;

            if (j == 0)
                side[0].push_back(word);
            else if (j == 5)
                side[1].push_back(word);
        }
    }

    do {
        if (check())
            break;
    } while (next_permutation(names, names+8));

    for (auto i : names) {
        cout << i << '\n';
    }
}
