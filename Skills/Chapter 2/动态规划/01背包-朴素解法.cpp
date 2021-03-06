#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;
int weight[MAX_N]={0},value[MAX_N]={0},n,max_w;
//从第i个物品开始挑选总重小于w的部分 
int rec(int i,int w)
{
	int ans;
	//没有剩余的物品了 
	if(i==n)
		ans=0;
	//无法挑选这个物品 
	else if(w<weight[i]) 
		ans=rec(i+1,w);
	//挑选和不挑选都尝试一下 
	else
		ans=max(rec(i+1,w-weight[i])+value[i],rec(i+1,w));
	return ans;
}
void solve()
{
	cout<<rec(0,max_w)<<endl;
}
int main()
{
	freopen("in.txt","r",stdin);
	while (cin>>n&&n)
	{
		for(int i=0;i<n;++i)
			cin>>weight[i]>>value[i];
		cin>>max_w;
		solve();
	}
	fclose(stdin);
	return 0;
}

