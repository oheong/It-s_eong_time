#include <stdio.h>
int N, max, score;
int line_up[9], stat[50][9], ground[3];
void init() { for (int i = 0; i < 3; i++) ground[i] = 0; }
void start_game() {
	int startman = 0, hitter = 0;;
	for (int inning = 0; inning < N; inning++) {
		int out_count = 0;
		for (int i = startman;; i++) {
			if (out_count == 3) {
				startman = i;
				break;
			}
			hitter = stat[inning][line_up[i % 9] - 1];
			if (hitter == 0) out_count++;
			else if (hitter == 1) {
				if (ground[2] == 1) score++;
				ground[2] = ground[1];
				ground[1] = ground[0];
				ground[0] = 1;

			}
			else if (hitter == 2) {
				for (int n = 1; n < 3; n++) {
					if (ground[n] == 1) score++;
					ground[n] = 0;
				}
				ground[2] = ground[0];
				ground[1] = 1;
				ground[0] = 0;
			}
			else if (hitter == 3 || hitter == 4) {
				if (hitter == 4) score++;
				for (int n = 0; n < 3; n++) {
					if (ground[n] == 1) score++;
					ground[n] = 0;
				}
				if (hitter == 3) ground[2] = 1;
			}
		}
		init();
	}
	if (max < score)max = score;
}
void dfs(int d) {
	if (d == 9) {
		if (line_up[3] == 1) {
			score = 0;
			start_game();
		}
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (line_up[i] == 0) {
			line_up[i] = d + 1;
			dfs(d + 1);
			line_up[i] = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &stat[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", max);
	return 0;
}