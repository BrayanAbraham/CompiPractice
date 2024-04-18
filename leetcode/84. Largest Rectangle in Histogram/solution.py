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
