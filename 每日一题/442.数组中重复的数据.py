#
# @lc app=leetcode.cn id=442 lang=python3
#
# [442] 数组中重复的数据
#

# @lc code=start
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for i, e in enumerate(nums.copy()):
            if nums[abs(e)-1] < 0:
                res.append(e)
            else:
                nums[abs(e)-1] = -nums[abs(e)-1]
            
        return res
# @lc code=end

