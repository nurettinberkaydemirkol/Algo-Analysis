#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define A_SIZE 20
#define G_SIZE 10
#define MAX_W 10

//Max deger icin sonsuz sayi
#define INF INT_MAX

void generate(int a[], int size);
void function1(int a[], int size);
int function2(int a[], int size);
void function3(int g[][G_SIZE], int d[][G_SIZE], int size);
void print1(int a[], int size);
void print2(int g[][G_SIZE], int size);
void print3(int g[][G_SIZE], int size, int t);

int main() {
    int a[A_SIZE];
    int g[G_SIZE][G_SIZE] = {
    { 0, 10,  3,  0,  0,  5,  0, 17,  0, 22},
    {10,  0,  5,  0,  2,  0, 13,  0,  0,  0},
    { 3,  5,  0,  2,  0,  4,  0, 21,  0, 11},
    { 0,  0,  2,  0,  7,  0,  6,  0,  0,  0},
    { 0,  2,  0,  7,  0,  6,  0,  0, 19,  0},
    { 5,  0,  4,  0,  6,  0,  9,  3,  0,  0},
    { 0, 13,  0,  6,  0,  9,  0,  4,  0,  0},
    {17,  0, 21,  0,  0,  3,  4,  0,  8,  0},
    { 0,  0,  0,  0, 19,  0,  0,  8,  0,  5},
    {22,  0, 11,  0,  0,  0,  0,  0,  5,  0}
    };
    int d[G_SIZE][G_SIZE];
    int t;

    // Rastgele sayi uretici icin seed
    srand(time(NULL));

    // Calisma suresinin hesaplanmasi
    clock_t start, end;
    double time;

    start = clock();

    generate(a, A_SIZE);
    printf("A:\n");
    print1(a, A_SIZE);

    function1(a, A_SIZE);
    printf("\nFunction1 Sonuc:\n");
    print1(a, A_SIZE);

    t = function2(a, A_SIZE);
    printf("\nFunction2 Sonuc: %d\n", t);

    printf("\nG:\n");
    print2(g, G_SIZE);

    function3(g, d, G_SIZE);
    printf("\nFunction3 Sonuc:\n");
    print2(d, G_SIZE);

    printf("\n%d icin sonuc:\n", t);
    print3(d, G_SIZE, t);

    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nCalisma Suresi: %f sn\n", time);

    return 0;
}

void generate(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % (2 * MAX_W) - MAX_W;
    }
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return i + 1;
}


void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(a, low, high);
        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

void function1(int a[], int size) {
    quickSort(a, 0, size - 1);
}

int function2(int a[], int size) {
    int t = 0, current_sum = 0, count=0;
    for (int i = 0; i < size; i++) {
        if (current_sum + a[i] > 0) {
            current_sum = current_sum + a[i];
        }
        else {
            current_sum = 0;
        }
        if (current_sum > t) {
            t = current_sum;
            count++;
        }
    }
    return t/count;
}

void function3(int g[][G_SIZE], int d[][G_SIZE], int size) {
    // Başlangıçta tüm d[i][j] değerlerini INF olarak ayarlayın
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            d[i][j] = INF;
        }
    }

    // Her bir düğüm için "Adım Adım Dijkstra" algoritmasını uygulayın
    for (int src = 0; src < size; src++) {
        // Ziyaret edilen düğümleri takip etmek için bir dizi oluşturun
        bool visited[size];
        memset(visited, false, sizeof(visited));

        // Başlangıç düğümünü ziyaret edildi olarak işaretleyin
        visited[src] = true;
        d[src][src] = 0;

        // src düğümünden tüm diğer düğümlere olan en kısa yolları hesaplayın
        for (int count = 0; count < size - 1; count++) {
            // Henüz ziyaret edilmemiş en kısa yol düğümünü bulun
            int minDistance = INF;
            int minIndex = -1;
            for (int i = 0; i < size; i++) {
                if (!visited[i] && d[src][i] < minDistance) {
                    minDistance = d[src][i];
                    minIndex = i;
                }
            }

            // En kısa yol düğümünü ziyaret edildi olarak işaretleyin
            visited[minIndex] = true;

            // En kısa yol düğümünden geçerek diğer düğümlere olan yolları güncelleyin
            for (int i = 0; i < size; i++) {
                if (!visited[i] && g[minIndex][i] && d[src][minIndex] + g[minIndex][i] < d[src][i]) {
                    d[src][i] = d[src][minIndex] + g[minIndex][i];
                }
            }
        }
    }
}

void print1(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

void print2(int g[][G_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (g[i][j] == INF) {
                printf("INF ");
            }
            else {
                printf("%3d ", g[i][j]);
            }
        }
        printf("\n");
    }
}

void print3(int d[][G_SIZE], int size, int t) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && d[i][j] < t) {
                printf("%c -> %c: %d\n", 'A' + i, 'A' + j, d[i][j]);
            }
        }
    }
}