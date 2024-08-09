#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void Sort(char a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                char temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int BinarySearch(char a[], int n, char x) {
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
    char a[] = {'Z', 'R', 'L', 'K', 'H', 'F', 'E', 'C', 'A'};
    int n = sizeof(a) / sizeof(a[0]);
    
    Sort(a, n);
    
    printf("Mang sau khi sap xep: ");
    for(int i = 0; i < n; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
    
    char values1[] = {'R', 'C'};
    for(int i = 0; i < 2; i++) {
        int result = BinarySearch(a, n, values1[i]);
        if(result != -1) {
            printf("Tim thay %c tai vi tri %d\n", values1[i], result);
        } else {
            printf("Khong tim thay %c\n", values1[i]);
        }
    }

    char values2[] = {'D', 'Q'};
    for(int i = 0; i < 2; i++) {
        int result = BinarySearch(a, n, values2[i]);
        if(result != -1) {
            printf("Tim thay %c tai vi tri %d\n", values2[i], result);
        } else {
            printf("Khong tim thay %c\n", values2[i]);
        }
    }
    
    return 0;
}
