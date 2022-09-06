"""
    An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

    You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

    To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as 
    the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of 
    all of the aforementioned pixels with color.

    Return the modified image after performing the flood fill.  
"""

def floodFill(image, sr, sc, color):
    rows, columns = len(image), len(image[0])
    base_color = image[sr][sc]
    
    if base_color == color: return image
    
    def fillColor(row, column):
        if image[row][column] == base_color:
            image[row][column] = color
            if row >= 1: fillColor(row - 1, column)
            if row + 1 < rows: fillColor(row + 1, column)
            if column >= 1: fillColor(row, column - 1)
            if column +1 < columns: fillColor(row, column + 1)
    
    fillColor(sr, sc)
    return image

    

    



print(f'floodFill(image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2):{floodFill(image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2)} ')
# [[2,2,2],[2,2,0],[2,0,1]]
# print(f'floodFill(image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0):{floodFill(image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0)} ')
# [[0,0,0],[0,0,0]]
