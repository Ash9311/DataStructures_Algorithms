  //https://practice.geeksforgeeks.org/contest/job-a-thon-11-hiring-challenge/problems/#
  //suppose the grid is of (4*3) take the minimum row or col. here it is '3' and then u can color 3*3. after coloring the grid becomes (1*3). recursively
  //move forward adding up +1 as numnber of moves. and when row==col u r done.
  
 class Solution {
  public:
  
  int solve(int A,int B){
      if(A==B){
          return 1;
      }
      int minn = min(A,B);
      if(A<B){
          return 1+solve(A,B-A);
      }
       return 1+solve(A-B,B);
  }
  
    int minimumMoves(int A, int B) {
        return solve(A,B);
    }
};
