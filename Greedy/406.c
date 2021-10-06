#include <stdio.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void **aa, const void**bb)
{
	const int *a = (int *)*aa;
	const int *b = (int *)*bb;
	if(a[0] < b[0]){
		return -1;
	}else if(a[0] == b[0]){
		return a[1] - b[1];
	}else{
		return 1;
	}
}
int insertIndex(int **array, int size, int index)
{
	int t = -1;
	for(int i = 0; i < size; ++i){
		if(array[i] == NULL){
            ++t;
		}if(t == index){
			return i;
		}
	}
	return -1;
}
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = peopleSize;
    qsort(people, peopleSize, sizeof(int *), cmp);
	int **ans;
	ans = (int **)malloc(sizeof(int *) * peopleSize);
    *returnColumnSizes = (int *)malloc(sizeof(int*) * peopleSize);
	for(int i = 0; i < peopleSize; ++i){
		ans[i] = NULL;
        (*returnColumnSizes)[i] = 2;
	}
	int index = 0, mark = 0;
	if(peopleSize == 1){
		ans[0] = people[0];
		return ans;
	}
	ans[people[0][1]] = people[0];
	for(int i = 1; i < peopleSize; ++i){
		if(people[i][0] == people[i-1][0]){
            mark++;
            index = insertIndex(ans, peopleSize, people[i][1]-mark);
		}else{
			index = insertIndex(ans, peopleSize, people[i][1]);
            mark = 0;
		}ans[index] = people[i];
        
	}
    return ans;
}
