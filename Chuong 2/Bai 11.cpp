#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void nhapMaTran(int a[][100], int m, int n);
void xuatMaTran(int a[][100], int m, int n);
int tinhTongChuSoDauLe(int a[][100], int m, int n);
void lietKeSoHoanThien(int a[][100], int m, int n);
int tinhTongLonHonTriTuyetDoiPhanTuSau(int a[][100], int m, int n);
int tinhTongDongK(int a[][100], int m, int n, int k);
int tinhTongGiaTriTrenBien(int a[][100], int m, int n);
int demTanSuatX(int a[][100], int m, int n, int x);
bool laSoNguyenTo(int n);
void demSoLuongPhanTu(int a[][100], int m, int n, int *chan, int *le, int *am, int *duong, int *nguyenTo);

int main() {
    int a[100][100];
    int m, n;
    int option;

    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &m);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &n);

    nhapMaTran(a, m, n);
	xuatMaTran(a, m, n);
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Tinh tong cac phan tu co chu so dau la chu so le\n");
        printf("2. Liet ke cac so hoan thien trong ma tran\n");
        printf("3. Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no\n");
        printf("4. Tinh tong gia tri tren dong k cua ma tran\n");
        printf("5. Tinh tong cac gia tri nam tren bien cua ma tran\n");
        printf("6. Dem tan suat xuat hien cua 1 gia tri x trong ma tran\n");
        printf("7. Dem so luong cac phan tu la so chan, so le, so am, so duong, so nguyen to\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang (1-8): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tinhTongChuSoDauLe(a, m, n));
                break;
            case 2:
                printf("Cac so hoan thien trong ma tran: ");
                lietKeSoHoanThien(a, m, n);
                break;
            case 3:
                printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d\n", tinhTongLonHonTriTuyetDoiPhanTuSau(a, m, n));
                break;
            case 4: {
                int k;
                printf("Nhap dong k: ");
                scanf("%d", &k);
                printf("Tong gia tri tren dong %d: %d\n", k, tinhTongDongK(a, m, n, k));
                break;
            }
            case 5:
                printf("Tong cac gia tri nam tren bien cua ma tran: %d\n", tinhTongGiaTriTrenBien(a, m, n));
                break;
            case 6: {
                int x;
                printf("Nhap gia tri x: ");
                scanf("%d", &x);
                printf("Tan suat xuat hien cua gia tri %d trong ma tran: %d\n", x, demTanSuatX(a, m, n, x));
                break;
            }
            case 7: {
                int chan, le, am, duong, nguyenTo;
                demSoLuongPhanTu(a, m, n, &chan, &le, &am, &duong, &nguyenTo);
                printf("So luong phan tu chan: %d\n", chan);
                printf("So luong phan tu le: %d\n", le);
                printf("So luong phan tu am: %d\n", am);
                printf("So luong phan tu duong: %d\n", duong);
                printf("So luong phan tu nguyen to: %d\n", nguyenTo);
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon tu 1 den 8.\n");
                break;
        }
    }
}

void nhapMaTran(int a[][100], int m, int n) {
    printf("Nhap gia tri cho ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuatMaTran(int a[][100], int m, int n) {
    printf("Gia tri cua ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int chuSoDauTien(int n) {
    n = abs(n);
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

bool laSoHoanThien(int n) {
    if (n <= 0) return false;
    int tong = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }
    return tong == n;
}

int tinhTongChuSoDauLe(int a[][100], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (chuSoDauTien(a[i][j]) % 2 != 0) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

void lietKeSoHoanThien(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(a[i][j])) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

int tinhTongLonHonTriTuyetDoiPhanTuSau(int a[][100], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] > abs(a[i][j + 1])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int tinhTongDongK(int a[][100], int m, int n, int k) {
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += a[k][j];
    }
    return tong;
}

int tinhTongGiaTriTrenBien(int a[][100], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int demTanSuatX(int a[][100], int m, int n, int x) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                dem++;
            }
        }
    }
    return dem;
}

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void demSoLuongPhanTu(int a[][100], int m, int n, int *chan, int *le, int *am, int *duong, int *nguyenTo) {
    *chan = *le = *am = *duong = *nguyenTo = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) (*chan)++;
            else (*le)++;
            if (a[i][j] < 0) (*am)++;
            else if (a[i][j] > 0) (*duong)++;
            if (laSoNguyenTo(a[i][j])) (*nguyenTo)++;
        }
    }
}

