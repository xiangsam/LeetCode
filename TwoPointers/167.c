#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	*returnSize = 2;
    int *p = NULL, *q = NULL;
	for(p = numbers, q = numbers + numbersSize - 1; p < q;){
		int sum = *p + *q;
		if(sum == target)break;
		else if(sum < target)
			p++;
		else
			q--;
	}
	int *ans = (int *)malloc(sizeof(int)*2);
	ans[0] = p-numbers + 1;
	ans[1] = q-numbers + 1;
	return ans;
}
