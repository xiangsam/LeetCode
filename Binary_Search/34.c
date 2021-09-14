/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int BS(int *num, int numsSize, int target){
	int l = 0, r = numsSize - 1;
	while(l <= r){
		int m = l + (r-l)/2;
		if(num[m] == target)
			return m;
		if(num[m] < target)
			l = m+1;
		else
			r = m-1;
	}
	return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int index = BS(nums, numsSize, target);
	*returnSize = 2;
	int * array = (int *)malloc(*returnSize * sizeof(int));
	if(index == -1){
		array[0] = -1;
        array[1] = -1;
		return array;
	}
    int l = index, r = index;
	while(l >= 0 && nums[l] == target) l--;
	while(r < numsSize && nums[r] == target) r++;
	array[0] = l+1;
	array[1] = r-1;
	return array;
}
