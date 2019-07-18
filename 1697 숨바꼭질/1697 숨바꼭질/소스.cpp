#include <stdio.h>
int N, K;//수빈, 동생
int min = 2123456789;
//void dfs(int d, int subin, int sis) {
//	if (d > 10)
//		return;
//	if (subin == sis) {
//		if (d < min) {
//			min = d;
//		}
//		return;
//	}
//	dfs(d + 1, subin * 2, sis);
//	dfs(d + 1, subin - 1, sis);
//	dfs(d + 1, subin + 1, sis);
//}
//int main() {
//	freopen("Text.txt", "r", stdin);
//	scanf("%d %d", &N, &K);
//	dfs(0, N, K);
//	printf("%d\n", min);
//	return 0;
//}
//이게 문제가 깊이가 커지면 커질수록 실행시간이 개노답이됨 ㅅㅂㅠㅠ

int f = -1, r = -1;
typedef struct { int sb; int d; }Queue;
Queue q[100001];
int visited[100001];
void enQ(int d, int subin) {
	r++;
	q[r].sb = subin;
	q[r].d = d;
}
void deQ() { f++; }
int empty() {
	if (f == r) return 1;
	else return 0;
}
Queue peek() { return q[f + 1]; }
void bfs(int subin) {
	visited[subin] = 1;
	enQ(0, subin);
	while (empty() == 0) {
		int td = peek().d;
		int tsubin = peek().sb;
		deQ();
		if (tsubin == K) min = td;
		for (int i = 0; i < 3; i++) {
			int nsubin;
			if (i == 0) nsubin = tsubin * 2;
			else if (i == 1) nsubin = tsubin + 1;
			else nsubin = tsubin - 1;

			if (0 <= nsubin && nsubin <= 100000 && visited[nsubin] == 0) {
				//0과 100000은 유효한 좌표임. 총 배열크기를 100001로 잡아줘야함ㅠㅠ
				visited[nsubin] = 1;
				enQ(td + 1, nsubin);
			}
		}
	}
}
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	bfs(N);
	printf("%d\n", min);
	return 0;
}
//이 씨발 뭐가틀렸냐