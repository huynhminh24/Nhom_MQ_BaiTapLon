#include <stdio.h>
#include <string.h>

int main() {
    char s1[20] = "Truong DHCT ", s2[10] = "Tp.HCM", input[30], s3[10];
    strcpy_s(input, s1);
    strcpy_s(s3, "aeiou");
    strcat_s(input, s2);
    int n = strlen(input), k = 0;
    printf("Chuoi: %s", input);
    for (int i = 0; i < n; i++) {
        if (strchr(s3, input[i])) k++;
    }
    printf("\nKet qua: %d", k);

    return 0;
}