class Solution:
    def getStartCoor(self, grid: list[list[int]]) -> tuple[int | None, int | None]:

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    return i,j

        return None, None
    
    def getPerimeter(self, grid: list[list[int]], startR: int, startC: int) -> tuple[list[list[int]], int]:
        
        if grid[startR][startC] == 0 or grid[startR][startC] == 2:
            return grid, 0
        
        per = 0

        grid[startR][startC] = 2

        if startR > 0:
            if grid[startR - 1][startC] == 0:
                per += 1
            else:
                grid, tPer = self.getPerimeter(grid, startR - 1, startC)
                per += tPer
        else:
            per += 1

        if startR < len(grid) - 1:
            if grid[startR + 1][startC] == 0:
                per += 1
            else:
                grid, tPer = self.getPerimeter(grid, startR + 1, startC)
                per += tPer
        else:
            per += 1
        
        if startC > 0:
            if grid[startR][startC - 1] == 0:
                per += 1
            else:
                grid, tPer = self.getPerimeter(grid, startR, startC - 1)
                per += tPer
        else:
            per += 1

        if startC < len(grid[startR]) - 1:
            if grid[startR][startC + 1] == 0:
                per += 1
            else:
                grid, tPer = self.getPerimeter(grid, startR, startC + 1)
                per += tPer
        else:
            per += 1

        return grid, per


    def islandPerimeter(self, grid: list[list[int]]) -> int:
        
        startR, startC = self.getStartCoor(grid)

        if startR == None or startC == None:
            return 0
        
        _, per = self.getPerimeter(grid, startR, startC)

        return per
