#include <iostream>
#include <iomanip>
#include <climits>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;
int V = 13;
int getIndex(string vertices[],string target)
{
    for (int i=0;i<V;i++)
    {
        if (vertices[i]==target)
        {
            return i;
        }
    }    
    return -1;
}
void addDistances(int graph[13][13],string vertices[13],string source,string destination,int distance)
{
    int sourceIndex = getIndex(vertices,source);
    int destinationIndex = getIndex(vertices,destination);
    graph[sourceIndex][destinationIndex] = distance;
}
void printGraph(int graph[13][13])
{
    for(int i = 0 ; i<13;i++)
    {
        for(int j= 0 ;j<13 ; j++)
        {
            cout<<graph[i][j]<<"   ";
        }
        cout<<endl;
    }
}

void dijkstraAlgorithm(int graph[13][13] ,string vertices[13],  string source)
{
    //find source vertix index
    int sourceIndex = -1;
    for(int i = 0 ; i<V ; i++)
    {
        if(source == vertices[i])
        {
            sourceIndex = i;
        }
    }

    bool visited[V] = {false};
    int distance[V]={INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX};
    distance[sourceIndex] = 0;

    for(int count = 0 ; count<V ; count++)
    {
        int min = INT_MAX; 
        int u = -1;
        for(int i = 0 ; i<V ; i++)
        {
            if(!visited[i] && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }
        if(u == -1)
        {
            break;
        }

        visited[u] = true;

        for(int j = 0 ; j<V ; j++)
        {
            if(!visited[j] && graph[u][j] != 0)
            {
                if(distance[j] > (graph[u][j]+distance[u]))
                {
                    distance[j] = graph[u][j]+distance[u];
                }
            }
        }

    }
    //return distance[0];
    for(int i = 0 ; i<V ; i++)
    {
        if(vertices[i] == source)
        {

        }
        else
        {
            cout<<"Distance form "<<source<<" to "<<vertices[i]<<" is "<<distance[i]<<" KM"<<endl;
        }
        
    }

}


void primAlgorithm(int graph[13][13] ,string vertices[],  string source)
{
    //find source vertix index
    int sourceIndex = -1;
    for(int i = 0 ; i<13 ; i++)
    {
        if(source == vertices[i])
        {
            sourceIndex = i;
        }
    }

    bool visited[13] = {false};
    string parents[13];
    parents[sourceIndex] = source;
    int distance[13]={INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX , INT_MAX, INT_MAX};
    distance[sourceIndex] = 0;

    for(int count = 0 ; count<13 ; count++)
    {
        int min = INT_MAX; 
        int u = -1;
        for(int i = 0 ; i<13 ; i++)
        {
            if(!visited[i] && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }
        if(u == -1)
        {
            break;
        }

        visited[u] = true;

        for(int j = 0 ; j<13 ; j++)
        {
            if(!visited[j] && graph[u][j] != 0)
            {
                if(distance[j] > (graph[u][j]))
                {
                    distance[j] = graph[u][j];
                    parents[j] = vertices[u];
                }
            }
        }

    }
    //return distance[0];
    int sum = 0;
    for(int i = 0 ; i<13 ; i++)
    {
        cout<<"Parent of "<<vertices[i]<<" is "<<parents[i]<<endl;
        sum+=distance[i];
    }
    cout<<"The Total Distance we covered is "<<sum<<" KM"<<endl;

}

int main(){

    int graph[13][13];
    for (int i=0;i<13;i++)
    {
        for (int j=0;j<13;j++)
        {
            graph[i][j]=0;
        }
    }

    string vertices[13] = {"Dehli","Channai","Mumbai","Chittagong","Kabul","Rawalpindi","Lahore","Eden Park","Galle",
                        "Lords","Sydney","Melbourne","Village Green"};



    ifstream file;
    file.open("StadiumsDistance.csv");
    string origin;
    string destination;
    int distance;

    while (!file.eof()){
        getline(file,origin,',');
        getline(file,destination,',');
        string dis;
        getline(file,dis,'\n');

        stringstream conveter;
        conveter<<dis;
        conveter>>distance;

        addDistances(graph,vertices,origin,destination,distance);
    }
    // displaygraph(graph);
    // printGraph(graph);
    // cout<<endl;
    // dijkstraAlgorithm(graph,vertices,"Dehli");
    // cout<<endl;
    // primAlgorithm(graph , vertices , "Dehli");


    while(true)
    {
        cout<<"Press 1 to check Shortest Distance from Particula Stadium \nPress 2 to make Shortest connection betwee Stadiums \nPress 3 to print Graph \nPress any other Key to exit "<<endl;
        int choice;
        cin>>choice;
        string s , s2;
        switch(choice)
        {
            case 1:
            cout<<"Enter Satdium from Which to to find shortest distance to all Other Stadiums "<<endl;
            cin>>s;
            dijkstraAlgorithm(graph , vertices , s);
            break;

            case 2:
            cout<<"Enter Satdium from Which to to find shortest Connection to all Other Stadiums "<<endl;
            cin>>s2;
            primAlgorithm(graph , vertices , s2);
            break;

            case 3:
            printGraph(graph);
            break;

            default:
            exit(0);

        }
    }
    return 0;
}