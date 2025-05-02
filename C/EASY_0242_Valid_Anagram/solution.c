/*
242. Valid Anagram

Given two strings s and t, return true if t is an
anagram
of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

Constraints:

    1 <= s.length, t.length <= 5 * 10^4
    s and t consist of lowercase English letters.

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

*/

#define HASH_LEN 26

int hashIndex(char c){
    return tolower(c) - 'a';
}

bool isAnagram(char* s, char* t) {
    uint32_t s_len = strlen(s);
    uint32_t t_len = strlen(t);

    if(t_len != s_len){
        return false;
    }

    int map[HASH_LEN] = {0};

    for(int i = 0; i < s_len; i++){
        map[hashIndex(s[i])] += 1;
        map[hashIndex(t[i])] -= 1;
    }

    for(int i = 0; i < HASH_LEN; i++){
        if(map[i] != 0){
            return false;
        }
    }

    return true;

}
