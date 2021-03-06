#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
 
#define LIMIT 37 
 
using namespace std;
 
struct node
{
	int val;
	int index;
};
 
int N;
int binary(int number, vector <int> &ans)
{
	int start=0;
	int n=ans.size();
	int end=n-1;
	int mid;
	if(start==end)
		return 0;
	while(start!=end)
	{
		mid=(start+end)/2;
		if(ans[mid]==number)
			break;
		if(ans[mid]>number)
			end=mid;
		else
			start=mid+1;
	}
	mid=(start+end)/2;
	return mid;
}
 
void display(vector <int> &list)
{
	cout<<endl;
	for(int i=0;i<list.size();i++)
		cout<<list[i]<<" ";
	cout<<endl;
}
 
int maxsubsequence(vector <int> &list)
{
	vector <int> ans;
	int N=list.size();
	ans.push_back(list[0]);
	int i;
	//display(list);
	for(i=1;i<N;i++)
	{
		int index=binary(list[i],ans);
		/*if(index+1<ans.size())
			continue;*/
		if(list[i]<ans[index])
			ans[index]=list[i];
		if(list[i]>ans[index])
			ans.push_back(list[i]);
		//display(ans);
	}
	return ans.size();
}
 
	
 
int compute(int index, int *g)
{
	vector <int> list;
	list.push_back(g[index]);
	int itr=(index+1)%N;
	while(itr!=index)
	{
		list.push_back(g[itr]);
		itr=(itr+1)%N;
	}
	return maxsubsequence(list);
}
int solve(int *g, vector <node> list)
{
	int i;
	int ret=1;
	for(i=0;i<min(LIMIT,(int)list.size());i++)
	{
		//cout<<list[i].index<<endl;
		ret=max(ret,compute(list[i].index,g));
	}
	return ret;
}
 
bool cmp(const node &o1, const node &o2)
{
	return (o1.val<o2.val);
}
int g[10001];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>N;
		vector <node> list;
		int i;
		for(i=0;i<N;i++)
		{
			
			node temp;
			cin>>g[i];
			temp.val=g[i];
			temp.index=i;
			list.push_back(temp);
		}
		sort(list.begin(),list.end(),cmp);
		cout<<solve(g,list)<<endl;
	}
	return 0;
}
