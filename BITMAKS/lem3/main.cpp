#include <bits/stdc++.h>
using namespace std;

int n, c[20][20], f[1<<17][20];
int main() {
	cin >> n;
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) cin >> c[i][j];
	memset(f, 0x1f, sizeof(f));
	for(int i=0;i<n;++i) f[1<<i][i] = 0;
	for(int b=1;b<(1<<n);++b)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j) if((b&(1<<j))==0)
				f[b|(1<<j)][j] = min(f[b|(1<<j)][j],f[b][i] + c[i][j]);
	cout << *min_element(f[(1<<n)-1], f[(1<<n)-1]+n) << endl;
	return 0;
}
