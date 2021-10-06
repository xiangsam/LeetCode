int canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
  if (n == 0) {
    return 1;
  } else {
    int prev = -2, i;
    if (flowerbedSize == 1) {
      if (n == 1 && flowerbed[0] == 0) return 1;
      return 0;
    }
    for (i = 0; i < flowerbedSize - 1; ++i) {
      if (flowerbed[i] == 1)
        prev = i;
      else {
        if (prev != i - 1 && (flowerbed[i + 1] == 0)) {
          n--;
          prev = i;
          flowerbed[i] = 1;
        }
      }
      if (n == 0) return 1;
    }
    if (n == 1 && flowerbed[i] == 0 && flowerbed[i - 1] == 0) return 1;
    return 0;
  }
}
