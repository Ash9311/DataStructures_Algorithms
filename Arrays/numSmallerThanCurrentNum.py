class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        result=[]
        clone = nums.copy()
        nums.sort()
        for i in clone:
            result.append(nums.index(i))
            
        return result
