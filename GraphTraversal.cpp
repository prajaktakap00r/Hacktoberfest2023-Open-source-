#include<iostream>
#include<stdio.h>
using namespace std;


class Node{
public:    
    int data;
    Node *next;   
};
class Queue{
private:    

    Node *front;
    Node *rear;

public:    
Queue() {
    front = nullptr;
    rear = nullptr;
}
  
    void enqueue(int x){
        Node *t=new Node;
        if(t==NULL){
            cout<<"Queue is Full";
        }else{
            t->data=x;
            t->next=NULL;
            if(front==NULL){  //If its first node
                front=rear=t;
            }else{
                rear->next=t;
                rear=t;
            }
        }
    }
    int dequeue(){
        int x=-1;
        Node *p;
        if(front==NULL){
            cout<<"Queue is empty";
        }else{
            p=front;
            front=front->next;
            x=p->data;
            delete p;
        }
        return x;
    }
    void Display(){
        Node *p=front;
        while(p){
            cout<<p->data<<"->";
            p=p->next;
        }
        cout<<endl;
    }
    int isEmpty(){
        return front==NULL;
    }

};

void BFS(int G[][7],int start,int n){
    int i=start,j;
    Queue q;
    int visited[7]={0};
    cout<<i<<" ";
    visited[i]=1;
    q.enqueue(i);
    while(!q.isEmpty()){
        i=q.dequeue();
        for(j=1;j<n;j++){
            if(G[i][j]==1 && visited[j]==0){
                cout<<j<<" ";
                visited[j]=1;
                q.enqueue(j);

            }
        }
    }
}
void DFS(int G[][7],int start,int n){
    static int visited[7]={0};
    if(visited[start]==0){
        cout<<start<<" ";
        visited[start]=1;
        for(int j=1;j<n;j++){
            if(G[start][j]==1 && visited[j]==0){
                DFS(G,j,n);
            }
        }
    }
}
int main(){

    int G[7][7]={
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},   //not using 0th row and 0th column
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    
    DFS(G,1,7);
    return 0;
}
