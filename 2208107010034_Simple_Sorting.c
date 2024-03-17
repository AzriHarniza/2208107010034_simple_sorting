#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk menghasilkan bilangan acak dan menyimpannya ke dalam sebuah file
void generateRandomNumbers(int n) {
    FILE *file;
    file = fopen("random_numbers.txt", "w");

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = rand();
        fprintf(file, "%d\n", num);
    }

    fclose(file);
}

// Fungsi untuk membaca bilangan dari sebuah file
void readNumbersFromFile(int *arr, int n) {
    FILE *file;
    file = fopen("random_numbers.txt", "r");

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

// Fungsi untuk melakukan Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar arr[j] dan arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk melakukan Selection Sort
void selectionSort(int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Tukar arr[i] dan arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Fungsi untuk melakukan Insertion Sort
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Pindahkan elemen-elemen arr[0..i-1], yang lebih besar dari key, ke posisi satu langkah di depan posisi mereka saat ini
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Fungsi untuk menyimpan bilangan yang sudah diurutkan ke dalam sebuah file
void saveSortedNumbersToFile(int *arr, int n, const char *filename) {
    FILE *file;
    file = fopen(filename, "w");

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}


int main() {
    printf("-------------------------------------------------------\n");
    printf("Jenis Algoritma    Jumlah Bilangan    Waktu Eksekusi(s)\n");
    printf("-------------------------------------------------------\n");

    int max_elements = 1000000;
    generateRandomNumbers(max_elements);

    // Melakukan pengukuran waktu dan penyimpanan setiap iterasi untuk Bubble Sort
    for (int num_elements = 100000; num_elements <= max_elements; num_elements += 100000) {
        printf("Bubble Sort        %dK                 ", num_elements / 1000);

        clock_t start, end;
        double cpu_time_used;

        int *arr = (int *)malloc(num_elements * sizeof(int));
        readNumbersFromFile(arr, num_elements);

        start = clock();
        bubbleSort(arr, num_elements);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used);

        char filename[50];
        sprintf(filename, "bubble_sorted_%dk.txt", num_elements / 1000);
        saveSortedNumbersToFile(arr, num_elements, filename);

        free(arr);
    }

    printf("-------------------------------------------------------\n");

    // Melakukan pengukuran waktu dan penyimpanan setiap iterasi untuk selection Sort
    for (int num_elements = 100000; num_elements <= max_elements; num_elements += 100000) {
        printf("Selection Sort     %dK                 ", num_elements / 1000);

        clock_t start, end;
        double cpu_time_used;

        int *arr = (int *)malloc(num_elements * sizeof(int));
        readNumbersFromFile(arr, num_elements);

        start = clock();
        selectionSort(arr, num_elements);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used);

        char filename[50];
        sprintf(filename, "selection_sorted_%dk.txt", num_elements / 1000);
        saveSortedNumbersToFile(arr, num_elements, filename);

        free(arr);
    }

    printf("-------------------------------------------------------\n");

    // Melakukan pengukuran waktu dan penyimpanan setiap iterasi untuk insertion Sort
    for (int num_elements = 100000; num_elements <= max_elements; num_elements += 100000) {
        printf("Insertion Sort     %dK                 ", num_elements / 1000);

        clock_t start, end;
        double cpu_time_used;

        int *arr = (int *)malloc(num_elements * sizeof(int));
        readNumbersFromFile(arr, num_elements);

        start = clock();
        insertionSort(arr, num_elements);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used);

        char filename[50];
        sprintf(filename, "insertion_sorted_%dk.txt", num_elements / 1000);
        saveSortedNumbersToFile(arr, num_elements, filename);

        free(arr);
    }

    printf("-------------------------------------------------------\n");

    return 0;
}
