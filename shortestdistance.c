#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void mindis(int arr[], int x, int y, int n) {
    int i, j;
    int dist = 10000;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i] == x && arr[j] == y) {
                if (abs(i - j) < dist) {
                    dist = abs(i - j);
                }
            }
        }
    }
    if (dist < 10000) {
        printf("%d", dist);
    } else {
        printf("x and y not found");
    }
}

int main() {
    int arr[] = {3, 5, 4, 7, 3, 7};
    int n = 6;
    mindis(arr, 7, 7, n);
    return 0;
}
