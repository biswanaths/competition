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
    int n;cin>>n; 
    int one=0,two=0,three=0;
    vector<int> v(n);
    map<int,int> m; 
    rep(n) { 
        int t; cin>>t; 
        v[i]=t;
        m[t]++;
    }
    for(auto& p:m) { 
        if(p.second==1) 
            one++; 
        else if(p.second==2) 
            two++;
        else 
            three++;
    } 
    char oc='A';
    bool first = true;
    if(one%2==1 && three==0) { 
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;

    for(auto& i:v) { 
        if(m[i]==2) cout<<'A';
        else if(m[i]==1) cout<<oc, oc=(oc=='A'?'B':'A');
        else {
            if(first && (one%2==1)) 
                cout<<'B'; 
            else cout<<'A';
            first = false;
        }
    }

    return 0;
}

