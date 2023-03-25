#include <iostream>
using namespace std;

class Node
{
    private:
    string name;
    Node* nextPtr;
    public:
    Node(string n, Node* nullPtr = NULL):name(n), nextPtr(nullPtr){}

    void setName(string n)
    {
        name = n;
    }
    void setNext(Node* ptr)
    {
        nextPtr = ptr;
    }
    string getName() 
    {
        return name;
    }
    Node* getNext()
    {
        return nextPtr;
    }
};

class LinkedList
{
    private:
    Node* headPtr1;
    Node* headPtr2;
    Node* headPtr3;
    public:
    LinkedList(Node* ptr1 = NULL, Node* ptr2 = NULL):headPtr1(ptr1), headPtr2(ptr2), headPtr3(NULL){}

    void setHead1(Node* ptr1)
    {
        headPtr1 = ptr1;
    }
    void setHead2(Node* ptr2)
    {
        headPtr2 = ptr2;
    }
    
    Node* getHead1() const
    {
        return headPtr1;
    }
    Node* getHead2() const
    {
        return headPtr2;
    }
    Node* getHead3() 
    {
        return this->headPtr3;
    }
    void insertAtBeginning1(string n)
    {
        Node* newNodePtr = new Node(n);
        newNodePtr->setNext(headPtr1);
        headPtr1 = newNodePtr;
    }
    void insertAtBeginning2(string n)
    {
        Node* newNodePtr = new Node(n);
        newNodePtr->setNext(headPtr2);
        headPtr2 = newNodePtr;
    }

    int getLength1()
    {
        int count = 0;
        Node* temp = headPtr1;
        while(temp != NULL)
        {
            temp = temp->getNext();
            count++;
        }
        return count;
    }
    int getLength2()
    {
        int count = 0;
        Node* temp = headPtr2;
        while(temp != NULL)
        {
            temp = temp->getNext();
            count++;
        }
        return count;
        
    }
    void insertAtCommon(string n)
    {   
      
        Node* newNodePtr = new Node(n, headPtr3);
        headPtr3 = newNodePtr;
        
    }

    void PrintData(Node* commonPtr)
        {
            int count = 0;
            {
                
                Node*currentNode;
                currentNode = commonPtr;
                cout<<"These are the Student/Students that has registered in both courses   :   "<<endl;
                while(currentNode != NULL)
                {
                    cout<<currentNode->getName() << "  ";
                    cout<<endl;
                    currentNode = currentNode->getNext();
                    count ++;
                }
                    cout<<endl;
            }
        }

};
    LinkedList obj1;
    LinkedList obj2;
    LinkedList commonStudentobj;
    

Node* common(Node* HEAD1, Node* HEAD2)
{
    Node* temp1 = HEAD1;
    Node* temp2 = HEAD2;
        for(int i = 0; i<obj1.getLength1(); i++)
        {
            
            for(int j = 0; j<obj2.getLength2(); j++)
            {
                if(temp1->getName() == temp2->getName())
                {
                
                commonStudentobj.insertAtCommon(temp2->getName());

                }
                temp2 = temp2->getNext();
            }   
            temp2 = HEAD2;
            temp1 = temp1->getNext();
        }
    delete temp1, temp2;
    
    return commonStudentobj.getHead3();
}


int main()
{
    string input1, input2;
    cout<<"Enter the inputs as long as you want to add for first list, enter -1 for it to stop"<<endl;
    while(true)
    {
        cin>>input1;
        if(input1 == "-1")
        { 
            break;
        }
        obj1.insertAtBeginning1(input1);
    }
    cout<<"Enter the inputs as long as you want to add for second list, enter -1 for it to stop"<<endl;
    while(true)
    {
        cin>>input2;
        if(input2 == "-1")
        { 
            break;
        }
        obj2.insertAtBeginning2(input2);
    }
    Node* tempHead1 = obj1.getHead1();
    Node* tempHead2 = obj2.getHead2();
    Node* tempCommonPtr = common(tempHead1, tempHead2);
    cout<<tempCommonPtr<<endl;
    commonStudentobj.PrintData(tempCommonPtr);
    return 0;

}