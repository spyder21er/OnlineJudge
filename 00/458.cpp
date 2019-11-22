#include <stdio.h>

int main() {
	char c;
	while(scanf("%c", &c) != EOF) {
		if(c != 10) printf("%c", c-7);
		else printf("%c", c);
	}
	return 0;
}