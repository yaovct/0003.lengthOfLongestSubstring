<?php

class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
    	$max_so_far = $curr_max = $start = 0;
    	$dct = Array();
    	for($i=0; $i<strlen($s); $i++) {
    		if(array_key_exists($s[$i], $dct) && $dct[$s[$i]] >= $start) {
    			$max_so_far = max($max_so_far, $curr_max);
    			$curr_max = $i - $dct[$s[$i]];
    			$start = $dct[$s[$i]] + 1;
    		} else {
    			$curr_max++;
    		}
    		$dct[$s[$i]] = $i;
    	}
      return max($max_so_far, $curr_max);
    }
}

$msg = array("abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj",
"yfsrsrpzuya");
$testSolution = new Solution();
for($i=0; $i<count($msg); $i++) {
	printf("%s = %d<br>",$msg[$i], $testSolution->lengthOfLongestSubstring($msg[$i]));
}

?>