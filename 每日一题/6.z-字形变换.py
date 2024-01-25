#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        ans = ''
        matrix = ['' for i in range(numRows)]
        print(matrix)
        i, step = 0, -1
        for c in s:
            matrix[i] += c
            if i == 0 or i == numRows - 1:
                step = -step
            i += step
        return ''.join(matrix)
# @lc code=end

