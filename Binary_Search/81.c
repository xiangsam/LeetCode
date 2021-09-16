#define bool int

bool search(int* nums, int numsSize, int target){
    int start = 0, end = numsSize - 1;
	while(start <= end){
		int middle = start + (end - start) / 2;
		if(nums[middle] == target)
			return 1;
		if(nums[start] == nums[middle])
			start++;
		else if(nums[middle] <= nums[end]){
			if(target <= nums[end] && target > nums[middle])
				start = middle + 1;
			else
				end = middle - 1;
		}else{
			if(target  >= nums[start] && target < nums[middle])
				end = middle - 1;
			else
				start = middle + 1;
		}
	}
	return 0;
}
