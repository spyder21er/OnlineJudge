#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    char c;
    string WERTYU (" VXSWDFGUHJKNBIO EARYCQZT ");

    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                printf("%c", (line[i] == '0') ? '9' : ((line[i] == '1') ? '`' : line[i] - 1));
            } else if (isalpha(line[i])) {
                printf("%c", WERTYU[line[i] - 'A']);
            } else {
                switch (line[i]) {
                    case '-':
                        printf("0");
                        break;
                    case '=':
                        printf("-");
                        break;
                    case '[':
                        printf("P");
                        break;
                    case ']':
                        printf("[");
                        break;
                    case 92: /* \ */
                        printf("]");
                        break;
                    case ';':
                        printf("L");
                        break;
                    case 39: /* ' */
                        printf(";");
                        break;
                    case ',':
                        printf("M");
                        break;
                    case '.':
                        printf(",");
                        break;
                    case '/':
                        printf(".");
                        break;

                    default:
                        printf("%c", line[i]);
                        break;
                }
            }
        }

        printf("\n");
    }
    return 0;
}