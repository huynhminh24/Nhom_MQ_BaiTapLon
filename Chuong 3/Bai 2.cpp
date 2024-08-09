#include <stdio.h>
#include <string.h>
#include <ctype.h>

int demKhoangTrang(const char *chuoi) {
    int dem = 0;
    while (*chuoi) {
        if (isspace(*chuoi)) dem++;
        chuoi++;
    }
    return dem;
}

void xoaKhoangTrangThua(char *chuoi) {
    char *src = chuoi, *dst = chuoi;
    
    while (*src == ' ') src++;
    
    while (*src) {
        *dst++ = *src++;
        if (*(dst - 1) == ' ' && *src == ' ') {
            dst--;
        }
    }
    
    if (*(dst - 1) == ' ') dst--;
    
    *dst = '\0';
}

void vietHoaTu(char *chuoi) {
    int vietHoa = 1;  
    
    while (*chuoi) {
        if (isspace(*chuoi)) {
            vietHoa = 1;  
        } else {
            if (vietHoa && islower(*chuoi)) {
                *chuoi = toupper(*chuoi);
            } else if (!vietHoa && isupper(*chuoi)) {
                *chuoi = tolower(*chuoi);
            }
            vietHoa = 0; 
        }
        chuoi++;
    }
}

int timKiemTen(const char *hoTen, const char *ten) {
    return strstr(hoTen, ten) ? 1 : 0;
}

void catTen(const char *hoTen, char *hoLot, char *ten) {
    char *space = strrchr(hoTen, ' ');
    
    if (space) {
        strncpy(hoLot, hoTen, space - hoTen);
        hoLot[space - hoTen] = '\0';
        strcpy(ten, space + 1);
    } else {
        strcpy(hoLot, "");
        strcpy(ten, hoTen);
    }
}

void chenTu(char *chuoi, const char *tu, int viTri) {
    int lenChuoi = strlen(chuoi);
    int lenTu = strlen(tu);
    
    memmove(chuoi + viTri + lenTu, chuoi + viTri, lenChuoi - viTri + 1);
    memcpy(chuoi + viTri, tu, lenTu);
}

void xoaTu(char *chuoi, const char *tu) {
    char *viTri;
    int lenTu = strlen(tu);
    int lenChuoi = strlen(chuoi);
    
    while ((viTri = strstr(chuoi, tu)) != NULL) {
        memmove(viTri, viTri + lenTu, lenChuoi - (viTri - chuoi) - lenTu + 1);
        lenChuoi -= lenTu;
    }
}

void demTanSuatKyTu(const char *chuoi) {
    int tanSuat[256] = {0};  
    
    while (*chuoi) {
        tanSuat[(unsigned char)*chuoi++]++;
    }
    
    for (int i = 0; i < 256; i++) {
        if (tanSuat[i] > 0) {
            printf("%c xuat hien %d lan\n", i, tanSuat[i]);
        }
    }
}

char timKyTuXuatHienNhieuNhat(const char *chuoi) {
    int tanSuat[256] = {0};
    int maxTanSuat = 0;
    char kyTuXuatHienNhieuNhat = '\0';
    
    while (*chuoi) {
        tanSuat[(unsigned char)*chuoi++]++;
    }
    
    for (int i = 0; i < 256; i++) {
        if (tanSuat[i] > maxTanSuat) {
            maxTanSuat = tanSuat[i];
            kyTuXuatHienNhieuNhat = i;
        }
    }
    
    return kyTuXuatHienNhieuNhat;
}

void menu() {
    char chuoi[100];
    char ten[100];
    char hoLot[100], tenRi[100];
    int luaChon;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. Dem so khoang trang trong chuoi\n");
        printf("2. Xoa khoang trang thua trong chuoi\n");
        printf("3. Doi chu dau tien cua moi tu thanh chu in hoa\n");
        printf("4. Tim kiem ten trong chuoi ho ten\n");
        printf("5. Cat chuoi ho lot va chuoi ten\n");
        printf("6. Chen mot tu vao vi tri cu the\n");
        printf("7. Xoa mot tu khoi chuoi\n");
        printf("8. Dem so lan xuat hien cua tung ky tu\n");
        printf("9. Tim ky tu xuat hien nhieu nhat trong chuoi\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &luaChon);
        getchar();  
        
        switch (luaChon) {
            case 1:
                printf("Nhap chuoi: ");
                fgets(chuoi, sizeof(chuoi), stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0';  
                printf("So khoang trang: %d\n", demKhoangTrang(chuoi));
                break;
            
            case 2:
                printf("Nhap chuoi: ");
                fgets(chuoi, sizeof(chuoi), stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0';  
                xoaKhoangTrangThua(chuoi);
                printf("Chuoi sau khi xoa khoang trang: '%s'\n", chuoi);
                break;
            
            case 3:
                printf("Nhap chuoi: ");
                fgets(chuoi, sizeof(chuoi), stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0';  
                vietHoaTu(chuoi);
                printf("Chuoi sau khi viet hoa: '%s'\n", chuoi);
                break;
            
            case 4:
                printf("Nhap chuoi ho ten: ");
                fgets(chuoi, sizeof(chuoi), stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0';  
                printf("Nhap ten de tim: ");
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0'; 
                if (timKiemTen(chuoi, ten)) {
                    printf("Ten '%s' da nhap dung.\n", ten);
                } else {
                    printf("Ten '%s' da nhap sai.\n", ten);
                }
                break;
            
            case 5:
                printf("Nhap chuoi ho ten: ");
                fgets(chuoi, sizeof(chuoi), stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0';  
                catTen(chuoi, hoLot, tenRi);
                printf("Chuoi ho lot: '%s'\n", hoLot);
                printf("Chuoi ten: '%s'\n", tenRi);
                break;
            
            case 6:
                printf("Nhap chuoi: ");
                fgets(chuoi, sizeof(chuoi), stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0';  
                printf("Nhap tu can chen: ");
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0'; 
                printf("Nhap vi tri chen: ");
                int viTri;
                scanf("%d", &viTri);
                chenTu(chuoi, ten, viTri);
                printf("Chuoi sau khi chen: '%s'\n", chuoi);
                break;
            
            case 7:
                printf("Nhap chuoi: ");
                fgets(chuoi, sizeof(chuoi), stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0'; 
                printf("Nhap tu can xoa: ");
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0';  
                xoaTu(chuoi, ten);
                printf("Chuoi sau khi xoa: '%s'\n", chuoi);
                break;
            
            case 8:
                printf("Nhap chuoi: ");
                fgets(chuoi, sizeof(chuoi), stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0';  
                demTanSuatKyTu(chuoi);
                break;
            
            case 9:
                printf("Nhap chuoi: ");
                fgets(chuoi, sizeof(chuoi), stdin);
                chuoi[strcspn(chuoi, "\n")] = '\0'; 
                printf("Ky tu xuat hien nhieu nhat la: '%c'\n", timKyTuXuatHienNhieuNhat(chuoi));
                break;
            
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
        
    } while (luaChon != 0);
}

int main() {
    menu();
    return 0;
}

