#include <stdio.h>

int xn(int n);
int yn(int n);

int xn(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return xn(n - 1) + yn(n - 1);
    }
}

int yn(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return 3 * xn(n - 1) + 2 * yn(n - 1);
    }
}

int main() {
    int n;

    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (n < 0) {
        printf("Nhap n phai lon hon hoac bang 0.\n");
        return 1;
    }

    printf("X_%d = %d\n", n, xn(n));
    printf("Y_%d = %d\n", n, yn(n));

    return 0;
}
