#include <stdio.h>

int Un(int n) {
    if (n < 6) {
        return n;
    }
    else {
        return Un(n - 5) + Un(n - 4) + Un(n - 3) + Un(n - 2) + Un(n - 1);
    }
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);
    printf("U(%d) = %d\n", n, Un(n));
    return 0;
}