#include <stdio.h>
#include <ctype.h>
#include <string.h>

void capitalizeWords(char* str) {
    int capitalize = 1;  

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            capitalize = 1; 
        }
        else if (capitalize && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            capitalize = 0; 
        }
        else {
            str[i] = tolower(str[i]); 
        }
    }
}

int main() {
    char input[100];

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    capitalizeWords(input);

    printf("Chuoi sau khi chinh sua: \"%s\"\n", input);

    return 0;
}
