#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main()
{
    string s;
    while(cin>>s)
    {
        string ret;
        for(int i=0; i<s.length(); ++i)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                ret.append(string(1, s[i]-('A'-'a')));
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                ret.append(string(1, s[i]));
            }
        } 
        cout<<ret<<endl;
    }

    return 0;
}