#include<bits/stdc++.h>
using namespace std;

int main(){
	
		int N=5,m=6;
	vector<pair<int,int> > adj[N]; 
	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
	
	
    int cur[N];
    int dis[N];
    bool vis[N];

    for(int i=0; i<N;i++)
     dis[i] = INT_MAX, vis[i] = false;

     priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

     dis[0] = 0;
     cur[0] = -1;
     pq.push({0,0});


     while( ! pq.empty())
     {

        int u = pq.top(). second;
        pq.pop();

        vis[u] = true;

        for(auto it : adj[u]){

            int v = it.first;
            int weight = it.second;

            if(vis[v]==false && weight<dis[v]){
                cur[v] = u;
                dis[v] = weight;
                pq.push({dis[v],v});
            }
        } 

     }

     cout << "Minumum Spanning tree : "<<endl;

     for(int i=1; i<N;i++)
     cout << cur[i] << " - "<<i<<"\n";
     
     int sum =0;
     for(int i=0; i<N;i++){
        sum+=dis[i];
     }

     cout << "Minimum Cost : "<< sum <<endl;
     
     return 0;
}


/*
    complexity Analysis: 
    
    Time Complexity: 
    O(NlogN) Here, N = iterration, logN = priority queue

    Space Complexity:
    O(N) Three array and priority queue

*/