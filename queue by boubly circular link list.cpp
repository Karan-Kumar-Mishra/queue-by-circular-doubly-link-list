#include<iostream>

using namespace std;
// queue by boubly link list
class node
{
public:
    int info;
    node *next;
    node *prev;
};
node* create(int data )
{
    node *ptr=new node;
    ptr->info=data;
    return ptr;
}
void display(node *head)
{
    node *ptr=head->next;
    do {
        cout<<" "<<ptr->info;
        ptr=ptr->next;
    } while(ptr!=head);
}
void insert(node *head,int data)
{

    node *ptr=head->next;
    do {
        ptr=ptr->next;
    } while(ptr->next!=head);
    node *p1=create(data);
    ptr->next=p1;
    p1->prev=ptr;
    p1->next=head;
}
void remove(node *head)
{
    head->next=head->next->next;

}
int main()
{
    node *head,*p1,*p2,*p3;
    head= new node;
    p1=create(10);
    p2=create(20);
    p3=create(30);
    head->next=p1;
    p1->prev=head;
    p1->next=p2;
    p2->prev=p1;
    p2->next=p3;
    p3->prev=p2;
    p3->next=head;

    display(head);
    cout<<endl<<endl;
    remove(head);
    cout<<endl<<endl;
    display(head);

    return 0;
}