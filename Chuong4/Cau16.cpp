#include <stdio.h>

#define MAX_N 100

int Xn_cache[MAX_N] = { 0 };

int XnRecursive(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 1;
    }
    if (Xn_cache[n] != 0) {
        return Xn_cache[n];
    }
    Xn_cache[n] = XnRecursive(n - 1) + (n - 1) * XnRecursive(n - 2);
    return Xn_cache[n];
}

int XnIterative(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;

    int X[MAX_N] = { 0 };
    X[1] = 1;
    X[2] = 1;

    for (int i = 3; i <= n; i++) {
        X[i] = X[i - 1] + (i - 1) * X[i - 2];
    }

    return X[n];
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
            Xn_cache[i] = 0;
        }
        printf("X_%d (De quy) = %d\n", n, XnRecursive(n));
    }
    else if (choice == 2) {
        printf("X_%d (Khu de quy) = %d\n", n, XnIterative(n));
    }
    else {
        printf("Lua chon khong hop le!\n");
        return 1;
    }

    return 0;
}
