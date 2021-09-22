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
/**********************************************/

int arr[100001];
int n, k;
bool check(int maxDiffAllowed)
{
    int pointsRequired = 0;
    int i = 1;
    while (i < n)
    {
        pointsRequired += (arr[i] - arr[i - 1] + maxDiffAllowed - 1) / maxDiffAllowed - 1;
        i++;
    }
    return pointsRequired <= k;
}
/******** User-defined Function *******/
void rohancpp()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 1, high = 1e9;
    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    cout << ans << "\n";
}

int32_t main()
{

    w(x)
    {
        rohancpp();
    }
}
