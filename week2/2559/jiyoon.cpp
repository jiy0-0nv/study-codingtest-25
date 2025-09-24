#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    /* 누적합
    int prefix[100001] = {0,};
    int ans = -10000001;

    for (int i=1; i<=N; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];

        if (i<K) continue;
        int partial = prefix[i]-prefix[i-K];
        if (ans < partial) ans = partial;
    }
    */

    /* 슬라이딩 윈도우 */
    int tem[100001];
    int partial = 0;
    int ans = -10000001;

    for (int i=0; i<N; i++){
        cin >> tem[i];
        partial += tem[i];

        if (i>=K) partial -= tem[i-K];
        if (i>=K-1 && partial>ans) ans = partial;
    }

    cout << ans;

    return 0;
}