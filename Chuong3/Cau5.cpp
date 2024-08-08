#include <stdio.h>
#include <string.h>

int main() {
    char fullName[100], searchName[50];

    printf("Nhap ho ten: ");
    fgets(fullName, sizeof(fullName), stdin);
    fullName[strcspn(fullName, "\n")] = '\0'; 

    printf("Nhap ten can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    if (strstr(fullName, searchName) != NULL) {
        printf("Ten \"%s\" da nhap dung!\n", searchName);
    }
    else {
        printf("Ten \"%s\" da nhap sai!\n", searchName);
    }

    return 0;
}
