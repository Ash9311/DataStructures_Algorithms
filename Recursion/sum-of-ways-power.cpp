//https://www.geeksforgeeks.org/count-ways-express-number-sum-powers/
#include <bits/stdc++.h>
using namespace std;

// num is current num.
int countWaysUtil(int target, int n, int i)
{
    int sum = target - pow(i,n);
    if(sum==0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    //we have choice of considering current index or not. so all combinations will be computed
    return countWaysUtil(sum,n,i+1) + countWaysUtil(target,n,i+1);
}

// Returns number of ways to express
// x as sum of n-th power of two.
int countWays(int target, int n)
{
	return countWaysUtil(target, n, 1);
}

// Driver code
int main()
{
	int target = 100, n = 2;
	cout << countWays(target, n);
	return 0;
}
