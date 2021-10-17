// https://www.interviewbit.com/problems/pick-from-both-sides/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int sum=0;
    int res =0;

    for(int i=0;i<B;i++){
        res+=A[i];
    }
    sum=res;

    for(int i=0;i<B;i++){
        sum+=A[n-i-1];
        sum-=A[B-i-1];
        res = max(res,sum);
    }
    return res;
}
