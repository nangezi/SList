typedef int SDataType;
//链表的节点
typedef struct SListNode
{
    SDataType _data;
    struct SListNode* next;
}Node,*SList;//SList 已经是一个指针了

//初始化
SList SListInit();
//头插法插入节点
SList SListInsertByhead(SList s,SDataType data);
//尾插法插入节点
SList SListInsertBytail(SList s,SDataType data);
//删除值为x的节点
SList DeleteByData(SList s,SDataType data);
//删除第i个节点
SList DeleteBypos(SList s,int i);
//链表为空,返回0为空，返回1为0
int isEmpty(SList s);
// 销毁链表 
void SListDestroy(SList s);
//打印链表
void SListPrint(SList s);

