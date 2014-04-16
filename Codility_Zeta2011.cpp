/*
有N行M列的正方形盒子。每个盒子有三种状态0, -1, +1。我们要扔球，球可以从盒子上面的边或者左面的边进入
盒子，从下面的边或者右面的边离开盒子。规则：
如果盒子的模式是-1，则进入它的球从下面出去。（方向变为向下）
如果盒子的模式是+1，则进入它的球从右面出去。 （反向变为向右）
如果盒子的模式是0， 则进入它的球方向不变。从上面进入的，从下面出去，从左面进入的，从右面出去。
球离开一个盒子，这个盒子的模式变为相反数。

已知，每个盒子的状态，扔k个球，它们都从左上角那个盒子的上面进入（方向向下），问最终有几个球从右下角的盒子的下边出去。
（可以理解维球一个一个放，等待的时间足够长，不会有两个球同时进入一个盒子的情形）。

数据范围 
N [1..1000]

M [1..1000]

K [0..10^9]

复杂度要求：

时间O(N*M)

空间O(M)
*/

int solution(const vector< vector<int> > &A, int K) {  
    // write your code here...  
    int i,j,right,n = A.size(), m = A[0].size();  
    vector<int> dp;  
    dp.resize(m, 0);  
    dp[0] = K;  
    for (i = 0; i < n; ++i) {  
        for (j = right = 0; j < m; ++j) {  
            K = dp[j] + right;  
            if (A[i][j] > 0) {  
                dp[j] = K >> 1;  
            }  
            else if (A[i][j] < 0) {  
                dp[j] = (K + 1) >> 1;  
            }  
            right = K - dp[j];  
        }  
    }  
    return dp[m - 1];  
                  
              
      
} 