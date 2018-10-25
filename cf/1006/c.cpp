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
#define N 200002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

LL p[N],s[N],v[N];


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n; cin>>n;

    rep(n) { 
        cin>>v[i+1];
        p[i+1] += p[i] + v[i+1];
        //cout<<p[i+1]<<" ";
    }
    //PEL;
    rep(n)  
        s[n-i] = s[n-i+1] + v[n-i];
    //rep(n) 
    //    cout<<s[i+1]<<" ";
    //PEL;
    LL ans=0;

    for(int i=1,j=n;;) { 
        //cout<<p[i]<<" "<<s[j]<<endl;
        if(i>=j) break;
        if(p[i]==s[j]) { 
            ans = p[i];
            i++,j--;
        }
        if(p[i]<s[j]) i++; 
        else if(p[i]>s[j]) j--; 
    }

    cout<<ans<<endl;

    return 0;
}

