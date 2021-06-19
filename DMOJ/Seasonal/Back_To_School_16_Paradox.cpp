#include <bits/stdc++.h>

using namespace std;

int C, N;
string E;
set<string> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> C;

    while (C--) {
        cin >> N;

        if (N == 1) {
            cin >> E;

            if (!s.count(E)) {
                s.insert(E);
                cout << "true\n";
            } else
                cout << "false\n";

        } else if (N == 2) {
            cin >> E;

            if (!s.count(E))
                cout << "false\n";
            else {
                s.erase(E);
                cout << "true\n";
            }

        } else if (N == 3) {
            cin >> E;

            if (!s.count(E))
                cout << "-1\n";
            else
                cout << distance(s.begin(), s.find(E)) << "\n";

        } else {
            if (s.count("true") && s.count("false"))
                cout << "false true\n";
            else if (s.count("true") && !s.count("false"))
                cout << "true\n";
            else if (!s.count("true") && s.count("false"))
                cout << "false\n";
            else
                cout << "\n";
        }
    }
}
