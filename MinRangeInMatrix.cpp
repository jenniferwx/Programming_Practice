/*
Facebook interview:
There is two dimensional array where each sub array (row) is sorted, i.e.

[[1 1000 2000]
[20 10001 5000]
[55 10002 222222]]

Find a minimum range contain a number from each row. For above array it should be (1000-1002) range.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int BinarySearch(int key, vector<int> L)
{
    int len = L.size();
    int i =0;
    int j = len-1;
    while(i<j)
    {
        int mid = (i+j)/2;
        if(L[mid]==key)
        return 0;
        if(L[mid]<key)
        i = mid+1;
        else
        j = mid-1;
    }
    return min(abs(L[j]-key),abs(L[j-1]-key));
}

void Distance(vector<int> L1, vector<int> L2, vector<int> &MinDist,vector<int> &result)
{
    int len = L1.size();
    int M = INT_MAX;
    for(int i=0;i<len;i++)
    {
        int D = BinarySearch(L1[i],L2);
        MinDist[i] +=D;
        if(MinDist[i]<M)
        {
            result[0] = i;
            result[1] = MinDist[i];
            M = MinDist[i];
        }
    }
}


vector<int> FindRange2(vector<vector<int> > list, int M, int N)
{
    vector<int> MinDist(N,0);
    vector<int> result(2,-1);
    result[1] = INT_MAX;
    if(M==0)
    return result;
    for(int i=M-1;i>0;i--)
    {
        int j = i-1;
        Distance(list[i],list[j],MinDist,result);
    }
    return result;
}

int main()
{
   int a[4] = {1,999,10000,19995};
   int b[4] = {20,100,19999,50000};
   int c[4] = {21,55,20006,2222222};
   int N = 4;
   vector<int> a1(a,a+N);
   vector<int> a2(b,b+N);
   vector<int> a3(c,c+N);
   vector<vector<int>> list(N,vector<int>(N,0));
   list[0] = a1;
   list[1] = a2;
   list[2] = a3;
   vector<int> result2 = FindRange2(list,3,4);
   cout<<result2[0]<<","<<result2[1]<<endl;
   int x = list[2][result2[0]]-result2[1];
   int y = list[2][result2[0]];
   cout<<"{"<<x<<","<<y<<"}"<<endl; 
   return 0;
}
