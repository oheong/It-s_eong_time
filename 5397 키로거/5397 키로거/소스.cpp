#include <stdio.h>
int testcase, t = -1;
char password[1000000], stack[1000000], temp[1000000];
int pwdcount = 0, tempcount = 0;
void push(char c) { stack[++t] = c; }
void pop() { t--; }
char peek() { return stack[t]; }
int main() {
	freopen("Text.txt", "r", stdin);
	int i = 0;
	scanf("%d\n", &testcase);
	for (int test = 0; test < testcase; test++) {
		for (int k = 0;; k++) {
			scanf("%c", &password[k]);
			if (password[k] == '\n' || password[k] == '\0') {
				break;
			}
			pwdcount++;
		}

		for (pwdcount; pwdcount > 0; pwdcount--) {
			if (password[i] == '\n') {
				break;
			}
			if (password[i] == '<') {
				if (t == -1) {
					i++;
					continue;
				}
				else {
					temp[tempcount++] = peek();
					pop();
				}
			}
			else if (password[i] == '>') {
				if (tempcount == 0) {
					i++;
					continue;
				}
				else {
					i++;
					push(temp[--tempcount]);
					continue;
				}
			}
			else if (password[i] == '-') {
				if (t != -1)
					pop();
			}
			else {
				push(password[i]);
			}
			i++;
		}
		if (tempcount != 0) {
			for (int k = tempcount - 1; k >= 0; k--) {
				push(temp[k]);
			}
		}
		for (int k = 0; k <= t; k++) {
			printf("%c", stack[k]);
			stack[k] = '\0';
		}
		printf("\n");
		pwdcount = 0;
		tempcount = 0;
		i = 0;
		t = -1;
	}
	return 0;
}
