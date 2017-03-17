#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<cstring>
#include<stack>

using namespace std;

const int MAX = 0x3f3f3f3f;

int postfixCalc(const char * input)
{
    int n = strlen(input);
    stack<int> nums;
    for(int i=0; i<n; ++i)
    {
        if(input[i]>='0' && input[i]<='9')
        {
            nums.push(input[i]-'0');
            continue;
        }
        if(input[i]>='A' && input[i]<='F')
        {
            nums.push(input[i]-'A'+10);
            continue;
        }

        int a;
        int b;
        b = nums.top();
        nums.pop();
        a = nums.top();
        nums.pop();
        if(input[i]=='+')
        {
            nums.push(a+b);
        }
        else if(input[i]=='-')
        {
            nums.push(a-b);
        }
        else if(input[i]=='*')
        {
            nums.push(a*b);
        }
    }
    int ret = nums.top();
    nums.pop();
    
    return ret;
}

int main()
{
    string s;
    while(cin>>s)
    {
        int ret = postfixCalc(s.c_str());
        cout<<ret<<endl;
    }
    
    return 0;
}