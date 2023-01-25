/*
Solved by Insoo Chung (limeorannge/Saycorn)
Problem link: https://www.acmicpc.net/problem/27231
*/
#define rp ' '
#define ln '\n'
#define ll long long
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
void dbg(){puts("okay");}
ll n;
ll cut[11];
ll digits[11];
ll cut_number(ll s, ll e){
    stack<ll> st;
    ll c = n;
    ll ans = 0;
    for(ll i=0; i<s; i++) c/=10;
    for(ll i=s; i<e; i++){
        st.push(c%10);
        c/=10;
    }
    while(!st.empty()){
        ans*=10;
        ans+=st.top();
        st.pop();
    }
    return ans;
}
ll pow(ll n, ll k){
    ll ans = 1;
    for(ll i=1; i<=k; i++){
        ans*=n;
    }
    return ans;
}
int main(){
    ll Q;
    cin >> Q;
    while(Q--){
        set<ll> ss;
        stack<ll> candidates;
        cin >> n;
        ll l = 0;
        ll c = n;
        bool infpos = 1;
        while(c>0){
            l++;
            if(c%10==0 || c%10==1);
            else infpos = 0;
            digits[l] = c%10;
            c/=10;
        }
        if(infpos){
            cout << "Hello, BOJ 2023!" << ln;
            continue;
        }
        ll ans = 0;
        for(ll i=0; i<1<<(l-1); i++){
            ll now = 0;
            ll cnt = 0;
            for(ll j=1; j<=l-1; j++){
                if((1<<(j-1))&i){ //j번째 문자가 존재함
                    cut[cnt++] = cut_number(now, j);
                    now = j;
                }
            }
            cut[cnt++] = (cut_number(now, l));
            ll m = 1;
            ll target = 0;
            //dbg();
            for(ll i=0; i<cnt; i++){
                //cout << cut[i] << ln;
                target+=cut[i];
            }
            while(1){
                ll sum = 0;
                for(ll i=1; i<=l; i++){
                    sum+=pow(digits[i], m);
                }
                if(sum==target){
                    ss.insert(m);
                    break;
                }
                else if(sum>target) break;
                m++;
            }
        }
        cout << ss.size() << ln;
    }
}