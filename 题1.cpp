#include <iostream>
#include <stdlib.h>
using namespace std;
/*题目描述 
字符串中的第一个唯一字符
描述：
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。
如果不存在，则返回 -1。假定该字符串只包含小写字母。
示例：
s = "leetcode"
返回 0.
s = "loveleetcode",
返回 2.
加分项：
时间复杂度为 O(n)
说明：
字符串中的第一个字母索引为0，第二个为1，以此类推 */
/*解题思路：用结构体，属性value存放字符，标记tag记录该字符是否已经检索过，0代表未检索，1代表已经检索；
检索方式为两层for循环,只检索tag为0的字符。若检索字符在其后的字符中未发现与其一样的字符，则直接返回该自负的下标，若检索到
与其一样的字符，则令其tag为1，那么在其后面的检索过程中就能省掉检索次数。*/ 
struct charNode{
	char value;
	int tag; 
}; 
typedef struct charNode* PcharNode;
struct CharArray{
	int n;
	PcharNode charArray;
};
/*初始化字符数组*/
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
/*寻找第一个不重复字符*/
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
	cout<<"请确定字符串长度：";
	cin>>m;
	CharArray* array=creatcharArray(m);
	cout<<"请输入字符串的内容：";
	for(m=0;m<array->n;m++)
		cin>>array->charArray[m].value;
	cout<<findFirstSingleChar(array);
	return 0;
}
