#include<iostream>
using namespace std;


bool safe(int path[4][4],int n,int x,int y){
    if(x<n && y<n && path[x][y]==1){
        return true;
    }
    return false;
}


bool solvemaze(int path[4][4],int n,int x,int y,int sol[4][4]){
    if(x==n-1 && y==n-1){
        sol[x][y]=1;
        return true;
    }
    if(safe(path,n,x,y)){
        sol[x][y]=1;
        if(solvemaze(path,n,x+1,y,sol)){
            return true;
        }
         if(solvemaze(path,n,x,y+1,sol)){
            return true;
        }
        sol[x][y]=0;
        return false;

    }
    return false;

}


int main(){
    int path[4][4]={
                    {1,0,1,1},
                    {1,1,0,1},
                    {0,1,1,1},
                    {1,0,1,1}
                    };
    int sol[4][4]={0};
     if (solvemaze(path, 4, 0, 0, sol)) {
        cout << "The path robot will take is :"<<endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found!" << endl;
    }
}
