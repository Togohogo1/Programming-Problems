#include <bits/stdc++.h>

using namespace std;

int N, v;
string s;
vector<pair<int, string>> names;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s >> v;
        names.push_back({v, s});
    }

    sort(names.begin(), names.end());
    cout << names[N/2-(N%2==0)].second << endl;
}
