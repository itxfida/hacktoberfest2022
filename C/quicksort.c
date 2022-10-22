/*
    Quicksort algorithm in C
    Submitted by Ashwin Prasanth (https://github.com/ashwinpra)  

    It works by selecting a certain element of the array as a "pivot", then placing the pivot 
    in such a position that all the elements to the left of it are lesser than it, and all the 
    elements to the right of it are greater than it. 

    The same procedure is then recursively repeated on the above mentioned left and right portions

    For a more detailed explanation, you may refer to https://en.wikipedia.org/wiki/Quicksort

*/

#include<stdio.h>
#include<stdlib.h>

// Utility function to swap two integers, given their corresponding pointers
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* 
	This function takes 3 arguments: 
		1. The array "A" to be sorted 
		2. The starting index of the array "p"
		3. The ending index of the array "r"

	It works by selecting the first element as the "pivot", 
	then places two pointers, one at the start of the array and one at the end, 
	and then loops while checking that all the elements traversed by the "start" 
	pointer are less than pivot, 
	and all the elements traversed by the "end" pointer are greater than pivot. 

	When this condition is violated, the elements pointed by start and end get swapped

	The loop finally terminates when "start" becomes greater than or equal to "end"

	Finally, the "pivot" element is swapped with the element pointed by "end", 
	and the new index of the pivot element is returned


*/
int partition(int* A, int p, int r){
	int pivot = A[p];
	int start = p, end = r; 

	while(start < end){

		// As long as the elements pointed by "start" are lower than pivot, we keep traversing
		while(A[start]<=pivot)
			start++;

		// As long as the elements pointed by "end" are greater than pivot, we keep traversing
		while(A[end]>pivot)
			end--;

		// When both of the above "while" loops terminate, we swap the elements pointed by "start" and "end", unless 
		// they have violated the condition of start<end
		if(start<end)
			swap(&A[start],&A[end]);
	}

	// Finally when the loop terminates, we switch the pivot and the "end" element, and return the new index of pivot

	swap(&A[p],&A[end]);
	return end;
}

/*
	This function takes 3 arguments: 
		1. The array "A" to be sorted 
		2. The starting index of the array "p"
		3. The ending index of the array "r"

	It runs the partition routine recursively as long as the start index (p) is less than the 
	end index (r)
*/

void quicksort(int* A, int p, int r){
	if(p<r){
		// Initially the partitioning is done on the entire array
		int q = partition(A,p,r);

		// It is then run on the portions to the left and rigt of the partition

		quicksort(A,p,q-1); // Left portion

		quicksort(A,q+1,r); // Right portion
	}
}

// Utility function to print an array "A" of size "size"
void printArr(int *A, int size){
	for(int i=0;i<size;i++) printf("%d ",A[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int n; 
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int A[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }

    printf("Before sorting: ");
    printArr(A,n);

    quicksort(A,0,n-1); // In the first call, the start index is 0 and the end index is "n-1"

    printf("After sorting: ");
    printArr(A,n);

    return 0;
}