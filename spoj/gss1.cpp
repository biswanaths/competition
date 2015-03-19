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

#define PB push_back
#define ST first
#define ND second


int d[1000000];

long long query(int a,int b) {
    long long sum=0;
    long long max=-99999999999LL;
    for(int i=a;i<=b;i++) {
        sum += d[i];
        if( sum > max) {
            max = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    return max;
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n;
    cin>>n;
    int r,m,a,b;
    for(int i=1;i<=n;i++) {
        cin>>r;
        d[i]=r;
    }   
    cin>>m;
    while(m--) {
        cin>>a>>b;
        cout<<query(a,b);
    }
}




