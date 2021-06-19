#include <bits/stdc++.h>

using namespace std;

int tot;
string A, B;
vector<pair<int, vector<int>>> v {
    {1, {0}},
    {1, {1}},
    {4, {2, 4, 8, 6}},
    {4, {3, 9, 7, 1}},
    {2, {4, 6}},
    {1, {5}},
    {1, {6}},
    {4, {7, 9, 3, 1}},
    {4, {8, 4, 2, 6}},
    {2, {9, 1}},
};

int calc(string n) {
    int t;

    for (int i = 0; i < n.size(); i++) {
        int num = (tolower(n[i]) - 96) % 10;
        t += v[num].second[i%v[num].first];
    }

    return t%10 + 10*(t%10==0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> A >> B;

    tot += calc(A);
    tot += calc(B);

    cout << tot << endl;
}
