#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>

class graph{
    public:
    unordered_map<T,list<T>> adj;

    void insertEdge(T u , T v , int direction){
        adj[u].push_back(v);

        
        adj[v].push_back(u);
    
    }

    void  printList(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto  j : i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph<int> gp;
    int n ;
    cout<<"enter number of nodes";
    cin>>n;
    int m ;
    cout<<"enter the number of edges";
    cin>>m;

    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin>>u>>v;

        gp.insertEdge(u,v,0);
    }
    gp.printList();
    return 0 ;
}
