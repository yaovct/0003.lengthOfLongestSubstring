#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_SIZE 40
	
int lengthOfLongestSubstring(char * s){
	int max_so_far, curr_max, start;
	max_so_far = curr_max = start = 0;
	int *dict; // replacing hash from char to integer: a-z
	dict = calloc(177 - 40 + 1, sizeof(int)); // initial value = 0; we shift value by 1
	for(int i=0; i<strlen(s); i++) {
		if(dict[s[i]-' '] !=0 && 	dict[s[i]-' '] > start) {
			max_so_far = max_so_far >= curr_max ? max_so_far : curr_max;
			curr_max = i - dict[s[i]-' '] + 1;
			start = dict[s[i]-' '];
		} else {
			curr_max++;
		}
		dict[s[i]-' '] = i + 1;
	}
	return max_so_far >= curr_max ? max_so_far : curr_max;
}


int main(int argc, char *argv[]) {
	char msg[][MAX_STRING_SIZE] = {"abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj",
"yfsrsrpzuya"};

	for(int i=0; i<sizeof(msg)/sizeof(msg[0]); i++) {
		printf("%s = %d\n", msg[i], lengthOfLongestSubstring(msg[i]));
	}
}