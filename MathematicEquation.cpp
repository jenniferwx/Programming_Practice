/*
implement一个例如“3*4+5"的计算
note: 
1）以下code只适合数字在0-9之间的加减乘除运算
2）公式中没有括号
3）运用two stack
*/

#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int str2int(string str)
{
    int res=0;
    int L = str.size();
	for(int i=0;i<L;i++)
	{
		if(str[i]!=' '&&str[i]>='0'&&str[i]<='9')
		res = res*10+(str[i]-'0');
	}
    return res;
}

string int2str(int num)
{
	string res="";
	while(num>0)
	{
		char a =  (num%10)+'0';
		res = a+res;
		num=num/10;
	}
	return res;
}
int calc(string equation)
{
    int result;
    stack<string> mystack1;
    stack<int> mystack2;
    int L = equation.size();
    if(L<=0)
    return result;
   // mystack1.push(equation[0]);
    for(int i=1;i+1<L;)
    {
        char cur = equation[i];
        string prev = equation.substr(i-1,1);

        if(cur=='+'||cur=='-')
        {            
            if(!mystack2.empty())
            {
				string p = int2str(mystack2.top());
                mystack1.push(p);
                mystack2.pop();
            }
            else
            {mystack1.push(prev);}
            
			stringstream ss;
			ss<<cur;
            mystack1.push(ss.str());
            if(i+1==L-1)
			{
				stringstream ss;
				ss<<equation[i+1];
				mystack1.push(ss.str());
			}
        }
        else if(cur=='*')
        {
            if(mystack2.empty())
            mystack2.push(str2int(prev));
         
            int p = mystack2.top();
            mystack2.pop();

            stringstream ss;
            ss<<equation[i+1];
            int num2 = str2int(ss.str());
            int result = p*num2;
            mystack2.push(result);            
        }
        else if(cur=='/')
        {
            if(mystack2.empty())
            mystack2.push(str2int(prev));
            
            int p = mystack2.top();
            mystack2.pop();
			stringstream ss;
			ss<<equation[i+1];
            int num2 = str2int(ss.str());
            int result = p/num2;
            mystack2.push(result);    
        }
        i+=2;
    }
	if(mystack1.empty()&&!mystack2.empty())
		return mystack2.top();
    if(!mystack2.empty())
    {
        mystack1.push(int2str(mystack2.top()));
        mystack2.pop();
    }
    while(mystack1.size()!=1)
    {
		result = 0;
        int N1 = str2int(mystack1.top());
        mystack1.pop();
        string oper = mystack1.top();
        mystack1.pop();
        int N2 = str2int(mystack1.top());
        mystack1.pop();
        if(oper[0]=='+')
        result +=N1+N2;
        else if(oper[0]=='-')
        result +=N2-N1;
		mystack1.push(int2str(result));
    }
    return result;   
}

int main()
{
   string eq = "3*2*3+5*5-6/2+3";
   cout<<"Equation: "<<eq<<endl;
   int result = calc(eq);
   cout<<"result= "<<result<<endl;
   return 0;
}
