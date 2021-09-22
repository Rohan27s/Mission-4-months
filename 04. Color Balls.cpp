#include <bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define int long long
#define mod 1000000007
#define MOD1 = 998244353;
#define pb push_back
#define mp make_pair
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vi, greater<int>>
#define INF 1e18
#define IN(A, B, C) assert(B <= A && A <= C)
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define sz(a) (int)(a.size())
#define Y second
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define print cout <<
#define take(t) cin >> t;
#define LSB(i) ((i) & -(i))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

/****** Template of some basic operations *****/
template <typename T, typename U>
inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
const int N = 100001;
/**********************************************/
int n, k;
int arr[N];
map<int, int> freq;
bool check(int minVal)
{
    int totalUsefulBalls = 0;
    for (auto v : freq)
    {
        totalUsefulBalls += min(v.second, minVal);
    }
    return totalUsefulBalls >= k * minVal;
}
/******** User-defined Function *******/
void rohancpp()
{
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int low = 0, high = n;
    int ans = low;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
            ans = mid, low = mid + 1;
        else
            high = mid - 1;
    }
    cout << ans << "\n";
    freq.clear();
}

int32_t main()
{

    w(x)
    {
        rohancpp();
    }
}
