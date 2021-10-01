#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int x=1;x<=t;x++)
	{
		unsigned int k, n;
		unsigned long long int v;
		cin>>n>>k>>v;
		vector<string> ar(n);
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		cout<<"Case #"<<x<<":"<<" "; 
		unsigned int temp= (k*(v-1))%n;
		int endindex=temp+k-1;
		if(endindex<n)	
		{
			for(unsigned int i=temp;i<=endindex;i++)
			{
				cout<<ar[i]<<" ";
			}
			cout<<endl;
		}
		else if(k<=n&&endindex>=n)
		{
			unsigned s2=temp;
			unsigned int e1=k-(n-temp+1);
			for(int i=0;i<=e1;i++)
			{
				cout<<ar[i]<<" ";
			}
			for(int i=s2;i<n;i++)
			{
				cout<<ar[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}