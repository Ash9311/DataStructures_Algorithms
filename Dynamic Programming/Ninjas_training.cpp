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


-----------
    //tabulation T.C->O(N*4*3) S.C->O(N*4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    //base condition as per bottom-up approach
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int day=1;day<n;day++){ //iterate through all the days
        for(int last=0;last<4;last++){ //iterate through all the lasts that u can have per day
            dp[day][last]=0;
            for(int task=0;task<3;task++){ //iterate through each tasks that can be performed based on condition and make a note of max
                if(task!=last){
                    int point = points[day][task] + dp[day-1][task]; //recurrence that we had used earlier would have been already computed in this bottom up approach.
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}

//space optimization  T.C->O(N*4*3) S.C->O(4)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,0);
    //base condition as per bottom-up approach
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            temp[last] = 0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    temp[last] = max(temp[last],points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
