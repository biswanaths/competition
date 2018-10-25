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

set<int> done;
map<int,int> freq;
int n,t;
lld ans;

void pfq() { 
    for (auto it = freq.begin(); it != freq.end(); it++)
        std::cout << (*it).first << " => " << (*it).second << '\n';
    cout<<"size -------"<<freq.size()<<endl;
}



int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    cin>>n;
    vector<int> v(n);
    rep(n)  cin>>t,v[i]=t,freq[t]++;
    rep(n) { 
        freq[v[i]]--;
        if(freq[v[i]]==0) {
            freq.erase(v[i]);
        }
        if(done.find(v[i])==done.end()) { 
            ans+= (lld )freq.size();
        }
        done.insert(v[i]);
        //pfq();
    }
    cout<<ans;

    return 0;
}

