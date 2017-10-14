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

#include <stdio.h>
#include <stdlib.h>
#include "Linktable.h"

/*create LinkTable*/
tLinkTable* CreatLinkTable()
{
    tLinkTable* pLinkTable=(tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkTable ==NULL)
    return NULL;
    pLinkTable->Head=NULL;
    pLinkTable->Tail=NULL;
    pLinkTable->num=0;
    return pLinkTable;
}

/*delete a node from linktable*/
int DelLinkTable(tLinkTable* pLinkTable)
{
    if(pLinkTable==NULL)
    return FAILURE;
    while(pLinkTable->Head != NULL)
    {
    tLinkNode* pNode = pLinkTable->Head;
    pLinkTable->Head = pLinkTable->Head->Next;
    free(pNode);
    pLinkTable->num--;
    }
    pLinkTable->Head = NULL;
    pLinkTable->Tail = NULL;
    free(pLinkTable);
    return SUCCESS;
}

/*add a node to linktable*/
int AddLinkNode(tLinkTable* pLinkTable,tLinkNode* pNode)
{
    if(pLinkTable == NULL || pNode ==NULL)
    {
         return FAILURE;
    }
    pNode->Next=NULL;
    if(pLinkTable->Head==NULL)
    {
        pLinkTable->Head = pNode;
    }
    
    if(pLinkTable->Tail==NULL)
    {
        pLinkTable->Tail = pNode;
    }
    else
    {
        pLinkTable->Tail->Next=pNode;
        pLinkTable->Tail=pLinkTable->Tail->Next;
    }
    pLinkTable->num++;
    return SUCCESS;
}

/*Delete  LinkTable*/
int DelLinkNode(tLinkTable* pLinkTable,tLinkNode* pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    return FAILURE;
    tLinkNode* p = pLinkTable->Head;
    if(pLinkTable->Head == pNode)
    {
    pLinkTable->Head=pLinkTable->Head->Next;
    free(p);
    pLinkTable->num--;
    if(pLinkTable->num ==0)
    {
        pLinkTable->Tail=NULL;
    }
    return SUCCESS;
    }
    while(p!=NULL)
    {
    if(p->Next==pNode)
    {
        tLinkNode* q=p->Next;
        p->Next =p->Next->Next;
        free(q);
        pLinkTable->num--;
        if(pLinkTable->num==0)
        {
        pLinkTable->Tail=NULL;
          }
        return SUCCESS;
    }
    p=p->Next;
    }
    return FAILURE;
}

/*create head node of linktable*/
tLinkNode* GetHeadNode(tLinkTable* pLinkTable)
{
    if(pLinkTable ==NULL||pLinkTable->Head==NULL)
    return NULL;
    return pLinkTable->Head;
}

/*create tail node of linktable*/
tLinkNode* GetTailNode(tLinkTable* pLinkTable)
{
    if(pLinkTable ==NULL||pLinkTable->Tail==NULL)
    return NULL;
    return pLinkTable->Tail;
}

/*get a next link node of the linktable*/
tLinkNode* GetNextNode(tLinkTable* pLinkTable,tLinkNode *pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
        return NULL;
    tLinkNode* p=pLinkTable->Head;
    while(p!=NULL)
    {
    if(p==pNode)
     {
        return p->Next;
    }
    p=p->Next;
    }
    return NULL;
}