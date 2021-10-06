#include <stdio.h>
#include <string.h>
char * findLongestWord(char * s, char ** dictionary, int dictionarySize){
    char * select = "";
	int sLen = strlen(s);
	for(int i = 0; i < dictionarySize; ++i){
        char *bs = dictionary[i];
        int bsLen = strlen(bs);
		if(bsLen > sLen)
			continue;
		int r = 0;
		for(int l = 0; l < sLen && r < bsLen;++l){
			if(s[l] == bs[r])
				r++;
		}
		if(r == bsLen){
			if(bsLen > strlen(select))
				select = bs;
			else if(bsLen == strlen(select) && strcmp(bs, select) < 0){
				select = bs;
			}
		}
	}
	return select;
}
