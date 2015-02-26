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

int tl[1000];
int sf=500;

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int m,t,r;cin>>m>>t>>r;
    bool done = false;
    rep(m) {
        int vs;
        cin>>vs;
        if(done) continue;
        int mvs = vs +sf;
        int al=0;
        for(int j=mvs-t;j<mvs;j++) {
            if(tl[j]==1) al++; 
        }
        if(al>=r) continue;
        int bal= r-al;
        for(int j=mvs-1;j>=mvs-t&&bal>0;j--) { 
            if(tl[j]!=1) {
                tl[j]=1;
                bal--;
            }
        }
        if(bal>0) {
            done = true;
        }
    }
    if(done) {
        cout<<-1;return 0;
    }
    int s = 0 ; 
    rep(999) s+= tl[i];
    cout<<s;

    return 0;
}

