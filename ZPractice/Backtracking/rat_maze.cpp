#include<bits/stdc++.h>

using namespace std;

//Dynamic array

void printSolution(int **solution,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j];
        }
    }
    cout<<endl;
}

void mazeHelp(int maze[][20],int n,int **solution,int x,int y){
    
    if(x==n-1 && y==n-1){
        solution[x][y]=1;
        printSolution(solution,n);
        return;
    }

    if(x>=n||x<0||y>=n||y<0||maze[x][y]==0||solution[x][y]==1){
        return;
    }
    solution[x][y]=1;
    mazeHelp(maze,n,solution,x-1,y);
    mazeHelp(maze,n,solution,x+1,y);
    mazeHelp(maze,n,solution,x,y-1);
    mazeHelp(maze,n,solution,x,y+1);
    solution[x][y]=0;
}

void ratInAMaze(int maze[][20],int n){
    // 2-D dynamic matrix 
    int **solution=new int*[n];
    for(int i=0;i<n;i++){
        solution[i]=new int*[n];
    }
    mazeHelp(maze,n,solution,0,0);
}
int main(){
    int maze[][20]={1,0,1,1,0,1,1,1,1};
    ratInAMaze(maze,3);
    return 0;
}