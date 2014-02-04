/*
 题目描述：

    给定两个整型数组A和B。我们将A和B中的元素两两相加可以得到数组C。
    譬如A为[1,2]，B为[3,4].那么由A和B中的元素两两相加得到的数组C为[4,5,5,6]。
    现在给你数组A和B，求由A和B两两相加得到的数组C中，第K小的数字。 

输入：

    输入可能包含多个测试案例。
    对于每个测试案例，输入的第一行为三个整数m，n， k(1<=m,n<=100000， 1<= k <= n *m)：n，m代表将要输入数组A和B的长度。
    紧接着两行， 分别有m和n个数， 代表数组A和B中的元素。数组元素范围为[0,1e9]。

输出：

    对应每个测试案例，
    输出由A和B中元素两两相加得到的数组c中第K小的数字。 
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long lld;
const lld M = 100001;
lld arr1[M],arr2[M];
lld m,n,k;

//统计小于等于 mid 的个数
lld cntMin(lld mid){
  lld cnt = 0;
  lld j = n-1;
  for(int i=0; i<m; i++){
    while(j >= 0 && arr1[i] + arr2[j] > mid) j--;
  cnt += j+1;
  }
  return cnt;
}
	 
lld low,high,mid;
int main() 
{
	freopen("in.txt", "r", stdin);
	while(scanf("%lld%lld%lld", &m,&n,&k) != EOF)
	{
	  for(lld i=0; i<m; i++) scanf("%lld", &arr1[i]);
	  for(lld j=0; j<n; j++) scanf("%lld", &arr2[j]);
	  sort(arr1, arr1+m);
	  sort(arr2, arr2+n);
	  low  = arr1[0] + arr2[0];
	  high = arr1[m-1] + arr2[n-1];
	  lld ans;
  
  	  while(low <= high)
  	  {
	  	mid = (low+high)/2;
  	  	lld cnt = cntMin(mid);
  	  	if(cnt >= k){
    	  	ans = mid; 
	  	high = mid-1;
		}
		else
		low = mid+1;
	  }
    	  printf("%lld\n",ans);
    	}
	return 0;
}
