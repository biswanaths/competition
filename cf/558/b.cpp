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

map<int,int> c,l,r;

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n; cin>>n;
    rep(n) { 
        int temp; cin>>temp;
        if(c.find(temp)==c.end()) { 
            c[temp] = 1;
            l[temp] = i+1;
        } else { 
            c[temp]++;
        }
        r[temp] = i+1;
    }
    int mc=-1,ml,mr;
    For(c) { 
        if( mc < it->second) { 
            mc= it->second,ml = l[it->first], mr = r[it->first];
        }
        if( mc == it->second) {
            if( mr-ml > r[it->first] - l[it->first] ) 
                ml = l[it->first], mr = r[it->first];
        }
    }

    cout<<ml<<" "<<mr;

    return 0;
}

