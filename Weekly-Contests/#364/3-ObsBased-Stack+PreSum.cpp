//link:https://leetcode.com/contest/weekly-contest-364/problems/beautiful-towers-ii/
//video:https://www.youtube.com/watch?v=qoJTmhtRV8I

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

//Aliases
using ll= long long;
using lld= long double;
using ull= unsigned long long;
// find_by_order(k) returns iterator to the kth element starting from 0
// order_of_key(k) returns count of elements strictly smaller than k 

//Constants
constexpr lld pi= 3.141592653589793238;
constexpr ll INF= LONG_LONG_MAX;
constexpr lld EPS = 1e-9;
constexpr ll MOD=1e9+7;

//TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;

// Macros
#define w(x) int x;cin>>x; while(x--)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(int i=0;i<n;i++)
#define rep(i,m,n) for(int i=n;i>=m;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define all(v) v.begin(),v.end()
#define allr(v) v.end(),v.begin()
// #define int long long

// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
template<typename T>
void printvec(vector<T>v){ll n=v.size();fl(i,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}

// Mathematical functions
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd doesnt work when 0 is present
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll modmul(ll a,ll b,ll m = MOD){ll res = 0;a %= m;while (b){if (b & 1)res = (res + a) % m;b >>= 1;}return res;}
ll modpow(ll x, ll y, ll m = MOD){ll res = 1;x = x % m;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % m;y = y>>1;x = (x*x) % m;}return res;}
ll modinv(ll x, ll m = MOD){return modpow(x, m - 2, m); }

//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return !(n&(n-1));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}


class Solution {
public:
    vector<int> nextSmallerToLeft(vector<int>&v){
       vector<int> res;
       int n=v.size();
        stack<int>st;
       for(int i=0;i<n;++i){
           if(!st.empty() && v[st.top()]<v[i]){
               res.pb(st.top());
           } else if(st.empty()){
               res.pb(-1);
           } else {
               while(!st.empty() && v[st.top()]>=v[i]){
                    st.pop();
               }
               if(!st.empty() && v[st.top()]<v[i]){
                    res.pb(st.top());
              } else if(st.empty()){
                    res.pb(-1);
              }    
            }
           st.push(i);
        }
        return res;
    }
    vector<int> nextSmallerToRight(vector<int>&v){
       vector<int> res;
       int n=v.size();
        stack<int>st;
       for(int i=n-1;i>=0;--i){
           if(!st.empty() && v[st.top()]<v[i]){
               res.pb(st.top());
           } else if(st.empty()){
               res.pb(n);
           } else {
               while(!st.empty() && v[st.top()]>=v[i]){
                    st.pop();
               }
               if(!st.empty() && v[st.top()]<v[i]){
                    res.pb(st.top());
              } else if(st.empty()){
                    res.pb(n);
              }    
            }
           st.push(i);
        }
        reverse(all(res));
        return res;
    }
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n=maxHeights.size();
        long long ans=0;
        vector<long long> resl(n,0);
        vector<long long> resr(n,0);
        vector<int> nextSmallerToLeftInd=nextSmallerToLeft(maxHeights);
        vector<int> nextSmallerToRightInd=nextSmallerToRight(maxHeights);
        for(int i=0;i<n;++i){
            long long curr=0;
            long long elSameToLeft=i-nextSmallerToLeftInd[i];
            curr+=(elSameToLeft)*maxHeights[i];
            if(nextSmallerToLeftInd[i]!=-1){
                curr+=resl[nextSmallerToLeftInd[i]];
            }
            resl[i]=curr;
        }
        for(int i=n-1;i>=0;--i){
            long long curr=0;
            long long elSameToRight=nextSmallerToRightInd[i]-i;
            curr+=(elSameToRight)*maxHeights[i];
            if(nextSmallerToRightInd[i]!=n){
                curr+=resr[nextSmallerToRightInd[i]];
            }
            resr[i]=curr;
            ans=max(ans,resl[i]+resr[i]-maxHeights[i]);
        }
        return ans;
    }
};