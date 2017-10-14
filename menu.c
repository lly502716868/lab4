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
#include<string.h>
#include "Linktable.h"
#define CMD_MAX_LEN 128
typedef struct DataNode
{
    tLinkNode* next;
    char *cmd;
    char *desc;
    int (*handler)();
}tDataNode;
 
int Initmenu(tLinkTable ** pLinkTable);
tDataNode * FindCmd(tLinkTable * head,char *cmd);
int ShowAllCmd(tLinkTable* head);
int Quit();
int Help();
int  Ls();
tLinkTable* head=NULL;

int main()
{
    char cmd[CMD_MAX_LEN];
    Initmenu(&head);
    while(1)
    {
    printf("Please input your command > ");
        scanf("%s",cmd);
       tDataNode *q =FindCmd(head,cmd);
       if(q==NULL)
        printf("This is a wrong cmd!\n");
      else
     {
        printf("%s-%s\n",q->cmd,q->desc);
        if(q->handler != NULL)
        q->handler();
    }
    }
    return 0;
}

int Initmenu(tLinkTable ** pLinkTable)
{
    *pLinkTable=CreatLinkTable();
    tDataNode* pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc="this is help command";
    pNode->handler=Help;
    AddLinkNode(*pLinkTable,(tLinkNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="version";
    pNode->desc="menu program v3.0";
    pNode->handler=NULL;
    AddLinkNode(*pLinkTable,(tLinkNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="quit";
    pNode->desc="This is quit cmd";
    pNode->handler=Quit;
    AddLinkNode(*pLinkTable,(tLinkNode*)pNode);
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="ls";
    pNode->desc="This is ls cmd";
    pNode->handler=Ls;
    AddLinkNode(*pLinkTable,(tLinkNode*)pNode);

    return 0;
}

tDataNode * FindCmd(tLinkTable*head,char * cmd)
{
    tDataNode* p=(tDataNode*)GetHeadNode(head);
    while(p!=NULL)
    {
    if(strcmp(p->cmd,cmd)==0)
        return p;
    p=(tDataNode*)GetNextNode(head,(tLinkNode*)p);
    }
    return NULL;
}

int ShowAllCmd(tLinkTable* head)
{
    printf("/****************************************/\n");
    tDataNode* p=(tDataNode*)GetHeadNode(head);
    printf("Menu list:\n");
    while(p!=NULL)
    {
    printf("* %-10s  \t\t--%-30s\n",p->cmd,p->desc);
    p=(tDataNode*)GetNextNode(head,(tLinkNode*)p);
    }
    printf("/****************************************/\n");
    return 0;
}

int Quit()
{
    exit(0);
    return 0;
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}
int  Ls()
{
    system("ls");
    return 0;
}