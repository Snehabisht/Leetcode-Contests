//link:https://leetcode.com/contest/biweekly-contest-111/problems/sorting-three-groups/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //LIS-DP-O(NlogN)
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;++i){
            if(v.size()==0 || v[v.size()-1]<=nums[i]){
                v.push_back(nums[i]);
            } else {
                int ind=upper_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[ind]=nums[i];
            }
        }
        return n-v.size();
        // dp approach-O(N) , concept from mock interview of Priyansh, Keerti on Keertis channel, Keerti's approach
        // vector<int>one(n,0),two(n,0),three(n,0);
        // one[0]=(nums[0]!=1);
        // two[0]=(nums[0]!=2);
        // three[0]=(nums[0]!=3);
        // for(int i=1;i<n;++i){
        //     one[i]=one[i-1]+(nums[i]!=1);
        //     two[i]=(nums[i]!=2)+min(one[i-1],two[i-1]);
        //     three[i]=(nums[i]!=3)+min(two[i-1],min(three[i-1],one[i-1]));
        // }
        // // for(int i=0;i<n;++i){ 
        // //     cout<<one[i]<<" ";
        // // }
        // // cout<<"\n";
        // // for(int i=0;i<n;++i){ 
        // //     cout<<two[i]<<" ";
        // // }
        // // cout<<"\n";
        // // for(int i=0;i<n;++i){ 
        // //     cout<<three[i]<<" ";
        // // }
        // // cout<<"\n";
        // return min(min(one[n-1],two[n-1]),three[n-1]);
    }
};