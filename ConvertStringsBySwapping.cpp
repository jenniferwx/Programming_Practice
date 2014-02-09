/*
Given a string S1, convert it to another string S2 (Anagram) by swapping only adjacent elements. 
Print all the intermediate strings formed. 

eg: s1: abcde 
s2: bcdae 

output: bacde,bcade, bcdae. 

like wise.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

void convertstring(string str1,string str2,int start1,int start2,int len,vector<bool> &avail)
{
    if(start2>=len)
    return;
    for(int i=start1;i<len;i++)
    {
        char ch1 = str1[i];
        char ch2 = str2[start2];
		if(avail[i]==true) continue;
        if(ch1==ch2){
            cout<<str1<<endl;
			avail[i]=true;
            convertstring(str1,str2,i+1,start2+1,len,avail);
        }
        else
        {
            int j = i+1;
            while(j<len)
            {
				swap(str1[j],str1[j-1]);
				j++;
			}
            convertstring(str1,str2,i,start2,len,avail);
        }
    }
}

void convert(string s1,string s2)
{
        int i = 0;
        int len = s1.size();
        while (i <len)
        {
            if (s2[i] == s1[i]) {
                i++;
                cout<<s1<<endl;
            } else {
                int j = i;
                while (j < s1.size() - 1 && s2[i] != s1[i])
                {
                    char temp = s1[j];
                    s1[j] = s1[j + 1];
                    s1[j + 1] = temp;
                    j++;
                }
            }
        }
}
int main()
{
    string str1="abcdef";
    string str2 = "bcdfae";
    int len = str1.size();
	vector<bool> avail(len,false);
    cout<<"start:"<<str1<<endl;
    convertstring(str1,str2,0,0,len,avail);
	cout<<"end:"<<str2<<endl;
	cout<<endl<<endl;
	cout<<"start:"<<str1<<endl;
	convert(str1,str2);
    cout<<"end:"<<str2<<endl;
     
   return 0;
}
