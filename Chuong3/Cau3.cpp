#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeExtraSpaces(char* str) {
    int i = 0, j = 0;
    int len = strlen(str);

    while (isspace(str[i])) {
        i++;
    }

    while (i < len) {
        if (!isspace(str[i]) || (j > 0 && !isspace(str[j - 1]))) {
            str[j++] = str[i];
        }
        i++;
    }

    if (j > 0 && isspace(str[j - 1])) {
        j--;
    }

    str[j] = '\0';
}

int main() {
    char input[100];

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    removeExtraSpaces(input);

    printf("Chuoi sau khi xoa khoang trang thua: \"%s\"\n", input);

    return 0;
}
