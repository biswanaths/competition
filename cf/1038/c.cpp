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

int a[N], b[N];


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;cin>>n;
    LL A=0, B=0;
    rep(n) cin>>a[i];
    rep(n) cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    bool turnA = true;
    int i = n-1, j= n-1;
    while(i>=0 && j>=0) {
        if(turnA) { 
            if( a[i] >= b[j])  
                A+=a[i],i--;
            else 
                j--;
        } else { 
            if(a[i] <= b[j])  
                B+=b[j],j--;
            else 
                i--;
        }
        turnA = !turnA;
        //cout<<i<<" "<<j<<" "<<A<<" "<<B<<endl;
    }

    while(i>=0) { 
        if(turnA) A+=a[i];
        turnA = !turnA;
        i--;
    }

    while(j>=0) { 
        if(!turnA) B+=b[j];
        turnA = !turnA;
        j--;
    }

    cout<<A-B;

    return 0;
}

