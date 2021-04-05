int checkPossibility(int* nums, int numsSize){
    int changed = 0;
	if(numsSize == 1)
		return 1;
	for(int i = 1; i < numsSize; ++i){
		if(nums[i] < nums[i-1]){
			if(i-2 < 0 || nums[i-2] <= nums[i]){
				nums[i-1] = nums[i];
			}else{
				nums[i] = nums[i-1];
			}
			if(changed == 0)
				changed = 1;
			else
				return 0;
		}
	}return 1;
}
