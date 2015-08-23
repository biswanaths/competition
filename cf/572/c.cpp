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
#define N 300002
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
    int a,b,c,l;cin>>a>>b>>c>>l;
    int ans=0;
    for(int i=0;i<=l;i++) { 
        for(int j=0;j<=c&&j+i<=l;j++) {
            int A=a+i,B=b+j,C=c;
            if(A+B>C && A+C>B && B+C>A) {
                ans++;
            }
        }
    }
    for(int i=0;i<=l;i++) { 
        for(int j=0;j<=b&&j+i<=l;j++) {
            int A=a+i,B=b,C=c+j;
            if(A+B>C && A+C>B && B+C>A) {
                ans++;
            }
        }
    }
    for(int i=0;i<=l;i++) { 
        for(int j=0;j<=a&&j+i<=l;j++) {
            int A=a,B=b+i,C=c+j;
            if(A+B>C && A+C>B && B+C>A) {
                ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}

