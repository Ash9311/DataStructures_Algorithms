
#include<bits/stdc++.h>
using namespace std;

bool nQueen(int board[][], int row){
    if(row==N){
        return true;
    }
    for(int col=0;col<N;col++){
        if(isSafe(board,row,col)){
            board[row][col] = 1;
            if(nQueen(board,row+1)){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}

int main() {


}
