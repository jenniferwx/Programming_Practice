/*
Max-double-slice-sum

对数组A，给定三元组（X,Y,Z)，0<=X<Y<Z<N，A[X + 1] + ...+ A[Y - 1] + A[Y + 1] +..+A[Z - 1]，叫做double-slice。
求最大的double-slice。

*/

int solution(vector<int> &A) {  
    // write your code in C++98  
    int n = A.size(), temp = 0;  
    vector<int> b;  
    b.resize(n);  
    for (int i = 1; i < n; ++i) {  
        if (temp < 0) {  
            temp = 0;  
        }  
        b[i] = temp;  
        temp += A[i];  
         
    }  
    temp = 0;  
    int result = 0;  
    for (int i = n - 2; i ; --i) {  
        if (temp < 0) {  
            temp = 0;  
        }  
        result = max(result, temp + b[i]);  
        temp += A[i];  
    }  
    return result;  
          
          
} 
