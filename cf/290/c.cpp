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
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)	
#define rep(n) for(int i =0;(i)<(int)(n);(i)++)
#define repi(n) for(int i =0;(i)<(int)(n);(i)++)
#define repj(n) for(int j =0;(j)<(int)(n);(j)++)
#define repij(n,m) for(int i =0;(i)<(int)(n);(i)++) for(int j =0;(j)<(int)(m);(j)++)
#define rep1n(n) for(int i=1;i<(int )(n);i++)

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
                  std::ostringstream() << std::dec << x ).str()

#define PB push_back
#define ST first
#define ND second

int cc[26], g[26][26],n;
string ins[102];

int visited[26];
int p =0;

bool cycle(int start,int a,bool first) { 
    //cout<<a<<"-> ";
    if((!first) && start==a) return true;
    visited[a]=1;
    for(int i=0;i<26;i++) {
        if(g[a][i]==1&&visited[i]==1&&i==start) 
            return true;
        if(g[a][i]==1&&visited[i]==0) 
            if(cycle(start,i,false)) return true;
    }
    return false;
}

int main() 
{
#ifndef ONLINE_JUDGE
	//freopen("test.in", "r",stdin);
	//freopen("test.out", "w",stdout);
#endif 
    cin>>n;
    rep(n) cin>>ins[i];

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int k=0;
            for(;k<min(ins[i].size(),ins[j].size());k++) {
                if(ins[i][k]==ins[j][k]) continue;
                if(g[ins[i][k]-'a'][ins[j][k]-'a']==0) 
                cc[ins[j][k]-'a']++;
                g[ins[i][k]-'a'][ins[j][k]-'a'] = 1;
                break;
            }
            if(k==min(ins[i].size(),ins[j].size()) && ins[i].size() > ins[j].size()) {
                cout<<"Impossible"; return 0;
            }
        }
    }
/*
    for(int i=0;i<26;i++) {
        cout<<(char ) (i+'a')<<": ";
        for(int j=0;j<26;j++) 
            cout<<(g[i][j]?(char)(j+'a'):'0')<<" ";
        cout<<endl;
    }*/
    int found = false;
    rep(26) if(cc[i]==0) { found = true; break; }
    if(!found) { 
        cout<<"Impossible"; 
        return 0;
    }
    for(int i=0;i<26;i++) {
        if(cc[i]!=0) {
            rep(26) visited[i]=0;
            //cout<<endl;
            if(cycle(i,i,true)) { 
                cout<<"Impossible"; 
                return 0;
            }
        }
    }

    //rep(26) cout<<cc[i]<<endl;

    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            if(cc[j]==i) 
                cout<<(char) (j+'a');
        }
    }

    return 0;
}

