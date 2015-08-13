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

int cw[102];

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,m;cin>>n>>m;
    int cm, mi,temp;
    for(int i=0;i<m;i++) { 
        mi = 0 , cm = -1;
        for(int j=0;j<n;j++) { 
            cin>>temp;
            if(temp>cm) { 
                cm = temp; 
                mi = j ; 
            }
        }
        cw[mi]++;
    }
    mi =  0 , cm = -1;
    for(int i=0;i<n;i++) { 
        if(cw[i] > cm) { 
            cm = cw[i];
            mi = i;
        }
    }
    cout<<mi+1;

    return 0;
}

