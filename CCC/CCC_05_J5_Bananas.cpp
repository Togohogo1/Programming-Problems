#include <bits/stdc++.h>

using namespace std;

string word;

bool valid(string s) {
    if (s == "")
        return false;

    if (s == "A")
        return true;

    // MW + N + MW
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N')
            if (valid(s.substr(0, i)) && valid(s.substr(i+1)))
                return true;
    }

    // B + MW + S
    if (s[0] == 'B' && s[s.size()-1] == 'S')
        return valid(s.substr(1, s.size()-2));
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (true) {
        cin >> word;

        if (word == "X")
            break;

        if (valid(word))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
