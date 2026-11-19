#generate all combinations containing k elements from the array [1, 2,..., n]

def combine(n: int, k: int) -> list[list[int]]:
    res=[]
    currAns=[]

    def helper(i: int, count: int)->None:
        if (count==k):
            res.append(currAns[:])
            return

        if (i>n or n-i+1<k-count): return

        currAns.append(i)
        helper(i+1, count+1)

        currAns.pop()
        helper(i+1, count)

        return

    helper(1, 0)

    return res

res=combine(4, 2)
print(res)