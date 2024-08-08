#include <stdio.h>
#include <math.h>

// Hàm tính giai thừa
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

// Hàm tính tổng từ 1 đến n
int sum(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n + sum(n - 1);
    }
}

// Các hàm tính S(n) theo đệ quy
double S1_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n + S1_recursive(n - 1);
    }
}

double S2_recursive(int n) {
    if (n == 1) {
        return sqrt(2);
    }
    else {
        return sqrt(2 + S2_recursive(n - 1));
    }
}

double S3_recursive(int n) {
    if (n == 1) {
        return 1.0 / 2.0;
    }
    else {
        return (double)n / (n + 1) + S3_recursive(n - 1);
    }
}

double S4_recursive(int n) {
    if (n == 1) {
        return 1.0;
    }
    else {
        return 1.0 / (2 * n + 1) + S4_recursive(n - 1);
    }
}

int S5_recursive(int n) {
    if (n == 1) {
        return 2;
    }
    else {
        return n * (n + 1) + S5_recursive(n - 1);
    }
}

double S6_recursive(int n) {
    if (n == 1) {
        return 1.0 / 6.0;
    }
    else {
        return 1.0 / (n * (n + 1) * (n + 2)) + S6_recursive(n - 1);
    }
}

int S7_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * n + S7_recursive(n - 1);
    }
}

int S8_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return sum(n) + S8_recursive(n - 1);
    }
}

double S9_recursive(int n) {
    if (n == 1) {
        return -1.0 / 2.0;
    }
    else {
        return pow(-1, n) * (2 * n - 1) * (2 * n) / (double)factorial(2 * n) + S9_recursive(n - 1);
    }
}

double S10_recursive(int n) {
    if (n == 1) {
        return (1.0 * 2.0) / (2.0 + sqrt(3.0));
    }
    else {
        return (n * (n + 1) * 1.0 * factorial(n)) / (n + 1 + sqrt(n + 2)) + S10_recursive(n - 1);
    }
}

double S11_recursive(int n) {
    if (n == 1) {
        return (1 + sqrt(1 + 2)) / (2 + sqrt(3));
    }
    else {
        return (n + sqrt(n + 1) + n + 1) / (n + 1 + sqrt(n + 2)) + S11_recursive(n - 1);
    }
}

// Các hàm tính S(n) theo khử đệ quy
double S1_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

double S2_iterative(int n) {
    double result = sqrt(2);
    for (int i = 2; i <= n; i++) {
        result = sqrt(2 + result);
    }
    return result;
}

double S3_iterative(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (double)i / (i + 1);
    }
    return sum;
}

double S4_iterative(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (2 * i + 1);
    }
    return sum;
}

int S5_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (i + 1);
    }
    return sum;
}

double S6_iterative(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}

int S7_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int S8_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum += j;
        }
    }
    return sum;
}

double S9_iterative(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i) * (2 * i - 1) * (2 * i) / (double)factorial(2 * i);
    }
    return sum;
}

double S10_iterative(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (i * (i + 1) * 1.0 * factorial(i)) / (i + 1 + sqrt(i + 2));
    }
    return sum;
}

double S11_iterative(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (i + sqrt(i + 1) + i + 1) / (i + 1 + sqrt(i + 2));
    }
    return sum;
}

int main() {
    int n, choice, func_choice;
    double result;
    printf("Nhap n: ");
    scanf_s("%d", &n);
    printf("Chon cach tinh (1 - De quy, 2 - Khu de quy): ");
    scanf_s("%d", &choice);
    printf("Chon cau (1 - 11): ");
    scanf_s("%d", &func_choice);

    switch (func_choice) {
    case 1:
        if (choice == 1) {
            result = S1_recursive(n);
        }
        else {
            result = S1_iterative(n);
        }
        printf("S(n) = %lf\n", result);
        break;
    case 2:
        if (choice == 1) {
            result = S2_recursive(n);
        }
        else {
            result = S2_iterative(n);
        }
        printf("S(n) = %lf\n", result);
        break;
    case 3:
        if (choice == 1) {
            result = S3_recursive(n);
        }
        else {
            result = S3_iterative(n);
        }
        printf("S(n) = %lf\n", result);
        break;
    case 4:
        if (choice == 1) {
            result = S4_recursive(n);
        }
        else {
            result = S4_iterative(n);
        }
        printf("S(n) = %lf\n", result);
        break;
    case 5:
        if (choice == 1) {
            result = S5_recursive(n);
        }
        else {
            result = S5_iterative(n);
        }
        printf("S(n) = %d\n", (int)result);
        break;
    case 6:
        if (choice == 1) {
            result = S6_recursive(n);
        }
        else {
            result = S6_iterative(n);
        }
        printf("S(n) = %lf\n", result);
        break;
    case 7:
        if (choice == 1) {
            result = S7_recursive(n);
        }
        else {
            result = S7_iterative(n);
        }
        printf("S(n) = %d\n", (int)result);
        break;
    case 8:
        if (choice == 1) {
            result = S8_recursive(n);
        }
        else {
            result = S8_iterative(n);
        }
        printf("S(n) = %d\n", (int)result);
        break;
    case 9:
        if (choice == 1) {
            result = S9_recursive(n);
        }
        else {
            result = S9_iterative(n);
        }
        printf("S(n) = %lf\n", result);
        break;
    case 10:
        if (choice == 1) {
            result = S10_recursive(n);
        }
        else {
            result = S10_iterative(n);
        }
        printf("S(n) = %lf\n", result);
        break;
    case 11:
        if (choice == 1) {
            result = S11_recursive(n);
        }
        else {
            result = S11_iterative(n);
        }
        printf("S(n) = %lf\n", result);
        break;
    default:
        printf("Chon cau khong hop le!\n");
        break;
    }

    return 0;
}