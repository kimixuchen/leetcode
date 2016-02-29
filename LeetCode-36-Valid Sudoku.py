"""
LeetCode-36-Valid Sudoku
29/02/16 09:20:19
xuchen
"""
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        N = 9
        used1 = [([False]*N) for i in range(0, N)]
        used2 = [([False]*N) for i in range(0, N)]
        used3 = [([False]*N) for i in range(0, N)]
        for i in range(0, N):
            for j in range(0, N):
                if board[i][j]!='.':
                    num = ord(board[i][j])-ord('0')-1
                    k = (i/3)*3 + j/3
                    if used1[i][num] or used2[j][num] or used3[k][num]:
                        return False
                    used1[i][num] = used2[j][num] = used3[k][num] = True
        return True
