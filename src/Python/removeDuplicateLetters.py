def removeDuplicateLetters(s: str) -> str:
    lastOccurence={char: i for i, char in enumerate(s)}

    stack=[]
    in_stack=set()

    for i, c in enumerate(s):
        if (c in in_stack): continue

        while (stack and stack[-1]>c and lastOccurence[stack[-1]]>i):
            removedChar=stack.pop()

            in_stack.remove(removedChar)

        stack.append(c)
        in_stack.add(c)

    return "".join(stack)
