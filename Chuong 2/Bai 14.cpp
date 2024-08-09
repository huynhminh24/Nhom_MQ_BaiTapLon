#include <stdio.h>

#define MAX 100

void nhapMaTran(int a[MAX][MAX], int n);
void inMaTran(int a[MAX][MAX], int n);
int tongDuongCheoChinh(int a[MAX][MAX], int n);
int tongDuongCheoPhu(int a[MAX][MAX], int n);
int tongTrenDuongCheoChinh(int a[MAX][MAX], int n);
int tongTrenDuongCheoPhu(int a[MAX][MAX], int n);

int main() {
    int a[MAX][MAX];
    int n;
    int luaChon;

    printf("Nhap kich thuoc ma tran vuong n: ");
    scanf("%d", &n);

    nhapMaTran(a, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tinh tong cac phan tu nam tren duong cheo chinh\n");
        printf("2. Tinh tong cac phan tu nam tren duong cheo phu\n");
        printf("3. Tinh tong cac phan tu nam phia tren duong cheo chinh\n");
        printf("4. Tinh tong cac phan tu nam phia tren duong cheo phu\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang (0-4): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Tong cac phan tu nam tren duong cheo chinh: %d\n", tongDuongCheoChinh(a, n));
                break;
            case 2:
                printf("Tong cac phan tu nam tren duong cheo phu: %d\n", tongDuongCheoPhu(a, n));
                break;
            case 3:
                printf("Tong cac phan tu nam phia tren duong cheo chinh: %d\n", tongTrenDuongCheoChinh(a, n));
                break;
            case 4:
                printf("Tong cac phan tu nam phia tren duong cheo phu: %d\n", tongTrenDuongCheoPhu(a, n));
                break;
            case 0:
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

void nhapMaTran(int a[MAX][MAX], int n) {
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void inMaTran(int a[MAX][MAX], int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int tongDuongCheoChinh(int a[MAX][MAX], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][i];
    }
    return tong;
}

int tongDuongCheoPhu(int a[MAX][MAX], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][n - 1 - i];
    }
    return tong;
}

int tongTrenDuongCheoChinh(int a[MAX][MAX], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tong += a[i][j];
        }
    }
    return tong;
}

int tongTrenDuongCheoPhu(int a[MAX][MAX], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            tong += a[i][j];
        }
    }
    return tong;
}

