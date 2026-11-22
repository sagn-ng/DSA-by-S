def lengthOfLongestSubstring(s: str) -> int:
    ans, i, n=0, 0, len(s)

    storeChar=set()

    for j in range(n):
        if (s[j] in storeChar):
            while (s[j] in storeChar):
                storeChar.remove(s[i])
                i+=1
        
        storeChar.add(s[j])

        ans=max(ans, j-i+1)

    return ans

#some tescases:
#testcases=["abcabcbb", "bbbbb", "pwwkew"]
#for x in testcases:
#    print(f"'{x}': {lengthOfLongestSubstring(x)}")