class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<target){
                low++;
            }else if(nums[mid]>target){
                high--;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
