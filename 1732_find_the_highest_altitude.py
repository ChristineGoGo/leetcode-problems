class Solution:
    def largestAltitude(self, gain):
        current_altitude = 0
        highest_altitude = 0
        
        for i in range(len(gain)):
            current_altitude += gain[i]
            if current_altitude > highest_altitude:
                highest_altitude = current_altitude
        
        return highest_altitude
    
    
    
    
if __name__ == '__main__':
    s = Solution()
    print(s.largestAltitude([-4,-3,-2,-1,4,3,2]))