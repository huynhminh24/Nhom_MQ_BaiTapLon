#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int count = 0;

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            count++;
        }
    }
    printf("So luong khoang trang trong chuoi: %d\n", count);

    return 0;
}
