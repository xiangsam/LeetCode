#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
	int k = *a;
	*a = *b;
	*b = k;
}

void quickSort(int array[], int first, int end){
	/*
	 * Quick sort algorithm
	 * valid index is in [first, end]
	 * T(n) = 2T(n/2) + n, so time complexity is O(nlogn)
	 * Tail recursion, space complexity is O(log n)
	 */
	if(first >= end) return;
	int l = first, r =end; //l must be first, first+1 is wrong for [1,3,2]
	int pivot = array[first];
	while(l < r){
        while(r > l && array[r] >= pivot) r--;//when pivot is in left, r decreases first 
		while(l < r && array[l] <= pivot) l++;
        swap(&array[l], &array[r]);
	}
	swap(&array[l], &array[first]);
    quickSort(array, first, l-1);
	quickSort(array, l+1, end);
}

void mergeSort(int array[], int first, int end){
	/*
	 * Merge sort algorithm
	 * valid index is in [first, end]
	 */
	if(first >= end) return;
	int mid = first + (end - first) / 2;
	mergeSort(array, first, mid);
	mergeSort(array, mid+1, end);
	int * temp = (int *)malloc(sizeof(int) * (end - first + 1));
	int i = first, j = mid+1;
	int index = 0;
	while(i <= mid && j <= end){
		if(array[i] < array[j])
			temp[index++] = array[i++];
		else
			temp[index++] = array[j++];
	}
	while(i <= mid) temp[index++] = array[i++];
	while(j <= end) temp[index++] = array[j++];
	for(int k = 0; k < index; ++k)
		array[first+k] = temp[k];
	free(temp);
}


void print(int array[], int arraySize){
	for(int i = 0; i < arraySize;++i)
		printf("%d ", array[i]);
}

int main()
{
	int array[] = {6, 5, 2, 7, 3, 9, 8, 4, 10, 1};
	int arraySize = 10;
	//quickSort(array, 0, arraySize-1);
	mergeSort(array, 0, arraySize-1);
	print(array, arraySize);
	return 0;
}
