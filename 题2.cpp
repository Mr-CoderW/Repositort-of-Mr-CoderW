#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node{
	int value;    //���ֵ 
	Node * next;
}; 
/*��������ͷ�Ŀ�����*/
Node* creatNullList(){
	Node* list=(Node*)malloc(sizeof(struct Node));
	if(list!=NULL){
		list->next=NULL;
		list->value=1;
		return list;
	}
	else return NULL;
} 
/*����ֵΪx���½ڵ�,����ĩβ*/
int insertPost(Node* list,int x){
	Node *p,*q;
	q=(Node*)malloc(sizeof(struct Node));
	if(q==NULL)return -1;   //q��㴴��ʧ��
	q->value=x;
	q->next=NULL; 
	p=list;
	while(p->next!=NULL)p=p->next;
	p->next=q;
	return 1;
} 
/*��ż�������
����˼�룺�����ĸ�ָ�����p,q,r,temp;pΪ���������ĩβ��㣬qΪż�������ĩβ��㣬rΪq����һ���ڵ㣬tempΪż������ͷ�ڵ㣬
ͨ��p->next=r,q->next=r->next,r->next=temp���н���*/
Node* change(Node* list){
	Node *p,*q,*r,*temp;
	p=list;          //��ʼpָ�������ͷ
	temp=q=list->next; //��ʼtemp��q��ָ������ĵڶ������
	r=q->next;      //��ʼrΪ��������� 
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
/*��ʾ��������*/
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
		cout<<"1.�����½ڵ�"<<endl; 
		cout<<"2.����˳��"<<endl;
		cout<<"3.��ʾ����"<<endl;
		cout<<"4.�˳�����"<<endl;
		cout<<"please input i=";
		cin>>i;
		if(i==1){
			cout<<"���������ڵ��ֵ=";
			cin>>x;
			insertPost(list,x);	
		}
		else if(i==2)change(list);
		else if(i==3)show(list);
		else break;
	}
	return 0;
}
