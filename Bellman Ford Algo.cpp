#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
using namespace std;
struct edge{
	int source,dest,weight;
};
vector<int> bellmanFord(int v,vector<edge> e, int s){
	vector<int> d(v,INT_MAX),emp;
	d[s] = 0;	int x;
	for(int j=0; j<v-1; j++){
		for(int i=0; i<e.size(); i++){
			x = d[e[i].source];
			x = (x==INT_MAX?INT_MAX:x+e[i].weight);
			if(d[e[i].dest]>x)	d[e[i].dest] = x;
		}	
	}
	for(int i=0; i<e.size(); i++){
		x = d[e[i].source];
		x = (x==INT_MAX?INT_MAX:x+e[i].weight);
		if(d[e[i].dest]>x)	return emp;
	}
	return d;
}
int main() {
	vector<int> d;
	vector<edge> e;
	int v,s,t;
	edge temp;
	cin>>t;
	vector<double> clk(t,0);
	clock_t start;
	for(int j=0; j<t; j++){
		cin>>v>>s;	e.clear();
		for(int i=0; i<s; i++){
			cin>>temp.source>>temp.dest>>temp.weight;
			e.push_back(temp);
		}
		cin>>s;			// reused variable s to store the source vectex
		start = clock();
		d = bellmanFord(v,e,s);
		clk[j] = double(clock() - start)/(CLOCKS_PER_SEC/1000);
	}
	for(int i=0; i<t; i++)
	cout<<100*(i+1)<<'\t'<<clk[i]<<endl;
	
	return 0;
}
