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
    int n,m;cin>>n>>m;
    int r,c;
    int f = 0, l = 0;
    rep(n) {
        string s; cin>>s;
        if(f) continue;
        for(int k=0;k<m;k++) { 
            if(!f && s[k]=='B') { 
                f = k+1;
            }
            if(f && !l && s[k] == 'W') {
                l = k;
            }
        }
        if(f&& !l) l = m;
        if(f) r = i+1;
    }
    //cout<<r<<f<<l<<endl;
    cout<<r+((l-f)/2)<<" "<<f+((l-f)/2);


    return 0;
}

