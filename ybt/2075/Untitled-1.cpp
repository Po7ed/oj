#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(string a[], string b[]){
	// 如果身高相同
	if(a[0] == b[0])
		// 按照名字升序排序
		return a[1] <= b[1];
	else
		// 按照身高升序排序
		return a[0] <= b[0];
}

int main() {
	int n=5;
	string name[5]={"lili", "kim", "alice", "wula", "hola"};
	string height[5]={"168", "160", "160", "175", "180"};
	// 动态创建二维数组
	string **info = new string*[n];
	for(int i=0; i<n; i++){
		info[i] = new string[2];
		info[i][0] = height[i];
		info[i][1] = name[i];
	}
	// 排序
	sort(info, info+n, cmp);
	// 输出
	for(int i=0; i<n; i++){
		cout << i << " " << info[i][0] << " " << info[i][1] << endl;
	}
    return 0;
}