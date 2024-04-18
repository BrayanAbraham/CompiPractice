class Solution(object):

    def updateMaxArea(self, heights, stack, right, maxArea):
        item = heights[stack.pop()]

        left = -1 if len(stack) == 0 else stack[-1]

        area = (right - left -1) * item
        
        maxArea = max(area, maxArea)

        return stack, maxArea

    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """

        stack = []

        maxArea = -1

        for i in range(len(heights)):

            while len(stack) > 0 and heights[stack[-1]] >= heights[i]:
                stack, maxArea = self.updateMaxArea(heights, stack, i, maxArea)

            stack.append(i)

        while len(stack) > 0:
            stack, maxArea = self.updateMaxArea(heights, stack, len(heights), maxArea)

        return maxArea



    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        
        heights = []
        maxArea = -1

        for i in range(len(matrix)):

            for j in range(len(matrix[i])):

                if i==0:
                    heights.append(0 if matrix[i][j] == "0" else 1)
                else:
                    heights[j] = heights[j] + 1 if matrix[i][j] == "1" else 0
                
            maxArea = max(maxArea, self.largestRectangleArea(heights))

        return maxArea