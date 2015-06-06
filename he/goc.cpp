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

int l,b,n;

char g[102][102];


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>l>>b;
    for(int i=0;i<l;i++) {
        string s; cin>>s;
        for(int j=0;j<b;j++) 
            g[i][j] = s[j];
    }
    cin>>n;
    while(n--) {
        int h; cin>>h;
        for(int k=0;i<b;k++) { 
            if(g[b-h][k]=='x') { 
                g[b-h][k]='.';
            }
        }

        for(int i=0;i<l;i++) { 
            for(int j=0;j<b;j++) { 
                if(g
    }

    return 0;
}

