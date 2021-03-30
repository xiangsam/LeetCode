#include <stdlib.h>
int cmp(const void *aa, const void *bb) {
  const int *a = (int *)aa;
  const int *b = (int *)bb;
  return *a - *b;
}

int findContentChildren(int *g, int gSize, int *s, int sSize) {
  qsort(g, gSize, sizeof(int), cmp);
  qsort(s, sSize, sizeof(int), cmp);
  int *flag = NULL;
  flag = (int *)malloc(sSize * sizeof(int));
  for (int i = 0; i < sSize; ++i) {
    flag[i] = 0;
  }
  int ans = 0;
  for (int i = 0; i < gSize; ++i) {
    for (int j = 0; j < sSize; ++j) {
      if (s[j] >= g[i] && flag[j] == 0) {
        flag[j] = 1;
        ans++;
        break;
      }
    }
  }
  return ans;
}
int findContentChildren_2(int *g, int gSize, int *s, int sSize) {
  qsort(g, gSize, sizeof(int), cmp);
  qsort(s, sSize, sizeof(int), cmp);
  int ans = 0;
  int i = 0, j = 0;
  while (i < gSize && j < sSize) {
    if (g[i] <= s[j]) {
      ans++;
      i++;
    }
    j++;
  }
  return ans;
}
