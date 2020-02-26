#include <stdio.h>
int T, N;
int map[5100];
int partition(int left, int right) {
	int pivot = map[left];
	int r = right, l = left;
	while (l < r) {//zz 이 부분 left<right 하면 무한반복임;;
		while (pivot < map[r]) r--;
		while (l < r&&map[l] <= pivot)
			l++;//l < r&& 이거는 l에 와야함
		int temp = map[l];
		map[l] = map[r];
		map[r] = temp;
	}
	map[left] = map[l];
	map[l] = pivot;
	return l;
}//이욜,,, 쪼금만 더 해서 완전히 외우자
void Qsort(int left, int right) {
	if (left >= right)return;
	int pivot = partition(left, right);
	Qsort(left, pivot - 1);
	Qsort(pivot + 1, right);
}
void sort() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (map[j] > map[j + 1]) {
				int temp = map[j];
				map[j] = map[j + 1];
				map[j + 1] = temp;
			}
		}
	}
}
void resort() {
	int flag = 0;
	for (int i = 0; i < N - 1; i++) {
		if (map[i] + 1 == map[i + 1]) {
			for (int j = i; j < N; j++) {
				if (map[i] + 1 < map[j]) {
					flag = 1;
					int temp = map[j];
					map[j] = map[i + 1];
					map[i + 1] = temp;
					break;
				}
			}
			if (flag == 0) {
				int t = map[i];
				for (int j = i; 0 <= j; j--) {
					if (map[j - 1] != t) {
						int tt = map[j];
						map[j] = map[i + 1];
						map[i + 1] = tt;
						break;
					}
				}
			}
			flag = 0;
		}
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &map[i]);
		//Qsort(0, N - 1);
		sort();
		resort();
		printf("#%d ", test + 1);
		for (int i = 0; i < N; i++) printf("%d ", map[i]);
		printf("\n");
	}
	return 0;
}

//ㅋㅋㅋ 시발