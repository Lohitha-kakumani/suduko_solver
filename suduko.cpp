#include<iostream>
#include<math.h>
using namespace std;

void Print(int board[][9], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j]<< " " ;
        }
        cout << endl;
    }
    cout << endl;
}

bool isValid(int board[][9], int i, int j, int num, int n){
    //checking the rows
    for(int x =0;x<n;x++){
        if(board[i][x] == num){
            return false;
        }
    }
    //checking the columns
    for(int x =0;x<n;x++){
        if(board[x][j] == num){
            return false;
        }
    }

    //checking matrix
    int rn = sqrt(n);
    int si = i-i%rn;
    int sj = j-j%rn;

    for(int x =si;x<si+rn;x++){
        for(int y=sj;y<sj+rn;y++){
            if(board[x][y] == num){
                return false;
            }
        }
    }

    return true;
}

bool SudukoSolver(int board[][9], int i, int j, int n){
    if( i == n){
        Print(board,n);
        return true;
    }

    //out of board means 
    if(j==n){
        return SudukoSolver(board,i+1,0,n);
    }

    //if cell is filled
    if(board[i][j] !=0 ){
        return SudukoSolver(board,i,j+1,n);
    }

    for(int num=1;num<=9;num++){
        if(isValid(board,i,j,num,n)){
            board[i][j] = num;
            bool subAns = SudukoSolver(board,i,j+1,n);
            if(subAns){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int n=9;
    int board[9][9] = {
        {0,0,7,1,0,0,0,6,0},
        {1,0,5,2,0,8,0,0,0},
        {6,0,0,0,0,7,1,2,0},
        {3,1,2,4,0,5,0,0,8},
        {0,0,6,0,9,0,2,0,0},
        {0,0,0,0,0,3,0,0,1},
        {8,0,3,9,0,6,0,0,0},
        {0,6,0,0,8,2,7,0,3},
    };

    SudukoSolver(board, 0, 0, n);

    return 0;
}