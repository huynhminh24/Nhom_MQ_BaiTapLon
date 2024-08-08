#include <stdio.h>

int f(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n % 2 == 0) {
        return 2 * f(n / 2);
    }
    else {
        return 2 * f(n / 2) + 3 * f(n / 2 + 1);
    }
}

int main() {
    int n, choice;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    printf("Chon cau (1 - Tinh f(5), 2 - Viet chuong trinh tinh f(n)): ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        printf("f(5) = %d\n", f(5));
        break;
    case 2:
        printf("f(%d) = %d\n", n, f(n));
        break;
    default:
        printf("Lua chon khong hop le!\n");
        break;
    }

    return 0;
}