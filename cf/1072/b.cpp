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
    int n; cin>>n;
    vector<int> a(n-1),b(n-1),c(n);
    rep(n-1) cin>>a[i];
    rep(n-1) cin>>b[i];

    int pos[4][4][4];
    for(int i=0;i<4;i++) 
    for(int j=0;j<4;j++) 
    for(int k=0;k<4;k++) 
        pos[i][j][k]=-1;

    for(int i=0;i<4;i++) { 
        for(int j=0;j<4;j++) { 
            //cout<<i<<" "<<j<<" "<<(i|j)<<" "<<(i&j)<<endl;
            pos[i][i|j][i&j] = j;
        }
    }

    bool ans = false;
    for(int i=0;i<4;i++) { 
        c[0] = i;
        bool found = true;
        for(int j=1;j<n;j++) { 
            int next = pos[c[j-1]][a[j-1]][b[j-1]];
            //cout<<i<<" "<<next<<endl;
            if(next ==-1) { 
                found = false;
                break;
            }
            else {
                c[j] = next;
            }
        }
        if(found) { ans= true;  break; } 
        else ans = false;
    }

    if(ans) { 
        cout<<"YES"<<endl;
        rep(n) cout<<c[i]<<" "; 
    }
    else { 
        cout<<"NO"<<endl;
    }

    return 0;
}

