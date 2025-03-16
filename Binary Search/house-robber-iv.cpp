// https://leetcode.com/problems/house-robber-iv/

class Solution {
bool check(vector<int>&nums, int n, int k,int mid){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(nums[i]<=mid){
            cnt++;
            i++;
        }
        if(cnt>=k)return true;
    }
    return false;
}
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int high = 1000000001;
        int low = 1;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(nums,n,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};