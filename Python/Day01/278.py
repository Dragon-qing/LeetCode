class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        start = 1
        end = n
        i = int((start+end)/2)
        while start<end:
            if isBadVersion(i):
                end = i
            else:
                start = i+1
            i = int((start+end)/2)
        return i
