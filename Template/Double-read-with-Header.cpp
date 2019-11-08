#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <cstdlib>
#include <list>
using namespace std;
inline double read();
double ans;
int main()
{
	double n=read();
	return 0;
}




inline double read()
{
	double x=0; int w=1; unsigned int cnt=10; char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	while(ch=='.'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x+(double)(ch-'0')/(double)cnt; cnt*=10; ch=getchar();}
	return x==0?x:x*w;
}
