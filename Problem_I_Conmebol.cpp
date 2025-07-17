#include<bits/stdc++.h>
#define INI cin.tie(0)->sync_with_stdio(0);
#define forn(i,n) for(int i=0;i<n;i++)
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define par pair<string,int>
typedef long long ll;
using namespace std;
par ganador(par a,par b)
{
    if(a.second>b.second)
        return {a.first,abs(a.second-b.second)};
    else if(a.second==b.second)
        {
            if(lexicographical_compare(a.first.begin(),a.first.end(),b.first.begin(),b.first.end()))
                return {a.first,abs(a.second-b.second)};
            else
               return {b.first,abs(a.second-b.second)};
        }
    else
        return {b.first,abs(a.second-b.second)};
}
void ganadorfinal(par a,par b)
{
     if(a.second>b.second)
        cout<<a.first<<'\n'<<b.first;
    else if(a.second==b.second)
    {
        if(lexicographical_compare(a.first.begin(),a.first.end(),b.first.begin(),b.first.end()))
            cout<<a.first<<'\n'<<b.first;
        else
            cout<<b.first<<'\n'<<a.first;
    }
    else
        cout<<b.first<<'\n'<<a.first;
}
void solve()
{
    int n;cin>>n;
    queue<pair<par,par>>cola;
    fore(i,1,n/2)
    {
        string cad1,cad2;int n1,n2;cin>>cad1>>n1>>cad2>>n2;
        cola.emplace(make_pair(cad1,n1),make_pair(cad2,n2));
    }
    while(cola.size()!=1)
    {
        string cad1=cola.front().first.first,cad2=cola.front().second.first;
        int n1=cola.front().first.second,n2=cola.front().second.second;
        cola.pop();
        string cad1_1=cola.front().first.first,cad2_1=cola.front().second.first;
        int n1_1=cola.front().first.second,n2_1=cola.front().second.second;
        cola.emplace(make_pair(ganador({cad1,n1},{cad2,n2}),(ganador({cad1_1,n1_1},{cad2_1,n2_1}))));
        cola.pop();
    }
    string cad1=cola.front().first.first,cad2=cola.front().second.first;
    int n1=cola.front().first.second,n2=cola.front().second.second;
    ganadorfinal({cad1,n1},{cad2,n2});
}
main()
{
    solve();
}

