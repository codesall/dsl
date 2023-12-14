#include <iostream>
using namespace std;
class Demo{
    public:
    class Node{
        public:
        Node *next=nullptr;
        string value;
        Node(string value){
            this->value=value;
        }
    };
    Node *front,*rear;
    int length;
    Demo(string value){
        Node* newNode=new Node(value);
        front=newNode;
        rear=newNode;
        length=1;
    }
    
    void disp(){
        Node *temp=front;
        while(temp!=nullptr){
            cout<<temp->value<<endl;
            temp=temp->next;
        }
    }
    void addjob(string value){
        Node* newnode=new Node(value);
        if (length==0){
            front=rear=newnode;
        }else{
            rear->next=newnode;
            rear=newnode;
        }
        length++;
        
    }
    Node* deletejob(){
        if (length==0)  
        {
            cout<<"queue is already empty"<<endl;
            return nullptr;
        }
        Node *temp=front;
        if (length==1)
        {
            front=rear=nullptr;
        }else{
            
            front=front->next;
            temp->next=nullptr;
        }
        length--;
        return temp;
    }

};
int main(){
    Demo d("J1");
    d.disp();
    d.addjob("J2");
    d.disp();
    d.deletejob();
    d.disp();
    
    return 0;
}