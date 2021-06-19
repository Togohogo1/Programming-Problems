#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (true) {
        getline(cin, s);

        if (s[0] == '0')
            break;

        stack<string> stk;

        // Scan from left to left (prefix)
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == ' ')
                continue;

            if (s[i] == '+' || s[i] == '-') {  // Operator
                string op1 = stk.top(); stk.pop();
                string op2 = stk.top(); stk.pop();
                stk.push(op1 + " " + op2 + " " + s[i]);
            } else  // Operand
                stk.push(s.substr(i, 1));
        }

        cout << stk.top() << '\n';
    }
}
