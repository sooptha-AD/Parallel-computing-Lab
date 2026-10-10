
#include <stdio.h>
#include <omp.h>

int main() {
    int n, i;
    int a[100], prefix[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    prefix[0] = a[0];

    #pragma omp parallel for
    for (i = 1; i < n; i++) {
        int sum = 0;
        int j;

        for (j = 0; j <= i; j++) {
            sum += a[j];
        }

        prefix[i] = sum;
    }

    printf("Prefix sum: ");
    for (i = 0; i < n; i++) {
        printf("%d ", prefix[i]);
    }

    printf("\n");
    return 0;
}
