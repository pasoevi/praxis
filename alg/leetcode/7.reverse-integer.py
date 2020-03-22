#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        xStr = "".join(reversed(str(x).strip("0") if len(str(x)) > 1 else str(x)))
        xNum = None
        if xStr.endswith("-"):
            xNum = int(xStr[0:-1], base=10) * -1
        else:
            xNum = int(xStr, base=10)
        return xNum if xNum >= pow(-2, 31) and xNum <= pow(2, 31) - 1 else 0

# @lc code=end

