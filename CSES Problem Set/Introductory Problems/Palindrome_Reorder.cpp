#include <bits/stdc++.h>

using namespace std;

int odd, sz;
string n, mid, fin;
map<char, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (char i : n) {
        mp[i]++;
    }

    for (auto &i : mp) {
        if (i.second & 1) {
            odd++;

            while (i.second) {
                mid += i.first;
                i.second--;
            }

        } else {
            int tmp = i.second / 2;

            while (i.second > tmp) {
                fin += i.first;
                i.second--;
            }
        }
    }

    sz = fin.size();
    fin += mid;

    for (int i = sz - 1; i >= 0; i--) {
        fin += fin[i];
    }

    cout << (odd < 2 ? fin : "NO SOLUTION") << '\n';
}
