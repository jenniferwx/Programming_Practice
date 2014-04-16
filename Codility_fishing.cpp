/*
Fishing

X轴上有一群鱼，每条鱼的位置不同。每条鱼游动的方向可能沿着x正方向，也可能沿着x轴负方向。从左到右（沿着x轴正方向）
知道每条鱼的大小和游动的方向，每条鱼的大小不同，游动速度一样，两条鱼相遇，大鱼会吃掉小鱼，问时间足够长之后能剩下
多少条鱼。

数据范围 鱼数 N [1..10^5]，每条鱼游动的方向只能是+1和-1，鱼大小的范围[0..10^9]。要求复杂度 时间O(N)，空间O(N)。
*/

#include <stack>  
  
int solution(vector<int> &A, vector<int> &B) {  
    // write your code in C++ 
    int n = A.size(),m = n;  
    stack<int> s;  
    for (int i = 0; i < n; ++i) {  
        if (B[i]) {  
            s.push(A[i]);  
        }  
        else {  
            while ((!s.empty()) && (s.top() < A[i])) {  
                s.pop();  
                --m;  
            }  
            if (!s.empty()) {  
                --m;  
            }  
        }  
    }  
    return m;  
}
