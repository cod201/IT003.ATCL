
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
    int info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
};
void ReverseList(List& l);
void AddTail( List &l, node *p)
{
    if (l.pHead==NULL)
    {
        l.pHead=p;
        l.pTail=p;
    }
    else
    {
        l.pTail -> pNext=p;
        l.pTail=p;
    }
};
node* CreateNode(int x)
{
    node *pNew;
    pNew = new node;
    pNew -> info =x;
    pNew -> pNext = NULL;
    return pNew;
};
void ReverseList(List& l)
{
    node* Pt = l.pHead;
    node* Q = NULL;
    node* T = NULL;
    while (Pt != NULL)
    {
        T = Pt->pNext;
        Pt->pNext = Q;
        Q = Pt;
        Pt = T;
    }
    l.pHead = Q;
}
void nhap(List &l)
{
    while (1)
    {
        int x;
        cin>>x;
        if (x==0)
            break;
        node *p=CreateNode(x);
        AddTail(l, p);
    }
};
void xuat(List l)
{
    node *p=l.pHead;
    while (p!=NULL)
    {
        cout<< p -> info << " ";
        p=p ->pNext;
    }
};

bool DelNode(node* ck,node* p,List& l)
{
    if (ck== NULL )
    {l.pHead=p->pNext;return 1;}
    else if (p->pNext==NULL)
    {ck->pNext=NULL; l.pTail = ck;return 1;}
    else {ck->pNext=p->pNext;return 1;};
    return 0;

};
bool Find(List& l, int x)
{
    node* p = l.pHead;
    node* ck = NULL;
    bool isDone;
    while (p != NULL)
    {
        if (p->info == x)
            isDone = DelNode(ck,p,l);
        if(isDone) return(1);
        ck=p;
        p = p->pNext;
    }
    return isDone;
}
int solve(int Num, List& l)
{
    nhap(l);
    cin>>Num;
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        ReverseList(l);
        if (!Find(l,Num)){
            cout<<"Khong tim thay "<<Num<<" trong danh sach:"<<endl;
        };
        if (l.pHead == NULL) {
            cout << "Danh sach rong.";
            exit(0);
        };


        xuat(l);
    }
    exit(0);
};
int main()
{
    List l;
    int Num;
    CreateList(l);
   solve(Num,l);
    return 0;
}
