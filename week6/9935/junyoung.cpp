#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, bomb;
    cin >> s >> bomb;
    
    string stack;
    stack.reserve(s.size());
    const int m = bomb.size();
    
    for (char c : s) {
        stack.push_back(c);
        
        if (c == bomb.back() && (int)stack.size() >= m) {
            bool same = true;
            for (int i = 0; i < m; i++) {
                if (stack[stack.size() - m + i] != bomb[i]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                for (int i = 0; i < m; i++) stack.pop_back();
            }
        }
    }
    
    if (stack.empty()) cout << "FRULA\n";
    else cout << stack << "\n";
    
    return 0;
}
