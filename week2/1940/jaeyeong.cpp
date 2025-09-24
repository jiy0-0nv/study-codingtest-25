#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;   
    cin >> m;   
    
    vector<int> arr(n);   
    for (int i = 0; i < n; i++) {
        cin >> arr[i];    
    }
    sort(arr.begin(), arr.end());

    int left = 0;          
    int right = n - 1;     
    int count = 0;         

    while (left < right) {
        int total = arr[left] + arr[right];  

        

        if (total == m) {     
            count++;
            left++;           
            right--;
        }
        else if (total < m) { 
            left++;
        }
        else {               
            right--;
        }
    }

    cout << count << endl;

    return 0;
}
