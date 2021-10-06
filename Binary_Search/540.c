int singleNonDuplicate(int* nums, int numsSize){
    int left = 0, right = numsSize - 1;
	while(left < right){
		int middle = left + (right - left) / 2;
		if(middle % 2 == 0){
			if(nums[middle] == nums[middle+1])
				left = middle + 2;
			else if(nums[middle] == nums[middle - 1])
				right = middle - 2;
			else
				return nums[middle];
		}else{
            if(nums[middle] == nums[middle + 1])
				right = middle - 1;
			else if(nums[middle] == nums[middle - 1])
				left = middle + 1;
			else
				return nums[middle];
		}
	}
	return nums[left];
}
