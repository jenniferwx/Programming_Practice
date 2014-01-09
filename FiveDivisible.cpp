#include <iostream>

using namespace std;

bool FiveDivisible1(int n)
{
    if((n&1)==1)
    n <<= 1;
    int x=((int)(n*0.1))*10;
    if((int)x==n)
    return true;
    else
    return false;
}


int main()
{
   int number = 5;
   cout<<number<<endl;
   if(FiveDivisible1(number))
   cout<<"can be divided by 5"<<endl;
   else
   cout<<"can not be divided by 5"<<endl;
}
