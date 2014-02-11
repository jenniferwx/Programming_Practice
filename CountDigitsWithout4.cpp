/*
Count the number of positive integers less than N that does not contains digit 4.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;

int count(int n)
{ 
    if (n < 4) {
        return n;
    }
    if (n >= 4 && n <=9) {
        return n - 1;
    }
    // otherwise for multi digit numbers, compute the order of magnitude
    int orderPower = (int)floor(log10(n));
    // actual number order 
    int order = (int) pow(10.0, (double)orderPower);
    
    // the first digit of the number n
    int d = (int) n / order;
    // the rest of the number when first digit is removed
    int remainder = n % order;
    // if the number starts with 4, then all of the remainder should not
    // be counted. Therefore, the count value is the same as number that
    // starts with d-1 as first digit and all the rest of digits are 9
    if (d == 4) {
        // remainder is all 9s
    remainder = (int) pow(10, orderPower) - 1;
    }

    // compute the power of 9
    int ninePower = (int) pow(9, orderPower);

    if (d < 4) {
        return d * ninePower + count(remainder);
    } else {
        return (d - 1) * ninePower + count(remainder);
    }   
}

bool containsFour(int n)
{
    std::stringstream v;
    v<<n;
    string value = v.str(); 
    if (value.find('4') != EOF) {
        return true;
    }
    return false;
}
int naiveCount(int n)
{
    int withoutFourCount = 0;
    for (int i = 1; i <= n; i++) {
        if (!containsFour(i)) {
            withoutFourCount++;
        }
    }
    return withoutFourCount;
}


int main()
{
   int num  = 315;
   cout<<count(num)<<endl;
   cout<<naiveCount(num)<<endl;
   return 0;
}
