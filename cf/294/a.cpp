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



int main() 
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    string s; 
    int ans =0;
    rep(8) {
        cin>>s;
        for(int j=0;j<8;j++) { 
            if(s[j]=='Q') ans+=9;
            else if(s[j]=='q') ans-=9;
            else if(s[j]=='R') ans+=5;
            else if(s[j]=='r') ans-=5;
            else if(s[j]=='B') ans+=3;
            else if(s[j]=='b') ans-=3;
            else if(s[j]=='N') ans+=3;
            else if(s[j]=='n') ans-=3;
            else if(s[j]=='P') ans+=1;
            else if(s[j]=='p') ans-=1;
            else if(s[j]=='K') ans+=0;
            else if(s[j]=='k') ans-=0;
            else ans=ans;
        }
    }
    if(ans==0) cout<<"Draw";
    else if(ans>0) cout<<"White";
    else    cout<<"Black";
    return 0;
}

