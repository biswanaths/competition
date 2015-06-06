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
#define ulld unsigned long long int 
#define EOL '\0'
#define PEL cout<<endl;
#define N 200002
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define For(iterable) for(__typeof__((iterable).begin()) it = (iterable).begin(); it != (iterable).end(); ++it)

string given;


int df(string s) {
    int diff = 0;
    rep(s.size()) diff+=(s[i]!=given[i]);
    //cout<<s<<" "<<given<<" "<<diff<<endl;
    return diff;
}

string inv(string s) {
    rep(s.size()) s[i] = s[i]=='0' ?'1':'0';
    return s;
}

string con(string s,int n,int k) {
    if(s.size()==n) {
        int pc = 0;
        char prev = 'p';
        rep(n) { 
            if(s[i]==prev) {
                pc++;
                if(pc >k ) {
                    return inv(given);
                }
            }
            else  pc =1; 
            prev = s[i];
        }
        return s;
    }
    string s0 = con(s+"0",n,k);int s0l = df(s0);
    string s1 = con(s+"1",n,k);int s1l = df(s1);
    if(s0l < s1l) return s0;
    else return s1;
}


string bf(int n,int k) {
    string start = "";
    return con(start,n,k); 
}

string solve(string s,int n, int k) {
    if(k==1) {
        string s0=s,s1=s; 
        rep(s.size()) s0[i] = (i%2)?'1':'0', s1[i] = (i%2)?'0':'1';
        if(df(s0)<df(s1)) return s0; else return s1;
    }

    string ss = "p" + s + "p";
    char prev = 'p';
    int pc =0;

    for(int i=1;i<ss.size()-1;i++) {
        if(ss[i]==prev) {
            pc++;
            if(pc>k) {
                if(ss[i+1]!= prev)
                    ss[i-1] = (prev=='0' ?'1':'0');
                else 
                    ss[i] = (ss[i]=='0' ?'1':'0');
            }
        } else {
            pc =1;
        }
        prev = ss[i];
    }
    string sss = s;
    rep(s.size()) sss[i] = ss[i+1];
    return sss;
}

int main() 
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif
    int t; cin>>t;
    while(t--) { 
        int n,k; cin>>n>>k;
        string s; cin>>s;
        given = s;
        string ss = solve(s,n,k);
        cout<<df(ss)<<endl<<ss<<endl;
        //cout<<bf(n,k)<<endl;
    }

    return 0;
}

