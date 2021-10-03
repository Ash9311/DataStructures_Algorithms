class Coordinates{
    int x;
    int y;
    int dist;
    Coordinates(int x,int y,int dist){
        this.x=x;
        this.y=y;
        this.dist=dist;
    }
}

class Solution
{
    //Function to find out minimum steps Knight needs to reach target position.
    
    public int minStepToReachTarget(int KnightPos[], int TargetPos[], int N)
    {
        // Code here
        
        boolean visited[][] = new boolean[N+1][N+1];
        int dx[]={-2,-2,-1,-1,1,1,2,2};
        int dy[]={-1,1,-2,2,-2,2,-1,1};
        Queue<Coordinates> q = new LinkedList<>();
        q.add(new Coordinates(KnightPos[0],KnightPos[1],0));
        while(!q.isEmpty()){
            Coordinates curr = q.remove();
            if(curr.x==TargetPos[0] && curr.y==TargetPos[1]){
                return curr.dist;
            }
            for(int i=0;i<8;i++){
                int x = curr.x + dx[i];
                int y = curr.y + dy[i];
                if(isSafe(x,y,N) && !visited[x][y]){
                    visited[x][y]=true;
                    q.add(new Coordinates(x,y,curr.dist+1));
                }
                
                
            }
        }
    return 0;
    }
    
    public boolean  isSafe(int x,int y,int n){
        return x>=1 && x<=n && y>=0 && y<=n;
    }
}
