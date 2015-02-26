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

int pa[N],ap[N];


int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m,k;lld ans=0;cin>>n>>m>>k;
    rep(n) { cin>>pa[i+1];ap[pa[i+1]]=i+1;}

    rep(m) {
        //rep(n) cout<<pa[i+1]<<" "; cout<<endl;
        //rep(n) cout<<ap[i+1]<<" "; cout<<endl;
        int a,p; cin>>a;
        p = ap[a];
        if(p%k==0) ans+=p/k;
        else ans+= (p/k)+1;
        //cout<<ans;PEL;
        if(p!=1) {
            int temp = pa[p];
            pa[p]=pa[p-1];
            pa[p-1] = temp;
            ap[pa[p-1]]--;
            ap[pa[p]]++;
        }
    }
    cout<<ans;

    return 0;
}

