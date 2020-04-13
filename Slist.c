#include <stdio.h>
#include <stdlib.h>
#include "Slist.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//初始化
SList SListInit(){
	Node *L =(Node *)malloc(sizeof(Node));
	if (!L)
	{
		printf("空间分配失败\n");
		exit(0);
	}else{
		L->next = NULL;
	}
	return L;
}
/*SList CreatS(SDataType *a, int n) {
	Node *L;
	L = SListInit();                        //初始化一个空链表
	Node *r;
	r = L;                                   //r始终指向终端结点，开始时指向头结点   
	Node *p;
	for (int i = 0; i < n; i++){
		p = (Node *)malloc(sizeof(Node));   //申请新的结点 
		if (p == NULL) {                         //判断是否有足够的内存空间   
			printf("申请内存空间失败\n");
			exit(0);
		}
		p->_data = a[i];                        //结点数据域赋值 
		p->next = r->next;
		r->next = p;                        //将结点插入到表头L-->|1|-->|2|-->NULL   
		r = p;
	}
 
	return L;

}*/
//头插法插入节点
SList SListInsertByhead(SList s,SDataType data){
	Node *x;
	x = (Node*)malloc(sizeof(Node));
	if(!x){
		printf("内存分配失败\n");
		exit(0);
	}
	else
	{
		x->_data = data;
		x->next = s->next;
		s->next = x;
	}
	return s;

}
//尾插法插入节点
SList SListInsertBytail(SList s,SDataType data){
	Node *x,*tail;
	tail = s;
	x = (Node*)malloc(sizeof(Node));
	if(!x){
		printf("内存分配失败\n");
		exit(0);
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		x->_data = data;
		tail->next = x;
		x->next = NULL;
	}
	return s;
}
int isEmpty(SList s){
	Node *p = s->next;
	if (p == NULL)
	{
		printf("链表为空\n");
		return 0;
	}
	else
	{
		return 1;
	}
	
	
}
//删除值为x的节点
SList DeleteByData(SList s,SDataType data){
	int empt = isEmpty(s);
	if(!empt){
		printf("链表为空\n");
		return NULL;
	}
	Node *p,*pre;
	pre = s;
	p = pre->next;
	if(p!=NULL)
	{
		while(p!=NULL && p->_data != data)
		{
			pre = p;
			p = p->next;
		}
		pre->next = p->next;
		free(p);

	}else
	{
		printf("该链表没有等于%d的值",data);
	}		
	return s;
}
//删除第i个节点
SList DeleteBypos(SList s,int i){
	Node *pre,*p;
	int x = 1;
	pre = s;
	p = pre->next;
	while (p != NULL)
	{
		if(x == i)
		{
			pre->next = p->next;
			free(p);
			break;
		}
		else
		{
			pre = p;
			p = p->next;
			x++;
		}
	
	}
	if (x < i)
	{
		printf("输入错误，超长\n");
	}
	return s;	
}
// 销毁链表 
void SListDestroy(SList s){
	free(s);
}
//打印链表
void SListPrint(SList s){
	int empt = isEmpty(s);
	Node *p = s->next;
	if(empt){
		
		while(p!=NULL){
			printf("%d, ",p->_data);
			p = p->next;
		}	
	}else{
		printf("链表为空\n");
	}
	printf("\n");
}

int main() {
	/*测试
	SList L = SListInit();	
	L = SListInsertBytail(L,1);//尾插1
	L = SListInsertBytail(L,2);//尾插2
	L = SListInsertByhead(L,3);//前插3
	L = SListInsertByhead(L,4);//前插3
	SListPrint(L);
	L = DeleteByData(L,3);//删除值为3的节点
	SListPrint(L);
	L = DeleteBypos(L,2); //删除第2个节点
	SListPrint(L);
	L = DeleteBypos(L,5);
	system("pause");
	return 0;
	*/
}
