/**
** Problem: https://www.hackerearth.com/december-clash-16/algorithm/gcd-strings/
**/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <limits>
#include <functional>
using namespace std;
#define LOOP(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define LOOPE(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPL(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define LOOPR(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB(item) push_back(item)
#define MP(item1,item2) make_pair((item1),(item2))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define ULL unsigned long long int
#define LL long long int
#define MOD 1000000007L
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
typedef list<pair<int,int> > LPII;
typedef vector<list<pair<int,int> > > VLPII;
typedef unordered_map<int,int> UMII;
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }

template<class T1> void DEBUG(T1 e1){    cout << e1 << endl;}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2){    cout << e1 << ", " << e2 << endl;}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3){    cout << e1 << ", " << e2 << ", " << e3 << endl;}
template<class T1,class T2,class T3,class T4> void DEBUG(T1 e1, T2 e2, T3 e3, T4 e4){    cout << e1 << ", " << e2 << ", " << e3 << ", " << e4 << endl;}

void gcd(vector<bool> &v, int a, int b){
    if(a%b==0){
        v.PB(1);
        a--;
        while(a--) v.PB(0);
    }
    else{
        gcd(v,b,a%b);
        int len=v.size();
        a-=len;
        while(a>=len){
            v.insert(v.end(),v.begin(),v.begin()+len);
            a-=len;
        }
        v.insert(v.end(),v.begin(),v.begin()+a);
    }
}
int main(){

    int T,x,y;
    cin>>T;
    while(T--){
        cin>>x>>y;
        vector<bool> v;
        gcd(v,x,y);
        int answer=0,power=1;
        if(v.back()==1) answer=1;
        LOOPR(i,v.size()-2,0){
            power=(power*2)%MOD;
            if(v[i]==1) answer=(answer+power)%MOD;
        }
        cout<<answer<<endl;
    }

    return 0;
}
