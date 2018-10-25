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


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m,d;cin>>n>>m>>d;
    vector<int> t(n);
    rep(n) cin>>t[i];
    vector<int> st(t);
    sort(st.begin(),st.end());
    vector<int> dmt(n);
    int ud = 0;
    for(int i=0;i<n;i++) { 
        int ct = st[i];
        if(dmt[ct]+d<ct) {
            dmt[ct] = ct;
        }
        else if(ct+1<ud) { 
            if(dmt[ct+1]+d < ct) {
                dmt[ct+1]= ct;
            }
        }
        else if(ct==ud
    }


    rep(n) cout<<td[t[i]]<<" ";

    cout<<"good"<<endl;

    return 0;
}

