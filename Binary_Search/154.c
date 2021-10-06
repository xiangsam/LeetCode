int findMin(int* nums, int numsSize){
    int left = 0, right = numsSize - 1;
	while(left < right){
		int middle = left + (right - left) / 2;
		if(nums[middle] > nums[right])
			left = middle+1;
		else if(nums[middle] < nums[right])
			right = middle; //if nums[middle] < nums[right], nums[middle] may be min number
		else
			right -= 1;
	}
	return nums[left];
}
