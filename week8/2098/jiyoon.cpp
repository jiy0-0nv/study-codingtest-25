#if 01
#include <iostream>
#include <algorithm>
#include <cstring> // memset
#define INF 987654321

using namespace std;

int N; // 정점 번호
int W[16][16]; // 인접 행렬
int  D[16][1 << 16]; // D[i][j] - i번 정점에 위치, 방문 히스토리가 j일 때 최소비용
int fullvst;

int tsp(int cur, int visited) {
	// cur: 현재 머물러 있는 도시의 번호
	// visited: 지금까지 방문한 도시들의 집합을 비트마스크로 표현한 정수
	
	// 모든 도시를 방문한 경우
	// -> cur에서 출발점(0번)으로 돌아가는 간선 비용 W[cur][0] 반환
	//    만약 출발점으로 돌아가는 간선이 없다면 INF를 반환 (유효하지 않은 경로)
	if (visited == fullvst) {
		return W[cur][0] ? W[cur][0] : INF;
	}

	// Memoization 활용
	int &t = D[cur][visited];
	if (t != -1) return t; // 이미 코스트를 구한 경우 바로 반환
	else t = INF;		   // 처음 접근하면 t를 INF로 초기화 (이후 최소값 비교를 위해)

	// 재귀 탐색
	for (int i = 0; i < N; i++) {
		// [skip 조건]
		// visited & (1 << i) : 방문한 도시
		// D[cur][i] == 0 : cur에서 i로 가는 길이 없음
		if ((visited & (1 << i)) || (W[cur][i] == 0)) continue;
		// 비트마스크를 갱신하여 tsp 호출 -> 반환값에 간선 비용 더하기
		t = min(t, tsp(i, visited | (1 << i)) + W[cur][i]);
		// 모든 i에 대하여 반복하며 t에 최소 비용을 업데이트
	}

	// t: 현재 상태에서 최적으로 남은 도시들을 모두 방문한 뒤 출발점으로 돌아가는 최소 비용
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	// init
	fullvst = (1 << N) - 1;   // 방문 상태의 완전 집합
	memset(D, -1, sizeof(D)); // -1로 초기화 (아직 계산되지 않은 상태)

	cout << tsp(0, 1);

	return 0;
}
#endif