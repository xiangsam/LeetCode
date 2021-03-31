#include <stdlib.h>
int candy(int *ratings, int ratingsSize) {
  long long sum = 0;
  int *candies = (int *)malloc(ratingsSize * sizeof(int));
  for (int i = 0; i < ratingsSize; ++i) {
    candies[i] = 0;
  }
  candies[0] = 1;
  for (int i = 1; i < ratingsSize; ++i) {
    if (ratings[i] > ratings[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    } else if (ratings[i] == ratings[i - 1]) {
      candies[i] = 1;
    } else {
      if (candies[i - 1] == 1) {
		  candies[i-1]++;
		  for(int j = i-2; j >= 0 && ratings[j] > ratings[j+1] && candies[j] <= candies[j+1]; --j){
			  candies[j]++;
		  }
      }
      candies[i] = 1;
    }
  }
  for (int i = 0; i < ratingsSize; ++i) {
    sum += candies[i];
  }
  return sum;
}
int candy2(int *ratings, int ratingsSize){
	int *candies = (int *)malloc(ratingsSize * sizeof(int));
	for(int i = 0; i < ratingsSize; ++i){
		candies[i] = 1;
	}
	for(int i = 1; i < ratingsSize; ++i){
		if(ratings[i] > ratings[i-1]){
			candies[i] = candies[i-1]+1;
		}
	}
	long long sum = candies[ratingsSize-1];
	for(int i = ratingsSize-2; i >= 0; --i){
		if(ratings[i] > ratings[i+1] && candies[i] < candies[i+1]){
			candies[i] = candies[i+1]+1;
		}
		sum += candies[i];
	}return sum;
}
