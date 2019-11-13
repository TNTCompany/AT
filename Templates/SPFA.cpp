#include <bits/stdc++.h>
using namespace std;
inline int read();

struct Edge{
	int to;
	int w;
	int from;
}e[200001];

int head[100001];
int d[100001];
bool vis[100001];

int cnt=0;

queue<int>q;

void spfa(int);

void add(int u, int v, int w)
{
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].from=head[u];
	head[u]=cnt;
}

int n, m, s;

int main()
{
	cin>>n>>m>>s;
	for(int i=0; i<m; i++){
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	spfa(s);
	for(int i=1; i<=n; i++)cout<<d[i]<<" ";
	return 0;
}

void spfa(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(d, 0x3f, sizeof(d));
	d[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x]; i; i=e[i].from){
			if(d[e[i].to] > d[x]+e[i].w){
				d[e[i].to]=d[x]+e[i].w;
				if(!vis[e[i].to]){
					vis[e[i].to]=1;
					q.push(e[i].to);
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
