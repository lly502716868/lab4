/************************************************************************/
/*              Copyright(C) mclab.com SSE@USTC , 2017.14.01            */
/*              FILENAME                :menu.c                         */
/*              PRINCIPAL AUTHOR        :heyulin                        */
/*              SUBSYSTEM NAME          :mene                           */
/*              MODULE NAME             :menu                           */
/*              LANGUAGE                :C                              */
/*              TARGET ENVIRONMENT      :ANY                            */
/*              DATE OF FIRST RELEASE   :2017/10/14                     */
/*              DESCRIPTION             :This is a program              */  

#ifndef LINKTABLE_H
#define LINKTABLE_H
#define SUCCESS 0
#define FAILURE -1

/*
 * LinkTable Node Type 
 */
typedef struct LinkNode
{
    struct LinkNode *Next;
}tLinkNode;

/*
 * LinkTable Type 
 */
typedef struct LinkTable
{
    tLinkNode *Head;
    tLinkNode *Tail;
    int num;
}tLinkTable;

/*create LinkTable*/
tLinkTable* CreatLinkTable();
/*Delete  LinkTable*/
int DelLinkTable(tLinkTable *pLinkTable);
/*add a node to linktable*/
int AddLinkNode(tLinkTable *pLinkTable,tLinkNode* pNode);
/*delete a node from linktable*/
int DelLinkNode(tLinkTable *pLinkTable,tLinkNode* pNode);
/*create head node of linktable*/
tLinkNode* GetHeadNode(tLinkTable* pLinkTable);
/*create tail node of linktable*/
tLinkNode* GetTailNode(tLinkTable* pLinkTable);
/*get a next link node of the linktable*/
tLinkNode* GetNextNode(tLinkTable* pLinkTable,tLinkNode *pNode);

#endif