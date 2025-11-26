#include <iostream>
#include <vector>

using namespace std;

int tree[200001]; // n, m <= 100,000
int position[100001]; // 각 영화(1~n)가 현재 배열의 몇 번째 인덱스에 있는지
int n, m;
int size_limit; // 전체 배열 크기 (n + m)

// 펜윅 트리 Update: i번째에 diff를 더함
void update(int i, int diff) {
    while (i <= size_limit) {
        tree[i] += diff;
        i += (i & -i);
    }
}

// 펜윅 트리 Sum: 1부터 i까지의 합
int sum(int i) {
    int result = 0;
    while (i > 0) {
        result += tree[i];
        i -= (i & -i);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        size_limit = n + m;

        for (int i = 0; i <= size_limit; i++) tree[i] = 0;

        // 초기 DVD 배치
        for (int i = 1; i <= n; i++) {
            position[i] = m + i; // i번 영화는 (m+i) 인덱스에 있dma
            update(position[i], 1); // 그 자리에 DVD가 있다(1)고 표시
        }

        // 맨 위로 올릴 다음 위치 초기화
        int next_top = m;

        for (int i = 0; i < m; i++) {
            int movie_num;
            cin >> movie_num;

            int current_idx = position[movie_num];

            // 내 위에 몇 개 있는지 계산
            // 내 현재 위치보다 앞에 있는 1의 개수를 셈
            cout << sum(current_idx - 1) << " ";

            // 영화 위치 이동 (빼서 맨 위로)
            update(current_idx, -1); // 원래 자리에서 제거 (0으로 만듬)
            
            position[movie_num] = next_top;
            update(next_top, 1);     // 새 자리에 추가 (1로 만듬)
            
            next_top--; // 다음 빈칸
        }
        cout << '\n';
    }
    return 0;
}
