#include <cstdio>
#include <queue>
#include <vector>
#include <cstring> 

struct edge{
	int to, ne;
	long long val;
}e[500005];

int cnt, h[100005];

void add(int a, int b, int v){
	e[++cnt] = (edge) {.to = b, .ne = h[a], .val = v};
	h[a] = cnt;
	return ;
}

std::vector <int> impoints;

struct node{
	int fr, to;
	long long d;
	bool operator < (const node &b) const {
		return d > b.d;
	}
};


std::priority_queue <node> pq;

struct dis_node {
	int from1, from2;
	long long disv1, disv2;
}d[100005];

//long long d[100005];
bool isimp[100005];
//int belonging[100005];

bool isbad(node info, int j){
	if (info.fr != d[j].from1 && info.fr != d[j].from2) return true;
	if (info.fr == d[j].from1 && info.d > d[j].disv1) return true;
	if (info.fr == d[j].from2 && info.d > d[j].disv2) return true;
	return false;
}

void renewp(long long dis, int from, int j) {
	if (from != d[j].from1 && from != d[j].from2) {
		if (dis < d[j].disv1) {
			d[j].disv2 = d[j].disv1;
			d[j].from2 = d[j].from1;
			d[j].disv1 = dis;
			d[j].from1 = from;
			pq.push((node){.fr = from, .to = j, .d = dis});
		}
		else if (dis < d[j].disv2) {
			d[j].disv2 = dis;
			d[j].from2 = from;
			pq.push((node){.fr = from, .to = j, .d = dis});
		}
		return ;
	}
	if (from == d[j].from1) {
		if (dis < d[j].disv1) {
			d[j].disv1 = dis;
			d[j].from1 = from;
			pq.push((node){.fr = from, .to = j, .d = dis});
		}
		return ;
	}
	if (from == d[j].from2) {
		if (dis < d[j].disv2) {
			d[j].disv2 = dis;
			d[j].from2 = from;
			pq.push((node){.fr = from, .to = j, .d = dis});
		}
		return ;
	}
	return ;
}

void dij(){
	while (!pq.empty()) pq.pop(); 
	for (auto i : impoints) {
		d[i].from1 = i;
		d[i].disv1 = 0;
		pq.push((node){.fr = i, .to = i, .d = 0});
	}
	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		if (isbad(now, now.to)) continue;
		for (int i = h[now.to]; i; i = e[i].ne)
			renewp(now.d+e[i].val, now.fr, e[i].to);
	} 
	return ;
}

int main(){
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i <= n; i++) {
    d[i] = (dis_node) {
      .from1 = -1,
      .from2 = -1,
      .disv1 = 0x3f3f3f3f3f3f3f3f,
      .disv2 = 0x3f3f3f3f3f3f3f3f
    };
  }
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    add(a, b, c);
  }
  for (int i = 1; i <= k; i++) {
    int c;
    scanf("%d", &c);
    impoints.push_back(c);
  }
  dij();
  long long ans = 0x3f3f3f3f3f3f3f3f;
  for (auto i : impoints)
    ans = std::min(ans, d[i].disv2);
  printf("%lld\n", ans);
	return 0;
}