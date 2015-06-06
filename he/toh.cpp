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

lld solve(vector< PII > d ) { 
    sort(d.begin(),d.end()); reverse(d.begin(),d.end());
    vector<lld> ds(d.size());
    rep(d.size()) ds[i] = d[i].second;
    for(int i=0;i<d.size();i++) { 
        for(int j=0;j<i;j++) { 
            PII di=d[i],dj=d[j];
            if(di.first< dj.first && di.second<dj.second) {
                if(ds[i] < ds[j] + (lld )di.second) {
                    ds[i] = ds[j] + (lld ) di.second;
                }
            }
        }
    }
    lld mh = 0;
    rep(ds.size()) 
        mh = max(mh,ds[i]);
    return mh;

}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t;cin>>t;
    while(t--) { 
        int n; cin>>n;
        vector< PII > disks(n);
        rep(n) 
            cin>>disks[i].first>>disks[i].second;
        cout<<solve(disks)<<endl;
    }

    return 0;
}

