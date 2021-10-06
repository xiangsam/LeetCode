#include <stdlib.h>
int cmp(const void **aa, const void **bb)
{
	const int *a = (int *)(*aa);
	const int *b = (int *)(*bb);
	return a[1] - b[1];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
	if(intervalsSize <= 1){
		return 0;
	}
	qsort(intervals, intervalsSize, *intervalsColSize * sizeof(int), cmp);
	int prev = intervals[0][1];
	int ans = 0;
	for(int i = 1; i < intervalsSize; ++i){
		if(intervals[i][0] < prev){
			ans++;
		}else{
			prev = intervals[i][1];
		}
	}return ans;
}
