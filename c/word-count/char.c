// $ gcc -Wall -std=c99 char.c -o char.exe

#include <stdio.h>
#include <string.h>

int main() {
    char nwl = '\n';
    char * txt = "first \n next \n last\n";
    int cnt = 0, len = 0;
    char c;
    while((c=*txt++) != '\0') {
        len++;
        if (c == nwl) cnt++;
    }
    printf("Enumerated %d newlines. Length = %d\n", cnt, len);

    return 0;
}