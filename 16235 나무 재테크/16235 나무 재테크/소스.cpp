#include <stdio.h>
#define SIZE 10
int tree[SIZE][SIZE][1000], A[SIZE][SIZE];//����, ���
int by[8] = { -1,-1,-1,0,0,1,1,1 }, bx[8] = { -1,0,1,-1,1,-1,0,1 };
int N, M, K, x, y, z, temp;
int count() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

		}
	}
}
void spring() {
	int nyom;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tree[i][j] != 0) {

			}
		}
	}
}
void summer() {

}
void fall() {

}
void winter() {

}
void solve() {
	while (K > 0) {
		spring();
		summer();
		fall();
		winter();
		K--;
	}
}
int main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = 5;//������ ù ����� ��� 5;
		}
	}
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp);//������� �޾ƿ�
			A[i][j] += temp;
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		tree[y - 1][x - 1][0] = z;
	}
	//��������� ���������� �ɾ�������.
	solve();
	return 0;
}