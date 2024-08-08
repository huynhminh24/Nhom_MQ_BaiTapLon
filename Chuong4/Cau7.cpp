#include <stdio.h>

int An1(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        return -1;
    }
    else {
        return 2 * An1(n - 1) - 3 * An1(n - 2) - An1(n - 3);
    }
}

int An2(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 3;
    }
    else {
        return 2 * An2(n - 1) + An2(n - 2) - 3 * An2(n - 3);
    }
}

int main() {
    int n, choice;
    printf("Nhap n: ");
    scanf_s("%d", &n);
    printf("Chon cau (1 hoac 2): ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        printf("A_%d = %d\n", n, An1(n));
        break;
    case 2:
        printf("A_%d = %d\n", n, An2(n));
        break;
    default:
        printf("Lua chon khong hop le!\n");
        break;
    }

    return 0;
}