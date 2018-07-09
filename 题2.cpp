#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node{
	int value;    //存放值 
	Node * next;
}; 
/*创建不带头的空链表*/
Node* creatNullList(){
	Node* list=(Node*)malloc(sizeof(struct Node));
	if(list!=NULL){
		list->next=NULL;
		list->value=1;
		return list;
	}
	else return NULL;
} 
/*插入值为x的新节点,插在末尾*/
int insertPost(Node* list,int x){
	Node *p,*q;
	q=(Node*)malloc(sizeof(struct Node));
	if(q==NULL)return -1;   //q结点创建失败
	q->value=x;
	q->next=NULL; 
	p=list;
	while(p->next!=NULL)p=p->next;
	p->next=q;
	return 1;
} 
/*奇偶链表调整
核心思想：定义四个指针变量p,q,r,temp;p为奇数链表的末尾结点，q为偶数链表的末尾结点，r为q的下一个节点，temp为偶数链的头节点，
通过p->next=r,q->next=r->next,r->next=temp进行交换*/
Node* change(Node* list){
	Node *p,*q,*r,*temp;
	p=list;          //初始p指向链表的头
	temp=q=list->next; //初始temp，q，指向链表的第二个结点
	r=q->next;      //初始r为第三个结点 
	while(r!=NULL){
		p->next=r;
		q->next=r->next;
		r->next=temp;
		p=r;
		q=q->next;
		if(q==NULL)break;
		r=q->next;
	} 
	return list;
} 
/*显示链表内容*/
void show(Node *list){
	Node *p=list;
	while(p!=NULL){
		if(p->next!=NULL)cout<<p->value<<"->";
		else cout<<p->value;
		p=p->next;
	}
	cout<<endl;
} 
int main(){
	int i,x;
	Node* list=creatNullList();
	/*insertPost(list,2);
	insertPost(list,3);
	insertPost(list,4);
	insertPost(list,5);
	insertPost(list,6); 
	Node *p,*q,*r,*temp;
	p=list;
	temp=q=list->next;
	r=q->next;
	cout<<p->value<<endl;
	cout<<temp->value<<endl;
	cout<<q->value<<endl;
	cout<<r->value<<endl;
    for(int i=0;i<2;i++){
		p->next=r;
		q->next=r->next;
		r->next=temp;
		p=r;
		q=q->next;
		r=q->next;
     }
	cout<<p->value<<endl;
	cout<<temp->value<<endl;
	cout<<q->value<<endl;
	show(list);
	p->next=r;
		q->next=r->next;
		r->next=temp;
	show(list);
		p=r;
		q=q->next;
		r=q->next;
    //}
	cout<<p->value<<endl;
	cout<<temp->value<<endl;
	cout<<q->value<<endl;
	//cout<<"q->next->value"<<q->next->value<<endl;
	//cout<<r->value<<endl;
	show(list);*/
	while(1){
		cout<<"1.插入新节点"<<endl; 
		cout<<"2.调整顺序"<<endl;
		cout<<"3.显示链表"<<endl;
		cout<<"4.退出程序"<<endl;
		cout<<"please input i=";
		cin>>i;
		if(i==1){
			cout<<"请输入插入节点的值=";
			cin>>x;
			insertPost(list,x);	
		}
		else if(i==2)change(list);
		else if(i==3)show(list);
		else break;
	}
	return 0;
}
