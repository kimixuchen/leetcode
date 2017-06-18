/**
LeetCode-625-Minimum Factorization
2017-06-18 10:13:13
xuchen
**/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <cstring>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    int smallestFactorization(int a) {
        if(a==1)
            return 1;

        int num2=0, num3=0, num5=0, num7=0;
        int num4=0, num6=0, num8=0, num9=0;

        while(a % 2 == 0) {
            num2++;
            a /= 2;
        }

        while(a % 3 == 0) {
            num3++;
            a /= 3;
        }

        while(a % 5 == 0) {
            num5++;
            a /= 5;
        }

        while(a % 7 == 0) {
            num7++;
            a /= 7;
        }

        if(a > 1)
            return 0;
        
        if(num2 >= 3) {
            num8 = num2/3;
            num2 %= 3;
        }
        if(num3 >= 2) {
            num9 = num3/2;
            num3 %= 2;
        }
        
        if(num2>0 && num3>0) {
            num6=1;
            num2--;
            num3--;
        }

        if(num2 == 2) {
            num4 = 1;
            num2 -= 2;
        }
        
        int totallen = num2+num3+num4+num5+num6+num7+num8+num9;
        //32 bit INT_MAX = 2147483647
        if(totallen >= 10)
            return 0;
        
        cout<<totallen<<endl;
        
        int ret = 0;
        for(int i=0; i<num2; i++) {
            ret *= 10;
            ret += 2;
        }
        for(int i=0; i<num3; i++) {
            ret *= 10;
            ret += 3;
        }
        for(int i=0; i<num4; i++) {
            ret *= 10;
            ret += 4;
        }
        for(int i=0; i<num5; i++) {
            ret *= 10;
            ret += 5;
        }
        for(int i=0; i<num6; i++) {
            ret *= 10;
            ret += 6;
        }
        for(int i=0; i<num7; i++) {
            ret *= 10;
            ret += 7;
        }
        for(int i=0; i<num8; i++) {
            ret *= 10;
            ret += 8;
        }
        for(int i=0; i<num9; i++) {
            ret *= 10;
            ret += 9;
        }

        return ret;
        

    }
};