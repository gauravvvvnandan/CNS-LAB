#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereCipher(char *input, char *key, char *output, int encrypt) {
    int inputLen = strlen(input);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < inputLen; i++, j++) {
        if (j >= keyLen) {
            j = 0; 
        }
        char currentChar = input[i];
        char keyChar = key[j];
        int shift = keyChar - 'a';

        if (!isalpha(currentChar)) {
            output[i] = currentChar; 
            j--;
            continue;
        }
        if (encrypt) {
            output[i] = 'a' + (currentChar - 'a' + shift) % 26;
        } else {
            output[i] = 'a' + (currentChar - 'a' - shift + 26) % 26;
        }
    }
    output[inputLen] = '\0'; 
}
int main() {
    char plaintext[100];
    char key[100]; 
    char encrypted[100]; 
    char decrypted[100]; 
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    vigenereCipher(plaintext, key, encrypted, 1);
    printf("Encrypted message: %s\n", encrypted);
    vigenereCipher(encrypted, key, decrypted, 0);
    printf("Decrypted message: %s\n", decrypted);
    return 0;
}
