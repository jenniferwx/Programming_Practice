/*
Given an input string, reverse all the words. 
For example:
input: “Interviews are awesome!” 
output: “awesome! are Interviews”. 

Consider all consecutive non-whitespace characters as individual words. If there are multiple spaces between words 
reduce them to a single white space. Also remove all leading and trailing whitespaces. 
So, the output for ”   CS degree”, “CS    degree”, “CS degree   “, or ”   CS   degree   ” are all the same: “degree CS”
*/

#include <iostream>
#include <cstring>
using namespace std;

string ReverseStr(string str)
{
    int len = str.length();
    string result = "";
    int start = 0;
    for(int i=0;i<len;)
    {
        while(str[i]!=' ')
        i++;
        if(start!=i)
        {
            if(i!=len-1)
            result = ' ' + result;
            string word = str.substr(start,i-start);
            result = word + result;
        }        
        start = i+1;
        i = start;
    }
    return result;
}
int main()
{
   string str1 = "  I love hangeng";
   string str2 = "I love hangeng";
   string str3 = "I love hangeng   ";
   string str4 = "I    love hangeng";
   string str5 = "   I love hangeng  ";
   cout<<"string: \n"<<str2<<endl;
   cout<<"After Reverse: \n"<<ReverseStr(str1)<<endl;
   cout<<"After Reverse: \n"<<ReverseStr(str2)<<endl;
   cout<<"After Reverse: \n"<<ReverseStr(str3)<<endl;
   cout<<"After Reverse: \n"<<ReverseStr(str4)<<endl;
   cout<<"After Reverse: \n"<<ReverseStr(str5)<<endl;
   return 0;
}
