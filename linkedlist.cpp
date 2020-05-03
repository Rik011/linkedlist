#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
//Structure of a Node
struct Node
{
    int data;
    Node* next;
    Node(){}
    Node(int n){
        this->data=n;
        this->next=NULL;
    }
};

//Let's Create the list class

class List{
    private:
        Node* ptr;

        //Functions for insertion
        void insertbegin(int num){
            Node* newptr=new Node(num);
            if(this->ptr==NULL)
                this->ptr=newptr;
            else{
                newptr->next=this->ptr;
                this->ptr=newptr;
            }
        }
        void insertend(int num){
            Node* newptr=new Node(num);
            if(this->ptr==NULL)
                this->ptr=newptr;
            else{
                Node *pptr=NULL,*cptr=ptr;
                while(cptr!=NULL){
                    pptr=cptr;
                    cptr=cptr->next;
                }
                pptr->next=newptr;
            }
        }
        void insertmiddle(int num,int key){
            if(ptr==NULL){
                cout<<"List is Empty. "<< key<<" not found.";
            }
            else{
                Node* newptr=new Node(num);
                Node *pptr=ptr;
                while(pptr->data!=key && pptr!=NULL){
                    pptr=pptr->next;
                }
                
                if(pptr==NULL)
                    cout<<key<<" not found"<<endl;
                else{
                    newptr->next=pptr->next;
                    pptr->next=newptr;
                }
            }
        }

        //Functions for removing an item
        void remove_front(){
            if(ptr==NULL)
                cout<<"List is Empty.";
            else{
                Node* pptr;
                pptr=ptr;
                ptr=ptr->next;
                delete pptr;
            }
            return;
        }
        void remove_end(){
            if(ptr==NULL)cout<<"List is empty.";
            else{
                Node *pptr,*cptr=ptr;
                if(ptr->next==NULL)
                    delete ptr;
                else{
                    while(cptr->next!=NULL){
                        pptr=cptr;
                        cptr=cptr->next;
                    }
                    pptr->next=NULL;
                    delete cptr;
                }
            }
        }
        void remove_intermediate(int key){
            if(ptr==NULL)cout<<"List is Empty."<<key<< "not found in the list";
            else if(ptr->data==key){
                Node* pptr=ptr;
                ptr=ptr->next;
                delete pptr;
            }
            else{
                Node *pptr,*cptr=ptr;
                while(cptr->data!=key && cptr->next!=NULL){
                    pptr=cptr;
                    cptr=cptr->next;
                }
                if(cptr->data!=key)cout<<key<<" Not found in the list.";
                else{
                    pptr->next=cptr->next;
                    cptr->next=NULL;
                    delete cptr;
                }
            }
        }
    public:
        List(){
            ptr=NULL;    //The default constructor which sets the pointer to Null when declared;
        }
        void insert(int num){
            cout<<"Where do you want to insert "<<endl<<" 1. At Front"<<endl<<" 2. At the End"<<endl<<"3. At any intermediate point"<<endl<<" Enter your choice :";
            char ch;
            cin>>ch;
            if(ch=='f'||ch=='F'||ch=='1')
                this->insertbegin(num);
            else if(ch=='e'||ch=='E'||ch=='2')
                this->insertend(num);
            else if(ch=='m'||ch=='M'||ch=='3'){
                int key;
                cout<<"Enter the key element :";
                cin>>key;
                this->insertmiddle(num,key);
            }
            else
                cout<<"Invalid choice.";
            return;
        }

        void remove(){
            cout<<"From where do you want to remove a node"<<endl<<" 1. From the beginning"<<endl<<" 2. From the end"<<endl<<" 3. Any particular Node"<<endl<<" Enter your choice :";
            char ch;
            cin>>ch;
            if(ch=='f'||ch=='F'||ch=='1')
                this->remove_front();
            else if(ch=='e'||ch=='E'||ch=='2')
                this->remove_end();
            else if(ch=='m'||ch=='M'||ch=='3'){
                int num;
                cout<<"Enter the key value you want to remove :";
                cin>>num;
                this->remove_intermediate(num);
            }
            else
                cout<<"Invalid Choice.";
            return;
        }
    void Display(){
        Node* pptr=ptr;
        while(pptr!=NULL){
            cout<<pptr->data<<"\t";
            pptr=pptr->next;
        }
        cout<<endl;
        return;
    }
};
