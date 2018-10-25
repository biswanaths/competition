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

LL min(LL a, LL b) { 
    return a<b?a:b;
}

LL max(LL a, LL b) { 
    return a>b?a:b;
}


LL n; 

bool solve(LL k) { 
    if(k==0) return false;
    LL v =0 , p =0;
    LL nn = n;
    while(nn>0) { 
        v+= min(nn,k), nn-= min(nn,k);
        p+= max(0,nn/10), nn-= max(0,nn/10);
    }
    return v>=p;
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n;
    LL v = 0 , p =0,b=0;  
    LL l =1,h=n;
    do { 
        LL m =  ( h+l)/2;
        //cout<<l<<" "<<m<<" "<<h<<endl;
        bool sm = solve(m), nm = solve(m+1), pm = solve(m-1);
        if(!pm && sm) {
            cout<<m;
            return 0;
        }
        if(!sm && nm ) {
            cout<<m+1;
            return 0;
        }
        else if(!sm && !nm)  { 
            l =m+1;
        }
        else if(sm && nm ) { 
            h = m;
        } 

    }while(l<h);

    return 0;
}

