#include <stdio.h>
char q[2510], cmp[55], c;
int num,len, ans;
int get_len(char temp_c[]) {
	int l = 0;
	while (1) {
		c = '\0';
		scanf("%c", &c);
		if (c == '\0'|| c == '\n') return l;
		temp_c[l++] = c;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	num = get_len(q);
	len = get_len(cmp);
	if(num<len) printf("%d\n", 0);
	else {
		for (int i = 0; i < num - len + 1; i++) {
			bool flag = false;
			for (int j = 0; j < len; j++) {
				if (q[i + j] != cmp[j]) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				ans++;
				i += len - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}