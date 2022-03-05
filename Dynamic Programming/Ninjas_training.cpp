//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
int f(int day,int last,vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day==0){
        int maxx=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxx = max(maxx,points[0][task]);
            }
        }
        return maxx;
    }
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    
    int maxx=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point = points[day][task] + f(day-1,task,points,dp);
            maxx = max(maxx,point);
        }
    }
    return dp[day][last]=maxx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
}
