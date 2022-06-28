#include<bits/stdc++.h>
using namespace std;
int main(){
      int n=5,m=6,source=1;
	vector<pair<int,int> > g[n+1]; 	// assuming 1 based indexing of graph
	// Constructing the graph
	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});	
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[source]=0;
        pq.push({0,source});
        while(!pq.empty())
        {   
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it=g[node].begin();it!=g[node].end();it++){
                    int nextnode=it->first;
                    int dist_to_next_node=it->second;
                    if(dist[nextnode]>dist_to_next_node+dist[node]){
                            dist[nextnode]=dist_to_next_node+d  ;
                            pq.push({dist[nextnode],nextnode});
                    }
            }
        }    
        cout<<"shortest dist are---"<<endl;
         for(int i=1;i<=n;i++){
            cout<<dist[i]<<endl; 
         }
        return 0;

    }
