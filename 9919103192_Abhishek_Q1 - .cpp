#include <bits/stdc++.h>

using namespace std;

int evaluate(char x) {
    if (x == '^')
        return 3;
    if (x == '/' || x == '*')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return -1;
}

void convert(const string &str) {
    int size = str.size();
    stack<char> q;

    for (int i = 0; i < size; ++i) {
        char worda = str[i];

        if (isalnum(worda)) {
            cout << worda;
        } else if (worda == '(')
            q.push(worda);
        else if (worda == ')') {
            while (!q.empty() and q.top() != '(') {
                cout << q.top();
                q.pop();
            }
            q.pop();
        } else {
            while (!q.empty() and evaluate(q.top()) >= evaluate(worda)) {
                cout << q.top();
                q.pop();
            }
            q.push(worda);
        }
    }

    while (!q.empty()) {
        cout << q.top();
        q.pop();
    }
}

int main() {
    string s = "w1*f1*1/2+w2*f2*1/2+w3*f3";
    convert(s);
}
