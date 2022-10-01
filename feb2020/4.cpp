#include <bits/stdc++.h> 
using namespace std;
#define ll long long
int perm(vector<vector<ll>> arr,string ques,int itr)
{
    if(itr==ques.length())
    {
        int ans=0;
        vector <ll> strg {
            arr[(ques[0]-65)][0],
            arr[(ques[1]-65)][1],
            arr[(ques[2]-65)][2],
            arr[(ques[3]-65)][3],
            };


        sort(strg.begin(),strg.end(),greater<>() );


        int price=100;
        for(int i=0;i<4;i++)
        {
            if(strg[i]==0)
            {
                ans-=100;
            }
            else
            {
                ans+=strg[i]*price;
            }

            price-=25;

        }
        return ans;
    }

    int ans=-500;
    for(int i=itr;i<ques.length();i++)
    {
        string ques2=ques;
        char ch=ques2[itr];
        ques2[itr]=ques2[i];
        ques2[i]=ch;

        ans=max(ans,perm(arr,ques2,itr+1));
    }

    return ans;
}


int main() {
	long long  t,maxsum=0;
	cin>>t;
	long long int res=0;
	while(t--){
	    long long  n,ans=0,num;
	    char ch;
	    cin>>n;
	    if(n==0)
	    {
	        ans=-400;
			cout<<ans<<endl;
			res-=400;
	    }
	    else{
	    vector<vector<long long > > arr( 4 , vector<long long > (4, 0));  
	    bool b[4];
	    long long  maxs[4];
	    int maxala=INT_MIN;
	    while(n--){
	        cin>>ch>>num;
	        if(ch == 'A'){
	            if(num== 12)
	            arr[0][0]+=1;
	            else if(num ==3)
	            arr[0][1]+=1;
	            else if(num == 6)
	            arr[0][2]+=1;
	            else if(num==9)
	            arr[0][3]+=1;
	        }
	        else if(ch == 'B'){
	            if(num== 12)
	            arr[1][0]+=1;
	            else if(num ==3)
	            arr[1][1]+=1;
	            else if(num == 6)
	            arr[1][2]+=1;
	            else if(num==9)
	            arr[1][3]+=1;
	        }
	        else if(ch == 'C'){
	            if(num== 12)
	            arr[2][0]+=1;
	            else if(num ==3)
	            arr[2][1]+=1;
	            else if(num == 6)
	            arr[2][2]+=1;
	            else if(num==9)
	            arr[2][3]+=1;
	        }
	        else{
	            if(num== 12)
	            arr[3][0]+=1;
	            else if(num ==3)
	            arr[3][1]+=1;
	            else if(num == 6)
	            arr[3][2]+=1;
	            else if(num==9)
	            arr[3][3]+=1;
	        }
		} 
		 int ans=perm(arr,"ABCD",0);
				cout<<ans<<endl;
			res+=ans;

		}
				// cout<<ans<<endl;

	}
		
		cout<<res<<endl;
		 
		

	return 0;
}