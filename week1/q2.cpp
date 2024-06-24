#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    int n = s.length();
    stack<char> one;
    for (auto c : s) {
        if (c == '{' || c == '(' || c == '[') {
            one.push(c);
        } else {
            if (one.empty() || 
                (c == '}' && one.top() != '{') || 
                (c == ']' && one.top() != '[') || 
                (c == ')' && one.top() != '(')) {
                return false;
            }
            one.pop();
        }
    }
    if(one.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (isValid(s)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}
