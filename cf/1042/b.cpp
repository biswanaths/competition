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

map<int,int> mp;

int key(string s) { 
    int k=1;
    rep(s.size()){ 
        k*=s[i];
    }
    return k;
}

bool all(int a) { 
    return a%'A'==0 && a%'B'==0 && a%'C'==0;
}


int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,p; cin>>n;string s;
    rep(n) { 
        cin>>p>>s;
        int k = key(s);
        if(mp.find(k)!=mp.end()) {
            mp[k] = min(mp[k],p);
        } else { 
            mp[k] = p;
        }
    }
    mp[1] = 0;
    int price = 1410065408;
    bool found = false;
    for ( const auto &i : mp) {
        for ( const auto &j : mp) {
            for ( const auto &k : mp) {
                if(all(i.first*j.first*k.first)) { 
                    price = min(price, i.second + j.second+k.second);
                    found = true;
                }
            }
        }
    }
    cout<<(found?price:-1)<<endl;

    return 0;
}

