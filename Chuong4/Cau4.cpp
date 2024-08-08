#include <stdio.h>

int capSoCong(int a, int r, int n) {
    if (n == 1) {
        return a;
    }
    else {
        return capSoCong(a, r, n - 1) + r;
    }
}

int main() {
    int a, r, n;
    printf("Nhap so hang dau tien (a): ");
    scanf_s("%d", &a);
    printf("Nhap cong sai (r): ");
    scanf_s("%d", &r);
    printf("Nhap so thu tu (n): ");
    scanf_s("%d", &n);
    printf("So thu %d cua cap so cong la: %d\n", n, capSoCong(a, r, n));
    return 0;
}