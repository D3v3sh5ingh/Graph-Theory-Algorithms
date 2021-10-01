#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void solver()
{
    ll n,p;
    cin>>n>>p;

    vector<ll> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 

    bool finder=false;

    vector<ll> strg(n,0);

    for(int i=0;i<n;i++)
    {
        if(p%arr[i]!=0)
        {

            finder=true;
            ll ans =p/arr[i] +1;
            strg[i]=ans;
            break;
        }
    }

    if(finder)
    {

        cout<<"YES ";

        for(int i=0;i<n;i++)
        {
            cout<<strg[i]<<" ";
        }

        cout<<endl;
        return;
    }

    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]%arr[i]!=0)
        {
            finder=true;
            ll first=p/arr[i]-1;
            ll second =1;

            strg[i]=first;
            strg[i+1]=second;
            break;


        }
    }

    if(finder)
    {

        cout<<"YES ";

        for(int i=0;i<n;i++)
        {
            cout<<strg[i]<<" ";
        }

        cout<<endl;
        return;
    }




    cout<<"NO"<<endl;



}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solver();
    }
    return 0;
}