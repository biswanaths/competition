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

string b[8];


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    rep(8) cin>>b[i];
    int mw=10,mb=10;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if( b[i][j]=='W') {
                for(int k=i;k>=0;k--) 
                    if(b[k][j]=='B') goto x;
                mw = (mw>i)?i:mw;
            } else if (b[i][j] == 'B') {
                for(int k=i;k<8;k++) 
                    if(b[k][j]=='W') goto x;
                mb = (mb>(8-i))? (8-i) : mb;
            }
            x: 
                continue;
        }
    }

    cout<<((mw<mb)?"A":"B");

    return 0;
}

