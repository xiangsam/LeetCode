#### introduction

Solution of LeetCode problems. The order is according to "LeetCode 101" by Chang Gao

#### todo-list

- [x] Greedy
- [x] Two Pointers
- [x] Binary Search
- [x] Sort Algorithm
- [x] DFS,BFS
- [ ] Dynamic Programming

to see the Mathematical formula, please close the dark mode of github

---

### Greedy

435:(similar to 452)

选择最小的区间结尾则其他区间无法再放在它前面。

665:

不同情况下需要选择的局部最优解不同。 对于 ![](https://latex.codecogs.com/svg.latex?nums[i]<nums[i-1]), 需要决定修改谁作为局部最优解. 修改 ![](https://latex.codecogs.com/svg.latex?nums[i-1]) 更好一点, 因为可以留下更多的余地. 但如果 ![](https://latex.codecogs.com/svg.latex?nums[i-2]>nums[i]), 改变 ![](https://latex.codecogs.com/svg.latex?nums[i-1]) 就不可行了, 需要改变![](https://latex.codecogs.com/svg.latex?nums[i])



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

步骤：修改当前节点状态 $\rightarrow$ 递归子节点 $\rightarrow$ 回改当前节点状态



**reference:**   [全排列](https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/)



---

### Dynamic Programing

如果题目需求的是最终状态，那么使用动态搜索比较方便；如果题目需要输出所有的路径，那么使用带有状态记录的优先搜索会比较方便。

542:

一般来说，因为这道题涉及到四个方向上的最近搜索，所以很多人的第一反应可能会是广度
优先搜索。但是对于一个大小 O(mn) 的二维数组，对每个位置进行四向搜索，最坏情况的时间复
杂度（即全是 1）会达到恐怖的 O(m2n2)。一种办法是使用一个 dp 数组做 memoization，使得广
度优先搜索不会重复遍历相同位置；另一种更简单的方法是，我们从左上到右下进行一次动态搜
索，再从右下到左上进行一次动态搜索。两次动态搜索即可完成四个方向上的查找。

221:

对于在矩阵内搜索正方形或长方形的题型，一种常见的做法是定义一个二维 dp 数组，其中
dp[i][j] 表示满足题目条件的、以 (i, j) 为右下角的正方形或者长方形的属性。

300:

本题还可以使用二分查找将时间复杂度降低为 O(n log n)。我们定义一个 dp 数组，其中 dp[k]
存储长度为 k+1 的最长递增子序列的最后一个数字。我们遍历每一个位置 i，如果其对应的数字
大于 dp 数组中所有数字的值，那么我们把它放在 dp 数组尾部，表示最长递增子序列长度加 1；
如果我们发现这个数字在 dp 数组中比数字 a 大、比数字 b 小，则我们将 b 更新为此数字，使得
之后构成递增序列的可能性增大。以这种方式维护的 dp 数组永远是递增的，因此可以用二分查找加速搜索

1143:

对于子序列问题，第二种动态规划方法是，定义一个 dp 数组，其中 dp[i] 表示到位置 i 为止
的子序列的性质，并不必须以 i 结尾。这样 dp 数组的最后一位结果即为题目所求，不需要再对每
个位置进行统计。
在本题中，我们可以建立一个二维数组 dp，其中 dp[i][j] 表示到第一个字符串位置 i 为止、到
第二个字符串位置 j 为止、最长的公共子序列长度。这样一来我们就可以很方便地分情况讨论这
两个位置对应的字母相同与不同的情况了