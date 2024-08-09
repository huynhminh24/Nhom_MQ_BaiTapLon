#include <stdio.h>

typedef struct {
    int tu;   
    int mau;  
} PhanSo;

void nhapDanhSachPhanSo(PhanSo ps[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d (tu mau): ", i + 1);
        scanf("%d%d", &ps[i].tu, &ps[i].mau);
        while (ps[i].mau == 0) {
            printf("Mau so phai khac 0. Nhap lai phan so thu %d (tu mau): ", i + 1);
            scanf("%d%d", &ps[i].tu, &ps[i].mau);
        }
    }
}

void xuatDanhSachPhanSo(PhanSo ps[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", ps[i].tu, ps[i].mau);
    }
    printf("\n");
}

float giaTriThuc(PhanSo p) {
    return (float)p.tu / p.mau;
}

PhanSo timPhanSoLonNhat(PhanSo ps[], int n) {
    PhanSo max = ps[0];
    for (int i = 1; i < n; i++) {
        if (giaTriThuc(ps[i]) > giaTriThuc(max)) {
            max = ps[i];
        }
    }
    return max;
}

PhanSo timPhanSoNhoNhat(PhanSo ps[], int n) {
    PhanSo min = ps[0];
    for (int i = 1; i < n; i++) {
        if (giaTriThuc(ps[i]) < giaTriThuc(min)) {
            min = ps[i];
        }
    }
    return min;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

PhanSo toiGianPhanSo(PhanSo p) {
    int ucln = gcd(p.tu, p.mau);
    p.tu /= ucln;
    p.mau /= ucln;
    return p;
}

PhanSo tongPhanSo(PhanSo ps[], int n) {
    PhanSo tong = {0, 1};  
    for (int i = 0; i < n; i++) {
        tong.tu = tong.tu * ps[i].mau + ps[i].tu * tong.mau;
        tong.mau *= ps[i].mau;
        tong = toiGianPhanSo(tong);
    }
    return tong;
}

PhanSo tichPhanSo(PhanSo ps[], int n) {
    PhanSo tich = {1, 1}; 
    for (int i = 0; i < n; i++) {
        tich.tu *= ps[i].tu;
        tich.mau *= ps[i].mau;
        tich = toiGianPhanSo(tich);
    }
    return tich;
}

void xuatNghichDaoPhanSo(PhanSo ps[], int n) {
    for (int i = 0; i < n; i++) {
        if (ps[i].tu == 0) {
            printf("0 ");
        } else {
            printf("%d/%d ", ps[i].mau, ps[i].tu);
        }
    }
    printf("\n");
}

void interchangeSortPhanSoAsc(PhanSo ps[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTriThuc(ps[i]) > giaTriThuc(ps[j])) {
                PhanSo temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;
            }
        }
    }
}

void interchangeSortPhanSoDesc(PhanSo ps[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTriThuc(ps[i]) < giaTriThuc(ps[j])) {
                PhanSo temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;
            }
        }
    }
}

int main() {
    PhanSo ps[50];
    int n;

    printf("Nhap so luong phan so (n <= 50): ");
    scanf("%d", &n);

    nhapDanhSachPhanSo(ps, n);

    printf("Danh sach phan so: ");
    xuatDanhSachPhanSo(ps, n);

    PhanSo max = timPhanSoLonNhat(ps, n);
    PhanSo min = timPhanSoNhoNhat(ps, n);
    printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);
    printf("Phan so nho nhat: %d/%d\n", min.tu, min.mau);

    PhanSo tong = tongPhanSo(ps, n);
    PhanSo tich = tichPhanSo(ps, n);
    printf("Tong cac phan so: %d/%d\n", tong.tu, tong.mau);
    printf("Tich cac phan so: %d/%d\n", tich.tu, tich.mau);

    printf("Nghich dao cac phan so: ");
    xuatNghichDaoPhanSo(ps, n);

    interchangeSortPhanSoAsc(ps, n);
    printf("Mang phan so sap xep tang dan: ");
    xuatDanhSachPhanSo(ps, n);

    interchangeSortPhanSoDesc(ps, n);
    printf("Mang phan so sap xep giam dan: ");
    xuatDanhSachPhanSo(ps, n);

    return 0;
}

