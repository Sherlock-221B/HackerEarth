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

VI bits;

LL query(LL index){
    LL value=0;
    for(LL i=index;i>0;i-=i&(-i)) value+=bits[i];
    return value;
}

void update(LL index,LL value){
    int n=bits.size();
    for(LL i=index;i<n;i+=i&(-i)) bits[i]+=value;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        VPII v(n);
        LOOP(i,0,n-1){
            cin>>v[i].first;
            v[i].second=i+1;
        }
        sort(ALL(v));
        bool won=false;
        LL neg=0;
        bits.assign(n+1,0);
        LOOP(i,0,n-1){
            if(v[i].first-neg>=0){
                if(i==n-1){
                    won=true;
                    break;
                }
                LL actual_value=v[i].first-neg;
                LL actual_index=v[i].second-query(v[i].second);
                neg += (actual_value/actual_index + 1)*actual_index;
            }
            update(v[i].second,1);
        }
        if(won) cout<<"Ladia"<<endl;
        else cout<<"Kushagra"<<endl;
    }

    return 0;
}
