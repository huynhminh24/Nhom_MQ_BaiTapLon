#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearchRecursive(arr, left, mid - 1, x);
        }

        return binarySearchRecursive(arr, mid + 1, right, x);
    }

    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Nhap so can tim kiem: ");
    scanf_s("%d", &x);

    int result = binarySearchRecursive(arr, 0, n - 1, x);
    if (result == -1) {
        printf("So %d khong ton tai trong mang.\n", x);
    }
    else {
        printf("So %d o vi tri %d trong mang.\n", x, result);
    }

    return 0;
}