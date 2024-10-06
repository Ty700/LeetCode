/*

125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:
    1 <= s.length <= 2 * 10^5
    s consists only of printable ASCII characters.

*/

char* filterWord(char* word){
    uint32_t org_word_len = strlen(word);
    char* new_word = calloc(org_word_len + 1, sizeof(char));
    int new_word_len = 0;

    for(int i = 0; i < org_word_len; i++){
        while(i < org_word_len && !isalnum(word[i])){
            i++;
        }

        if( i >= org_word_len){
            new_word[new_word_len] = '\0';
            break;
        }

        new_word[new_word_len++] = tolower(word[i]);
    }
    printf("Filtered Word: %s", new_word);
    return new_word;
}

bool isPalindrome(char* s) {
    s = filterWord(s);
    uint32_t new_s_size = strlen(s);
    for(int i = 0, j = new_s_size - 1; i < j; ++i, --j){
        if(s[i] != s[j]){
            printf("%c != %c", s[i], s[j]);
            return 0;
        }
    }
    return 1;
}
