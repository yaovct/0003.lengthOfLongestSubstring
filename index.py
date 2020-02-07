# sliding window
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lst = []
        tmp = []
        hashtmp ={}
        for i in range(0, len(s)):
        	if not tmp or not s[i] in hashtmp:
        		tmp.append(s[i])
        		hashtmp[s[i]] = i
        	else:
	      		if len(tmp) > len(lst):
	      			lst = list(tmp)
        		while tmp:
        			#print ("before [%s %s] %d:%s" % (tmp, hashtmp, i, s[i]))
        			# we need to del hashtmp first, then del tmp[j]!!!!
        			# or we will mess up the dict
        			key = tmp[0]
        			del hashtmp[key] # remove dict by key
        			del tmp[0] # remove key from the first
        			#print ("after [%s %s] %s" % (tmp, hashtmp, key))
        			if key == s[i]:
        				tmp.append(s[i])
        				hashtmp[s[i]] = i
        				break
      		#print ("lst = %s, tmp = %s, s[%d] = %s" % (lst, tmp, i, s[i]))
    		if len(tmp) > len(lst):
    			lst = list(tmp)
    		#print ("lst = %s, tmp = %s" % (lst, tmp))
        return len(lst)

my_test = Solution()
msg = ["abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj",
"yfsrsrpzuya"]
for m in msg:
	print("%s = %d" % (m,my_test.lengthOfLongestSubstring(m)))
