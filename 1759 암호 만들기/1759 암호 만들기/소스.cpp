#include <stdio.h>
int L, C;
int list[15], visited[15];
char c[15];
int check() {
	int mo = 0, ja = 0;
	for (int i = 0; i < L; i++) {
		if (c[list[i]] == 'a' || c[list[i]] == 'e' || c[list[i]] == 'i' || c[list[i]] == 'o' || c[list[i]] == 'u')
			mo++;
		else ja++;

	}
	if (mo >= 1 && ja >= 2)
		return 1;
	else return 0;
}
void sort() {
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C - i - 1; j++) {
			if (c[j] > c[j + 1]) {
				char t = c[j];
				c[j] = c[j + 1];
				c[j + 1] = t;
			}
		}
	}
}
void dfs(int d, int n) {
	if (d == L) {
		if (check() == 1) {
			for (int i = 0; i < L; i++) {
				printf("%c", c[list[i]]);
			}
			printf("\n");
		}
		return;
	}
	for (int i = n; i < C; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			list[d] = i;
			dfs(d + 1, i);
			visited[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d\n", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf("%c ", &c[i]);
	}
	sort();
	dfs(0, 0);
	return 0;
}