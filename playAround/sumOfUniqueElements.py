class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        res=0
        for i in nums:
            if(nums.count(i)==1):
                res+=i
        return res
