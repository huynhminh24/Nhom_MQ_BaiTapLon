#include <stdio.h>
#include <string.h>

#define MAX_MON 5
#define MAX_SV 100

typedef struct {
    char maMon[10];
    char tenMon[50];
    int soTinChi;
    float diem;
} MonHoc;

typedef struct {
    char mssv[15];
    char hoTen[50];
    MonHoc monHoc[MAX_MON];
    float diemTrungBinh;
} SinhVien;

void nhapSinhVien(SinhVien *sv, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho sinh vien thu %d:\n", i + 1);
        printf("Ma so sinh vien: ");
        scanf("%s", sv[i].mssv);
        printf("Ho ten sinh vien: ");
        getchar(); // Ð?c ký t? '\n' th?a
        fgets(sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
        sv[i].hoTen[strlen(sv[i].hoTen) - 1] = '\0'; // Xóa ký t? '\n' cu?i chu?i
        
        sv[i].diemTrungBinh = 0;
        int tongTinChi = 0;

        for (int j = 0; j < MAX_MON; j++) {
            printf("Nhap thong tin cho mon hoc thu %d:\n", j + 1);
            printf("Ma mon: ");
            scanf("%s", sv[i].monHoc[j].maMon);
            printf("Ten mon: ");
            getchar(); 
            fgets(sv[i].monHoc[j].tenMon, sizeof(sv[i].monHoc[j].tenMon), stdin);
            sv[i].monHoc[j].tenMon[strlen(sv[i].monHoc[j].tenMon) - 1] = '\0';
            
            printf("So tin chi: ");
            scanf("%d", &sv[i].monHoc[j].soTinChi);
            printf("Diem: ");
            scanf("%f", &sv[i].monHoc[j].diem);

            sv[i].diemTrungBinh += sv[i].monHoc[j].diem * sv[i].monHoc[j].soTinChi;
            tongTinChi += sv[i].monHoc[j].soTinChi;
        }

        sv[i].diemTrungBinh /= tongTinChi;
    }
}

void xuatSinhVien(SinhVien *sv, int n) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("MSSV: %s, Ho ten: %s, Diem trung binh: %.2f\n", sv[i].mssv, sv[i].hoTen, sv[i].diemTrungBinh);
        for (int j = 0; j < MAX_MON; j++) {
            printf("   Ma mon: %s, Ten mon: %s, So tin chi: %d, Diem: %.2f\n",
                   sv[i].monHoc[j].maMon, sv[i].monHoc[j].tenMon, sv[i].monHoc[j].soTinChi, sv[i].monHoc[j].diem);
        }
    }
}

void timSinhVienTheoMSSV(SinhVien *sv, int n, const char *mssv) {
    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].mssv, mssv) == 0) {
            printf("Tim thay sinh vien:\n");
            xuatSinhVien(&sv[i], 1);
            return;
        }
    }
    printf("Khong tim thay sinh vien co MSSV: %s\n", mssv);
}

void timSinhVienDiemCaoNhat(SinhVien *sv, int n) {
    float maxDiem = sv[0].diemTrungBinh;
    int viTri = 0;

    for (int i = 1; i < n; i++) {
        if (sv[i].diemTrungBinh > maxDiem) {
            maxDiem = sv[i].diemTrungBinh;
            viTri = i;
        }
    }

    printf("Sinh vien co diem trung binh cao nhat:\n");
    xuatSinhVien(&sv[viTri], 1);
}

void themSinhVien(SinhVien *sv, int *n, SinhVien svMoi) {
    sv[*n] = svMoi;
    (*n)++;
}

void xoaSinhVienTheoMSSV(SinhVien *sv, int *n, const char *mssv) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(sv[i].mssv, mssv) == 0) {
            for (int j = i; j < *n - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*n)--;
            printf("Da xoa sinh vien co MSSV: %s\n", mssv);
            return;
        }
    }
    printf("Khong tim thay sinh vien co MSSV: %s\n", mssv);
}

void sapXepSinhVienTheoDiem(SinhVien *sv, int n, int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && sv[i].diemTrungBinh > sv[j].diemTrungBinh) ||
                (!tangDan && sv[i].diemTrungBinh < sv[j].diemTrungBinh)) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

void xepLoaiHocTap(SinhVien *sv, int n) {
    for (int i = 0; i < n; i++) {
        if (sv[i].diemTrungBinh >= 8.5) {
            printf("Sinh vien %s xep loai Xuat Sac\n", sv[i].hoTen);
        } else if (sv[i].diemTrungBinh >= 7.0) {
            printf("Sinh vien %s xep loai Gioi\n", sv[i].hoTen);
        } else if (sv[i].diemTrungBinh >= 5.5) {
            printf("Sinh vien %s xep loai Kha\n", sv[i].hoTen);
        } else if (sv[i].diemTrungBinh >= 4.0) {
            printf("Sinh vien %s xep loai Trung Binh\n", sv[i].hoTen);
        } else {
            printf("Sinh vien %s xep loai Yeu\n", sv[i].hoTen);
        }
    }
}

void thongKeMonDauRot(SinhVien *sv, int n) {
    for (int i = 0; i < n; i++) {
        int soMonDau = 0, soMonRot = 0;
        for (int j = 0; j < MAX_MON; j++) {
            if (sv[i].monHoc[j].diem >= 5.0) {
                soMonDau++;
            } else {
                soMonRot++;
            }
        }
        printf("Sinh vien %s: %d mon dau, %d mon rot\n", sv[i].hoTen, soMonDau, soMonRot);
    }
}

int main() {
    SinhVien danhSach[MAX_SV];
    int soLuongSV = 0;
    int luaChon;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien theo MSSV\n");
        printf("4. Tim sinh vien co diem trung binh cao nhat\n");
        printf("5. Them sinh vien\n");
        printf("6. Xoa sinh vien theo MSSV\n");
        printf("7. Sap xep sinh vien theo diem trung binh\n");
        printf("8. Xep loai hoc tap sinh vien\n");
        printf("9. Thong ke so mon dau rot cua sinh vien\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &soLuongSV);
                nhapSinhVien(danhSach, soLuongSV);
                break;
            case 2:
                xuatSinhVien(danhSach, soLuongSV);
                break;
            case 3: {
                char mssv[15];
                printf("Nhap ma so sinh vien can tim: ");
                scanf("%s", mssv);
                timSinhVienTheoMSSV(danhSach, soLuongSV, mssv);
                break;
            }
            case 4:
                timSinhVienDiemCaoNhat(danhSach, soLuongSV);
                break;
            case 5: {
                SinhVien svMoi;
                printf("Nhap thong tin sinh vien moi:\n");
                nhapSinhVien(&svMoi, 1);
                themSinhVien(danhSach, &soLuongSV, svMoi);
                break;
            }
            case 6: {
                char mssv[15];
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%s", mssv);
                xoaSinhVienTheoMSSV(danhSach, &soLuongSV, mssv);
                break;
            }
            case 7: {
                int tangDan;
                printf("Sap xep tang dan (1) hay giam dan (0): ");
                scanf("%d", &tangDan);
                sapXepSinhVienTheoDiem(danhSach, soLuongSV, tangDan);
                break;
            }
            case 8:
                xepLoaiHocTap(danhSach, soLuongSV);
                break;
            case 9:
                thongKeMonDauRot(danhSach, soLuongSV);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}

