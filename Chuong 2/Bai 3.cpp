#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapMang(int *a, int n) {
    for(int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int *a, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int timMax(int *a, int n) {
    int max = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int timMin(int *a, int n) {
    int min = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int demChan(int *a, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int demLe(int *a, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int linearSearch(int *a, int n, int x) {
    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            return i;
        }
    }
    return -1;
}

void sapXepMang(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int *a, int n, int x) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int demSoLan(int *a, int n, int x) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            count++;
        }
    }
    return count;
}

int demLonHonX(int *a, int n, int x) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > x) {
            count++;
        }
    }
    return count;
}

int tinhTongMang(int *a, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int kiemTraSoNguyenTo(int n) {
    if(n < 2) {
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void xuatSoNguyenTo(int *a, int n) {
    for(int i = 0; i < n; i++) {
        if(kiemTraSoNguyenTo(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

int kiemTraSoHoanHao(int n) {
    int sum = 0;
    for(int i = 1; i <= n / 2; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

void xuatSoHoanHao(int *a, int n) {
    for(int i = 0; i < n; i++) {
        if(kiemTraSoHoanHao(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void xuatViTriChan(int *a, int n) {
    for(int i = 0; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void xuatViTriLe(int *a, int n) {
    for(int i = 1; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void xuatMaxViTri(int *a, int n) {
    int max = timMax(a, n);
    printf("Max: %d tai vi tri: ", max);
    for(int i = 0; i < n; i++) {
        if(a[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void xuatMinViTri(int *a, int n) {
    int min = timMin(a, n);
    printf("Min: %d tai vi tri: ", min);
    for(int i = 0; i < n; i++) {
        if(a[i] == min) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void ghepMang(int *b, int m, int *c, int n, int *a) {
    int i = 0, j = 0, k = 0;
    while(i < m && j < n) {
        if(b[i] < c[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = c[j++];
        }
    }
    while(i < m) {
        a[k++] = b[i++];
    }
    while(j < n) {
        a[k++] = c[j++];
    }
}

int main() {
    int *a = NULL, *b = NULL, *c = NULL;
    int n = 0, m = 0, choice = 0, x = 0;

    while(1) {
        printf("Menu:\n");
        printf("1. Nhap mang\n");
        printf("2. Xuat mang\n");
        printf("3. Tim max/min\n");
        printf("4. Dem so phan tu chan/le\n");
        printf("5. Tim kiem phan tu (tuyen tinh)\n");
        printf("6. Tim kiem phan tu (nhi phan)\n");
        printf("7. Dem so phan tu x\n");
        printf("8. Dem so phan tu lon hon x\n");
        printf("9. Tinh tong cac phan tu\n");
        printf("10. Xuat cac so nguyen to\n");
        printf("11. Xuat cac so hoan hao\n");
        printf("12. Xuat cac phan tu o vi tri chan/le\n");
        printf("13. Xuat gia tri max/min kem theo vi tri\n");
        printf("14. Ghep 2 day so tang dan\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if(a != NULL) {
                    free(a);
                }
                printf("Nhap so luong phan tu cua mang: ");
                scanf("%d", &n);
                a = (int *)malloc(n * sizeof(int));
                if (a == NULL) {
                    printf("Loi cap phat bo nho.\n");
                    return 1;
                }
                nhapMang(a, n);
                break;
            }
            case 2: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                xuatMang(a, n);
                break;
            }
            case 3: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("Max: %d\n", timMax(a, n));
                printf("Min: %d\n", timMin(a, n));
                break;
            }
            case 4: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("So phan tu chan: %d\n", demChan(a, n));
                printf("So phan tu le: %d\n", demLe(a, n));
                break;
            }
            case 5: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("Nhap gia tri x: ");
                scanf("%d", &x);
                int pos = linearSearch(a, n, x);
                if (pos == -1) {
                    printf("Khong tim thay phan tu %d\n", x);
                } else {
                    printf("Phan tu %d nam tai vi tri %d\n", x, pos);
                }
                break;
            }
            case 6: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                sapXepMang(a, n);
                printf("Mang sau khi sap xep: ");
                xuatMang(a, n);
                printf("Nhap gia tri x: ");
                scanf("%d", &x);
                int pos = binarySearch(a, n, x);
                if (pos == -1) {
                    printf("Khong tim thay phan tu %d\n", x);
                } else {
                    printf("Phan tu %d nam tai vi tri %d\n", x, pos);
                }
                break;
            }
            case 7: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("Nhap gia tri x: ");
                scanf("%d", &x);
                printf("So phan tu x: %d\n", demSoLan(a, n, x));
                break;
            }
            case 8: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("Nhap gia tri x: ");
                scanf("%d", &x);
                printf("So phan tu lon hon %d: %d\n", x, demLonHonX(a, n, x));
                break;
            }
            case 9: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("Tong cac phan tu: %d\n", tinhTongMang(a, n));
                break;
            }
            case 10: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("Cac so nguyen to: ");
                xuatSoNguyenTo(a, n);
                break;
            }
            case 11: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("Cac so hoan hao: ");
                xuatSoHoanHao(a, n);
                break;
            }
            case 12: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                printf("Cac phan tu o vi tri chan: ");
                xuatViTriChan(a, n);
                printf("Cac phan tu o vi tri le: ");
                xuatViTriLe(a, n);
                break;
            }
            case 13: {
                if(a == NULL) {
                    printf("Mang chua duoc khoi tao. Vui long nhap mang truoc.\n");
                    break;
                }
                xuatMaxViTri(a, n);
                xuatMinViTri(a, n);
                break;
            }
            case 14: {
                if (b != NULL) {
                    free(b);
                }
                if (c != NULL) {
                    free(c);
                }
                printf("Nhap so luong phan tu cho mang b: ");
                scanf("%d", &m);
                b = (int *)malloc(m * sizeof(int));
                if (b == NULL) {
                    printf("Loi cap phat bo nho.\n");
                    return 1;
                }
                nhapMang(b, m);
                sapXepMang(b, m);
                xuatMang(b, m);

                printf("Nhap so luong phan tu cho mang c: ");
                scanf("%d", &n);
                c = (int *)malloc(n * sizeof(int));
                if (c == NULL) {
                    printf("Loi cap phat bo nho.\n");
                    free(b);
                    return 1;
                }
                nhapMang(c, n);
                sapXepMang(c, n);
                xuatMang(c, n);

                int *aTemp = (int *)malloc((m + n) * sizeof(int));
                if (aTemp == NULL) {
                    printf("Loi cap phat bo nho.\n");
                    free(b);
                    free(c);
                    return 1;
                }
                ghepMang(b, m, c, n, aTemp);
                printf("Mang sau khi ghep: ");
                xuatMang(aTemp, m + n);
                free(aTemp);
                break;
            }
            case 0:
                if (a != NULL) {
                    free(a);
                }
                if (b != NULL) {
                    free(b);
                }
                if (c != NULL) {
                    free(c);
                }
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }
    return 0;
}

