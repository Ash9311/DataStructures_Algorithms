//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//recursively iterate through all the tasks and make a note of max for each day keeping the restriction of not doing the same task as that of prev day.
int f(int day,int last,vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day==0){ //if day is 0 its a base case. we are not having further calls, so just take the max of whatever u can
        int maxx=0;
        for(int task=0;task<3;task++){
            if(task!=last){ //exclude previously taken value
                maxx = max(maxx,points[0][task]); //get the max of all possible tasks
            }
        }
        return maxx;
    }
    if(dp[day][last]!=-1){
        return dp[day][last]; //return if its an overlapping sub problem
    }
    
    int maxx=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point = points[day][task] + f(day-1,task,points,dp); //add up current task points and recursively call for previous day passing task which was done
            maxx = max(maxx,point);
        }
    }
    return dp[day][last]=maxx; //memoize
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1)); //declare 2d vector of size 4 bcz for last day which is 3rd v must pass something
    return f(n-1,3,points,dp); //so we passed 3, there is no task as such since task are 0,1,2. since this is our first iteration we are not filtering any
}
