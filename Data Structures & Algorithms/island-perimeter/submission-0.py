class Solution:
    def islandPerimeter(self, grid: list[list[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        perimeter = 0
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    # Start with 4 sides for this land cell
                    perimeter += 4
                    
                    # Check all 4 neighbors (up, down, left, right)
                    # If a neighbor is land (1), it shares an edge, so we subtract 1
                    if r > 0 and grid[r - 1][c] == 1:     # Up
                        perimeter -= 1
                    if r < rows - 1 and grid[r + 1][c] == 1: # Down
                        perimeter -= 1
                    if c > 0 and grid[r][c - 1] == 1:     # Left
                        perimeter -= 1
                    if c < cols - 1 and grid[r][c + 1] == 1: # Right
                        perimeter -= 1
                        
        return perimeter