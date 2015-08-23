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

map<int,int> bb,ss;


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,s;cin>>n>>s;
    rep(n) { 
        char dir; cin>>dir;
        int p,q;cin>>p>>q;
        if(dir=='B') {
            if(bb.find(p)==bb.end()) {
                bb[p]=0;
            }
            bb[p]+=q;
        }
        else { 
            if(ss.find(p)==ss.end()) {
                ss[p]=0;
            }
            ss[p]+=q;
        }
    }
    vector< pair<int, int > > bbb,sss;
    For(bb) {
        bbb.push_back( *it);
    }
    For(ss) {
        sss.push_back( *it);
    }
    sort(sss.begin(),sss.end());
    int sz= min(s,(int)sss.size());
    rep(sz) {
        cout<<"S "<<sss[sz-i-1].first<<" "<<sss[sz-i-1].second<<endl;
    }
    sort(bbb.begin(),bbb.end());
    reverse(bbb.begin(),bbb.end());
    sz= min(s,(int)bbb.size());
    rep(sz) {
        cout<<"B "<<bbb[i].first<<" "<<bbb[i].second<<endl;
    }

    return 0;
}

