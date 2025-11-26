#include <iostream>

using namespace std;

int N,M,K;
long long a,b,c;
long long org[1000002];
long long arr[1000002];


// https://yabmoons.tistory.com/438 
// Fenwick Tree
void update(int index, long long diff, int size){

    while( index <= size ){
        arr[index] += diff; // diff 를 업데이트해준다. 안 그러면 좀 오류남
        index += (index & -index);
    }
}

long long sum(int index){
    long long ans = 0;
    while ( index > 0 ){
        ans += arr[index];
        index -= (index & -index);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;

    arr[0] = 0;
    org[0]=0;
    for (int i = 1; i <= N; i++)
    {
        
        cin >> org[i];
        update(i , org[i], N);
    }

    for (size_t i = 0; i < M+K; i++)
    {
        cin >> a >> b >> c;
        if (a==1){
            long long diff = c - org[b];
            org[b] =c;
            update(b, diff, N);
        }
        else{
            cout << sum(c) - sum(b-1)<<"\n";
        }
    }
    
    



    return 0;
}