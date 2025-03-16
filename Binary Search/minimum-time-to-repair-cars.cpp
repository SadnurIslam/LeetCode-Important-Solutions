// https://leetcode.com/problems/minimum-time-to-repair-cars/description

Approach 1: Using priority Queue

#define ll long long int
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll ans = -1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
        int n = ranks.size();
        for(int i=0;i<n;i++){
            pq.push({ranks[i],1});
        }
        while(cars--){
            ll cur1 = pq.top().first;
            ll cur2 = pq.top().second;
            pq.pop();
            ans = max(ans,cur1);
            cur1 = cur1/(cur2*cur2);
            cur2++;
            pq.push({cur1*cur2*cur2,cur2});
        }
        return ans;
    }
};



Approach 2: Using Binary Search (Faster)

#define ll long long int
class Solution {
public:
    bool possible(vector<int>&ranks, ll mid, int cars){
        ll cnt = 0;
        int n = ranks.size();
        for(int i=0;i<n;i++){
            ll div = mid/ranks[i];
            ll rt = sqrt(div);
            cnt+=rt;
        }
        // cout<<cnt<<endl;
        return cnt>=cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll ans = 100000000000000;
        ll low = 1;
        ll high = ans;
        while(low<=high){
            ll mid = (low+high)/2;
            // cout<<mid<<endl;
            if(possible(ranks,mid,cars)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};