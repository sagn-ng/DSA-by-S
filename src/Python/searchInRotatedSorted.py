def search(self, nums: list[int], target: int) -> int:
    left, right=0, len(nums)-1

    while (left<=right):
        mid=left+(right-left)//2

        if (nums[mid]==target): return mid

        if (nums[mid]>=nums[left]):
            if (target>=nums[left] and target<nums[mid]):
                right=mid-1
                    
            else: left=mid+1
            
        else: #nums[mid]<=nums[right]
            if (target<=nums[right] and target>nums[mid]):
                left=mid+1

            else: right=mid-1
        
    return -1

#use the same idea that was applied in the problem "find minimum in rotated sorted array"