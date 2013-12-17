#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

bool IsSorted(int a[], size_t n);
void shuffle(int a[], size_t n);
void printarray(int a[], size_t n);

#define swap(a, b) \
    do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

bool IsSorted(int a[], size_t n)
{
    size_t i;

    for (i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}

void shuffle(int a[], size_t n)
{
    size_t i;
    int r;

    for (i = n - 1; i > 0; i--) {
        r = rand() % i;
        swap(a[r], a[i]);
    }

    return;
}

void printarray(int a[], size_t n)
{
    size_t i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return;
}

int main()
{
    int p = 0;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(array) / sizeof(array[0]);

    srand((unsigned)time(NULL));

    shuffle(array, n);
    printarray(array, n);

    while (!IsSorted(array, n)) {
        shuffle(array, n);
        p++;
    }

    printf("Done, took %d passes\n", p);
    return 0;
}


