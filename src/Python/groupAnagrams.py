from collections import defaultdict

def groupAnagrams(strs: list[str]) -> list[list[str]]:
    store=defaultdict(list)

    for s in strs:
        countCharacters=[0]*26

        for c in s:
            countCharacters[ord(c)-ord('a')]+=1

        store[tuple(countCharacters)].append(s)

    return list(store.values())