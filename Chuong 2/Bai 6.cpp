#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool tatCaLaSoNguyenTo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (!laSoNguyenTo(a[i])) {
            return false;
        }
    }
    return true;
}

bool laDoiXung(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) {
            return false;
        }
    }
    return true;
}

bool laTangDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool laGiamDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool laKhongThayDoi(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int a[n];
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (tatCaLaSoNguyenTo(a, n)) {
        printf("Mang chua toan bo so nguyen to.\n");
    } else {
        printf("Mang khong chua toan bo so nguyen to.\n");
    }

    if (laDoiXung(a, n)) {
        printf("Mang doi xung.\n");
    } else {
        printf("Mang khong doi xung.\n");
    }

    if (laTangDan(a, n)) {
        printf("Mang tang dan.\n");
    } else if (laGiamDan(a, n)) {
        printf("Mang giam dan.\n");
    } else if (laKhongThayDoi(a, n)) {
        printf("Mang khong thay doi.\n");
    } else {
        printf("Mang khong tang khong giam.\n");
    }

    return 0;
}

