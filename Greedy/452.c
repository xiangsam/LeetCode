int cmp(const void **aa, const void **bb) {
  const int *a = (int *)*aa;
  const int *b = (int *)*bb;
  if (a[1] < b[1]) return -1;
  return 1;
}
int findMinArrowShots(int **points, int pointsSize, int *pointsColSize) {
  if (pointsSize == 0) return 0;
  qsort(points, pointsSize, sizeof(int *), cmp);
  int prev = points[0][1];
  int ans = 1;
  for (int i = 1; i < pointsSize; ++i) {
    if (points[i][0] > prev) {
      ans++;
      prev = points[i][1];
    }
  }
  return ans;
}
