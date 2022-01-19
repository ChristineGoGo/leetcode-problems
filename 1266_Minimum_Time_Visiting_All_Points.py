class Solution:
    def minTimeToVisitAllPoints(self, points):
        distance = 0
        dx = dy = 0
        for i in range(len(points)-1,0,-1):
            dx = points[i][0] - points[i - 1][0]
            dy = points[i][1] - points[i-1][1]
            distance += max(abs(dx), abs(dy))
        
        return distance

if __name__ == '__main__':
    s = Solution()
    print(s.minTimeToVisitAllPoints([[1,-2], [1,3], [4,0]]))
    
    
    