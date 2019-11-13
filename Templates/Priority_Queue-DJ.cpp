#include <bits/stdc++.h>
using namespace std;
inline int read();

int dis[14250], head[14250];
bool vis[14250];

struct Edge{
	int to, w, from;
}e[54250];

int cnt=0;

inline void add(int u, int v, int w)
{
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].from=head[u];
	head[u]=cnt;
}
void dijkstra(int);
struct node{
	int d, x;
	/*bool operator < (const node &nd) const{
		return d > nd.d;
	}*/
};
priority_queue<node>q;
// This kind of queue only pop the "max" data inside.
// Therefore, operator '<' should mean "shorter distance is bigger".
bool operator < (const node &x, const node &y)
{
	return x.d > y.d;
}

int main()
{
	int n=read(), m=read(), s=read();
	for(int i=0; i<m; i++){
		int u=read(), v=read(), w=read();
		add(u, v, w);
	}
	dijkstra(s);
	for(int i=1; i<=n; i++)cout<<dis[i]<<" ";
	
	return 0;
}

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s]=0;
	q.push((node){0, s});
	while(!q.empty()){
		node p=q.top();
		q.pop();
		int x=p.x;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x]; i; i=e[i].from){
			int u=e[i].to;
			if(dis[u]>dis[x]+e[i].w){
				dis[u]=dis[x]+e[i].w;
				if(!vis[u]){
					q.push((node){dis[u], u});
				}
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
