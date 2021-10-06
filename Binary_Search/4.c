#define min(a,b) a>b?b:a
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int total = nums1Size + nums2Size;
	double ans;
	if(total % 2 == 1)
		ans = findKth(nums1, 0, nums1Size-1, nums2, 0, nums2Size-1, total / 2+1);
	else
		ans = (findKth(nums1, 0, nums1Size-1, nums2, 0, nums2Size-1, total/2) +
				findKth(nums1, 0, nums1Size-1, nums2, 0 , nums2Size-1, total/2+1))/2.0;
	return ans;
}

int findKth(int* nums1, int n1_head, int n1_tail, int* nums2, int n2_head, int n2_tail, int k){
    int len1 = n1_tail - n1_head + 1;
	int len2 = n2_tail - n2_head + 1;
	if(len1 == 0)
		return nums2[n2_head + k - 1];
	if(len2 == 0)
		return nums1[n1_head + k - 1];
	if(k == 1)
		return min(nums1[n1_head], nums2[n2_head]);
	else{
		int i = n1_head + (min(len1, k/2)) - 1;
		int j = n2_head + (min(len2, k/2)) - 1;
		if(nums1[i] > nums2[j])
			return findKth(nums1, n1_head, n1_tail, nums2, j+1, n2_tail, k-(j+1-n2_head));
		else
			return findKth(nums1, i+1, n1_tail, nums2, n2_head, n2_tail, k-(i+1-n1_head));
	}
}
