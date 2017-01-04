/**
** Problem: https://www.hackerearth.com/january-easy-17/algorithm/substring-divide/
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

LL to_num(string s){
    LL num=0;
    for(char c:s){
        num=num*10+c-48;
    }
    return num;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        LL count=0;
        vector<vector<int> > v;
        vector<int> v2(3,0);
        LL rem=0;
        LOOPR(i,n-1,0){
            rem=(rem+s[i])%3;
            v2[rem]++;
            v.PB(v2);
        }
        reverse(ALL(v));
        LL sum_right=0;
        LOOPR(j,n-1,0){
            LL sum=0;
            LOOPR(i,j,0){
                //substring is from  i to j inclusive
                sum+=s[i]-48;
                LL num=to_num(s.substr(i,j-i+1));
                if(j-i+1<3){
                    if(num%8==0 && num%3!=0) count++;
                }else{
                    if(num%8==0){
                        if(sum%3!=0) count++;
                        switch(sum_right%3){
                            case 0: count+=v[0][1]+v[0][2]-v[i][1]-v[i][2];
                            break;
                            case 1: count+=v[0][0]+v[0][2]-v[i][0]-v[i][2];
                            break;
                            case 2: count+=v[0][1]+v[0][0]-v[i][1]-v[i][0];
                            break;
                        }
                    }
                    break;
                }
            }
            sum_right+=s[j]-48;
        }
        cout<<count<<endl;
    }

    return 0;
}
