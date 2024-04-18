class Solution:
    aliveBefore = [1, 2, 3]
    aliveAfter = [3,4]

    def countNeighbors(self, board: list[list[int]], i:int, j:int) -> int:
        count = 0

        if i > 0:
            if board[i-1][j] in self.aliveBefore:
                count += 1
        
        if i > 0 and j > 0:
            if board[i-1][j-1] in self.aliveBefore:
                count += 1

        if i > 0 and j < len(board[i]) - 1:
            if board[i-1][j+1] in self.aliveBefore:
                count += 1

        if j > 0:
            if board[i][j-1] in self.aliveBefore:
                count += 1
        
        if j < len(board[i]) - 1:
            if board[i][j+1] in self.aliveBefore:
                count += 1
        
        if i < len(board) - 1 and j > 0:
            if board[i+1][j-1] in self.aliveBefore:
                count += 1

        if i < len(board) - 1:
            if board[i+1][j] in self.aliveBefore:
                count += 1
        
        if i < len(board) - 1 and j < len(board[i]) - 1:
            if board[i+1][j+1] in self.aliveBefore:
                count += 1
        
        return count


    def gameOfLife(self, board: list[list[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        for i in range(len(board)):
            for j in range(len(board[i])):
                neighbors = self.countNeighbors(board, i, j)

                if board[i][j] == 1:
                    if neighbors < 2:
                        board[i][j] = 2
                    elif neighbors == 2 or neighbors == 3:
                        board[i][j] = 3
                    else:
                        board[i][j] = 2
                else:
                    if neighbors == 3:
                        board[i][j] = 4
                    else:
                        board[i][j] = 5

                print(neighbors, board)
        
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] in self.aliveAfter:
                    board[i][j] = 1
                else:
                    board[i][j] = 0

sol = Solution()
board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
sol.gameOfLife(board)

print(board)
        