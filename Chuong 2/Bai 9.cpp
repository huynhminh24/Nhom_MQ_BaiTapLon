#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int stt;
    char mssv[11];
    char hoTen[50];
    float diemTieuLuan;
    float diemThiKetThuc;
    float diemTongKet;
} SinhVien;

void nhapSinhVien(SinhVien *sv);
void xuatSinhVien(const SinhVien *sv);
void nhapDanhSachSinhVien(SinhVien sv[], int n);
void xuatDanhSachSinhVien(const SinhVien sv[], int n);
void tinhDiemTongKet(SinhVien *sv);
void tinhDiemTongKetDanhSach(SinhVien sv[], int n);
void timSinhVienDiemCaoNhatThapNhat(const SinhVien sv[], int n, SinhVien *svCaoNhat, SinhVien *svThapNhat);
void demSinhVienDatKhongDat(const SinhVien sv[], int n, int *soSinhVienDat, int *soSinhVienKhongDat);
float quyDoiDiemHe4(float diem10);
void sapXepTangDan(SinhVien sv[], int n);
void sapXepGiamDan(SinhVien sv[], int n);
float tinhDiemTrungBinh(const SinhVien sv[], int n);
void ghiFile(const char *filename, const SinhVien sv[], int n);
void docFile(const char *filename, SinhVien sv[], int *n);

void nhapSinhVien(SinhVien *sv) {
    printf("Nhap so thu tu: ");
    scanf("%d", &sv->stt);
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->mssv);
    printf("Nhap ho ten sinh vien: ");
    getchar(); 
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0; 
    printf("Nhap diem tieu luan: ");
    scanf("%f", &sv->diemTieuLuan);
    printf("Nhap diem thi ket thuc mon: ");
    scanf("%f", &sv->diemThiKetThuc);
}

void xuatSinhVien(const SinhVien *sv) {
    printf("%-8d%-12s%-20s%-10.2f%-10.2f%-15.2f\n", sv->stt, sv->mssv, sv->hoTen, sv->diemTieuLuan, sv->diemThiKetThuc, sv->diemTongKet);
}

void nhapDanhSachSinhVien(SinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&sv[i]);
    }
}

void xuatDanhSachSinhVien(const SinhVien sv[], int n) {
    printf("Danh sach sinh vien doc tu file:\n");
    printf("STT     MSSV           Ho Ten                     Diem TL   Diem Thi  Diem Tong Ket\n");
    for (int i = 0; i < n; i++) {
        printf("%-8d%-15s%-25s%-10.1f%-10.1f%-10.1f\n", 
               sv[i].stt, sv[i].mssv, sv[i].hoTen, 
               sv[i].diemTieuLuan, sv[i].diemThiKetThuc, 
               sv[i].diemTongKet);
    }
}

void tinhDiemTongKet(SinhVien *sv) {
    sv->diemTongKet = 0.3 * sv->diemTieuLuan + 0.7 * sv->diemThiKetThuc;
}

void tinhDiemTongKetDanhSach(SinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        tinhDiemTongKet(&sv[i]);
    }
}

void timSinhVienDiemCaoNhatThapNhat(const SinhVien sv[], int n, SinhVien *svCaoNhat, SinhVien *svThapNhat) {
    *svCaoNhat = sv[0];
    *svThapNhat = sv[0];
    for (int i = 1; i < n; i++) {
        if (sv[i].diemTongKet > svCaoNhat->diemTongKet) {
            *svCaoNhat = sv[i];
        }
        if (sv[i].diemTongKet < svThapNhat->diemTongKet) {
            *svThapNhat = sv[i];
        }
    }
}

void demSinhVienDatKhongDat(const SinhVien sv[], int n, int *soSinhVienDat, int *soSinhVienKhongDat) {
    *soSinhVienDat = 0;
    *soSinhVienKhongDat = 0;
    for (int i = 0; i < n; i++) {
        if (sv[i].diemTongKet >= 5.0) {
            (*soSinhVienDat)++;
        } else {
            (*soSinhVienKhongDat)++;
        }
    }
}

float quyDoiDiemHe4(float diem10) {
    if (diem10 >= 8.5) return 4.0;
    if (diem10 >= 7.0) return 3.0;
    if (diem10 >= 5.5) return 2.0;
    if (diem10 >= 4.0) return 1.0;
    return 0.0;
}

void sapXepTangDan(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diemTongKet > sv[j].diemTongKet) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

void sapXepGiamDan(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diemTongKet < sv[j].diemTongKet) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

float tinhDiemTrungBinh(const SinhVien sv[], int n) {
    float tongDiem = 0;
    for (int i = 0; i < n; i++) {
        tongDiem += sv[i].diemTongKet;
    }
    return tongDiem / n;
}

void ghiFile(const char *filename, const SinhVien sv[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %s %.2f %.2f %.2f\n", sv[i].stt, sv[i].mssv, sv[i].hoTen, sv[i].diemTieuLuan, sv[i].diemThiKetThuc, sv[i].diemTongKet);
    }
    fclose(file);
}

void docFile(const char *filename, SinhVien sv[], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file de doc. Duong dan: %s\n", filename);
        return;
    }

    *n = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (sscanf(buffer, "%d %10s %49[^0-9] %f %f %f", 
                   &sv[*n].stt, sv[*n].mssv, sv[*n].hoTen, 
                   &sv[*n].diemTieuLuan, &sv[*n].diemThiKetThuc, 
                   &sv[*n].diemTongKet) == 6) {
            (*n)++;
        } else {
            printf("Khong the doc dong: %s\n", buffer);
        }
    }
    fclose(file);

    printf("Da doc %d sinh vien tu file.\n", *n);
}

int main() {
    SinhVien sv[50];
    int n = 0;
    int option;
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tinh diem tong ket cho danh sach sinh vien\n");
        printf("4. Tim sinh vien diem cao nhat va diem thap nhat\n");
        printf("5. Dem so sinh vien dat va khong dat\n");
        printf("6. Xem danh sach sinh vien va diem he 4\n");
        printf("7. Sap xep danh sach sinh vien tang dan theo diem tong ket\n");
        printf("8. Sap xep danh sach sinh vien giam dan theo diem tong ket\n");
        printf("9. Tinh diem trung binh cua tat ca sinh vien\n");
        printf("10. Ghi danh sach sinh vien vao file\n");
        printf("11. Doc danh sach sinh vien tu file\n");
        printf("12. Thoat\n");
        printf("Chon chuc nang (1-12): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Nhap so luong sinh vien (n <= 50): ");
                scanf("%d", &n);
                nhapDanhSachSinhVien(sv, n);
                for (int i = 0; i < n; i++) {
                    tinhDiemTongKet(&sv[i]);
                }
                break;
            case 2:
                xuatDanhSachSinhVien(sv, n);
                break;
            case 3:
                for (int i = 0; i < n; i++) {
                    tinhDiemTongKet(&sv[i]);
                }
                printf("Tinh diem tong ket cho danh sach sinh vien xong.\n");
                break;
            case 4:
                {
                    SinhVien svCaoNhat, svThapNhat;
                    timSinhVienDiemCaoNhatThapNhat(sv, n, &svCaoNhat, &svThapNhat);
                    printf("Sinh vien co diem tong ket cao nhat: %s - %.2f\n", svCaoNhat.hoTen, svCaoNhat.diemTongKet);
                    printf("Sinh vien co diem tong ket thap nhat: %s - %.2f\n", svThapNhat.hoTen, svThapNhat.diemTongKet);
                }
                break;
            case 5:
                {
                    int soSinhVienDat, soSinhVienKhongDat;
                    demSinhVienDatKhongDat(sv, n, &soSinhVienDat, &soSinhVienKhongDat);
                    printf("So sinh vien dat: %d\n", soSinhVienDat);
                    printf("So sinh vien khong dat: %d\n", soSinhVienKhongDat);
                }
                break;
            case 6:
                printf("Danh sach sinh vien va diem he 4:\n");
                for (int i = 0; i < n; i++) {
                    float diemHe4 = quyDoiDiemHe4(sv[i].diemTongKet);
                    printf("%-8d%-12s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", sv[i].stt, sv[i].mssv, sv[i].hoTen, sv[i].diemTieuLuan, sv[i].diemThiKetThuc, sv[i].diemTongKet, diemHe4);
                }
                break;
            case 7:
                sapXepTangDan(sv, n);
                printf("Danh sach sinh vien sap xep tang dan theo diem tong ket:\n");
                xuatDanhSachSinhVien(sv, n);
                break;
            case 8:
                sapXepGiamDan(sv, n);
                printf("Danh sach sinh vien sap xep giam dan theo diem tong ket:\n");
                xuatDanhSachSinhVien(sv, n);
                break;
            case 9:
                {
                    float diemTrungBinh = tinhDiemTrungBinh(sv, n);
                    printf("Diem trung binh cua tat ca sinh vien: %.2f\n", diemTrungBinh);
                }
                break;
            case 10:
                ghiFile("danh_sach_sinh_vien.txt", sv, n);
                printf("Danh sach sinh vien da duoc ghi vao file.\n");
                break;
            case 11:
                {
                    docFile("danh_sach_sinh_vien.txt", sv, &n);
                    printf("Danh sach sinh vien doc tu file:\n");
                    xuatDanhSachSinhVien(sv, n);
                }
                break;
            case 12:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon tu 1 den 12.\n");
                break;
        }
    }
}
