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
    int n; cin>>n; 
    vector<int> v(n); 
    int nc=0, zc=0, pc=0;
    int mn=0, mni=-1;
    rep(n) { 
        cin>>v[i]; 
        if(v[i]==0) zc++; 
        else if(v[i]>0) pc++; 
        else nc++;
        if(v[i]<0) {
            if(mn==0) { mn = v[i], mni = i; };
            if(mn<v[i]) {
                mn = v[i];
                mni = i;
            }
        }
    }
    if(zc==n || (zc==n-1 && nc==1) ) {  
        rep(n-1) 
            cout<<1<<" "<<i+1<<" "<<i+2<<endl;
        return 0;
    } 
    set<int> pos;
    set<int> npos;
    bool once = true;
    rep(n) { 
        if(v[i]==0 || (nc%2==1 && i == mni)) { 
            npos.insert(i);
        } else { 
            pos.insert(i);
        }
    }
    bool first = true; 
    int prev = -1;
    for(auto i:pos) { 
        if(!first) 
            cout<<1<<" "<<prev<<" "<<i+1<<endl;
        prev = i+1;
        first = false;
    } 

    first = true; 
    int fn;

    for(auto i:npos) { 
        if(first) {
            fn = i;
            first = false;
            continue;
        }
        cout<<1<<" "<<i+1<<" "<<fn+1<<endl;
    } 

    if(npos.size()>0)
        cout<<2<<" "<<fn+1<<endl;

    return 0;
}

