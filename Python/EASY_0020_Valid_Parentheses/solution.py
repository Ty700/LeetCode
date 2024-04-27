class Solution:
    def isValid(self, s: str) -> bool:
        hash_map = {
            ')': '(',
            '}': '{',
            ']': '[',
        }

        stack = []

        for paren in s:
            # Opening
            if paren in hash_map.values():
                stack.append(paren)
            # Closing
            else:
                if len(stack) > 0 and stack[-1] == hash_map[paren]:
                    stack.pop()
                else:
                    return False
        
        return (len(stack) == 0)                            
            
