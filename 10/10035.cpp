#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, digit_a, digit_b, carries, sum, has_previous_carry;

    while (scanf("%d %d", &a, &b), a + b) {
        carries = 0;
        has_previous_carry = 0;
        while ((a > 0 && b > 0) || has_previous_carry) {
            digit_a = a % 10;
            digit_b = b % 10;
            a /= 10;
            b /= 10;
            sum = digit_a + digit_b + has_previous_carry;
            if (sum >= 10) {
                carries++;
                has_previous_carry = 1;
            } else {
                has_previous_carry = 0;
            }
        }

        if (carries) {
            printf("%d ", carries);
        } else {
            printf("No ");
        }

        printf("carry operation");
        
        if (carries < 2) {
            printf(".\n");
        } else {
            printf("s.\n");
        }
    }
    return 0;
}