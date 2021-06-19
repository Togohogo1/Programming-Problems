#include<bits/stdc++.h>

using namespace std;

const int M = 102;
int L, n, dep;
string name, arr[2*M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> L;

    for (int i = 0; i < L; i++) {
        dep = 0;

        vector<pair<int, string>> aux;
        stack<string> stk;
        unordered_map<string, pair<int, int>> names;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> name;
            arr[i] = name;
            names[name] = {0, 0};
        }

        names[name] = {1, 0};

        for (int i = 2; i <= n+1; i++) {
            if (!names[arr[i-2]].first) {
                names[arr[i-2]].first = i;
            }

            names[arr[i-2]].second = i;
        }

        for (auto i : names) {
            aux.push_back({i.second.first, i.first});
            aux.push_back({i.second.second, i.first});
        }

        sort(aux.begin(), aux.end());

        for (auto i : aux) {
            if (stk.empty() || stk.top() != i.second)
                stk.push(i.second);
            else
                stk.pop();

            dep = max(dep, (int)stk.size());
        }

        cout << (n-2*(dep-1))*10 << '\n';
    }
}
