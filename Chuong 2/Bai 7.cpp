#include <stdio.h>
#include <conio.h>
#include <string.h>

struct PhanSo {
    int tu;  
    int mau; 
};

void nhapPhanSo(struct PhanSo *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

void xuatPhanSo(struct PhanSo ps) {
    printf("%d/%d", ps.tu, ps.mau);
}

int kiemTraMauKhac0(struct PhanSo ps) {
    return ps.mau != 0;
}

int timUCLN(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

void toiGianPhanSo(struct PhanSo *ps) {
    int ucln = timUCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
}

struct PhanSo tinhTong(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

struct PhanSo tinhHieu(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

struct PhanSo tinhTich(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.tu;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

struct PhanSo tinhThuong(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau;
    ketQua.mau = ps1.mau * ps2.tu;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

int main() {
    struct PhanSo ps1, ps2, ketQua;

    printf("Nhap phan so thu nhat:\n");
    nhapPhanSo(&ps1);
    printf("Nhap phan so thu hai:\n");
    nhapPhanSo(&ps2);

    printf("Phan so thu nhat: ");
    xuatPhanSo(ps1);
    printf("\n");

    printf("Phan so thu hai: ");
    xuatPhanSo(ps2);
    printf("\n");

    ketQua = tinhTong(ps1, ps2);
    printf("Tong hai phan so: ");
    xuatPhanSo(ketQua);
    printf("\n");

    ketQua = tinhHieu(ps1, ps2);
    printf("Hieu hai phan so: ");
    xuatPhanSo(ketQua);
    printf("\n");

    ketQua = tinhTich(ps1, ps2);
    printf("Tich hai phan so: ");
    xuatPhanSo(ketQua);
    printf("\n");

    ketQua = tinhThuong(ps1, ps2);
    printf("Thuong hai phan so: ");
    xuatPhanSo(ketQua);
    printf("\n");

    return 0;
}
