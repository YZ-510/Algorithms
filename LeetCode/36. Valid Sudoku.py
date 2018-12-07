class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        '''
        board[i][j] 对每行、每列、每个3x3格子里的数字都要做判断
        每行比较 board[i][j]、board[i][column]，如果这个元素合法，只有 column==j 的时候 board[i][j]和board[i][column]才相等
        （i//3) * 3, (j//3) * 3 就是3x3格子左上角第一个元素的坐标
        '''
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    for column in range(9):
                        if column != j and board[i][j] == board[i][column]:
                            return False
                    for row in range(9):
                        if row != i and board[i][j] == board[row][j]:
                            return False
                    for row in range((i//3) * 3, (i//3) * 3 + 3):
                        for col in range((j//3) * 3, (j//3) * 3 + 3):
                            if row != i and col != j and board[i][j] == board[row][col]:
                                return False
        return True
    
        '''
        Cell = [[] for i in range(9)]
        Col = [[] for i in range(9)]
        Row = [[] for i in range(9)]
        
        for i, row in enumerate(board):
            for j, num in enumerate(row):
                if num != '.':
                    k = (i//3)*3 + j//3
                    if num in Row[i] + Col[j] + Cell[k]:
                        return False
                    Row[i].append(num)
                    Col[j].append(num)
                    Cell[k].append(num)
                    
        return True
        '''