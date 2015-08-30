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
#define N 100003
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

int data[N];
int finall[N],finalr[N];


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n; cin>>n; 
    rep(n) cin>>data[i+1];

    for(int i=1;i<=n;i++) { 
        finall[i]=min(finall[i-1]+1,data[i]);
    }

    for(int i=n;i>=0;i--) { 
        finalr[i]=min(finalr[i+1]+1,data[i]);
    }

    int mans=-1;
    for(int i=0;i<=n;i++) {
        mans= max( min(finall[i],finalr[i]), mans);
    }


    cout<<mans;
    return 0;
}

