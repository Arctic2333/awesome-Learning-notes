// 全排列
#include <stdio.h>

void swap(int * p1, int * p2) {
    int t = * p1;
    * p1 = * p2;
    * p2 = t;
}

void permutation(int a[], int index, int size) {
    if (index == size) {
        for (int i = 0; i < size; i++)
            printf("%d ", a[i]);
        printf("\n");
    } else {
        for (int j = index; j < size; j++) {
            swap( & a[j], & a[index]);
            permutation(a, index + 1, size);
            swap( & a[j], & a[index]);
        }
    }
}

int main() {
    int n;
    scanf("%d", & n);
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    permutation(a, 0, n);
    return 0;
}