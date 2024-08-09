#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

void nhapMaTran(int a[MAX][MAX], int *m, int *n);
void inMaTran(int a[MAX][MAX], int m, int n);
void lietKeCotCoTongNhoNhat(int a[MAX][MAX], int m, int n);
void lietKeDongCoNhieuSoHoanThienNhat(int a[MAX][MAX], int m, int n);
void lietKeDongChuaToanGiaTriChan(int a[MAX][MAX], int m, int n);
void timGiaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n);
void timSoNguyenToNhoNhat(int a[MAX][MAX], int m, int n);
void timMinMaxTrongDong(int a[MAX][MAX], int m, int n, int k);
void timMinMaxTrongCot(int a[MAX][MAX], int m, int n, int k);
bool laSoHoanThien(int num);
bool laSoNguyenTo(int num);

int main() {
    int a[MAX][MAX];
    int m, n;
    int luaChon, k;

    nhapMaTran(a, &m, &n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Liet ke cac cot co tong nho nhat\n");
        printf("2. Liet ke cac dong co nhieu so hoan thien nhat\n");
        printf("3. Liet ke chi so cac dong chua toan gia tri chan\n");
        printf("4. Tim gia tri xuat hien nhieu nhat\n");
        printf("5. Tim so nguyen to nho nhat\n");
        printf("6. Tim phan tu lon (nho) nhat trong dong thu k\n");
        printf("7. Tim phan tu lon (nho) nhat trong cot thu k\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang (0-7): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                lietKeCotCoTongNhoNhat(a, m, n);
                break;
            case 2:
                lietKeDongCoNhieuSoHoanThienNhat(a, m, n);
                break;
            case 3:
                lietKeDongChuaToanGiaTriChan(a, m, n);
                break;
            case 4:
                timGiaTriXuatHienNhieuNhat(a, m, n);
                break;
            case 5:
                timSoNguyenToNhoNhat(a, m, n);
                break;
            case 6:
                printf("Nhap chi so dong k: ");
                scanf("%d", &k);
                timMinMaxTrongDong(a, m, n, k);
                break;
            case 7:
                printf("Nhap chi so cot k: ");
                scanf("%d", &k);
                timMinMaxTrongCot(a, m, n, k);
                break;
            case 0:
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

void nhapMaTran(int a[MAX][MAX], int *m, int *n) {
    printf("Nhap so hang va so cot (m n): ");
    scanf("%d %d", m, n);

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void inMaTran(int a[MAX][MAX], int m, int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void lietKeCotCoTongNhoNhat(int a[MAX][MAX], int m, int n) {
    int minTong = INF;
    int tongCot[MAX] = {0};

    for (int j = 0; j < n; j++) {
        tongCot[j] = 0;
        for (int i = 0; i < m; i++) {
            tongCot[j] += a[i][j];
        }
        if (tongCot[j] < minTong) {
            minTong = tongCot[j];
        }
    }

    printf("Cac cot co tong nho nhat (%d) la:\n", minTong);
    for (int j = 0; j < n; j++) {
        if (tongCot[j] == minTong) {
            printf("%d ", j);
        }
    }
    printf("\n");
}

void lietKeDongCoNhieuSoHoanThienNhat(int a[MAX][MAX], int m, int n) {
    int maxSoHoanThien = 0;
    int soHoanThien[MAX] = {0};

    for (int i = 0; i < m; i++) {
        soHoanThien[i] = 0;
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(a[i][j])) {
                soHoanThien[i]++;
            }
        }
        if (soHoanThien[i] > maxSoHoanThien) {
            maxSoHoanThien = soHoanThien[i];
        }
    }

    printf("Cac dong co nhieu so hoan thien nhat (%d) la:\n", maxSoHoanThien);
    for (int i = 0; i < m; i++) {
        if (soHoanThien[i] == maxSoHoanThien) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void lietKeDongChuaToanGiaTriChan(int a[MAX][MAX], int m, int n) {
    printf("Cac dong chua toan gia tri chan la:\n");
    for (int i = 0; i < m; i++) {
        bool toanChan = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                toanChan = false;
                break;
            }
        }
        if (toanChan) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void timGiaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int freq[MAX * MAX] = {0}; 
    int giaTriXuatHienNhieuNhat = a[0][0];
    int maxSoLanXuatHien = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            freq[a[i][j]]++;
            if (freq[a[i][j]] > maxSoLanXuatHien) {
                maxSoLanXuatHien = freq[a[i][j]];
                giaTriXuatHienNhieuNhat = a[i][j];
            }
        }
    }

    printf("Gia tri xuat hien nhieu nhat la: %d\n", giaTriXuatHienNhieuNhat);
}

void timSoNguyenToNhoNhat(int a[MAX][MAX], int m, int n) {
    int soNguyenToNhoNhat = INF;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > 1 && laSoNguyenTo(a[i][j]) && a[i][j] < soNguyenToNhoNhat) {
                soNguyenToNhoNhat = a[i][j];
            }
        }
    }

    if (soNguyenToNhoNhat == INF) {
        printf("Khong co so nguyen to trong ma tran.\n");
    } else {
        printf("So nguyen to nho nhat la: %d\n", soNguyenToNhoNhat);
    }
}

void timMinMaxTrongDong(int a[MAX][MAX], int m, int n, int k) {
    if (k < 0 || k >= m) {
        printf("Chi so dong khong hop le.\n");
        return;
    }

    int min = a[k][0], max = a[k][0];
    for (int j = 1; j < n; j++) {
        if (a[k][j] < min) min = a[k][j];
        if (a[k][j] > max) max = a[k][j];
    }

    printf("Dong %d: Min = %d, Max = %d\n", k, min, max);
}

void timMinMaxTrongCot(int a[MAX][MAX], int m, int n, int k) {
    if (k < 0 || k >= n) {
        printf("Chi so cot khong hop le.\n");
        return;
    }

    int min = a[0][k], max = a[0][k];
    for (int i = 1; i < m; i++) {
        if (a[i][k] < min) min = a[i][k];
        if (a[i][k] > max) max = a[i][k];
    }

    printf("Cot %d: Min = %d, Max = %d\n", k, min, max);
}

bool laSoHoanThien(int num) {
    if (num <= 1) return false;
    int tong = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i == num) {
                tong += i;
            } else {
                tong += i + num / i;
            }
        }
    }
    return tong == num;
}

bool laSoNguyenTo(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

