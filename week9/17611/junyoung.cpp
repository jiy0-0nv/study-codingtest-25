#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    // 마지막 점과 처음 점도 이어지는 다각형이므로
    auto getNext = [&](int i) { return (i == n - 1 ? 0 : i + 1); };

    vector<pair<long long, int>> verticalEvents;   // (y, +1/-1)
    vector<pair<long long, int>> horizontalEvents; // (x, +1/-1)

    for (int i = 0; i < n; i++) {
        int j = getNext(i);

        long long x1 = p[i].first, y1 = p[i].second;
        long long x2 = p[j].first, y2 = p[j].second;

        if (x1 == x2) { 
            // vertical segment
            long long lo = min(y1, y2);
            long long hi = max(y1, y2);
            verticalEvents.push_back({lo, +1});  // 시작 lo
            verticalEvents.push_back({hi, -1});  // 끝 hi
        } else {
            // horizontal segment
            long long lo = min(x1, x2);
            long long hi = max(x1, x2);
            horizontalEvents.push_back({lo, +1});
            horizontalEvents.push_back({hi, -1});
        }
    }

    auto sweep = [&](vector<pair<long long,int>>& events) {
        sort(events.begin(), events.end());
        long long active = 0, maxActive = 0;

        for (auto &e : events) {
            active += e.second;
            maxActive = max(maxActive, active);
        }
        return maxActive;
    };

    long long h = sweep(verticalEvents);
    long long v = sweep(horizontalEvents);

    cout << max(h, v) << "\n";
    return 0;
}
