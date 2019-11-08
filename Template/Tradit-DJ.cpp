#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
inline int read();

struct Edge//前向星存边
{
	int to;//此边的子节点
	int w;//此边的权值
	int from;//与它最近的父节点一样的边的编号
}e[1000001];
int head[200001];//以某点为父节点引出的最后一条边
/*unsigned*/ int cnt=0;//边编号


bool vis[200001];
long long dis[200001];


inline void add(int u, int v, int w)//add Edge
{
	e[++cnt].to=v;
	e[cnt].w=w;
	
	e[cnt].from=head[u];
	head[u]=cnt;//更新head
}

void dijkstra(int);

int n, m, s;
int main()
{
	n=read(), m=read(), s=read(); 
	//n->number of Points  m->number of Edges  s->Source point
	
	for(int i=0; i<m; i++){
		int u=read(), v=read(), w=read();
		add(u, v, w);
		//no direction: add(v, u, w);
	}
	
	dijkstra(s);
	
	for(int i=1; i<=n; i++) printf("%lld ", dis[i]);
	return 0;
}



void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	//vis[] 是否作为过起点
	memset(vis, 0, sizeof(vis));	//距离
	int x=s;
	dis[s]=0;
	//long long minn;
	while(!vis[x])//即搜完整张图
	{
		vis[x]=1;//已做为过起点
		for(int i=head[x]; i; i=e[i].from)//链式前向星搜边
		{
			if(!vis[e[i].to]&&dis[e[i].to]>dis[x]+e[i].w)
			dis[e[i].to]=dis[x]+e[i].w;//更新操作
		}
		long long mn=0x7f7f7f7f;
		for(int i=1; i<=n; i++)
		{
			if(!vis[i] && mn>dis[i])//取新的最小值
			{
				mn=dis[i];
				x=i;
			}
		}
	}
}



inline int read()
{
	int x=0, w=1; char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*w;
}
