#include <stdio.h>
#include <string.h>

#define MAX 256

void createshift(char *pattern, int shifttable[], int m) {
    int i;
    for (i = 0; i < MAX; i++) {
        shifttable[i] = m; // Initialize all shifts to the pattern length
    }
    for (i = 0; i < m - 1; i++) {
        shifttable[(unsigned char)pattern[i]] = m - i - 1;
    }
}

int horspool(char *text, char *pattern, int *comparisons) {
    int n = strlen(text);
    int m = strlen(pattern);
    int shifttable[MAX];
    createshift(pattern, shifttable, m); // Fixed call to createshift

    int i = m - 1; // Start from the last character of the pattern
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - k - 1] == text[i - k]) {
            k++;
            (*comparisons)++;
        }
        if (k == m) {
            printf("Pattern found at position: %d\n", i - m + 1);
            return 1; // Successful search
        }
        (*comparisons)++;
        i += shifttable[(unsigned char)text[i]]; // Fixed typo: shiftTable -> shifttable
    }
    printf("Pattern not found.\n");
    return 0; // Unsuccessful search
}

int main() {
    char text[] = "this is an example";
    char pattern1[] = "example";
    char pattern2[] = "xyz"; // Fixed missing semicolon
    int comparisons = 0;

    printf("Searching for '%s'...\n", pattern1);
    horspool(text, pattern1, &comparisons);
    printf("Key comparisons in successful search: %d\n", comparisons);

    comparisons = 0; // Reset comparison count
    printf("Searching for '%s'...\n", pattern2);
    horspool(text, pattern2, &comparisons);
    printf("Key comparisons in unsuccessful search: %d\n", comparisons);

    return 0;
}
