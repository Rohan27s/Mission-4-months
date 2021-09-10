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

/******** User-defined Function *******/
class MyStructure
{
private:
    multiset<int> M1, M2; //we will maintain 2 multisets one with max values(M1) and another with min values of M1 which will be M2
    int sum;
    int K;

public:
    MyStructure(int K) : K(K), sum(0ll){};

    void add(int x)
    {
        M1.insert(x); 
        sum += x; //whenever we insert x value we have to add it to the sum
        if ((int)M1.size() > K) //agar m1 ka size bada hoga K se tabhi hum add krenge
        {
            int y = *(M1.begin()); //m1 ka sabse small value maintain krni hogi yaha hume(pointer banake)
            M1.erase(M1.find(y));
            sum -= y;
            M2.insert(y);
        }
        return;
    }

    void remove(int x)
    {
        if (M2.find(x) != M2.end())
        {
            M2.erase(M2.find(x));
        }
        else if (M1.find(x) != M1.end())
        {
            sum -= x;
            M1.erase(M1.find(x));
            if (M2.empty())
                return;
            int y = *(M2.rbegin());
            sum += y;
            M1.insert(y);
            M2.erase(M2.find(y));
        }
        return;
    }

    int getSum()
    {
        return sum;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Q, K;
    cin >> Q >> K;

    MyStructure M(K);

    while (Q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            M.add(x);
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            M.remove(x);
        }
        else if (t == 3)
        {
            char c;
            cin >> c;
            cout << M.getSum() << "\n";
        }
    }

    return 0;
}
