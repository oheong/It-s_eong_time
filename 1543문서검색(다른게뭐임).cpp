#include <stdio.h>
char q[2510], cmp[55], c;
int f, r, len, ans;
void enQ(char c) {
	r++;
	q[r] = c;
}
void deQ() { f++; }
char peek() { return q[f + 1]; }
int empty() {
	if (f == r) return 1;
	else return 0;
}
int get_len() {
	int l = 0;
	while (1) {
		c = '\0';
		scanf("%c", &c);
		if (c == '\0') return l;
		cmp[l++] = c;
	}
}
int is_ok() {
	for (int i = 1; i < len; i++) {
		if (q[f + i] == cmp[i]) continue;
		else return 0;
	}
	return 1;
}
int main() {
	//freopen("Text.txt", "r", stdin);
	f = r = -1;
	while (1) {
		scanf("%c", &c);
		if (c != '\n')
			enQ(c);
		else break;
	}
	len = get_len();

	while (empty() == 0) {
		if (r - f < len)break;
		char tc = peek();
		deQ();
		if (tc == cmp[0]) { // 비교 시작
			if (is_ok() == 0) // 다름
				continue;
			for (int i = 1; i < len; i++) deQ();
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}