#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;
    int counts[26] = {0};
    
    for (char c : S) {
        counts[c - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        cout << counts[i] << " ";
    }
    
    return 0;
}
