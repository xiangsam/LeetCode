#### introduction

Solution of LeetCode problems. The order is according to "LeetCode 101" by Chang Gao

#### todo-list

- [x] Greedy
- [x] Two Pointers
- [x] Binary Search
- [x] Sort Algorithm
- [x] DFS,BFS
- [x] Dynamic Programming
- [x] Divide Conquer
- [x] Math
- [x] Bit_Ops
- [x] Data_Structure
- [x] String
- [x] Linked_List
- [x] Tree
- [x] Graph
- [x] Additional Structure


---

### Greedy

435:(similar to 452)

选择最小的区间结尾则其他区间无法再放在它前面。

665:

不同情况下需要选择的局部最优解不同。 对于$nums[i]< nums[i-1]$, 需要决定修改谁作为局部最优解. 修改$nums[i-1]$更好一点, 因为可以留下更多的余地. 但如果 $nums[i-2]>nums[i]$, 改变$nums[i-1]$就不可行了, 需要改变$nums[i]$



----

### Two pointers

142:

we need to [detect cycle](https://en.wikipedia.org/wiki/Cycle_detection) in linked-list.  Floyd's cycle detection aligorithm is useful.

We can create two pointer point to head. The fast pointer move two steps at a time and the slow pointer move one step at a time. The linked-list is finite. if the fast pointer could move infinitely, we can get the conclusion that there is a loop. That also means the two pointers will meet in the loop. Once they meet, we move the fast pointer to head, and let it move one step at a time. The place they meet again is where the loop started.

the proof is [here](https://leetcode-cn.com/problems/linked-list-cycle-lcci/solution/huan-lu-jian-ce-by-leetcode-solution-s2la/)

680:

when meet difference, just delete one of them and check remain again



- premium problem 340 skip now



---

### Binary Search

`find the case that you can choose one side by comparing middle with something`

69:

[Newton method](https://oi-wiki.org/math/newton/)

81:

- middle point $p_{mid}<p_{end}$,  we can make sure $p_{mid} \to p_{end}$ sort in non-decreasing order
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


---
### 背包问题：

背包问题是一种组合优化的 NP 完全问题：有 N 个物品和容量为 W 的背包，每个物品都有
自己的体积 w 和价值 v，求拿哪些物品可以使得背包所装下物品的总价值最大。如果限定每种物
品只能选择 0 个或 1 个，则问题称为 0-1 背包问题；如果不限定每种物品的数量，则问题称为无
界背包问题或完全背包问题。

#### 0-1 背包问题：

以 0-1 背包问题为例。我们可以定义一个二维数组 dp
存储最大价值，其中 dp[i][j] 表示前 i 件物品体积不超过 j 的情况下能达到的最大价值。在我们遍
历到第 i 件物品时，在当前背包总容量为 j 的情况下，如果我们不将物品 i 放入背包，那么 dp[i][j]
= dp[i-1][j]，即前 i 个物品的最大价值等于只取前 i-1 个物品时的最大价值；如果我们将物品 i 放
入背包，假设第 i 件物品体积为 w，价值为 v，那么我们得到 dp[i][j] = dp[i-1][j-w] + v。我们只需
在遍历过程中对这两种情况取最大值即可，总时间复杂度和空间复杂度都为 O(NW)。
![Screenshot from 2022-05-21 11-15-14.png](https://s2.loli.net/2022/05/21/MJVCo4xPIWcESiz.png)

#### 空间压缩

我们可以去掉 dp 矩阵的第一个维度，在考虑物品 i 时变成 dp[j]
= max(dp[j], dp[j-w] + v)。这里要注意我们在遍历每一行的时候必须逆向遍历，这样才能够调用
上一行物品 i-1 时 dp[j-w] 的值；若按照从左往右的顺序进行正向遍历，则 dp[j-w] 的值在遍历到
j 之前就已经被更新成物品 i 的值了。

#### 无界背包问题

![Screenshot from 2022-05-21 11-12-58.png](https://s2.loli.net/2022/05/21/O1PeAs7KIXLrjGx.png)

在完全背包问题中，一个物品可以拿多次。如图上半部分所示，假设我们遍历到物品 i = 2，
且其体积为 w = 2，价值为 v = 3；对于背包容量 j = 5，最多只能装下 2 个该物品。那么我们的状
态转移方程就变成了 dp[2][5] = max(dp[1][5], dp[1][3] + 3, dp[1][1] + 6)。如果采用这种方法，假设
背包容量无穷大而物体的体积无穷小，我们这里的比较次数也会趋近于无穷大，远超 O(NW) 的
时间复杂度。
怎么解决这个问题呢？我们发现在 dp[2][3] 的时候我们其实已经考虑了 dp[1][3] 和 dp[2][1]
的情况，而在时 dp[2][1] 也已经考虑了 dp[1][1] 的情况。因此，如图下半部分所示，对于拿多个
物品的情况，我们只需考虑 dp[2][3] 即可，即 dp[2][5] = max(dp[1][5], dp[2][3] + 3)。这样，我们
就得到了完全背包问题的状态转移方程：dp[i][j] = max(dp[i-1][j], dp[i][j-w] + v)，其与 0-1 背包问
题的差别仅仅是把状态转移方程中的第二个 i-1 变成了 i。

#### 空间压缩

同样的，我们也可以利用空间压缩将时间复杂度降低为 O(W)。这里要注意我们在遍历每一
行的时候必须正向遍历，因为我们需要利用当前物品在第 j-w 列的信息

---


650：

除了常规的DP解法，这题还可以使用数学方法。得到N个'A'的方法为[CP..][CP...]，操作数分别为$g_{1}， g_{2}$，第一组得到$g_{1}$个'A'，再结合第二组操作可以得到$g_{1}g_{2}$个'A'，因此N = $g_{1}g_{2}...$。若$g_{i} = pq$，则该组操作可以分为两个子组，操作数从pq变为p+q，对$p \geq 2, q\geq 2$，显然$pq \geq p+q$。因此，问题转为求N的质因子之和。

使用埃氏筛求小于N的质因子：
```
vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    vector<int> prime;
    for (int i = 2; i <= n; ++i) { //埃氏筛
      if (is_prime[i]) {
        prime.push_back(i);
        for (int j = 2 * i; j <= n; j += i) {
          is_prime[j] = false;
        }
      }
    }
```

72:

需要仔细考虑*的匹配情况。能匹配/不能匹配， 如何匹配.


###  Data Structure
#### 单调栈与优先队列
**优先队列**：优先队列是一种抽象数据类型，其基本操作包括插入元素和移除优先级最高的元素。优先队列通常用堆（Heap）来实现，它可以快速地执行以下操作：

- 插入元素：通常时间复杂度是 O(log n)。
- 移除和访问优先级最高的元素：通常时间复杂度是 O(1)。

优先队列适用的场景通常包括：

- 需要经常插入元素并按特定顺序（如最小或最大）移除元素的场合。
- 需要合并多个有序的数据流。

**单调栈**：单调栈是一种特殊的栈结构，其主要特点是它内部的元素保持单调性。根据问题的需求，单调栈可以是单调递增或单调递减的。单调栈主要用于：

- 时间复杂度通常是 O(n)，因为每个元素最多只会进栈和出栈一次。

单调栈适用的场景通常包括：

- 需要找到每个元素的下一个更大（或更小）元素的场合。
- 需要处理具有某种单调性质的问题，例如股票价格问题，其中需要找到每一天之后的更高价格。

#### KMP算法
快速查找子串的算法。
核心思想：记忆匹配的子串，从而在模式串上实现跳跃匹配。
跳跃多少？模式串构建next数组,表示模式串的首“尾”相同位置。当前模式串位置 j+1 匹配失败，则模式串跳跃到j=next[j]
相关例题：214

#### 树状数组与线段树
相关例题: 307

---
### Tree
#### 从前、中、后序遍历恢复树
- 前+中：pre_start, pre_end, in_start, in_end。使用pre_start为根节点找到其在中序遍历中的位置，在中序遍历中确定左右子树长度。
- 后+中：post_start, post_end, in_start, in_end。使用post_end为根节点找到其在中序遍历中的位置，在中序遍历中确定左右子树长度。
- 前+后：pre_start, pre_end, post_start, post_end。pre_start+1为左子树根节点，找到其在后序遍历中的位置，从而结合post_start确定左子树长度。

#### 前中后序遍历迭代写法
- 前序
  ```c++
  stack<TreeNode *> stk;
    vector<int> ans;
    TreeNode *ptr = root;
    while (ptr || !stk.empty()) {
      while (ptr) {
        stk.emplace(ptr->right);
        ans.emplace_back(ptr->val);
        ptr = ptr->left;
      }
      ptr = stk.top();
      stk.pop();
    }
  ```
- 中序
  ```c++
  stack<TreeNode *> stk;
    vector<int> ans;
    TreeNode *ptr = root;
    while (ptr || !stk.empty()) {
      while (ptr) {
        stk.emplace(ptr);
        ptr = ptr->left;
      }
      ptr = stk.top();
      stk.pop();
      ans.emplace_back(ptr->val);
      ptr = ptr->right;
    }
    return ans;
  ```
- 后序
  ```c++
  stack<TreeNode *> stk;
    vector<int> ans;
    TreeNode *ptr = root;
    while (ptr || !stk.empty()) {
      while (ptr) {
        ans.emplace_back(ptr->val);
        stk.emplace(ptr->left);
        ptr = ptr->right;
      }
      ptr = stk.top();
      stk.pop();
    }
    reverse(ans.begin(), ans.end());
  ```
  ```c++
  stack<TreeNode *> stk;
    TreeNode *ptr = root;
    vector<int> ans;
    unordered_map<TreeNode *, bool> visited;
    while (ptr || !stk.empty()) {
      while (ptr) {
        stk.emplace(ptr);
        visited[ptr] = false;
        ptr = ptr->left;
      }
      while (!stk.empty() && visited[stk.top()]) {
        ans.emplace_back(stk.top()->val);
        stk.pop();
      }
      if (!stk.empty()) {
        ptr = stk.top()->right;
        visited[stk.top()] = true;
      }
    }
  ```
  
---
### Graph
#### 最小生成树MST
最小生成树是**加权无向图**中边权值之和最小的生成树。
- 生成树是指包含图中所有顶点，且结构形成一棵树的子图（即没有环，并且连通）

例题：1135
- Prim算法
- Kruskal算法
  - 并查集（路径压缩，按秩合并优化）
  
#### 最短路径
当图边权重非负时 -> Dijkstra算法


---
#### 并查集
并查集（union-ﬁnd, 或 disjoint set）可以动态地连通两个点，并且可以非常快速地判断两个点是否连通。假设存在 n 个节点，我们先将所有节点的父亲标为自己；每次要连接节点 i 和 j时， 我们可以将 i 的父亲标为 j；每次要查询两个节点是否相连时，我们可以查找 i 和 j 的祖先先是否最终为同一个人。
- 路径压缩：让所有节点直接指向祖先节点
- 按秩合并优化

#### LRU缓存
最少最近使用缓存(LRU)：每次将信息插入未满的缓存的时候，以及更新或查找一个缓存内存在的信息的时候，将该信息标为最近使用。在缓存满的情况下将一个新信息插入的时候，需要移除最旧的信息，插入新信息，并将该信息标为最近使用。

实现：双向链表(list)+哈希表
- c++中list基础实现就是双向链表，其内存空间不连续。
- list 不允许通过下标访问。

#### 平衡树(B-Tree)，红黑树(RB-Tree)
- 红黑树是一种自平衡的二叉搜索树
- `std::set`, `std::map`, `std::multiset`, `std::multimap`容器实现都是用了红黑树，其元素永远遵循一个严格的排序。默认排序为`less<T>`
  - 使用 `std::greater` 作为排序准则，元素会按照降序排列`std::set<int, std::greater<int>> descendingSet`
  - 对map, multimap是按照键key进行排列。
  - 对multiset, multimap会保持稳定的插入顺序。
  - multimap不提供`operator[]`
- `std::unordered_set`, `std::unordered_map`内部实现则为哈希表


---
### 每日一题

- 2846： 求树的LCA，tarjan离线算法
- 365: 水壶问题。递归+状态模拟 或 最小公倍数+贝祖定理
- 514: 动态规划，很适合练习动态规划的状态定义和状态转移 
- 2808:
  对于这个问题，直觉上可能会想到贪心或动态规划，因为这两种策略在很多最优化问题中都很实用。然而，对于这个特定问题，贪心和动态规划可能并不是正确的策略，或者至少不是直接可用的策略，因为这个问题有一个关键的性质：我们在任何时刻都可以选择任意一个元素来替换任意一个位置的元素，这导致了状态转移的复杂性。贪心算法可能会在每一步尝试采取最佳的即时选择，但在这个问题中，一个最佳的即时选择可能并不会导致全局的最优解，因为早期的选择可能会限制后续的操作。动态规划通常用于求解具有明确的递推关系和重叠子问题的问题。在这个问题中，由于每次操作都可以基于前一秒的任何一种状态，可能的状态太多，这使得动态规划的状态定义和状态转移都变得非常困难。

- 322, 518：两道题都是使用动态规划，但是322的目标是最小化硬币数，518的目标是组合问题，因此写法会有所不同!!!