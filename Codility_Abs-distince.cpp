/*
Abs-distinct:
一个长度为N的整数数组，已经按非降序排好序，求数组中的数有多少种不同的绝对值。数据范围N [1..10^5]，
数组元素[-2147483648,+2147483647]。
要求复杂度 时间O(N)，空间O(N)。
*/

int solution(const vector<int> &A) {  
    // write your code here...  
int n = A.size(), i, j ,r, t;  
    for (i = r = 0, j = n - 1; (i < j) && (A[i] < 0) && (A[j] > 0); ++r) {  
        t = (A[i] + A[j] < 0)?A[i]:A[j];  
        for (;((t < 0) && (A[i] == t)) || ((t > 0) && (A[i] + t == 0)) ; ++i);  
        for (;((t < 0) && (A[j] + t == 0)) || ((t > 0) && (A[j] == t)); --j);  
    }  
    for (;i <= j;++r) {  
        for (t = A[i]; (i <= j) && (A[i] == t); ++i)  
        ;  
    }  
    return r;  
}  
