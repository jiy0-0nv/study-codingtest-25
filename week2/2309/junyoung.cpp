#include <iostream>
#include <algorithm>
using namespace std;

int dwf[9];
int sum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < 9; i++) {
        cin >> dwf[i];
        sum += dwf[i];
    }
    
    sort(dwf, dwf + 9);
    
    int d1, d2;
    bool found = false;
    
    if (!found) {
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 9; j++) {
                int total = sum - dwf[i] - dwf[j];
                if (total == 100) {
                    d1 = i;
                    d2 = j;
                    found = true;
                    break;
                }
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        if (i != d1 && i != d2) {
            cout << dwf[i] << "\n";
        }
    }
    
    return 0;
}
