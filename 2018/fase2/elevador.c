/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-08-04 */

#include <stdio.h>
#include <stdlib.h>

void merge(long int arr[], long int left, long int middle, long int right) {
    long int i, j, k;
    long int n1 = middle - left + 1;
    long int n2 = right - middle;

    long int* leftArr = (long int*)malloc(n1 * sizeof(long int));
    long int* rightArr = (long int*)malloc(n2 * sizeof(long int));

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

void mergeSort(long int arr[], long int left, long int right) {
    if (left < right) {
        long int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    long int n;
    scanf("%li", &n);
    long int v[n];
    
    for(long int i=0; i<n; i++)
        scanf("%li", &v[i]);
    
    mergeSort(v, 0, n - 1);
    
    for(long int i=1; i<n; i++) {
        if(v[i] - v[i-1] > 8) {
            printf("N");
            system("pause");
            return 0;
        }
    }
    
    if(v[0] > 8)
        printf("N");
    else
        printf("S");
        
    system("pause");
    return 0;
}
