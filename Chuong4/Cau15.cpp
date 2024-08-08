#include <stdio.h>

#define MAX_N 100

int Yn_cache[MAX_N] = { 0 };

int YnRecursive(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 3;
    }
    if (Yn_cache[n] != 0) {
        return Yn_cache[n];
    }
    Yn_cache[n] = YnRecursive(n - 1) + 2 * YnRecursive(n - 2) + 3 * YnRecursive(n - 3);
    return Yn_cache[n];
}

int YnIterative(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;

    int Y[MAX_N] = { 0 };
    Y[1] = 1;
    Y[2] = 2;
    Y[3] = 3;

    for (int i = 4; i <= n; i++) {
        Y[i] = Y[i - 1] + 2 * Y[i - 2] + 3 * Y[i - 3];
    }

    return Y[n];
}

int main() {
    int n, choice;

    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (n < 1 || n >= MAX_N) {
        printf("Nhap n trong khoang tu 1 den %d.\n", MAX_N - 1);
        return 1;
    }

    printf("Chon cach tinh (1: De quy, 2: Khu de quy): ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        for (int i = 0; i < MAX_N; i++) {
            Yn_cache[i] = 0;
        }
        printf("Y_%d (De quy) = %d\n", n, YnRecursive(n));
    }
    else if (choice == 2) {
        printf("Y_%d (Khu de quy) = %d\n", n, YnIterative(n));
    }
    else {
        printf("Lua chon khong hop le!\n");
        return 1;
    }

    return 0;
}
