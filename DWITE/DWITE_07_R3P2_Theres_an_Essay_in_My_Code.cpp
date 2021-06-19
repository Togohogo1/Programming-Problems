#include <bits/stdc++.h>

using namespace std;

int main() {
    for(int t = 1; t <= 5; t++) {
        string s = "", ans = "";
        getline(cin, s);

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '"') {
                int nxt = s.find("\"", i+1);
                ans += " " + s.substr(i+1, nxt-i-1);
                i = nxt;

            } else if (s[i] == '\'') {
                int nxt = s.find("\'", i+1);
                ans += " " + s.substr(i+1, nxt-i-1);
                i = nxt;

            } else if (s[i] == '/' && i+1 < s.size() && s[i+1] == '*') {
                int nxt = s.find("*/", i+2);
                ans += " " + s.substr(i+2, nxt-i-2);
                i = nxt;

            } else if (s[i] == '/' && i+1 < s.size() && s[i+1] == '/') {
                ans += " " + s.substr(i+2);
                i = s.size();
            }
        }

        cout << ans.substr(1) << endl;
    }
}
