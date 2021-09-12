#include <math.h>
#define bool int
bool judgeSquareSum(int c){
    unsigned int right = (unsigned int)sqrt(c);
    unsigned int left = 0;
	while(left <= right){
	    unsigned int sum = left*left + right * right;
		if(sum == c)
			return 1;
		if(sum < c)
			left+=1;
		else
			right-=1;
	}
	return 0;
}
