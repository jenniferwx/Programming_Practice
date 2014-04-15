/*
Max-Counters:
(Codility problem)
一个数组，长度为N，起初全部数都为0，有两种操作，一个是对某个元素加1，另一个是把所有元素变为目前的最大值，
给定若干次这样的操作之后，求数组最终状态。数组长度N和操作个数M都在[1..10^5]。要求复杂度时间O(N + M)，空间O(N)
*/

vector<int> solution(int N, vector<int> &A) 
{  
    // write your code here...  
    int i,m = A.size(), lastv = 0, v = 0;  
    vector<int> r;  
    r.resize(N , 0);  
    for (i = 0; i < m; ++i) {  
        if (--A[i] < N) {  
            v = max(v, r[A[i]] = max(r[A[i]], lastv) + 1);  
        }  
        else {  
            lastv = v;  
        }  
    }  
    for (i = 0; i < N; ++i) {  
        r[i] = max(r[i], lastv);  
    }  
    return r;  
              
}  
