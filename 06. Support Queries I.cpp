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
    multiset<int> mySet;
    int sum; //have to maintain sum throughout the program

public:
    MyStructure() : sum(0LL){};

    void add(int x)
    {
        mySet.insert(x);
        sum += x;
    }

    void remove(int x)
    {
        if (mySet.find(x) != mySet.end())
        {
            mySet.erase(mySet.find(x));
            sum -= x; //if the number is present in the code we will erase it and then minus it from the sum
        }
        return;
    }

    int getMin()
    {
        if (mySet.empty())
            return -1;
        return *(mySet.begin()); //first index will be min
    }

    int getMax()
    {
        if (mySet.empty())
            return -1;
        return *(mySet.rbegin()); //rbegin which means the last value will be the max
    }

    int getSum()
    {
        return sum; //we will just return the sum which we have maintained throughout the code
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Q;
    cin >> Q;

    MyStructure M;

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
            cout << M.getMin() << "\n";
        }
        else if (t == 4)
        {
            char c;
            cin >> c;
            cout << M.getMax() << "\n";
        }
        else if (t == 5)
        {
            char c;
            cin >> c;
            cout << M.getSum() << "\n";
        }
    }
}
