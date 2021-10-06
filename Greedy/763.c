/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void getInterval(int **interval, char *S)
{
	int flag[26] = {0};
	for(int i = 0; S[i] != '\0'; ++i){
		if(flag[(S[i]) - 'a'] == 0){
			interval[S[i]-'a'][0] = i;
		}else{
			interval[S[i]-'a'][1] = i;
		}
	}
}
int* partitionLabels(char * S, int* returnSize){
  int interval[26][2];
  getInterval(interval, S);
  int temp[500], num = 0;
  int prev = interval[S[0] - 'a'][1];
  for(int i = 1; S[i] != '\0'; ++i){
	  if(interval[S[i] - 'a'][1] > prev){
		  prev = interval[S[i] - 'a'][1];
	  }
	  if(i == prev){
		  temp[num++] = i;
	  }
  }
  returnSize = (int *)malloc(num * sizeof(int));
  for(int i = 0; i < num; ++i){
	  returnSize[i] = temp[i];
  }
  return returnSize;
}
