#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool tatCaChuSoLaSoLe(int n) {
    while (n > 0) {
        int chuSo = n % 10;
        if (chuSo % 2 == 0) return false;
        n /= 10;
    }
    return true;
}

int demSoNguyenTo(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) dem++;
    }
    return dem;
}

void inTatCaChuSoLe(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (tatCaChuSoLaSoLe(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

int timViTriMaxCuoiCung(int a[], int n) {
    int max = a[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] >= max) {
            max = a[i];
            index = i;
        }
    }
    return index;
}

bool tatCaLaSoChan(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) return false;
    }
    return true;
}

bool laDaySoChanLeXenKe(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || 
            (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int soNguyenTo = demSoNguyenTo(a, n);
    printf("So phan tu la so nguyen to: %d\n", soNguyenTo);

    printf("Cac phan tu co tat ca cac chu so la so le: ");
    inTatCaChuSoLe(a, n);

    int viTriMaxCuoiCung = timViTriMaxCuoiCung(a, n);
    printf("Vi tri cua phan tu lon nhat cuoi cung: %d\n", viTriMaxCuoiCung);

    if (tatCaLaSoChan(a, n)) {
        printf("Mang co toan bo la so chan.\n");
    } else {
        printf("Mang khong toan bo la so chan.\n");
    }

    if (laDaySoChanLeXenKe(a, n)) {
        printf("Mang la day so chan le xen ke.\n");
    } else {
        printf("Mang khong phai la day so chan le xen ke.\n");
    }

    free(a);
    return 0;
}

