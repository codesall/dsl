#include <iostream>
#include <string>
using namespace std;
class Demo{
    public:
    class Node{
        
        public:
        int prn;string name;
        Node *next=nullptr;
        Node(int prn,string name){
            this->prn=prn;
            this->name=name;
        }
    };
    Node *head,*tail;
    int length;
    Demo(int prn,string name){
        Node* newNode=new Node(prn,name);
        head=newNode;
        tail=newNode;
        length=1;

    }
    

    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<"-----------------------"<<endl;
            cout<<"PRN : "<<temp->prn<<endl;
            cout<<"NAME : "<<temp->name<<endl;
            temp=temp->next;
        }
    }

    bool append(int prn,string name){
        Node* newNode=new Node(prn,name);
        if (length==0)
        {
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
        length++;
        return true;
    }
    bool prepend(int prn,string name){
        Node* newNode=new Node(prn,name);
        if (length==0)
        {
            head=newNode;
            tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
        length++;
        return true;
        
    }
    Node* removeFirst(){
        if (length==0)
        {
            return nullptr;
        }
        Node* temp=head;
        if (length==1)
        {
            head=nullptr;
            tail=nullptr;
        }else{
            head=head->next;
            temp->next=nullptr;
        }
        length--;
        return temp;
    }
    Node* removeLast(){
        if (length==0)
        {
            return nullptr;
        }
        Node* temp=head;
        Node* pre=head;
        while (temp->next!=nullptr)
        {
            pre=temp;
            temp=temp->next;
        }
        tail=pre;
        tail->next=nullptr;
        length--;
        if (length==0)
        {
            head=nullptr;
            tail=nullptr;
        }
        return temp;
    }
    bool insert(int index,int prn,string name){
        if (index<0||index>length)
        {
            return false;
        }
        if (index==0)
        {
            prepend(prn,name);
            return true;
        }
        if (index==length)
        {
            append(prn,name);
            return true;
        }
        
        Node* newNode=new Node(prn,name);
        Node* temp=get(index-1);
        newNode->next=temp->next;
        temp->next=newNode;
        length++;
        return true;
    }
    Node* get(int index){
        if (index<0||index>length)
        {
            return nullptr;
        }
        Node* temp=head;
        for (int i = 0; i < index; i++)
        {
            temp=temp->next;
        }
        return temp;

    }
    Node* remove(int index){
        if (index<0||index>length)
        {
            return nullptr;
        }
        if (index==0)
        {
            return removeFirst();
        }
        if (index==length)
        {
            return removeLast();
        }
        Node* pre=get(index-1);
        Node* temp=pre->next;
        pre->next=temp->next;
        temp->next=nullptr;
        length--;
        
        return temp;
        
    }
    Node* concat(Demo& l2){
        if (!head) {
        return l2.head;
        }

        if (!l2.head) {
            return head;
        }
        tail->next=l2.head;
        tail=l2.tail;
        return head;

    }
};
int main(){
    Demo d1(1,"SAM1");
    d1.append(2,"varad1");
    Demo d2(1,"Sam2");
    d2.append(2,"Varad2");
    cout<<"current club 1 : "<<endl;d1.display();
    cout<<"current club 2 : "<<endl;d2.display();
    cout<<"Adding pres : "<<endl;d1.prepend(3,"pres");
    cout<<"Adding sec : "<<endl;d1.append(3,"sec");
    cout<<"current club 1 : "<<endl;d1.display();
    cout<<"Total no of members in club 1 : "<<d1.length<<endl;
    cout<<"Displaying members : "<<endl;d1.display();
    cout<<"Concatinating 2 lists : "<<endl;d1.concat(d2);
    cout<<"Final list : "<<endl;d1.display();

    return 0;
}