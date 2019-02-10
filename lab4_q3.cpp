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
	if(pos == countItems()){
		delet();
	}
	else{
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
class Queue{
	public:
		Node * top;
		Node * end;
		LL l1;

	Queue(){
		top= NULL;
	}
	void enqueue(int value){
	//insert value at end
		l1.insert(value);
		end = l1.tail;
	}
	void dequeue(){
	//delete at the top
		l1.deleteAt(1);
		top=l1.head;
	}
	int size(){
		return l1.countItems();
	}
	bool isEmpty(){
		if(top == NULL) return true;
        	return false;
	}
	void topDisplay(){
		cout<<"Top is :"<<top->data<<endl;
	}
	void display(){
		l1.display();
	}

};

class Stack{
    public:
    	Queue q1,q2 ;
    // Pushes on top
    void push(int value){
       if(q1.size() == 0 )
			q1.enqueue(value);
		
		//reverse it in q2
		else{
			
			q2.enqueue(q1.end->data);
			q1.dequeue();
			push(value);
			q1.enqueue(q2.end->data);
			q2.dequeue();
		}
	
    }
    // Pops the top
    void pop(){
        if(q1.size() == 0){
		cout<<"No element to pop"<<endl;
	}
	else
		q1.dequeue();
    }
    void isEmpty(){
        q1.isEmpty();
    }
    int size(){
        return q1.size();
    }
    void topDisplay(){
	q1.topDisplay();
    }
    void display(){
        q1.display();
    }
};
int main(){
Stack s1;
s1.push(5);
s1.push(7);
s1.push(9);
s1.display();

return 0;
}
	
