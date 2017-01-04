/**
** Problem: https://www.hackerearth.com/january-easy-17/algorithm/one-sized-game/
**/
#include<bits/stdc++.h>
using namespace std;
#define LOOP(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPR(i,u,l) for(int (i)=(int)(u);(i)>=(int)(l);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define LL long long int
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }
template<class T1> void DEBUG(T1 e1){    cout << e1 << endl;}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2){    cout << e1 << ", " << e2 << endl;}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3){    cout << e1 << ", " << e2 << ", " << e3 << endl;}

int get_actual_index(map<int,int> &m,int n,int index){
    auto it=m.lower_bound(n-index);
    if(it==m.end()) return index;
    else return index-it->second;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        VPII v(n);
        LOOP(i,0,n-1){
            cin>>x;
            v[i].first=x;
            v[i].second=i+1;
        }
        sort(ALL(v));
        LL neg=0,deleted=0;
        map<int,int> m;
        LOOP(i,0,n-1){
            int index=get_actual_index(m,n,i);
            
        }
        if(deleted==n-1) cout<<"Ladia"<<endl;
        else cout<<"Kushagra"<<endl;
    }

    return 0;
}
