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


class StackLL{
    public:
    Node * top;
    LL l1;
    StackLL(){
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

	class QueueLL{
	public:
		Node * top;
		LL l1;

	QueueLL(){
		top= NULL;
	}
	void enqueue(int value){
	//insert value at end
		l1.insert(value);
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

	class StackArr{
	private:
	int top;
	int Arr[];
	public:
	StackArr(){
		top= -1;
	}
	void push(int value){
		Arr[++top]=value;
	}
	void pop(){
		if(top==-1)
			cout<<"No element to pop"<<endl;
		else
			top--;
	}
	int  size(){
		return top+1;
	}
	bool isEmpty(){
		if(top==-1)
			return true;
		else
			return false;
	}
	void topDisplay(){
		if(top==-1){
			cout<<"Stack is empty"<<endl;
	}
		else
		cout<<"Top is :"<<Arr[top]<<endl;
	}
	void display(){
		int current = top;
		while(current!=-1){
			cout<<Arr[current]<<"->";
			current--;
		}
		cout<<endl;
	}
	};

	class QueueArr{
	public:
		int top,end;
		int Arr[];
	QueueArr(){
		top=-1;
		end=-1;
	}
	void enqueue(int value){
		if(size()==0){
			top++;
			end++;
		}
		else
			end++;
		Arr[end]=value;
	}
	void dequeue(){
		if(size()==0)
			cout<<"Nothing to dequeue"<<endl;
		else
			top++;
	}
	int size(){
		if((top==-1)&&(end==-1))
			return 0;
		else
			return (end-top+1);
	}
	void topDisplay(){
		if(top==-1){
			cout<<"Stack is empty"<<endl;
	}
		else
		cout<<"Top is :"<<Arr[top];
	}
	void display(){
		int current = top;
		while(current<end){
			cout<<Arr[current]<<"->";
			current--;
		}
		cout<<endl;}
	bool isEmpty(){
		if((top==-1)&&(end==-1))
			return true;
		else
			return false;}};


int main() {
 
	LL l1;
   
    l1.insertAt(1,3);
    cout<<l1.countItems()<<endl;
	StackLL s1;

    for(int i = 0; i < 5 ; i++)
        s1.push(i);
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	cout<<s1.size()<<endl;
	s1.pop();
	s1.display();
	s1.topDisplay();
	s1.pop();
	s1.display();
	cout<<s1.isEmpty()<<endl;
	s1.pop();
	s1.display();
	cout<<s1.isEmpty()<<endl;

	
	QueueLL q1;
	 for(int i = 0; i < 5 ; i++)
        q1.enqueue(i);
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	cout<<q1.size()<<endl;
	q1.dequeue();
	q1.display();
	q1.topDisplay();
	q1.dequeue();
	q1.display();
	cout<<q1.isEmpty()<<endl;
	q1.dequeue();
	q1.display();
	cout<<q1.isEmpty()<<endl;
	StackArr s1;
	for(int i = 0; i < 5 ; i++){
        s1.push(i);
	}
	s1.display();
	
	s1.pop();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	cout<<s1.size()<<endl;
	s1.pop();
	s1.display();
	s1.topDisplay();
	s1.pop();
	s1.display();
	cout<<s1.isEmpty()<<endl;
	s1.pop();
	s1.display();
	cout<<s1.isEmpty()<<endl;
	
	s1.topDisplay();
	QueueArr q1;
	 for(int i = 0; i < 5 ; i++)
        q1.enqueue(i);
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	cout<<q1.size()<<endl;
	q1.dequeue();
	q1.display();
	q1.topDisplay();
	q1.dequeue();
	q1.display();
	cout<<q1.isEmpty()<<endl;
	q1.dequeue();
	q1.display();
	cout<<q1.isEmpty()<<endl;
	return 0;
}
