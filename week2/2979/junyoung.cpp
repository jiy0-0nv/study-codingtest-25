
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int price[4];
    for (int i = 1; i <= 3; i++) {
        cin >> price[i];
    }
    
    int time[101] = {0};
    for (int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        for (int j = start; j < end; j++) {
            time[j]++;
        }
    }
    
    int fee = 0;
    for (int n : time) {
        fee += price[n] * n;
    }
    
    cout << fee;
    
    return 0;    
}
