#### introduction

Solution of LeetCode problems. The order is according to "LeetCode 101" by Chang Gao

#### todo-list

- [x] Greedy
- [x] Two Pointers
- [ ] Binary Search
- [ ] Sort
- [ ] Search
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

680:

when meet difference, just delete one of them and check remain again



- premium problem 340 skip now



---

### Binary Search

69:

[Newton method](https://oi-wiki.org/math/newton/)

81:

- middle point $p_{mid} < p_{end}$,  we can make sure $p_{mid} \to p_{end}$ sort in non-decreasing order
- if $p_{mid} > p_{end}$, then $p_{start}\to p_{mid}$ sort in non-decreasing order
- if $p_{mid} = p_{end}$, both cases are possible, $p_{start}\to p_{mid}$ is the same. if $p_{start} \neq p_{mid}$, $p_{mid}\to p_{end}$ sort in non-decreasing order. if $p_{start} = p_{mid}$, we can't judge,  just incerase start

