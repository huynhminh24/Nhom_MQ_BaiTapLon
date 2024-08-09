#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int BinarySearch(int a[], int n, int x) {
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

int main() {
    int a[] = {7, 9, 13, 17, 27, 30, 31, 35, 38, 40};
    int n = sizeof(a) / sizeof(a[0]);
    
    int values1[] = {17, 35, 40};
    for(int i = 0; i < 3; i++) {
        int result = BinarySearch(a, n, values1[i]);
        if(result != -1) {
            printf("Tim thay %d tai vi tri %d\n", values1[i], result);
        } else {
            printf("Khong tim thay %d\n", values1[i]);
        }
    }

    int values2[] = {23, 10, 36};
    for(int i = 0; i < 3; i++) {
        int result = BinarySearch(a, n, values2[i]);
        if(result != -1) {
            printf("Tim thay %d tai vi tri %d\n", values2[i], result);
        } else {
            printf("Khong tim thay %d\n", values2[i]);
        }
    }
    
    return 0;
}
