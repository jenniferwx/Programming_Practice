/*
You have a lists with integers. Find all the pairs of numbers that sum less 
than or equal to to a particular number k. The list contains minimum 5 Million number. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> &array,int endstart,int endend)
{
    int L= array.size();
    for(int i=0;i<endstart;i++)
    for(int j=i;j<L;j++)
    cout<<"("<<array[i]<<","<<array[j]<<")"<<endl;
    int i = endstart;
    for(int j=endstart;j<=endend;j++)
    cout<<"("<<array[i]<<","<<array[j]<<")"<<endl; 
}
void Search(vector<int> &array, int start, int end,int K)
{
    int i=start,j=end;
    while(j>=i)
    {
        int sum = array[i]+array[j];
        if(sum>K)
        j--;
        else
        break;        
    }
    print(array,i,j);
}
void findpair(vector<int> &array, int K)
{
    int L = array.size();
    int start = 0;
    while(start<L)
    {
       int Max = array[start]+array[L-1];
       if(Max>K)
       break;
       else 
       start++;
    }
    Search(array,start,L-1,K);
}

int main()
{
   int a[] = {2,1,8,5,10,3,18,23,21,4,6};
   int s = sizeof(a)/sizeof(int);
   vector<int> array(a,a+s);
   sort(array.begin(),array.end());
   for(int i=0;i<s;i++)
   cout<<array[i]<<",";
   cout<<"print pairs"<<endl;
   int K = 30;
   findpair(array,K); 
   return 0;
}
