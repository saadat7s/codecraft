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
            tail_Ptr = newNodePtr;
                
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
                cout<<"Top Element of Stack"<<endl;
                while(currentNode != NULL)
                {
                    cout<<currentNode->returnKey();
                    currentNode = currentNode->retrieveNext();
                    count++;
                    break;
                }
                    cout<<endl;
            }
        }
        
        bool isempty()
        {
            return (head_Ptr == NULL);
        }
        
        
};
template<class T>
class Stack
{
    private:
    LinkedList<T> obj;
    public:
    void Push(T data)
    {
        obj.insertAtBeginning(data);
    }

    bool isEmpty()
    {
        return obj.isempty();
    }

    void Pop()
    {
        obj.deleteNodeFromFront();
    }

    void getTop()
    {
        obj.PrintData();
    }
};
int main()
{  
    Stack<int>obj;
    obj.isEmpty();
    obj.Push(5);
    obj.Push(6);
    obj.Push(7);
    obj.getTop();
    obj.Pop();
    obj.getTop();
    obj.isEmpty();

    return 0;
}
