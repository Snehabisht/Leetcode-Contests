//linkToVideo :https://www.youtube.com/watch?v=74c6JV9DlHg
//link:https://leetcode.com/contest/biweekly-contest-112/problems/count-k-subsequences-of-a-string-with-maximum-beauty/

class Solution {
    int mod=1e9+7;
     long long power( long long x,
                                  int y, int p)
{
     long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
 long long modInverse( long long n, int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
 long long nCrModPFermat( long long n, int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
     long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<char,int>mpp;
        for(auto i:s){
            mpp[i]++;
        }
        unordered_map<char,int>lenToFreq;
        for(auto i:mpp){
            lenToFreq[i.second]++;
        }
        vector<vector<int>>v;
        for(auto i:lenToFreq){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        });
        long long res=1;
        if(v.size()>=k){
            for(int i=0;i<k;++i){
               res=(res*((v[i][0]*v[i][1])%mod))%mod;
                cout<<res<<" ";
            }
        } else {
            for(int i=0;i<v.size()-1;++i){
                res=(res*((v[i][0]*v[i][1])%mod))%mod;
            }
            k-=(v.size()-1);
            res*=nCrModPFermat(v[v.size()-1][1]*1ll,k,mod);
            
        }
        return (int)(res%mod);
    }
};