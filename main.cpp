#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<bool> used;
vector<int> d;

int main() {
  int n, s, f, count;
  cin >> n >> s >> f;
  s--;
  f--;
  g.resize(n);
  used.resize(n, false);
  d.resize(n, -1);
  d[s] = 0;
  // я не использую INF
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      int x;
      cin >> x;
      if (x != -1){
        g[i].push_back({j, x});
      }
    }
  }
      
  for (int step = 0; step < n; ++step){
    int v = -1;
    for (int u = 0; u < n; ++u){
      if (!used[u] && d[u] != -1 && (v == -1 || d[v] > d[u])){
        v = u;
      }
    }
    if (v == -1){
      break;
    }
    // cout << "\n";
    // cout << v << "\n";
    count += v;
    used[v] = true;
    for (auto [u, w] : g[v]){
       if ((!used[u]) && (d[u] == -1 || d[u] > d[v] + w)){
        d[u] = d[v] + w;

    /*    
    if (d[u] == f){
        cout << d[f] << endl;
    }
    else{
        cout << -1 << endl;
    }*/
        
      }
    }
  }
  cout << d[f];
}
