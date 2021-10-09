#### introduction

Solution of LeetCode problems. The order is according to "LeetCode 101" by Chang Gao

#### todo-list

- [x] Greedy
- [x] Two Pointers
- [x] Binary Search
- [x] Sort Algorithm
- [ ] DFS,BFS
- [ ] Dynamic Programming

to see the Mathematical formula, please close the dark mode of github

---

### Greedy

435:(similar to 452)

At first I am confused with the fact that you can simply focus on the end of interval. Once I notice that choose the minimum end meaning another intervals is unable to put in front of it, the solution is naturally

665:

This problem is special because the locally optimal solution differs. if we get ![](https://latex.codecogs.com/svg.latex?nums[i]<nums[i-1]), we need to decide change which one to get the locally optimal solution. Changing ![](https://latex.codecogs.com/svg.latex?nums[i-1]) is prefered, as it can give larger space for the remain. But if ![](https://latex.codecogs.com/svg.latex?nums[i-2]>nums[i]), changing ![](https://latex.codecogs.com/svg.latex?nums[i-1]) can't work, we need to change ![](https://latex.codecogs.com/svg.latex?nums[i])



----

### Two pointers

142:

we need to [detect cycle](https://en.wikipedia.org/wiki/Cycle_detection) in linked-list.  Floyd's cycle detection aligorithm is useful.

We can create two pointer point to head. The fast pointer move two steps at a time and the slow pointer move one step at a time. The linked-list is finite. if the fast pointer could move infinitely, we can get the conclusion that there is a loop. That also means the two pointers will meet in the loop. Once they meet, we move the fast pointer to head, and let it move one step at a time. The place they meet again is where the loop started.

the proof is [here](https://leetcode-cn.com/problems/linked-list-cycle-lcci/solution/huan-lu-jian-ce-by-leetcode-solution-s2la/)

680:~~~~

when meet difference, just delete one of them and check remain again



- premium problem 340 skip now



---

### Binary Search

`find the case that you can choose one side by comparing middle with something`

69:

[Newton method](https://oi-wiki.org/math/newton/)

81:

- middle point $p_{mid} < p_{end}$,  we can make sure $p_{mid} \to p_{end}$ sort in non-decreasing order
- if $p_{mid} > p_{end}$, then $p_{start}\to p_{mid}$ sort in non-decreasing order
- if $p_{mid} = p_{end}$, both cases are possible, $p_{start}\to p_{mid}$ is the same. if $p_{start} \neq p_{mid}$, $p_{mid}\to p_{end}$ sort in non-decreasing order. if $p_{start} = p_{mid}$, we can't judge,  just incerase start

154:

![154](./picture_dir/154.png)

compare nums[middle] with nums[end], and judge which part to choose.

[solution](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-de-zui--16/)

4:

the problem can be regard as find k-th large number in two sorted array



----

### Sort Algorithm

215:

**quick select algorithm**: find k-th largest/smallest element int unsorted array

Time complexity: O(n)

when we swap pivot point and l(l==r) in quick sort algorithm, we can make sure pivot point is x-th largest number in the array, so we can throw one side array when search target

347, 451:

**Bucket sort algorithm**

unordered_map is useful to count character's frequency in CPP



---

### DFS and BFS

#### DFS

we usually accomplish depth-first search with stack struction or  recursion equally.

DFS is also useful in detecting cycle.

695:

There are two ways to write DFS in recursion, search next->check valid or check valid-> search next.



46:

回溯法，常用于解决排列，组合，选择类问题

步骤：修改当前节点状态 $\rightarrow$ 递归字节点 $\rightarrow$ 回改当前节点状态



**reference:**   [全排列](https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/)





