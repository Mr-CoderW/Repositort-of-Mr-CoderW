#include <iostream>
#include <stdlib.h>
using namespace std;
/*��Ŀ���� 
�ַ����еĵ�һ��Ψһ�ַ�
������
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ�������������������
��������ڣ��򷵻� -1���ٶ����ַ���ֻ����Сд��ĸ��
ʾ����
s = "leetcode"
���� 0.
s = "loveleetcode",
���� 2.
�ӷ��
ʱ�临�Ӷ�Ϊ O(n)
˵����
�ַ����еĵ�һ����ĸ����Ϊ0���ڶ���Ϊ1���Դ����� */
/*����˼·���ýṹ�壬����value����ַ������tag��¼���ַ��Ƿ��Ѿ���������0����δ������1�����Ѿ�������
������ʽΪ����forѭ��,ֻ����tagΪ0���ַ����������ַ��������ַ���δ��������һ�����ַ�����ֱ�ӷ��ظ��Ը����±꣬��������
����һ�����ַ���������tagΪ1����ô�������ļ��������о���ʡ������������*/ 
struct charNode{
	char value;
	int tag; 
}; 
typedef struct charNode* PcharNode;
struct CharArray{
	int n;
	PcharNode charArray;
};
/*��ʼ���ַ�����*/
CharArray* creatcharArray(int m){
	CharArray* array=(CharArray*)malloc(sizeof(struct CharArray));
	if(array!=NULL){
		array->charArray=(PcharNode)malloc(sizeof(struct charNode)*m);
		if(array->charArray){
			array->n=m;
			for(int i=0;i<m;i++)
				array->charArray[i].tag=0;
			return array;
		}
		else free(array);
	}
	return NULL;
} 
/*Ѱ�ҵ�һ�����ظ��ַ�*/
int findFirstSingleChar(CharArray* array){
	int i,j;
	for(i=0;i<array->n;i++){
		for(j=i+1;j<array->n;j++){
			if(array->charArray[i].value==array->charArray[j].value){
				array->charArray[i].tag=1;
				array->charArray[j].tag=1;
			}
		}
		if(array->charArray[i].tag==0)return i;
	}
	return -1;
} 
int main(){
	int m;
	cout<<"��ȷ���ַ������ȣ�";
	cin>>m;
	CharArray* array=creatcharArray(m);
	cout<<"�������ַ��������ݣ�";
	for(m=0;m<array->n;m++)
		cin>>array->charArray[m].value;
	cout<<findFirstSingleChar(array);
	return 0;
}
