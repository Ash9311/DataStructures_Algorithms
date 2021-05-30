def maxSumSubArray(a):
    maxx = 0
    curr = 0

    for i in range(len(a)):
        curr += a[i]
        if(curr>maxx):
            maxx = curr
        
        if(curr<0):
            curr=0
    return maxx


a= [1,-2,2,-3,44,-1,41]
print(maxSumSubArray(a))


