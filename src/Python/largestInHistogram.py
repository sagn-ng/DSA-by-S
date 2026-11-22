def largestRectangleArea(heights: list[int]) -> int:
    heights=heights+[0] #append 0 at the end helps clear the stack and find the final value of ans
    stack=[] #during the traversal, this will be an 'non-decreasing stack'
    ans=0

    #suppose we have the stack like this:
    # ....x stack[-1]
    #and (i, h) is the position we're at while traversing
    #we know that if heights[stack[-1]>h], the right side of stack[-1] gets blocked,
    #so we just need to find the left side's border (to get the width)
    for i, h in enumerate(heights):
        while (stack and heights[stack[-1]]>h):
            curr=stack.pop()
            left=stack[-1] if stack else -1

            width=i-left-1

            ans=max(ans, heights[curr]*width)

        stack.append(i)

    return ans

# print(largestRectangleArea([2,1,5,6,2,3]))