/**
LeetCode-223-Rectangle Area
10/10/16 08:50:19
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int dup = 0;
        if(E>=C || G<=A || B>=H || F>=D)
            dup=0;
        else
        {
            int ax, ay, bx, by;
            if(E>=A && E<C)
            {
                ax = E;
                bx = min(C, G);
            }
            else if(E<A && A<G)
            {
                ax = A;
                bx = min(C, G);
            }
            
            if(H>B && H<=D)
            {
                by = H;
                ay = max(B, F);
            }
            else if(H>D && D>F)
            {
                by = D;
                ay = max(B, F);
            }
            dup = (bx-ax)*(by-ay);
        }
        
        return (C-A)*(D-B)+(G-E)*(H-F)-dup;
        
    }
};
