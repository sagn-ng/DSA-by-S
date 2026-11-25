#nums will contain 2 sorted halves
def findMin(nums: list[int]) -> int:
    if (len(nums)==1): return nums[0]

    n=len(nums)
    left, right=0, n-1
    ans=5000

    while (left<=right):
        if (nums[left]<nums[right]):
            ans=min(ans, nums[left])
            break

        mid=left+(right-left)//2

        if (nums[mid]>=nums[left]): left=mid+1
        else: right=mid-1 #nums[mid]<=nums[right]

        ans=min(ans, nums[mid])

    return ans

#example:
nums = [3, 4, 5, 1, 2]
print(findMin(nums))