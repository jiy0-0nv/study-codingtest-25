#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        stack<char> st;
        bool valid = true;

        for (char ch : s) {
            if (ch == '(') {
                st.push('(');
            } else {
                if (st.empty()) {
                    valid = false;
                    break;
                }
                st.pop();
            }
        }

        if (!st.empty()) valid = false;

        cout << (valid ? "YES\n" : "NO\n");
    }
    return 0;
}
