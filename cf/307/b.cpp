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

int ac[26],bc[26],cc[26];

bool pb(int k) { 
    rep(26) { 
        if(k*bc[i]<=ac[i]) ;
        else return false;
    }
    return true;
}

bool pbc(int k,int l) { 
    rep(26) { 
        if(k*bc[i] + l * cc[i] <=ac[i]) ;
        else return false;
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    string a,b,c;cin>>a>>b>>c;
    rep(a.size()) ac[a[i]-'a']++;
    rep(b.size()) bc[b[i]-'a']++;
    rep(c.size()) cc[c[i]-'a']++;

    int gm = 0,gb=-1,gc=-1;
    int i=0,j=0;

    for(int i=0;pb(i);i++) { 
        int j=gm-i;
        for(; pbc(i,j);j++) {
        }
        if(j==gm-i) continue;
        if(j) j--;
        if(gm<max(gm,i+j)) {
            gm = max(gm,i+j);gb=i,gc=j;
        }
    }
    if(gm==0) { cout<<a<<endl;return 0; }
    for(int bi=0;bi<gb;bi++) cout<<b;
    for(int ci=0;ci<gc;ci++) cout<<c;
    for(int k=0;k<26;k++) { 
        for(int kk=0;kk<(ac[k]-gb*bc[k]-gc*cc[k]);kk++)
            cout<<((char )(k+'a'));
    }

    return 0;
}

