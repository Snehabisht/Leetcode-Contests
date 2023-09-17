//link:https://leetcode.com/contest/weekly-contest-362/problems/minimum-moves-to-spread-stones-over-grid/
//video link:https://www.youtube.com/watch?v=KTSBf8sJm5s


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
    int ans=INT_MAX;
public:
    void getAllPermutations(int i, int n, vector<vector<int>>&excess, vector<vector<int>>&def){
        
        if(i==n){
            int res=0;
            for(int t=0;t<n;++t){
                res+=(abs(excess[t][0]-def[t][0])+abs(excess[t][1]-def[t][1]));
            }
            ans=min(res,ans);
            return;
        }
        for(int j=i;j<n;++j){
            swap(excess[i],excess[j]);
            getAllPermutations(i+1,n,excess,def);
            swap(excess[i],excess[j]);
        }
        
    }
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>>excess;
        vector<vector<int>> def;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==0){
                    def.push_back({i,j});
                } else {
                    for(int t=1;t<grid[i][j];++t){
                        excess.push_back({i,j});
                    }
                }
            }
        }
        getAllPermutations(0,excess.size(),excess,def);
        return ans;
    }
};