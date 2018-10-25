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

LL f[20001][4];

LL fi(char c) { 
    if(c=='U') return 0;
    if(c=='D') return 1;
    if(c=='L') return 2;
    if(c=='R') return 3;
    return 0;
}

LL dv(char c) { 
    if(c=='U') return 1;
    if(c=='D') return -1;
    if(c=='L') return -1;
    if(c=='R') return 1;
    return 0;
}

LL hv(char c) { 
    if(c=='L') return -1;
    if(c=='R') return 1;
    return 0;
}

LL vv(char c) { 
    if(c=='U') return 1;
    if(c=='D') return -11;
    return 0;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
 
    LL n,x,y; string s; cin>>n>>s>>x>>y; 

    LL rx=x, ry=y;

    if(s.size() < abs(x)+abs(y)) { 
        cout<<-1;
        return 0;
    }
    f[0][fi(s[0])]++;

    rx = rx- hv(s[0]); 
    ry = ry- vv(s[0]); 

    for(LL i=1;i<n;i++) { 
        rx = rx- hv(s[i]); 
        ry = ry- vv(s[i]); 
        for(LL j=0;j<4;j++) { 
            f[i][j] = f[i-1][j];
        }
        f[i][fi(s[i])]++;
    }


    rep(n) { 
        for(int j=0;j<4;j++) { 
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<rx<<" "<<ry<<endl;

    LL mi = n+1; 
    for(LL left=0;left<n;left++) { 
        for(LL right = left;right<n;right++) { 
            bool  he = false, ve = false;
            bool hg = false, vg = false;

            if(rx==0) 
                he = true;
            else if( rx > 0) { 
                if(f[right][3]-f[left][3]==rx) 
                    he = true; 
                else if(f[right][3]-f[left][3]> rx)
                    hg = true;
            }
            else if( rx < 0) { 
                 if(f[right][2]-f[left][2]==rx) 
                     he = true;
                 else if(abs(f[right][2]-f[left][2])>abs(rx))
                     he = true;
            }
            if(ry==0) 
                ve = true;
            else if( ry > 0) {
                if(f[right][0]-f[left][0]==ry) 
                    ve = true; 
                else if(f[right][0]-f[left][0]>ry) 
                    vg = true; 
            }
            else if( ry < 0) { 
                if( f[right][1]-f[left][1]==ry) 
                    ve = true;
                else if( f[right][1]-f[left][1]> ry) 
                    vg = true;
            }
            if( he && ve) { 
                mi = min( mi, right-left+1);
                left++;
            }
            else if( hg || vg) left++;
            else right++;
        }
    }

    cout<<mi<<endl;


    return 0;
}

