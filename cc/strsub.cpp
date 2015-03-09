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

#define PB push_back
#define ST first
#define ND second

int n,k,q;
string s;
int l,r;
int z='0';
int o='1';

int cs(int p) { 
    if(p==0) return 0;
    return (p * (p+1))/2;
}

int solve(int l,int r) {
    int w=0,b=0;
    int i=l,j=l;
    int d =0;
    int ans = 0;
    for(;i<=r && j<=r;){ 
        //cout<<i<<" "<<j<<endl;
        w+=s[j]==z,b+=s[j]==o;
        if(w<=k && b<=k) {
            j++;
            d = j-i;
        }
        else {
            ans+= cs(d); 
            d =0;
            w-=s[i]==z,b-=s[i]==o;
            i++;
        }
        cout<<"d: "<<d<<endl;
    }
    ans+=cs(d);
    return ans;
}

int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    while(t--) { 
        cin>>n>>k>>q;
        cin>>s;
        cout<<s<<endl;
        while(q--) {
            cin>>l>>r;
            cout<<solve(l-1,r-1)<<endl;
            //solve(l-1,r-1);
        }
    }

    return 0;
}

