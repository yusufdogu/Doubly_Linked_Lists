#include <stdio.h>
#include <stdlib.h>
typedef struct DOUBLE {
    int data;
    struct DOUBLE *next;
    struct DOUBLE *prev;
}dlist;
void iterate(int );
void impBeg(int );
void impend(int );
void impmid(int ,int);
void remnode(int );
dlist *tail=NULL;
dlist *head=NULL;
int main() {
    int a,b,count=0;
    while(1) {
        printf("enter");
        scanf("%d",&a);
        if(a==-1) break;
        scanf("%d",&b);
        switch (a) {
            case 1:
                iterate(b);
                count++;
                break;
            case 2:
                impBeg(b);
                count++;
                break;
            case 3:
                impend(b);
                count++;
                break;
            case 4:
                impmid(b,count);
                count++;
                break;
            case 5:
                remnode(count);
                count--;
                break;
        }
        dlist *curr=head;
        while(curr!=NULL) {
            printf("%d ",curr->data);
            curr=curr->next;
        }
    }
    dlist *curr=head;
    while (curr!=NULL) {
        dlist *temp=curr;
        curr=curr->next;
        free(temp);
    }
}
void iterate(int data) {
    dlist *new=malloc(sizeof(dlist));
    new->data=data;
    new->next=NULL;
    if(tail==NULL) {
        new->prev= NULL;
        tail=new;
        head=new;
    }
    else {
        new->prev=tail;
        tail->next=new;
        tail=new;
    }
}
void impBeg(int data) {//implementing at beginning
    dlist *new=malloc(sizeof(dlist));
    new->data=data;
    new->prev=NULL;
    if(tail==NULL) {
        new->next=NULL;
        tail=new;
        head=new;
    }
    else {
        new->next=head;
        head->prev=new;
        head=new;
    }
}
void impend(int data) {
    dlist *new=malloc(sizeof(dlist));
    new->data=data;
    new->next=NULL;
    if(tail==NULL) {
        new->prev=NULL;
        tail=new;
        head=new;
    }
    else {
        tail->next=new;
        new->prev=tail;
        tail=new;
    }
}
void impmid(int data , int index) {
    int m;
    printf("which place do you want to add\n ");
    scanf("%d",&m);
    dlist *new=malloc(sizeof(dlist));
    new->data=data;
    if(m==1) {
        impBeg(data);
        return;
    }
    if(tail==NULL) {
        iterate(data);
        return;
    }
    if(m>index) {
        impend(data);
        return;
    }
    dlist *temp=head;
    dlist *prev=NULL;
    while(m>1) {
        prev=temp;
        temp=temp->next;
        m--;
    }
    prev->next=new;
    new->prev=prev;
    new->next=temp;
    temp->prev=new;
}
void remnode(int index) {
    int a;
    printf("from which place do you want to remove a node");
    scanf("%d",&a);
    if(tail==NULL) {
        return;
    }
    if(a==1) {
        dlist *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        free(temp);
    }
    else if(a==index) {
        dlist *temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            // If tail becomes NULL, it means the list had only one node
            head = NULL;
        }
        free(temp);
    }
    else {
        dlist *temp=head;
        dlist *prev=NULL;
        while(a>1) {
            prev=temp;
            temp=temp->next;
            a--;
        }
        prev->next=temp->next;
        temp->next->prev=prev;
        free(temp);
    }

}