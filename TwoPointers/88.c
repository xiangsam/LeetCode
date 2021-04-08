#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int*)b;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = nums1Size-nums2Size; i < nums1Size; ++i){
        nums1[i] = nums2[i-nums1Size+nums2Size];
    }qsort(nums1, nums1Size, sizeof(int), cmp);
}
void merge2(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *p1 = nums1+nums1Size-nums2Size -1, *p2 = nums2+nums2Size-1;
	int index = nums1Size-1;
	while(index >=0 && (p1-nums1 >= 0 && p2 - nums2 >= 0)){
		if(*p1 > *p2){
			nums1[index--] = *(p1--);
		}else{
			nums1[index--] = *(p2--);
		}
	}while(p2-nums2 >=0){
		nums1[index--] = *(p2--);
	}
}
void merge3(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int index = nums1Size;
	while(index >0 && m > 0 && n > 0){
		if(nums1[m] > nums2[n]){
			nums1[--index] = nums1[--m];
		}else{
			nums1[--index] = nums2[--n];
		}
	}while(n >0){
		nums1[--index] = nums2[--n];
	}
}

