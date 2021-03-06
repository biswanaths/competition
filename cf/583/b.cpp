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
#define N 1002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

int n; int a[N];

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n;
    rep(n) { 
        cin>>a[i];
    }


    int turn =0; int collected=0;
    while(1) {
        rep(n) { 
            if(a[i]!=-1 && a[i]<= collected) a[i]=-1,collected++;
        }

        if(collected==n) break;
        turn++;
        for(int i=n-1;i>=0;i--) { 
            if(a[i]!=-1 && a[i]<= collected) a[i]=-1,collected++;
        }
        if(collected==n) break;
        turn++;
    }

    cout<<turn;

    return 0;
}

