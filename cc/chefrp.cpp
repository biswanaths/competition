#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define lld long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define N 100002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

#define PB push_back
#define ST first
#define ND second

int solve(int n) {
    vector<int> a;bool np = false;
    rep(n) {
        int p; cin>>p; a.push_back(p);
        if(p<2) np = true;
    }
    if(np) return -1;
    sort(a.begin(),a.end());
    int ans=0;
    rep(a.size()) ans+=a[i];
    ans-=a[0]; ans+=2;
    return ans;
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    ios::sync_with_stdio(false);
    int t,x,y,k,n;cin>>t;
    while(t--) { 
        cin>>n; cout<<solve(n)<<endl;
    }
    return 0;
}

