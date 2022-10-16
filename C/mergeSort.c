// Name: karol marques

// Username: karoldm

// Favorite Language: Javascript :p 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/****************************************************************************************************************/
/* in MergeSort the array is always split in half generating subarrays with n/2 elements. Recursive calls occur when 
/* we arrive at the base case: size(A) <=1, since an array with 1 or 0 elements is already sorted. After this step, 
/* the Merge function joins the subarrays already sorting them.                                                                                   
/****************************************************************************************************************/

void MergeSort(int *A, int start, int end){
    int x;
    if(start>=end) return;
    x = (start+end)/2;
    MergeSort(A, start, x);
    MergeSort(A, x+1, end);
    Merge(A, start, x, end);
}

/*The Merge function helps MergeSort work by merging two arrays in an orderly manner. These two arrays are actually 
subarrays of a single vector halved by MergeSort: A' = [Start,...,Middle] and A'' = [Middle+1,...,End]*/

void Merge(int *A, int start, int middle, int end){
    int i, j, k, B[end+1];
    i = start;
    j = middle+1;
    k = start;
    /*If the element of A at position i is smaller than the element of A at position j it is added to the auxiliary 
    vector B, otherwise the element at position j is added. This causes the elements of B to be inserted into the array 
    already sorted.*/
    while ((i <= middle) && (j <= end)){
        if (*(A+i) < *(A+j)) {
            B[k] = *(A+i);
            k++; i++;
        }
        else {
            B[k] = *(A+j);
            k++; j++;
        }
    }
    /*If one of the arrangements runs out and the other still has elements to be inserted*/
    while (i <= middle){ B[k] = *(A+i); k++; i++;}
    while (j <= end){ B[k] = *(A+j); k++; j++;}
    for (i = start; i <= end; i++) *(A+i) = B[i]; //copying the elements from B (which are sorted) back to A.
}

void printVector(int *A, int Dim){
    int i;
    printf("\n\n");
    printf("{");
    for(i=0; i<Dim-1; i++) printf("%d, ", *(A+i));
    printf("%d}", *(A+i));
}

int size(void){
    int dim;
    printf("\nEnter the number of vector elements: ");
    scanf("%d",&dim);
    return(dim);
}

void randValues(int *A, int dim){
    int i, seed = time(NULL);
    if (dim > 0){
        srand((unsigned) seed);
        for (i = 0; i < dim; i++) *(A+i) = rand();
    }
}

int main(void){
    int *A, Dim;

    Dim = size();
    A = (int *)malloc(Dim*sizeof(int));

    randValues(A, Dim);

    printf("\n\nVECTOR: ");
    printVector(A, Dim);

    printf("\n\n>>SORT BY MERGESORT: ");
    MergeSort(A, 0, Dim-1);
    printVector(A, Dim);

    printf("\n\n\n");
    system("pause");
    return(0);
}