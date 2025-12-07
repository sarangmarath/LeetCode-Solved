class Solution {
    public int countKDifference(int[] nums, int k) {
        int i,count=0;
        for(i=0;i<nums.length;i++){
            for(int j=0;j<nums.length;j++){
                if(nums[i]-nums[j]==k){
                    count++;
                }
            }
        }
        return count;
    }
}