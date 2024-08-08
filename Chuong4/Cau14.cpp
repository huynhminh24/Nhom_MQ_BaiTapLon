#include <stdio.h>

#define MAX_N 100

int An_cache[MAX_N] = { 0 };

int An(int n) {
    if (n == 1) {
        return 1;
    }
    if (n < 1) {
        return 0;
    }
    if (An_cache[n] != 0) {
        return An_cache[n];
    }
    if (n == 2) {
        An_cache[n] = 2;
    }
    else {
        An_cache[n] = n * (An(n - 1) + An(n - 2));
    }
    return An_cache[n];
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (n < 1 || n >= MAX_N) {
        printf("Nhap n trong khoang tu 1 den %d.\n", MAX_N - 1);
        return 1;
    }

    printf("A_%d = %d\n", n, An(n));
    return 0;
}
