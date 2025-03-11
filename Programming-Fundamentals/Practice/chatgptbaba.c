#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Define some strings and buffers
    char str1[50] = "Hello, ";
    char str2[50] = "World!";
    char str3[50];
    char str4[50] = "Hello, World!";
    char buffer[50];
    
    // 1. strlen: Get the length of a string
    printf("Length of str1: %zu\n", strlen(str1)); // Length of "Hello, "

    // 2. strcpy: Copy string
    strcpy(str3, str2);
    printf("After copying str2 to str3: %s\n", str3); // str3 = "World!"

    // 3. strncpy: Copy n characters
    strncpy(str3, str1, 5);
    str3[5] = '\0'; // Null-terminate after copying
    printf("After copying first 5 chars of str1 to str3: %s\n", str3);

    // 4. strcat: Concatenate strings
    strcat(str1, str2);
    printf("After concatenating str2 to str1: %s\n", str1); // str1 = "Hello, World!"

    // 5. strncat: Concatenate n characters
    char str5[50] = "Good ";
    strncat(str5, "Morning, Everyone!", 7);
    printf("After strncat: %s\n", str5); // str5 = "Good Morning"

    // 6. strcmp: Compare two strings
    printf("Comparison of str1 and str4: %d\n", strcmp(str1, str4)); // Should be 0 (equal)

    // 7. strncmp: Compare first n characters
    printf("Comparison of first 5 chars of str1 and str4: %d\n", strncmp(str1, str4, 5));

    // 8. strchr: Find first occurrence of a character
    char *pos = strchr(str1, 'W');
    if (pos != NULL) {
        printf("First occurrence of 'W' in str1: %s\n", pos);
    }

    // 9. strrchr: Find last occurrence of a character
    pos = strrchr(str1, 'o');
    if (pos != NULL) {
        printf("Last occurrence of 'o' in str1: %s\n", pos);
    }

    // 10. strstr: Find a substring
    char *sub = strstr(str1, "World");
    if (sub != NULL) {
        printf("Substring 'World' found in str1: %s\n", sub);
    }

    // 11. strtok: Tokenize a string
    char str6[50] = "This is a test";
    char *token = strtok(str6, " ");
    printf("Tokens:\n");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    // 12. memset: Fill memory with a constant byte
    memset(buffer, 'A', 10);
    buffer[10] = '\0';
    printf("Buffer after memset: %s\n", buffer);

    // 13. memcpy: Copy memory block
    memcpy(buffer, str2, strlen(str2) + 1);
    printf("Buffer after memcpy: %s\n", buffer);

    // 14. memmove: Move memory block (handles overlap safely)
    char overlap[] = "OverlapExample";
    memmove(overlap + 7, overlap, 7);
    printf("After memmove with overlap: %s\n", overlap);

    // 15. memcmp: Compare memory blocks
    int cmp = memcmp("ABC", "ABD", 3);
    printf("Comparison of 'ABC' and 'ABD': %d\n", cmp);

    // 16. strdup: Duplicate a string
    char *duplicate = strdup("Duplicated String");
    printf("Duplicated string: %s\n", duplicate);
    free(duplicate); // Free dynamically allocated memory

    // 17. strspn: Get length of initial segment containing only specified characters
    size_t len = strspn("123abc", "123");
    printf("Length of initial numeric segment: %zu\n", len);

    // 18. strcspn: Get length of segment not containing specified characters
    len = strcspn("abc123", "123");
    printf("Length before numeric segment: %zu\n", len);

    // 19. strpbrk: Find first matching character from a set
    pos = strpbrk("abc123", "123");
    if (pos != NULL) {
        printf("First matching character from '123': %c\n", *pos);
    }

    // 20. strerror: Get error string for error code
    printf("Error string for error 2: %s\n", strerror(2));

    // 21. strcoll: Compare two strings using locale
    printf("Locale-aware comparison of 'abc' and 'abc': %d\n", strcoll("abc", "abc"));

    // 22. strxfrm: Transform string for locale-aware comparison
    char transformed[50];
    size_t transformed_len = strxfrm(transformed, "abc", sizeof(transformed));
    printf("Transformed string: %s (length: %zu)\n", transformed, transformed_len);

    return 0;
}
