#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        INT_32_MIN = -2**31
        INT_32_MAX = 2**31-1
        str_x = str(x)[::-1]
        x = int(str_x) if x >= 0 else -int(str_x[:-1])
        if x > INT_32_MAX or x < INT_32_MIN: return 0
        return x
# @lc code=end

