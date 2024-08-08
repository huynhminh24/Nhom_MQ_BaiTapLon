#include <stdio.h>

int power(int m, int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return m * power(m, n - 1);
    }
}

int main() {
    int m, n;
    printf("Nhap so nguyen m: ");
    scanf_s("%d", &m);
    printf("Nhap so nguyen duong n: ");
    scanf_s("%d", &n);
    printf("%d mu %d = %d\n", m, n, power(m, n));
    return 0;
}