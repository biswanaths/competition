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
    int n,r;cin>>n>>r;
    vector<int> v(n); 
    rep(n) cin>>v[i];
    int count = 0 ; 
    int last = 0;
    for(int i=0;i<n;) { 
        bool found = false;
        for(int j=max(0,i-r+1);j<=min(n-1,i+r-1);j++) { 
         //   cout<<i<<" "<<j<<endl;
            if(v[j]) last=j, found = true; 
        }
        if(!found) { cout<<-1; return 0; } 
        i = last+r;
        count++;
        //cout<<i<<" "<<last<<" "<<count<<endl;
    }

    cout<<count;

    return 0;
}

