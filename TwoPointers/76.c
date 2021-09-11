#include <stdio.h>
#include <string.h>
char * minWindow(char * s, char * t){
    int count = 0;
	int tCount[128] = {0};
	int flag[128] = {0};
    int m = strlen(s);
	int n = strlen(t);
	for(int i = 0; i < n; ++i){
		flag[t[i]] = 1;
		++tCount[t[i]];
	}
    int l = 0;
	int winSize = m+1, winL = 0;
	for(int r = 0; r < m; ++r){
		if(flag[s[r]] && --tCount[s[r]] >= 0){
				count++;
	    }
		while(count == n){
			if(r-l+1 < winSize){
                winL = l;
				winSize = r-l+1;
			}
            if(flag[s[l]] && ++tCount[s[l]] > 0)
				--count;
			l++;
		}
    }
	if(winSize > m)
		return "";
	char* substr =  s+winL;
	*(substr + winSize) = '\0';
	return substr;
}
