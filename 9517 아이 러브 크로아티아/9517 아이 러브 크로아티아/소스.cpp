#include <stdio.h>
int time, remain = 210, starter, Qnum;
char ans;
typedef struct { int time; char ans; }GAME;
GAME g[101];
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d\n%d", &starter, &Qnum);
	for (int i = 0; i < Qnum; i++) {
		scanf("%d %c\n", &time, &ans);
		g[i].time = time;
		g[i].ans = ans;
	}
	int i = 0;//¹®Á¦ °¹¼ö
	while (1) {
		remain -= g[i % Qnum].time;
		if (remain <= 0) break;
		if (g[i % Qnum].ans == 'T') {
			starter++;
		}
		i++;
	}
	int ans = starter % 8;
	if (ans == 0)ans = 8;// ½Ã¹ß ÀÌ»õ³¢,,,,,,,,,,,,,,,,,,,,,
	printf("%d\n", ans);
	return 0;
}