/*
    PROBLEM STATEMENT FROM KATTIS (NOT codeforces):
    https://open.kattis.com/problems/alehouse
*/


//libraries
#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <iostream>

//macros
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define abs(a) ((a) < 0 ? -(a) : (a))
#define F(i, L, R) for (int i = L; i < R; i++)
#define FE(i, L, R) for (int i = L; i <= R; i++)
#define FF(i, L, R) for (int i = L; i > R; i--)
#define FFE(i, L, R) for (int i = L; i >= R; i--)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define PI 3.1415926535897932384626
#define mp make_pair
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);

using namespace std;

//typedef
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

int main()
{
    FAST;

    int n, k; cin>>n>>k;

    vi starts, ends;
    F(i,0,n){
        int a,b;
        cin>>a>>b;
        starts.push_back(a);
        ends.push_back(b);
    }
    sort(starts.begin(),starts.end());
    sort(ends.begin(),ends.end());


    int ans = 0;
    for(auto e : ends){
        int curr = n;
        curr -= distance(ends.begin(),lower_bound(ends.begin(), ends.end(), e));
        curr -= distance(upper_bound(starts.begin(), starts.end(), e+k), starts.end());
        ans = max(ans,curr);
    }

    cout<<ans<<endl;

}