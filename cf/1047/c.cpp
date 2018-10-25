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

int gcd(int a, int b) { 
    if(b==0) return a; 
    return gcd(b,a%b);
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n; cin>>n;
    vector<int> v(n);
    bool first = true;
    int g;

    rep(n) { 
        cin>>v[i]; 
        if(first) g=v[i], first=false;
        g = gcd(g,v[i]);
    }


    map<int,int> f;
    rep(n) {
        int c = v[i]/g;
        if(c%2==0) f[2]++;
        while(c%2==0) c/=2;
        int k =3; 
        while(k*k<=c) {
            if(c%k==0) f[k]++;
            while(c%k==0) c/=k;
            k+=2;
        }
        if(c>1) f[c]++;
    }

    //cout<<g<<endl;

    int mf = -1;

    for(auto &x:f) { 
     //   cout<<x.first<<" "<<x.second<<endl;
        mf = max(mf, x.second);
    }
    if(mf==-1 || n==mf)
        cout<<-1;
    else 
        cout<<n-mf;

    return 0;
}

