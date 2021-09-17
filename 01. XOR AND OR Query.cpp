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
int prefSum[1000001][31];

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

/******** User-defined Function *******/
void rohancpp()
{
    int n, q;
    int i;
    cin >> n;
    for (i = 0; i <= n; i++)
        for (int j = 0; j < 31; j++)
            prefSum[i][j] = 0;
    for (i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        int cnt = 0;
        while (a > 0)
        {
            prefSum[i][cnt] = a % 2;
            a /= 2;
            cnt++;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (int j = 0; j < 31; j++)
            prefSum[i][j] += prefSum[i - 1][j];
    }
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        double total = (r - l + 1.0) / (2);
        long long x1 = 0, x2 = 0, x3 = 0;
        for (i = 0; i < 31; i++)
        {
            int p = prefSum[r][i] - prefSum[l - 1][i];
            if (p < total)
                x1 += (1LL << i);
            if (p != (r - l + 1))
                x2 += (1LL << i);
            if (p)
                x3 += (1LL << i);
        }
        long long ans = x1 + x2 + x3;
        cout << ans << "\n";
    }
}

int32_t main()
{

    w(x)
    {
        rohancpp();
    }
}
