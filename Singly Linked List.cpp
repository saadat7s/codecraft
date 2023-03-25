#include <iostream>
using namespace std;
template<class T>
class Node
{
    private:
        T key;
        Node *next_ptr;
    public:
        Node(T value, Node *null_Ptr = NULL) : key(value), next_ptr(null_Ptr) {}
        
        
        T returnKey()
        {
            return key;
        }
        Node* retrieveNext()
        {
            return next_ptr;
        }
        void setNext(Node* ptr)
        {
            next_ptr = ptr;
        }
        
};

template<class T>
class LinkedList
{
    private:
        Node <T>*head_Ptr;
    
    public:
        LinkedList():head_Ptr(NULL){}
        
        void insertAtBeginning(T data)
        {
            Node<T>* newNodePtr = new Node<T>(data);
            newNodePtr->setNext(head_Ptr);
            head_Ptr = newNodePtr;
                
        }
        void insertAtEnd(T data)
        {
            if(head_Ptr == NULL)
            {
                cout<<"Linked list is empty"<<endl;
            }
            Node<T>* newNodePtr = new Node<T>(data);
            Node <T>*temp = head_Ptr;
            while(temp->retrieveNext() != NULL)
            {
                temp = temp->retrieveNext();
            }
            temp->setNext(newNodePtr);
        
        }        
        
        T searchValue(T val)
        {
            T index = 0;
            Node <T>*currentNode = head_Ptr;
            while(currentNode != NULL)
            {
                
                if(currentNode-> returnKey() == val)
                {
                    return val;
                }
                currentNode = currentNode->retrieveNext();
            }
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
    LinkedList<int> obj2;
    int input;
    cout<<"Enter the inputs as long as you want to add, enter -1 for it to stop"<<endl;
    while(true)
    {
        cin>>input;
        if(input == -1)
        { 
            break;
        }
        obj.insertAtBeginning(input);
        obj2.insertAtEnd(input);
        
    }
    cout<<"Data of 1 Linked List"<<endl;
    obj.PrintData();
    cout<<"Data of 2nd Linked List"<<endl;
    obj2.PrintData();
    obj.deleteNodeFromFront();
    obj2.deleteNodeFromEnd();
    cout<<"Data of 1 Linked List After Deletion from Front"<<endl;
    obj.PrintData();
    cout<<"Data of 2nd Linked List after deletion from end"<<endl;
    obj2.PrintData();
    cout<<"Enter value you want to search:  "<<endl;
    int value;
    cin>>value;
    cout<<obj.searchValue(value);

    return 0;
}
