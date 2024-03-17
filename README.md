# 2208107010034_Simple_Sorting
tugas 2 SDA
Program ini adalah sebuah program sederhana yang mengimplementasikan tiga algoritma pengurutan, yaitu Bubble Sort, Selection Sort, dan Insertion Sort. Program ini bertujuan untuk mengukur waktu eksekusi dari ketiga algoritma pengurutan tersebut.

Langkah menjalankan program :
1. Pastikan Anda memiliki kompiler C yang terinstal di sistem Anda, seperti GCC (GNU Compiler Collection).
2. Buka terminal atau command prompt di sistem Anda.
3. Salin repositori program ini ke komputer Anda.
4. Masuk ke direktori program. 
5. Compile program menggunakan compiler C.
6. Setelah kompilasi selesai, jalankan program.
7. Program akan mengeksekusi dan outputnya akan ditampilkan di terminal atau command prompt. 

Penjelasan Fungsi yang Ada:
1. generateRandomNumbers(int n): Fungsi ini digunakan untuk menghasilkan n bilangan acak dan menyimpannya dalam sebuah file bernama "random_numbers.txt".
2. readNumbersFromFile(int *arr, int n): Fungsi ini membaca bilangan dari file "random_numbers.txt" dan menyimpannya dalam array arr sebanyak n bilangan.
3. bubbleSort(int arr[], int n): Fungsi ini melakukan pengurutan array arr berukuran n menggunakan algoritma Bubble Sort.
4. selectionSort(int arr[], int n): Fungsi ini melakukan pengurutan array arr berukuran n menggunakan algoritma Selection Sort.
5. insertionSort(int arr[], int n): Fungsi ini melakukan pengurutan array arr berukuran n menggunakan algoritma Insertion Sort.
6. saveSortedNumbersToFile(int *arr, int n, const char *filename): Fungsi ini menyimpan array arr yang sudah diurutkan dalam file dengan nama yang ditentukan oleh parameter filename.
7. main(): Fungsi utama program yang melakukan pengukuran waktu eksekusi untuk setiap jenis algoritma pengurutan (Bubble Sort, Selection Sort, dan Insertion Sort) dengan jumlah bilangan yang bervariasi dari 100 ribu hingga 1 juta. Hasil pengukuran waktu eksekusi ditampilkan dalam sebuah tabel yang mencakup jenis algoritma, jumlah bilangan yang diurutkan, dan waktu eksekusi dalam detik.
