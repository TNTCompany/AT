#include <bits/stdc++.h>
using namespace std;
inline void fgets(char[]);

char test[16];

int main()
{
	fgets(test);
	cout<<test<<endl;
	return 0;
}




inline void fgets(char ch_C[])
{
	memset(ch_C, 0, sizeof(ch_C)/sizeof(char));
	char ch_R = getchar();
	unsigned int cnt=0;
	while(ch_R != '\n'){
		ch_C[cnt++] = ch_R;
		ch_R = getchar();
	}
}

