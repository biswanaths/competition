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

int cs[2002];
string s,t;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m,q;
    cin>>n>>m>>q;
    cin>>s>>t;
    for(int i=0;i<n;i++) { 
        bool found = true;
        int j =0;
        for(;i+j<n && j<m;j++) { 
            found = found && (s[i+j]==t[j]);
        }
        if(j==m && found) 
            cs[i+1] = 1;
    }
//    rep(12) cout<<cs[i]<<" ";PEL;

    rep(2001)  
        cs[i+1]=cs[i+1] + cs[i];
//    rep(12) cout<<cs[i]<<" ";PEL;


    rep(q) { 
        int l,r; cin>>l>>r;
        //cout<<cs[r]<<" "<<cs[l-1-1]<<" ";
        if(r-l+1<m) cout<<0<<endl;
        else cout<<cs[r-m+1]-cs[l-1]<<endl;
    }

    return 0;
}

