class Solution:
    def placeQueen(self, board:list[list[str]], r:int, c:int) -> list[list[str]]:

        i = r - 1
        j = c - 1

        while i >= 0 and j >= 0:
            board[i][j] = "."
            i -= 1
            j -= 1

        i = r - 1
        j = c + 1
        while i >= 0 and j < len(board):
            board[i][j] = "."
            i -= 1
            j += 1

        i = r + 1
        j = c - 1
        while i < len(board) and j >= 0:
            board[i][j] = "."
            i += 1
            j -= 1
        
        i = r + 1
        j = c + 1
        while i < len(board) and j < len(board):
            board[i][j] = "."
            i += 1
            j += 1
        
        for i in range(len(board)):
            board[i][c] = "."
            board[r][i] = "."
        
        board[r][c] = "Q"

        return board

    def solveNQueensBoard(self, n:int, board: list[list[str]], row:int) -> list[list[list[str]]]:
        results = []
        if row == n - 1:
            for i in range(n):
                if board[row][i] == " ":
                    results.append(self.placeQueen([item[:] for item in board], row, i))
                    break
            return results
        
        for i in range(n):
            if board[row][i] == " ":
                newBoard = [item[:] for item in board]
                newBoard = self.placeQueen(newBoard, row, i)
                results.extend(self.solveNQueensBoard(n, newBoard, row + 1))

        return results


    def solveNQueens(self, n: int) -> list[list[str]]:
        board = []

        for i in range(n):
            board.append([])
            for _ in range(n):
                board[i].append(" ")

        results = self.solveNQueensBoard(n, board, 0)

        return list(map(lambda x: list(map(lambda y: "".join(y), x)), results))