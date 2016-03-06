/**
LeetCode-37-Sudoku Solver
06/03/16 11:12:35
xuchen
**/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <bitset>
#include <array>
using namespace std;
class Solution {
    struct cell{
        int val;
        int numPossible;
        bitset<10> constrains;
        cell(): val(0), numPossible(9), constrains(){};
    };
    array<array<cell, 9>, 9> cells;
    vector<pair<int, int>> bt;
    
    bool set(int i, int j, int v)
    {
        cell& curCell = cells[i][j];
        if(curCell.constrains[v])
            return false;
        if(curCell.val == v)
            return true;
        
        curCell.constrains.set();
        curCell.constrains.reset(v);
        curCell.numPossible = 1;
        curCell.val = v;
        int krow;
        int kcol;
        for(int k=0; k<9; k++)
        {
            if(k!=i && !update(k, j, v))
                return false;
            if(k!=j && !update(i, k, v))
                return false;
            krow = (i/3)*3 + k/3;
            kcol = (j/3)*3 + k%3;
            if(krow!=i && kcol!=j && !update(krow, kcol, v))
                return false;
            
        }
        return true;
    }

    bool update(int i, int j, int v)
    {
        cell& curCell = cells[i][j];
        if(curCell.constrains[v])
            return true;
        if(curCell.val == v)
            return false;
        
        curCell.constrains.set(v, 1);
        --curCell.numPossible;
        if(curCell.numPossible < 2)
        {
            int k=9;
            while(curCell.constrains[k] !=0 )   --k;
            if(!set(i, j, k))
                return false;
        }
        return true;
    }

    bool setMultiPossibleBlock()
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(cells[i][j].val==0)
                    bt.push_back(make_pair(i, j));
            }
        }
        //has been solved
        if(bt.size()==0)
            return true;
        
        sort(bt.begin(), bt.end(), [this](const pair<int, int>&a, const pair<int, int> b){
                return cells[a.first][a.second].numPossible < cells[b.first][b.second].numPossible;});
        return backtrack(0);
    }
    
    bool backtrack(int k)
    {
        if(k > bt.size())
            return true;
        
        int i = bt[k].first;
        int j = bt[k].second;
        cell& curCell = cells[i][j];
        //have been caculated
        if(curCell.val)
            return backtrack(k+1);
        
        //a snapshot
        array<array<cell, 9>, 9> snapshot(cells);
        for(int p=1; p<=9; p++)
        {
            if(!curCell.constrains[p])
            {
                if(set(i, j, p))
                    if(backtrack(k+1))
                        return true;
                cells = snapshot;
            }
        }
        return false;
    }
    void print()
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                printf("%d ", cells[i][j].val);
            }
            printf("\n");
        }
    } 
public:
    void solveSudoku(vector<vector<char>>& board) {
        cells = array<array<cell, 9>, 9>();
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.' && !set(i, j, board[i][j]-'0'))
                    return;     //the input matrix is illegal
            }
        }
        
        print();
        if(!setMultiPossibleBlock())    //can't get answer
            return;
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                board[i][j] = cells[i][j].val+'0';
            }
        }
        return;
        
    }
};
