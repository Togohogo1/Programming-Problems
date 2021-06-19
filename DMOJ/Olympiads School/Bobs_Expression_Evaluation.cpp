#include <bits/stdc++.h>

using namespace std;

int res;
string expr;

int oper(char op, int a, int b) {
    switch(op) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        case '%':
            res = a % b;
            break;
    }

    return res;
}

int pre(string expr) {
    stack<int> s;
    reverse(expr.begin(), expr.end());

    for (char i : expr) {
        if (i == ' ')
            continue;

        if (isdigit(i))
            s.push(i-'0');
        else {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(oper(i, a, b));
        }
    }

    return s.top();
}

int post(string expr) {
    stack<int> s;

    for (char i : expr) {
        if (i == ' ')
            continue;

        if (isdigit(i))
            s.push(i-'0');
        else {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(oper(i, b, a));
        }
    }

    return s.top();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 5; i++) {
        getline(cin, expr);

        if (isdigit(expr[0]))
            cout << post(expr) << '\n';
        else
            cout << pre(expr) << '\n';
    }
}
