class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        w = s.strip().split()
        return len(w[-1]) if w else 0
        