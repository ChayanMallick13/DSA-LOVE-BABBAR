#include<iostream>
using namespace std;


//implementing graph
class graph {
    private:
    int n;
    bool ** matrix;



    public:

    graph(int nodes){
        this->n=nodes;
        matrix = new bool*[n];
        for(int i = 0;i<n;i++){
            matrix[i]=new bool[n];
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                matrix[i][j]=false;
            }
        }
    }
    void add_edge(int u,int v,bool dir){
        matrix[u][v]=1;
        if(!dir)
            matrix[v][u]=1;
    }

    void print(){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }cout<<endl;
        }cout<<endl<<endl;
    }
    ~graph(){
        for(int i = 0;i<n;i++){
            delete matrix[i];
        }
        delete matrix;
    }

};



int main(int argc, char const *argv[])
{
    cout<<"Enter the number of nodes : ";
    int n;
    cin>>n;
    cout<<"\nEnter the number of edges : ";
    int m;
    cin>>m;
    
    graph * g = new graph(n);
    while(m--){
        int u, v;
        cin>>u>>v;
        g->add_edge(u,v,0);
    }

    g->print();

    return 0;
}
