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

int a[N];
int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int n,k; cin>>n>>k;
    int q=-1;
    rep(n) {
        string s;cin>>s; 
        if(s=="?") {
            q = i;
        }
        else {
            a[i]= stoi(s);
        }
    }
    cout<<"a"<<endl;
    if(q!=-1 &&q-k>=0) a[q]=a[q-k]+1;
    else if(q!=-1 && q+k<n) a[q]=a[q+k]-1;
    lld su = 0;
    for(int i=0;i<k;i++) { 
        su += a[i];
    }
    for(int i=k;i+k<n;i++) { 
        lld nsu = su+a[i]-a[i-k];
        if(nsu <= su) { 
            cout<<"Incorrect sequence";
            return 0;
        }
    }
    rep(n) 
        cout<<a[i]<<" ";
    
    return 0;

}

