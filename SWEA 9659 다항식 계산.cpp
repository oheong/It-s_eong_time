#include <stdio.h>
#define SIZE 60
#define mod 998244353
int T, N, M;
int is[SIZE][3], x[SIZE];
long long f[SIZE];
void init() {
	for (int i = 0; i <= N; i++) f[i] = 0;
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 2; i <= N; i++) {
			scanf("%d %d %d", &is[i][0], &is[i][1], &is[i][2]);
		}
		scanf("%d", &M);
		for (int i = 1; i <= M; i++) {
			scanf("%d", &x[i]);
		}
		printf("#%d ", test + 1);
		for (int m = 1; m <= M; m++) { // m번 시행해라. 왜? x가 m개니까
			f[0] = 1;
			f[1] = x[m];
			for (int n = 2; n <= N; n++) { // fn을 구하기 위한 여정
				if (is[n][0] == 1) {
					f[n] = f[is[n][1]] % mod + f[is[n][2]] % mod;
				}
				else if (is[n][0] == 2) {
					f[n] = is[n][1] * f[is[n][2]] % mod;
				}
				else if (is[n][0] == 3) {
					f[n] = f[is[n][1]] * f[is[n][2]] % mod;
				}
			}
			printf("%lld ", f[N] % mod);
			init();
		}
		printf("\n");
	}
	return 0;
}

//3/14 ㅡㅡ