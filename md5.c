#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

int main() {
    char input[1024];
    unsigned char digest[MD5_DIGEST_LENGTH];
    int i;

    printf("Enter text: ");
    if (fgets(input, sizeof(input), stdin) == NULL) return 1;
    input[strcspn(input, "\n")] = 0;

    MD5((unsigned char*)input, strlen(input), digest);

    for (i = 0; i < MD5_DIGEST_LENGTH; i++)
        printf("%02x", digest[i]);
    printf("\n");

    return 0;
}
