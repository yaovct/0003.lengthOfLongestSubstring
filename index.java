import java.lang.*;
import java.util.*;

class Solution {
  public int lengthOfLongestSubstring(String s) {
  	Map<Character, Integer> map = new HashMap<Character, Integer>();
  	int max_so_far, curr_max, start;
  	max_so_far = curr_max = start = 0;
  	for(int i=0; i<s.length(); i++) {
  		if(map.containsKey(s.charAt(i)) && map.get(s.charAt(i)) >= start) {
  			max_so_far = Math.max(max_so_far, curr_max);
  			curr_max = i - map.get(s.charAt(i));
  			start = map.get(s.charAt(i)) + 1;
  		} else {
  			curr_max++;
  		}
  		map.put(s.charAt(i),i);
  	}
    return Math.max(max_so_far, curr_max);
  }
}

public class index {

	public static void main(String[] args) {
		String[] msg = new String[] {"abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj",
"yfsrsrpzuya"};

    Solution demo = new Solution();
    for(int i=0; i<msg.length; i++) {
    	System.out.printf("%s = %d\n", msg[i], demo.lengthOfLongestSubstring(msg[i]));
    }
	}
}