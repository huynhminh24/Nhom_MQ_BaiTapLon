#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void nhapMaTran(int a[MAX][MAX], int *n, int *m);
void inMaTran(int a[MAX][MAX], int n, int m);
void sapXepDongChanTangDongLeGiam(int a[MAX][MAX], int n, int m);
void sapXepCotChanTangCotLeGiam(int a[MAX][MAX], int n, int m);
void sapXepZicZac(int a[MAX][MAX], int n, int m, bool tangDan);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sapXepMang(int a[], int n, bool tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && a[i] > a[j]) || (!tangDan && a[i] < a[j])) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void sapXepDongChanTangDongLeGiam(int a[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        int temp[m];
        for (int j = 0; j < m; j++) {
            temp[j] = a[i][j];
        }
        sapXepMang(temp, m, i % 2 == 0);
        for (int j = 0; j < m; j++) {
            a[i][j] = temp[j];
        }
    }
}

void sapXepCotChanTangCotLeGiam(int a[MAX][MAX], int n, int m) {
    for (int j = 0; j < m; j++) {
        int temp[n];
        for (int i = 0; i < n; i++) {
            temp[i] = a[i][j];
        }
        sapXepMang(temp, n, j % 2 == 0);
        for (int i = 0; i < n; i++) {
            a[i][j] = temp[i];
        }
    }
}

void sapXepZicZac(int a[MAX][MAX], int n, int m, bool tangDan) {
    int temp[n * m];
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[index++] = a[i][j];
        }
    }

    sapXepMang(temp, n * m, tangDan);

    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // Dòng ch?n (0, 2, 4,...)
            for (int j = 0; j < m; j++) {
                a[i][j] = temp[index++];
            }
        } else { // Dòng l? (1, 3, 5,...)
            for (int j = m - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }
}

void nhapMaTran(int a[MAX][MAX], int *n, int *m) {
    printf("Nhap so hang va so cot (n m): ");
    scanf("%d %d", n, m);

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void inMaTran(int a[MAX][MAX], int n, int m) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX];
    int n, m;
    int luaChon;

    nhapMaTran(a, &n, &m);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Sap xep cac phan tu trong ma tran sao cho dong chan tang, dong le giam\n");
        printf("2. Sap xep cac phan tu trong ma tran sao cho cot chan tang, cot le giam\n");
        printf("3. Sap xep ma tran theo zic-zac tang dan\n");
        printf("4. Sap xep ma tran theo zic-zac giam dan\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang (0-4): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                sapXepDongChanTangDongLeGiam(a, n, m);
                inMaTran(a, n, m);
                break;
            case 2:
                sapXepCotChanTangCotLeGiam(a, n, m);
                inMaTran(a, n, m);
                break;
            case 3:
                sapXepZicZac(a, n, m, true); 
                inMaTran(a, n, m);
                break;
            case 4:
                sapXepZicZac(a, n, m, false); 
                inMaTran(a, n, m);
                break;
            case 0:
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

