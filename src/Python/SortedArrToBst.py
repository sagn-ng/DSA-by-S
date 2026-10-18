from Sang_Library import TreeNode

#the approach is to use recursion: always pick the 'mid' value to
#be the 'root'
def helper(nums: list[int], left: int, right: int)->TreeNode | None:
    if (left>right): return None

    mid=left+(right-left)//2

    leftNode=helper(nums, left, mid-1)
    rightNode=helper(nums, mid+1, right)

    parentNode=TreeNode(nums[mid], leftNode, rightNode)

    return parentNode

def sortedArrayToBST(nums: list[int])->TreeNode | None:
    n=len(nums)
    return helper(nums, 0, n-1)