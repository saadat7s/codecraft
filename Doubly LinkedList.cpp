#include <iostream>
using namespace std;
template<class T>
class Node
{
    private:
        T key;
        Node *next_ptr;
        Node *prev_ptr;
    public:
        Node(T value, Node *null_Ptr = NULL) : key(value), next_ptr(null_Ptr), prev_ptr(null_Ptr){}
        
        
        T returnKey() const
        {
            return key;
        }
        Node* retrieveNext()const
        {
            return next_ptr;
        }
        Node* retrievePrevious() const
        {
            return prev_ptr;
        }
        void setNext(Node* ptr)
        {
            next_ptr = ptr;
        }
        void setPrevious(Node* ptr)
        {
            prev_ptr = ptr;
        }
        
};

template<class T>
class LinkedList
{
    private:
        Node <T>*head_Ptr;
        Node <T>*tail_Ptr;
    
    public:
        LinkedList():head_Ptr(NULL), tail_Ptr(NULL){}
        
        void insertAtBeginning(T data)
        {
            Node<T>* newNodePtr = new Node<T>(data);
            newNodePtr->setNext(head_Ptr);
            newNodePtr->setPrevious(NULL);
            if(head_Ptr != NULL)
            {
                head_Ptr->setPrevious(newNodePtr);
            }
            head_Ptr = newNodePtr;
                
        }

        void insertAtEnd(T data)
        {
            if(head_Ptr == NULL)
            {
                insertAtBeginning(data);
                return;
            }
            Node<T>* newNodePtr = new Node<T>(data);
            Node <T>*temp = head_Ptr;
            while(temp->retrieveNext() != NULL)
            {
                temp = temp->retrieveNext();
            }
            temp->setNext(newNodePtr);
            newNodePtr->setPrevious(temp);
            tail_Ptr = temp;
        
        }
        void insertAtSpecific(T data, T position)
        {
            if(position == 1)
            {
                insertAtBeginning(data);
                return;
            }

                Node<T>* newNodePtr = new Node<T>(data);
                Node<T>* temp1 = head_Ptr;
                Node<T>* temp2;
                while(position != 1 && temp1 != NULL)
                {
                    temp1 = temp1->retrieveNext();
                    position--;
                }
                if(temp1==NULL)
                {
                    insertAtEnd(data);
                    return;
                }
                temp2 = temp1->retrieveNext();
                newNodePtr->setPrevious(temp1);
                newNodePtr->setNext(temp2);
                temp1->setNext(newNodePtr);
                if(temp2 != NULL)
                {
                    temp2->setPrevious(newNodePtr);
                }
                else
                {
                    tail_Ptr = newNodePtr;
                }

        }
        T searchValue(T val)
        {
            T index = 0;
            Node <T>*currentNode = head_Ptr;
            while(currentNode != NULL)
            {
                
                if(currentNode-> returnKey() == val)
                {   
                    cout<<"Value found: "<<endl;
                    return val;
                }
                else
                currentNode = currentNode->retrieveNext();
            }
            cout<<"Value not found"<<endl;
            return 0;
        }
        
        void deleteNodeFromFront()
        {
            if(head_Ptr == NULL)
            {
                cout<<"Linked List is Empty"<<endl;
            }
            else
            {
                Node<T>* temp;
                temp = head_Ptr;
                head_Ptr = head_Ptr->retrieveNext();
                delete temp;
            }
        }
        void deleteNodeFromEnd()
        {
            if(head_Ptr==NULL)
            {
                cout<<"LinkedList is Empty"<<endl;
            }
            Node <T>*temp = head_Ptr;
            while(temp->retrieveNext() != NULL)
            {
                temp = temp->retrieveNext();
            }
            Node<T>* temp2 = temp->retrievePrevious();
            temp2->setNext(NULL);
            delete temp;
        }
        void PrintData()
        {
            int count = 0;
            {
                
                Node <T>*currentNode;
                currentNode = head_Ptr;
                cout<<"Elements of LinkedList"<<endl;
                while(currentNode != NULL)
                {
                    cout<<currentNode->returnKey();
                    currentNode = currentNode->retrieveNext();
                    count ++;
                }
                    cout<<endl;
            }
        }
        
        void isEmpty()
        {
            if(head_Ptr == NULL)
            {
              cout<<"Linked list is empty"<<endl;  
            }
            
            else
            {
                cout<<"LinkedList has elements"<<endl;
            }
        }
        
        
};


int main()
{   

    LinkedList<int> obj;
    int input;
    cout<<"Enter the inputs as long as you want to add, enter -1 for it to stop"<<endl;
    while(true)
    {
        cin>>input;
        if(input == -1)
        { 
            break;
        }
        obj.insertAtEnd(input);
        
    }
    obj.PrintData();
    int position, data;
    cout<<"At which position would you like to add node and the data respectively"<<endl;
    cin>>position>>data;
    obj.insertAtSpecific(data, position);
    obj.PrintData();
    obj.deleteNodeFromEnd();
    obj.PrintData();
    cout<<"Enter value you want to search:  "<<endl;
    int value;
    cin>>value;
    cout<<obj.searchValue(value)<<endl;
    obj.isEmpty();

    return 0;
}
