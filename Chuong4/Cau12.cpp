#include <stdio.h>

int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n) {
    int a = 0, b = 1, c;
    if (n <= 1) return n;
    for (int i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int findLargestFibonacciLessThan(int n, int useRecursive) {
    int fib = 0;
    int i = 0;

    if (useRecursive) {
        while (fibonacciRecursive(i) < n) {
            fib = fibonacciRecursive(i);
            i++;
        }
    }
    else {
        while (fibonacciIterative(i + 1) < n) {
            fib = fibonacciIterative(i);
            i++;
        }
    }

    return fib;
}

int main() {
    int n, choice;

    printf("Nhap so nguyen n: ");
    scanf_s("%d", &n);
    printf("Chon cach tinh Fibonacci (1: De quy, 2: Khu de quy): ");
    scanf_s("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Lua chon khong hop le!\n");
        return 1;
    }

    int result = findLargestFibonacciLessThan(n, choice == 1);
    printf("So Fibonacci lon nhat nho hon %d la: %d\n", n, result);

    return 0;
}
