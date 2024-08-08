#include <stdio.h>

int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    printf("Day Fibonacci co %d so la: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}