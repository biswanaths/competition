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


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int ans=-1,n;
    cin>>n;
    vector<PII > males,females;
    for(int i=0;i<n;i++) { 
        char c;int s,e;
        cin>>c>>s>>e;
        if(c=='M') 
            males.push_back(make_pair(s,e));
        else 
            females.push_back(make_pair(s,e));
    }
    for(int i=1;i<=366;i++) {
        int m=0,f=0;
        For(males) 
            if(it->first <= i && i <= it->second) m++;
        For(females) 
            if(it->first <= i && i <= it->second) f++;
        ans = max( ans, 2 * min(m,f));
    }
    cout<<ans;

    return 0;
}

