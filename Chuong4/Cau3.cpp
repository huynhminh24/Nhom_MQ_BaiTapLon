#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    int a, b;
    printf("Nhap so nguyen duong a: ");
    scanf_s("%d", &a);
    printf("Nhap so nguyen duong b: ");
    scanf_s("%d", &b);
    printf("UCLN cua %d va %d la: %d\n", a, b, gcd(a, b));
    return 0;
}