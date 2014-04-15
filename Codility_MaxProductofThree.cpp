/*
MaxProductofThree
 给定一个数组，找到乘积最大的3个不同的元素。
数组元素个数N [3..10^5]，每个元素的范围[-1000, +1000]。
*/

int solution(vector<int> &A) {  
    // write your code here...  
    sort(A.begin(), A.end());  
    int n = A.size();  
    int a,b,c;
    a = A[n-1];
    int j,k;
    for(j=n-2,b=A[j];j>1&&A[j]==a;j--); 
    b = A[j];
    for(k=j-1,c=A[k];k>0&&A[k]==b;k--);
    c = A[k];
    return a*b*c;     
 }
