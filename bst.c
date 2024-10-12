#include <stdio.h>
#include<stdlib.h>
struct BinaryTreeNode{
    int key;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};
struct BinaryTreeNode* create(int x){
    struct BinaryTreeNode* temp=(struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
// Searching of Node element in Binary Search Tree
int searchNode(struct BinaryTreeNode* root,int x){
    if(root==NULL){
        return 0;
    }
    if(x<root->key){
        return searchNode(root->left,x);
    }
    if(x>root->key){
        return searchNode(root->right,x);
    }
    if(root->key==x){
        return 1;
    }
}
// Insertion of Node in Binary Search Tree
struct BinaryTreeNode* insert(struct BinaryTreeNode* root,int x){
    if(root==NULL){
        return create(x);
    }
    if(x<root->key){
        root->left=insert(root->left,x);
    }
    if(x>root->key){
        root->right=insert(root->right,x);
    }
    return root;
}
// Finding minimum element in Right subtree for replacing the deleted node
struct BinaryTreeNode* findMin(struct BinaryTreeNode* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left!=NULL){
        return findMin(root->left);
    }
    return root;
}
//Deletion of Node in Binary Search Tree
struct BinaryTreeNode* Delete(struct BinaryTreeNode* root,int x){
    if(root==NULL){
        return NULL;
    }
    if(root->key==x&&root->left==NULL&&root->right==NULL){
        return NULL;
    }
    if(root->key==x&&(root->left==NULL||root->right==NULL)){
        if(root->left==NULL){
            root=root->right;
            return root;
        }
        if(root->right==NULL){
            root=root->left;
            return root;
        }
    }
    if(x<root->key){
        root->left=Delete(root->left,x);
        return root;
    }
    if(x>root->key){
        root->right=Delete(root->right,x);
        return root;
    }
    if(x==root->key){
        struct BinaryTreeNode* temp=findMin(root->right);
        root->key=temp->key;
        root->right=Delete(root->right,root->key);
        return root;
    }
    
}
//Preorder Traversal of Binary Search Tree
void preorder(struct BinaryTreeNode* root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->key);
    preorder(root->left);
    preorder(root->right);
}
// Postorder Traversal of Binary Search Tree
void postorder(struct BinaryTreeNode* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->key);
}
//Inorder traversal of Binary Search Tree
void inorder(struct BinaryTreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->key);
    inorder(root->right);
}
int main() {
    // Write C code here
     printf("1. Insertion of Node\n");
        printf("2. Deletion of Node\n");
        printf("3. Searching of Node\n");
        printf("4. Printing of Preorder Traversal of Binary Search Tree\n");
        printf("5. Printing of Postorder Traversal of Binary Search Tree\n");
        printf("6. Printing of Inorder Traversal of Binary Search Tree\n");
        printf("7. Exit\n\n");
        struct BinaryTreeNode* root=NULL;
    while(1){
        printf("Please Enter your option based on above\n");
        int x,y;
        scanf("%d",&x);
        if(x==1){
            printf("Enter element to insert:\n");
            scanf("%d",&y);
            root=insert(root,y);
            printf("Element %d is inserted\n",y);
        }
        if(x==2){
            printf("Enter element to delete:\n");
            scanf("%d",&y);
            root=Delete(root,y);
        }
        if(x==3){
            printf("Enter Element to search:\n");
            scanf("%d",&y);
            int status=searchNode(root,y);
            if(status==1){
                printf("Element %d found\n");
            }else{
                printf("Element %d not found\n");
            }
        }
        if(x==4){
            printf("Preorder Traversal of Binary Search Tree is :\n");
            preorder(root);
            printf("\n");
        }
        if(x==5){
            printf("Postorder Traversal of Binary Search Tree is :\n");
            postorder(root);
            printf("\n");
        }
        if(x==6){
            printf("Inorder Traversal of Binary Search Tree is :\n");
            inorder(root);
            printf("\n");
        }
        if(x==7){
            printf("Exit\n");
            break;
        }
    }

    return 0;
}