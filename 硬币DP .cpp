//最少硬币 
#include<bits/stdc++.h>
using namespace std;
const int MONEY=251;       //最大金额 
const int VALUE=5;        //5种硬币
int type[VALUE]={1,5,10,25,50};  //5种面值 
int Min[MONEY];             //金额所对应的最少硬币数
int Min_path[MONEY]={0}; 

void solve(){
	for(int k=0;k<MONEY;k++)   //初始值为无穷大 
	  Min[k]=INT_MAX;
	Min[0]=0;
	for(int j=0;j<VALUE;j++)
	   for(int i=type[j];i<MONEY;i++){
	   //Min[i]=min(Min[i],Min[i-type[j]]+1);  //递推式 
	   if(Min[i]>Min[i-type[j]]+1)   //Min[]为无穷大  
	   Min_path[i]=type[j];         //记录路径 
	   Min[i]=Min[i-type[j]]+1;
       }
}

void print_ans(int *Min_path,int s){    //打印硬币组合 
	while(s){
		cout<<Min_path[s]<<" ";
		s=s-Min_path[s];
	}
} 

int main(){
	int s;
	solve();
	while(cin>>s){
		cout<<Min[s]<<endl;
		print_ans(Min_path,s);
	}
	return 0;
} 


//所有硬币组合有多少种 
#include<bits/stdc++.h>
using namespace std;
const int COIN = 101;                   //题目要求不超过100个硬币
const int MONEY = 251;                  //题目给定的钱数不超过250
int dp[MONEY][COIN] = {0};              // DP转移矩阵
int type[5] = {1, 5, 10, 25, 50};      //5种面值
void solve() {                             // DP
    dp[0][0] = 1;
    for(int i=0; i<5; i++)
        for(int j=1; j<COIN; j++)
            for(int k = type[i]; k < MONEY; k++)
                dp[k][j] += dp[k-type[i]][j-1];
}
int main() {
    int s;
    int ans[MONEY] = {0};
    solve();                          //用DP计算完整的转移矩阵
    for(int i=0; i< MONEY; i++)   //对每个金额，计算有多少种组合方案。打表
        for(int j=0; j<COIN; j++)  //从0开始，注意 dp[0][0]=1
            ans[i] += dp[i][j];
    while(cin >> s)
        cout << ans[s] << endl;
    return 0;
}
