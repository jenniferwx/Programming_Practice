/*
Problem: Given a matrix with 1s and 0s, please find the number of groups of 1s. A group is defined by horizontally or 
vertically adjacent 1s. For example, there are four groups of 1s in Figure 1 which are drawn with different colors.
1 1 0 0 1
1 0 0 1 0
1 1 0 1 0 
0 0 1 0 0
*/

#include <iostream>
#include<vector>
using namespace std;
void DFS(vector<vector<int>> &M,int x, int y, int row, int col)
{
    if(x>=row || x<0)
    return;
    if(y>=col || y<0)
    return;
    if(M[x][y]==0)
    return;
    M[x][y]=0;
    DFS(M,x+1,y,row,col);
    DFS(M,x-1,y,row,col);
    DFS(M,x,y+1,row,col);
    DFS(M,x,y-1,row,col);
}

int main()
{
/*   vector<vector<int>> M(4,vector<int>(5,0));
   M[0][0]=1;
   M[0][1]=1;
   M[0][4]=1;
   M[1][0]=1;
   M[1][3]=1;
   M[2][0]=1;
   M[2][1]=1;
   M[2][3]=1;
   M[3][2]=1;
   int row = 4;
   int col = 5;
*/
   int row = 5;
   int col = 5;
   vector<vector<int>> M(row,vector<int>(col,0));
   for(int i=0;i<row;i++)
 {  for(int j=0;j<col;j++)
   {
       int r = rand()%10+1;
       M[i][j] = r>5?1:0;
       cout<<M[i][j]<<" ";
   }
   cout<<endl;
 }
cout<<endl;
   int number=0;
   for(int i=0;i<row;i++)
   for(int j=0;j<col;j++)
   {
       if(M[i][j]==1)
       {
           number++;
           DFS(M,i,j,row,col);
       }
   }
   cout<<"# of group of 1s: "<<number<<endl;
   return 0;
}
