int findKthLargest(int* nums, int numsSize, int k){
    int first = 0, end = numsSize - 1;
	k -= 1;
	while(first < end){
		int pivot_index = quickSelect(nums, first, end);
		if(pivot_index == k)
			return nums[pivot_index];
		if(pivot_index < k)
			first = pivot_index + 1;
		else
			end = pivot_index - 1;
	}
	return nums[first];
}
void swap(int *a, int *b){
	int k  =*a;
	*a = *b;
	*b = k;
}
int quickSelect(int *nums, int first, int end)
{
	int pivot = nums[end];
	int l = first, r =end;
	while(l < r){
		while(l < r && nums[l] >= pivot) l++;
		while(l < r && nums[r] <= pivot) r--;
		swap(&nums[l], &nums[r]);
	}
	swap(&nums[end], &nums[l]);
	return l;
}
