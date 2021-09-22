#include <stdio.h>
#include <stdlib.h>
struct Node{
    int num;
	int freq;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* aa, const void* bb)
{
    struct Node* a = (struct Node *)aa;
	struct Node* b = (struct Node *)bb;
	if(a->freq != b->freq)
		return b->freq - a->freq;
	else
		return a->num - b->num;
}
int cmp2(const void *aa, const void *bb)
{
	int *a = (int *)aa;
	int *b = (int *)bb;
	return *a - *b;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
	qsort(nums, numsSize, sizeof(int),cmp2);
    struct Node *array = (struct Node *) malloc(numsSize*sizeof(struct Node));
	for(int i =0; i < numsSize; ++i){
		array[i].freq = 0;
	}
	int max = 0;
	int index = 0;
	array[0].num = nums[0];
	array[0].freq = 1;
	for(int i = 1; i < numsSize; ++i){
		if(array[index].num != nums[i])
			array[++index].num = nums[i];
		array[index].freq++;
		if(max < array[index].freq){
			max = array[index].freq;
		}
	}
    qsort(array, numsSize, sizeof(struct Node), cmp);
    int * list = (int *)malloc(sizeof(int)*k);
	for(int i = 0; i < k; ++i){
		list[i] = array[i].num;
	}
	free(array);
	*returnSize = k;
	return list;
}
