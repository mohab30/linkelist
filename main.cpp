#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
};

/////////////////////////////////////////////////

class linkedlist
{
    node* head;

public:
    linkedlist()
    {
     head = NULL;
    }

    bool isempty()
    {
        return (head == NULL);
    }


    void ins_first(int val)
    {
        node* newnode=new node();
        newnode->data=val;

        if (isempty())
        {
            newnode->next=NULL;
            head=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }

    void display()
    {
        node *temp=head;
        int c=1;
        while(temp!=NULL)
        {
            cout<<"Value "<<c++<<" is: " <<temp->data <<endl;
            temp = temp-> next;
        }
    }

    int counter()
    {
       node *temp=head;
        int c=0;
        while(temp!=NULL)
        {
            temp = temp-> next;
            c++;
        }
     return c;
    }

 bool is_found(int val)
    {
        node *temp=head;
        bool found=false;
        while(temp!=NULL)
        {
            if(temp->data==val)
            {
                found=true;
            }
            temp = temp-> next;
        }
        return found;
    }

void insert_before(int value , int before)
{
    if(is_found(before))
    {
    node * newnode = new node();
    newnode -> data = value;
    node * temp = head;

    while(temp->next!=NULL && temp->next->data != before)
        temp = temp->next;

    newnode->next = temp ->next;
    temp->next = newnode;
    }
    else
        cout<<"Before not found!!"<<endl;
}

void append(int value)
{
    if(isempty())
        ins_first(value);
    else
        {
        node * temp = head;
        while(temp->next!=NULL)
            temp = temp->next;

        node * newnode = new node();
        newnode -> data = value;
        temp->next = newnode;
        newnode->next = NULL;

        }
}

void deletenode(int value)
{
    if(isempty())
    {
        cout<<"Its empty, Man!"<<endl;
        return;
    }
    node *delptr=head;
    if(head->data==value)
    {
        head = head->next;
        delete delptr;
    }
    else
    {
        node* prev=NULL;
        while(delptr != NULL && delptr->data!=value)
            {
                prev=delptr;
                delptr=delptr->next;
            }
        if(delptr== NULL)
            {
                cout << "Item not found in the list." << endl;
                return;
            }

        prev->next=delptr->next;
        delete delptr;
    }
}

void update(int newvalue , int old)
{
    if (is_found(old))
    {
        node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == old)
            {
                temp->data = newvalue;
                return;
            }
            temp = temp->next;
        }
    }
    else
        cout << "Not Found!!" << endl;
}
};


int main()
{
    int cont;
    linkedlist mohab;

    //Insert Values
    int c;
    cout<<"How many values you want to insert??"<<endl;
    cin>>c;
    int value;
    int method;

     cout << "Select method:\n1. Insert first\n2. Append\n";
     cin>>method;
     switch(method)
     {
         case 1:
            //Insert Values with insert first
            for(int i=0;i<c;i++)
              {
                cout<<"Enter item "<<i+1<<" to insert."<<endl;
                cin>>value;
                mohab.ins_first(value);
              }
            break;
         case 2:
            //Insert Values with append
            for(int i=0;i<c;i++)
              {
                cout<<"Enter item "<<i+1<<" to insert."<<endl;
                cin>>value;
                mohab.append(value);
              }
            break;
         default:
            cout<<"Invalid input!!!"<<endl;
     }
  /////////////////////////////////////////////////////////////
do
{
      // The Choice!
      int choice;
      cout<<"What do you want, MAN!!"<<endl;
      cout<<"1. Display all elements."<<endl;
      cout<<"2. Check if its empty or not(and count it)."<<endl;
      cout<<"3. Insert another element in first."<<endl;
      cout<<"4. Insert another element in Last."<<endl;
      cout<<"5. Insert element before specific element."<<endl;
      cout<<"6. Search for specific element."<<endl;
      cout<<"7. Update a specific element."<<endl;
      cout<<"8. delete specific element"<<endl;
      cin>>choice;

      switch(choice)
      {
      case 1:
          cout<<"Values you inserted:"<<endl;
          mohab.display();
          break;
      case 2:
          if(mohab.isempty())
            cout<<"Its empty"<<endl;
          else
             cout<<"The List contains: "<<mohab.counter()<<" elements."<<endl;
        break;
      case 3:
          cout<<"Insert the value you want to insert. (First)"<<endl;
          cin>>value;
          mohab.ins_first(value);
          break;
      case 4:
          cout<<"Insert the value you want to insert. (Last)"<<endl;
          cin>>value;
          mohab.append(value);
          break;
      case 5:
            int before;
            cout<<"Insert the value you want to insert."<<endl;
            cin>>value;
            cout<<"Before what??"<<endl;
            cin>>before;
            mohab.insert_before(value , before);
            break;
      case 6:
            cout<<"Insert the value you want to Search."<<endl;
            cin>>value;
            if(mohab.is_found(value))
                cout<<"Founded!"<<endl;
            else
                cout<<"Not found"<<endl;
            break;
      case 7:
          int old;
          cout<<"What item will you replace?"<<endl;
          cin>>old;
          cout<<"What's new?"<<endl;
          cin>>value;
          mohab.update(value,old);
          break;
      case 8:
            cout<<"Which element do you want to delete?"<<endl;
            cin>>value;
            mohab.deletenode(value);
            break;
      default:
        cout<<"Invalid Choice!!!"<<endl;
      }
      cout<<"----------------Done----------------"<<endl;
      cout<<"Continue??   Enter 1"<<endl;
      cin>>cont;
}
while(cont==1);

}
