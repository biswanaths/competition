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
#define N 500002
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

int u[N];
int c[N];

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    std::ios::sync_with_stdio(false);

    string s;
    cin>>s;
    int z = s.size();
    double p = 0.0;
    for(int i=0;i<z;i++) {
        u[i] = ( s[i] =='I' || s[i] =='E' || s[i] =='A' || s[i] =='O' || s[i] =='U' || s[i] =='Y' );
        p += u[i];
        c[i] = u[i];
    }

    for(int i=1;i<z;i++) {
        int pp = 0 ;
        for(int j=0;j+i<z;j++) {
            c[j]=c[j]+u[j+i];
            pp += c[j];
        }
        p += ( (( double) pp)/ (double)(i+1));
    }
    cout<<setprecision(7)<<p;

    return 0;
}

