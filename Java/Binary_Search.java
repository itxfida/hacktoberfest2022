// Name: Shaurya pratap
// Username: @itsmeShaurya
// Favorite Language: Java


//Program to search for an element in a sorted using binary search

class Solution {
    public int search(int[] nums, int target) {
        int left = 0;                          //left or starting index
        int right = nums.length - 1;           //right or ending index
      
        while(left <= right){
            int mid = left + (right-left)/2;  //find the middle element
          
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;                            //return -1 if element does not exist
    }
}
