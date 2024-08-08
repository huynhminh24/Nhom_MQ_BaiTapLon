#include <stdio.h>

double capSoNhan(double a, double q, int n) {
    if (n == 1) {
        return a;
    }
    else {
        return q * capSoNhan(a, q, n - 1);
    }
}

int main() {
    double a, q;
    int n;
    printf("Nhap so hang dau tien (a): ");
    scanf_s("%lf", &a);
    printf("Nhap cong boi (q): ");
    scanf_s("%lf", &q);
    printf("Nhap so thu tu (n): ");
    scanf_s("%d", &n);
    printf("So thu %d cua cap so nhan la: %lf\n", n, capSoNhan(a, q, n));
    return 0;
}