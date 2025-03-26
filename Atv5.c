#include <stdio.h>

// Função para trocar dois valores
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

// Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Função para mesclar dois subarrays ordenados (usado no Merge Sort)
void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = A[p + i];
    for (int j = 0; j < n2; j++) R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
        k++;
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
}

// Merge Sort
void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

// Função para imprimir um array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal para testar os algoritmos
int main() {
    int arr[] = {10, 20, 5, 40, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr1[] = {10, 20, 5, 40, 4};
    bubbleSort(arr1, n);
    printf("Bubble Sort: ");
    printArray(arr1, n);

    int arr2[] = {10, 20, 5, 40, 4};
    insertionSort(arr2, n);
    printf("Insertion Sort: ");
    printArray(arr2, n);

    int arr3[] = {10, 20, 5, 40, 4};
    selectionSort(arr3, n);
    printf("Selection Sort: ");
    printArray(arr3, n);

    int arr4[] = {10, 20, 5, 40, 4};
    shellSort(arr4, n);
    printf("Shell Sort: ");
    printArray(arr4, n);

    int arr5[] = {10, 20, 5, 40, 4};
    mergeSort(arr5, 0, n - 1);
    printf("Merge Sort: ");
    printArray(arr5, n);

    return 0;
}
