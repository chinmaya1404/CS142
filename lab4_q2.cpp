#include <iostream>
using namespace std;
//define class node
class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(){
        next = NULL;
    }

};
//define linked list class
class LL{

    public:
    // head & tail Node type ptr
    Node * head;
    Node * tail;

    // Constructor
    LL(){
        head = NULL;
        tail = NULL;
    } 
    // Rules how circles will be linked
    //1. Insertion
    void insert(int value){
       // first new Node is created
       Node * temp = new Node; 
       // Insert value in the node
       temp->data = value;
       //if new Node is 1st Node.
       if(head == NULL){
            head = temp;
       }
       //for Any other Node only.
       else{
            tail->next = temp;
       }
       tail = temp;
    } 
        //insertion at some position
    void insertAt(int pos, int value){
        //condition
        if((pos<1)||(pos>(countItems()+1)))
        {
            cout<<"Linked List does not have that many elements"<<endl;
        }
	else{
	if((pos==(countItems()+1))||(head==NULL)){
		insert(value);
	}
	else{
	 // Create a node
        Node * temp = new Node;
        temp -> data = value;
	if(pos==1){
		temp->next=head;
		head=temp;
	}
        else
        {
        // Reach the place before the position
        Node * current = head;
        int i =1;
        while(i < pos-1){
            i++;
            current = current->next;
        }
       
        
        // Moving ptrs like magic ! if not head
        temp->next = current->next;
        current->next = temp;
        }
	}
	}
    }

    // Deletion of last element
    void delet(){
        // store the tail in temp
        Node * temp = tail;
        // before tail has to point to null
        Node * current = head;
        while(current->next != tail){
            current = current->next;
        }
        current->next = NULL; 

        // update tail
        tail = current;
        // delete temp
         delete temp;
    }
    //Deletion at some position
    void deleteAt(int pos){
        //condition
        if(countItems()<pos){
            cout<<"Element does not exist"<<endl;
        }
        else
        {
            if(pos==1){
                Node * current = head;
                head= current->next;
                delete current;
            }
            else
            {
        //finding element to delet
        Node * current = head;
        int i =1;
        while(i < pos){
            i++;
            current = current->next;
        }
        //shifting pointer to the before Node
        //finding element before delete element
        Node * current1 = head;
        int j =1;
        while(j < pos-1){
            j++;
            current1 = current1->next;
        }
        //shifting
        current1->next = current->next;
        //delete current
        delete current;
            }
        }
    }

    //count items
    int countItems(){
	int i;
        if(head==NULL){
		 i=0;
	}
	else{
	i=1;
        // before tail has to point to null
        Node * current = head;
        while(current->next != NULL){
            current = current->next;
            i++;
        } }
        return i;
    }
    // Display
    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout <<"NULL"<< endl;
    }
};


class Stack{
    public:
    Node * top;
    LL l1;
    Stack(){
        top = NULL;
    }
    // Pushes on top
    void push(int value){
        // void insertAt(int value, int pos){
        l1.insertAt(1,value);
        //top = new_head;
        top = l1.head ;
    }
    // Pops the top
    void pop(){
        // void deleteAt(int pos){
        l1.deleteAt(1);
        //top = new_head;
        top = l1.head;
    }
    bool isEmpty(){
        if(top == NULL) return true;
        return false;
    }
    int size(){
        return l1.countItems();
    }
    void topDisplay(){
	cout<<"Top is :"<<top->data<<endl;
    }
    void display(){
        l1.display();
    }
};

	
class Queue{
	public:
	//declare two stcks
	Stack s1,s2;
	//enque function
	void enqueue(int value){
		if(s1.size() == 0 ){
			s1.push(value);
		}
		//reverse it in s2
		else{
			s2.push(s1.top->data);
			s1.pop();
			enqueue(value);
			s1.push(s2.top->data);
			s2.pop();
		}
	}
//deque function same for both
	void dequeue(){
		if(s1.size() == 0)
			cout<<"No element to delete"<<endl;
		else
			s1.pop();
	}
	int size(){ 
        	return s1.size();
    	}
	void display(){
		s1.display();
	}
};

int main(){
Queue q1;
q1.dequeue();
q1.enqueue(7);
q1.enqueue(4);
q1.enqueue(3);
q1.display();
q1.dequeue();
q1.enqueue(8);
q1.enqueue(4);
q1.display();
q1.dequeue();
q1.enqueue(2);
q1.display();
q1.display();
return 0;}

