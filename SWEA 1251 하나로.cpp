#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
#define SIZE 1000
int T, N;
long double E;
int visited[SIZE];
typedef struct { int y; int x; }MAP; MAP map[SIZE];
struct Edge { int v1; long long wieght; };
struct Comp {
	bool operator()(struct Edge E1, struct Edge E2) {
		return E1.wieght > E2.wieght;
	}
};
long long graph[SIZE][SIZE]; // ���鰣�� �Ÿ� �׷���
long long prim(int start) { // long long
	long long distance = 0;
	priority_queue<struct Edge, vector<struct Edge>, Comp> pq;
	struct Edge S;
	S.v1 = start; S.wieght = 0;
	pq.push(S);

	while (!pq.empty()) {
		// �켱����ť���� �ּҰŸ��� ������ ����
		int now = pq.top().v1; // ���� ��� ��ȣ
		long long weight = pq.top().wieght; // ����� ���� ����� �Ÿ�
		pq.pop();

		if (visited[now] == 1) continue; // �̹� �湮�� ����� ��ŵ

		// ó�� �κ�
		visited[now] = 1;
		distance += weight;

		for (int to = 0; to < N; to++) {
			if (to == now) continue;
			if (visited[to] == 0) {
				//���� �湮���� ��常 ����
				struct Edge E;
				E.v1 = to; E.wieght = graph[now][to];
				pq.push(E);
			}
		}
	}
	return distance;
}
void init() {
	for (int i = 0; i < N; i++) visited[i] = 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	cin >> T;
	for (int test = 0; test < T; test++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> map[i].x;
		for (int i = 0; i < N; i++) cin >> map[i].y;
		cin >> E;

		// �Էµ� �ڷḦ ������� �� ���� ����ġ �׷��� ����� (���鰣�� �Ÿ�)
		long long from_y, from_x, to_x, to_y;
		for (int i = 0; i < N; i++) {
			from_y = map[i].y;
			from_x = map[i].x;
			for (int j = i + 1; j < N; j++) {
				to_y = map[j].y;
				to_x = map[j].x;
				graph[j][i] = graph[i][j] =
					(from_y - to_y)*(from_y - to_y) + (from_x - to_x)*(from_x - to_x);
			}
		}
		long long cost = floor(prim(0)*E + 0.5);
		cout << "#" << test + 1 << " " << cost << "\n";
		init();
	}
	return 0;
}