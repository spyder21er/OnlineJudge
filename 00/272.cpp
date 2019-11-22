#include <stdio.h>
using namespace std;

int main() {
	char c;
	bool open = 0;
	while(scanf("%c", &c) != EOF) {
		if(c == '"') {
			open = !open;
			if(open) {
				printf("``");
			} else
				printf("''");
		} else printf("%c", c);
	}
	return 0;
}