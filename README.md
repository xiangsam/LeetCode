#### introduction

Solution of LeetCode problems. The order is according to "LeetCode 101" by Chang Gao

#### todo-list

- [x] Greedy
- [ ] Two Pointers
- [ ] Binary Search
- [ ] Sort
- [ ] Search
- [ ] Dynamic Programming




---

### Greedy

435:(similar to 452)

At first I am confused with the fact that you can simply focus on the end of interval. Once I notice that choose the minimum end meaning another intervals is unable to put in front of it, the solution is naturally

665.c:

This problem is special because the locally optimal solution differs. if we get ![](https://latex.codecogs.com/svg.latex?nums[i]<nums[i-1]), we need to decide change which one to get the locally optimal solution. Changing ![](https://latex.codecogs.com/svg.latex?nums[i-1]) is prefered, as it can give larger space for the remain. But if ![](https://latex.codecogs.com/svg.latex?nums[i-2]>nums[i]), changing ![](https://latex.codecogs.com/svg.latex?nums[i-1]) can't work, we need to change ![](https://latex.codecogs.com/svg.latex?nums[i])

