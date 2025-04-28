//ID:241014080
//Name:Farjana Akter Jim

#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *left;
struct node *right;

};

struct node *newNode(int data){
    struct node *node=malloc(sizeof(struct node));

    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return(node);
}

struct node *insert(struct node *root,int data){
if(root==NULL){
    return newNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
    root->right=insert(root->right,data);
    }
    return root;
}

void printPreorder(struct node *node){
if(node==NULL)
    return;

printf("%d\n ",node->data);

printPreorder(node->left);

printPreorder(node->right);

}

int main(){
int n,data;
struct node *root=NULL;
scanf("%d",&n);

for(int i=0;i<n;i++){
    scanf("%d",&data);
    root=insert(root,data);
}
printPreorder(root);
return 0;

}



