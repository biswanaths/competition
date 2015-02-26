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
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)	
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repi(n) for(int i =0;(i)<(int)(n);(i)++)
#define repj(n) for(int j =0;(j)<(int)(n);(j)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)
#define rep1n(n) for(int i=1;i<(int )(n);i++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define PB push_back
#define ST first
#define ND second
#define N 100002
#define MOD 1000000007

int n,x;
int a[100005];
map<lld,lld> c;

lld cp(lld p) {
    if(p==0) return 1;
    if(p==1) return (lld) x;
    if(c.find(p)==c.end()) {
        lld cans;
        cans = cp(p/2);
        cans = (cans * cans ) % MOD;
        if(p%2==1) {
            cans = ( cans * x) % MOD;
        }
        c[p] = cans;
        return cans;
    }
    else {
        return c[p];
    }
}


int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("D:\MyCode\Data\test.out", "w",stdout);
#endif
    cin>>n>>x;
    rep(n) cin>>a[i];
    sort(a,a+n);
    lld sum=0;
    rep((n-1)) sum+=a[i];
    int k=0;
    for(k=1;k<n&&a[k]==a[k-1];k++);
    if(k==n) {
        int xp=x;int xpp=1; 
        while(xp>n) xp= xp *x,xpp++;
        xp = xp/x;xpp--;
        if(xp==n) sum+= min(a[n-1],xpp);
        //k && n==x) sum++;
    }
    cout<<cp(sum);
    return 0; 
}
