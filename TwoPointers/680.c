#include <string.h>
#include <stdlib.h>
#define bool int
bool isPalindrome(char * s, int left, int right){
	for(int i = left, j = right; i<=j; ++i, --j){
		if(s[i] != s[j])
			return 0;
	}
	return 1;
}
bool validPalindrome(char * s){
	int size = strlen(s);
	for(int i = 0, j = size-1; i <= j; ++i, --j){
		if(s[i]!= s[j]){
			return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
		}
	}return 1;
}
