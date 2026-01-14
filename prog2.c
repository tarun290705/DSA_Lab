/*  2. Design, Develop and Implement a Program for sorting the elements using
    a. Insertion sort
    b. Selection sort
*/

#include<stdio.h>
#define MAX 100

int a[MAX], n;

//Insertion Sort
void insertionSort(int a[], int n) {
    for(int i=1; i<n; i++) {
        int key = a[i], j = i - 1;
        while(j>=0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    printf("Sorted Array (Insertion Sort) : ");
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

//Selection Sort
void selectionSort(int a[], int n) {
    for(int i=0; i<n; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
            if(a[j] < minIndex)
                minIndex = j;
        int temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;       
    }
    printf("Sorted Array (Selection Sort) : ");
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");    
}

int main() {
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter %d elements into the array : ", n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("Unsorted Array : ");
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");

    insertionSort(a, n);
    selectionSort(a, n);

    return 0;        
}