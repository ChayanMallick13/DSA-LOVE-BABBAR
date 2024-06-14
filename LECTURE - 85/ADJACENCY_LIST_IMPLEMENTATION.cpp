#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


//CLASS FOR THE GRAPH
class graph {

    //DATA MEMBERS
    private:

    //FOR STORING THE NEIGHBOURS OF A NODE
    unordered_map<int,list<int>> m;

    public:

    //ADD A EDGE
    void add_edge(int u,int v,bool dir){
        // dir -> 1 non dir->0

        //MAKE V NEIGHBOUR OF U
        m[u].push_back(v);

        //IF NON DIRECTED THE MAKE U NEIGHBOUR OF V
        if(!dir){

            m[v].push_back(u);

        }

    }

    //JUST TO PRINT THE LIST
    void print_list(){

        for(auto i : m){

            cout<<i.first<<"  -->  ";

            for(auto j : i.second){

                cout<<j<<" , ";

            }

            cout<<endl<<endl;

        }

        cout<<"\n\n\n";

    }

};


/*********************************************DRIVER CODE****************************************************************/
int main(int argc, char const *argv[])
{
    cout<<"Enter the number of nodes : ";
    int n;
    cin>>n;
    cout<<"\nEnter the number of edges : ";
    int m;
    cin>>m;
    graph * newgraph = new graph;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        newgraph->add_edge(u,v,0);
    }

    newgraph->print_list();
    return 0;
}
/*************************************************************************************************************************/