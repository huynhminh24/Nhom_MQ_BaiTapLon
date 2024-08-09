#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hoanDoiInt(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void hoanDoiFloat(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

void hoanDoiChar(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void hoanDoiString(char **x, char **y) {
    char *temp = *x;
    *x = *y;
    *y = temp;
}

void sapXepInterchangeIntTang(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                hoanDoiInt(&a[i], &a[j]);
            }
        }
    }
}

void sapXepInterchangeIntGiam(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] < a[j]) {
                hoanDoiInt(&a[i], &a[j]);
            }
        }
    }
}

void sapXepInterchangeFloatTang(float a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                hoanDoiFloat(&a[i], &a[j]);
            }
        }
    }
}

void sapXepInterchangeFloatGiam(float a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] < a[j]) {
                hoanDoiFloat(&a[i], &a[j]);
            }
        }
    }
}

void sapXepInterchangeCharTang(char a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                hoanDoiChar(&a[i], &a[j]);
            }
        }
    }
}

void sapXepInterchangeCharGiam(char a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] < a[j]) {
                hoanDoiChar(&a[i], &a[j]);
            }
        }
    }
}

void sapXepInterchangeStringTang(char *a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp(a[i], a[j]) > 0) {
                hoanDoiString(&a[i], &a[j]);
            }
        }
    }
}

void sapXepInterchangeStringGiam(char *a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp(a[i], a[j]) < 0) {
                hoanDoiString(&a[i], &a[j]);
            }
        }
    }
}

int main() {
    int choice;
    printf("Chon loai du lieu can sap xep:\n");
    printf("1. So nguyen\n");
    printf("2. So thuc\n");
    printf("3. Ky tu\n");
    printf("4. Chuoi ky tu\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            int n;
            printf("Nhap so luong phan tu: ");
            scanf("%d", &n);
            int *arr = (int*)malloc(n * sizeof(int));
            printf("Nhap cac phan tu:\n");
            for(int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            sapXepInterchangeIntTang(arr, n);
            printf("Mang so nguyen sap xep tang: ");
            for(int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            sapXepInterchangeIntGiam(arr, n);
            printf("Mang so nguyen sap xep giam: ");
            for(int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            free(arr);
            break;
        }
        case 2: {
            int n;
            printf("Nhap so luong phan tu: ");
            scanf("%d", &n);
            float *arr = (float*)malloc(n * sizeof(float));
            printf("Nhap cac phan tu:\n");
            for(int i = 0; i < n; i++) {
                scanf("%f", &arr[i]);
            }
            sapXepInterchangeFloatTang(arr, n);
            printf("Mang so thuc sap xep tang: ");
            for(int i = 0; i < n; i++) {
                printf("%.2f ", arr[i]);
            }
            printf("\n");
            sapXepInterchangeFloatGiam(arr, n);
            printf("Mang so thuc sap xep giam: ");
            for(int i = 0; i < n; i++) {
                printf("%.2f ", arr[i]);
            }
            printf("\n");
            free(arr);
            break;
        }
        case 3: {
            int n;
            printf("Nhap so luong phan tu: ");
            scanf("%d", &n);
            char *arr = (char*)malloc(n * sizeof(char));
            printf("Nhap cac phan tu:\n");
            for(int i = 0; i < n; i++) {
                scanf(" %c", &arr[i]);
            }
            sapXepInterchangeCharTang(arr, n);
            printf("Mang ky tu sap xep tang: ");
            for(int i = 0; i < n; i++) {
                printf("%c ", arr[i]);
            }
            printf("\n");
            sapXepInterchangeCharGiam(arr, n);
            printf("Mang ky tu sap xep giam: ");
            for(int i = 0; i < n; i++) {
                printf("%c ", arr[i]);
            }
            printf("\n");
            free(arr);
            break;
        }
        case 4: {
            int n;
            printf("Nhap so luong phan tu: ");
            scanf("%d", &n);
            char **arr = (char**)malloc(n * sizeof(char*));
            printf("Nhap cac phan tu:\n");
            for(int i = 0; i < n; i++) {
                arr[i] = (char*)malloc(100 * sizeof(char));
                scanf("%s", arr[i]);
            }
            sapXepInterchangeStringTang(arr, n);
            printf("Mang chuoi ky tu sap xep tang: ");
            for(int i = 0; i < n; i++) {
                printf("%s ", arr[i]);
            }
            printf("\n");
            sapXepInterchangeStringGiam(arr, n);
            printf("Mang chuoi ky tu sap xep giam: ");
            for(int i = 0; i < n; i++) {
                printf("%s ", arr[i]);
            }
            printf("\n");
            for(int i = 0; i < n; i++) {
                free(arr[i]);
            }
            free(arr);
            break;
        }
        default:
            printf("Lua chon khong hop le.\n");
    }

    return 0;
}

