# enhanced version
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dct = {}
        max_so_far = curr_max = start = 0
        for index, i in enumerate(s):
        	if i in dct and dct[i] >= start:
        		max_so_far = max(max_so_far, curr_max)
        		curr_max = index - dct[i]
        		start = dct[i] + 1
        	else:
        		curr_max += 1
        	dct[i] = index
        return max(max_so_far, curr_max)

my_test = Solution()
msg = ["abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj",
"yfsrsrpzuya"]
for m in msg:
	print("%s = %d" % (m,my_test.lengthOfLongestSubstring(m)))
