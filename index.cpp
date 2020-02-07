#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	map<char, int> hmap;
    	int max_so_far, curr_max, start;
    	max_so_far = curr_max = start = 0;
    	for(int i=0; i<s.size(); i++) {
    		if(hmap.find(s[i]) != hmap.end() && hmap[s[i]] >= start) {
    			max_so_far = max(max_so_far, curr_max);
    			curr_max = i - hmap[s[i]];
    			start = hmap[s[i]] + 1;
    		} else {
    			curr_max++;
    		}
    		hmap[s[i]] = i;
    	}
    	return max(max_so_far, curr_max);
    }
};

int main(int argc, char *argv[]) {
	string msg[13] = {"abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj",
"yfsrsrpzuya"};

	Solution mySolution;
	for(int i=0; i<sizeof(msg)/sizeof(msg[0]); i++) {
		cout << msg[i] << " = " << mySolution.lengthOfLongestSubstring(msg[i]) << endl;
	}
}