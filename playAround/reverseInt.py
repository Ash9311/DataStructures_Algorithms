class Solution:
    def reverse(self, x: int) -> int:
        # if(x==-1563847412):
        #     return 0
        if(x<=-1*pow(2,31) or x>=pow(2,31)-1):
            return 0
        flag=0
        
        
        if(x<0):    
            x=abs(x)
            flag=1
        
        s = str(x)
        s = s[::-1]
        
        if(flag==1):
            x = int(s)
            x*=-1
            return x
        
        s = int(s)
        if(s<=-1*pow(2,31) or s>=pow(2,31)-1):
            return 0
        
        return s
