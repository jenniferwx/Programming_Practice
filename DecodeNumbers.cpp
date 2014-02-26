/*
Given a library of numbers to corresponding letters (1 = a, 2 = b, 3 = c, etc.) and a string made up of digits, 
return how many different ways those digits can be translated to letters
ex: “1111”: “aaaa” “kaa” “aka” “aak” “kk” => 5 different ways
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <string.h>
using namespace std;
int count=0;

void CountWays(vector<char> &letters,string str,vector<string> &result,string &current)
{
    int len =str.size();
    if(len==0)
    {
        result.push_back(current);
        count++;
        cout<<"result:"<<current<<endl;
        return;
    }
    int num = 0;
    for(int i=0;i<len;i++)
    {
        int L = (str[i]-'0');
        num = num*10 + L;  
        
        if(num>26||num<1) continue;
        else
        {
           current.push_back(letters[num-1]); 
           CountWays(letters,str.substr(i+1),result,current);
        }
        current.pop_back();
    }
}
int main()
{
    vector<char> letters(26);
   for(int i=0;i<26;i++)
   {
       letters[i] = i+'a';
   }
   string str = "1134";
   vector<string> result;
   string current ="";
   CountWays(letters,str,result,current);
   cout<<count<<endl;
   return 0;
}
