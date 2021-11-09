#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <strings.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
typedef struct TreeNode {
 int data;
 struct TreeNode *left, *right;
} TreeNode;

TreeNode n1={15, NULL, NULL};
TreeNode n2={4, &n1, NULL};
TreeNode n3={16, NULL, NULL};
TreeNode n4={25, NULL, NULL};
TreeNode n5={15, &n3, &n4};
TreeNode n6={15, &n2, &n5};
TreeNode *root= &n6;

TreeNode m1={15, NULL, NULL};
TreeNode m2={4, &n1, NULL};
TreeNode m3={16, NULL, NULL};
TreeNode m7 = {28, NULL, NULL}; // 추가
TreeNode m4={25, NULL, &m7}; // 변경
TreeNode m5={15, &m3, &m4};
TreeNode m6={15, &m2, &m5};
TreeNode *root2= &m6;

int get_nonleaf_count(TreeNode *t) {
    int count = 0;
    if (t != NULL) {
        if (t->left == NULL && t->right == NULL)
            return 0;
        else
            count = 1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
    }
    return count;
}

int equal(TreeNode *t1, TreeNode *t2) {
    if((t1 == NULL) && (t2 == NULL))
        return 1;
    
    else if((t1 != NULL) && (t2 != NULL)) {
        if(equal(t1->left, t2->left)) {
            if(equal(t1->right, t2->right)) {
                if(t1->data == t2->data)
                    return 1;
            }
        }
    }
    return 0;
}

int get_oneleaf_count(TreeNode *t) {
    int count = 0;
    if (t != NULL) {
        if (t->left == NULL && t->right != NULL)
            count = 1 + get_oneleaf_count(t->left) + get_oneleaf_count(t->right);
        else if (t->right == NULL && t->left != NULL)
            count = 1 + get_oneleaf_count(t->left) + get_oneleaf_count(t->right);
        else
            return 0;
    }
    return count;
}

int get_twoleaf_count(TreeNode *t) {
    int count = 0;
    if (t != NULL) {
        if (t->left != NULL && t->right != NULL)
            count = 1 + get_oneleaf_count(t->left) + get_oneleaf_count(t->right);
        else
            return 0;
    }
    return count;
}

int get_max(TreeNode *t) {
    int root, left, right, max = -1;
    if (t != NULL) {
        root = t->data;
        left = get_max(t->left);
        right = get_max(t->right);
        
        if (left > right)
            max = left;
        else
            max = right;
        
        if (root > max)
            max = root;
    }
    return max;
}

int get_min(TreeNode *t) {
    int root, left, right, min = 999;
    if (t != NULL) {
        root = t->data;
        left = get_min(t->left);
        right = get_min(t->right);
        
        if (left < right)
            min = left;
        else
            min = right;
        
        if (root < min)
            min = root;
    }
    return min;
}

void node_increase(TreeNode *t) {
    if (t != NULL) {
        t->data ++;
        node_increase(t->left);
        node_increase(t->right);
    }
}

void preorder1(TreeNode *root) // p271 코드 복사
{
    if (root!=NULL) {
        printf("%d ", root->data);
        preorder1(root->left);
        preorder1(root->right);
    }
}

TreeNode *copy(TreeNode *tree)
{
    TreeNode *temp;
    
    if(tree == NULL)
         return NULL;

    temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->left = copy(tree->left);
    temp->right = copy(tree->right);
    temp->data = tree->data;
    
    return temp;
}

int main(void)
{
     TreeNode *clone;
    
     printf("가)\n");
     printf("트리 root 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
     printf("트리 root2 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));
    
     printf("트리 root 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
     printf("트리 root2 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));
    
     printf("트리 root 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
     printf("트리 root2 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));
    
     printf("트리 root 에서 가장 큰 수는 %d.\n", get_max(root));
     printf("트리 root2 에서 가장 큰 수는 %d.\n", get_max(root2));
     printf("트리 root 에서 가장 작은 수는 %d.\n", get_min(root));
     printf("트리 root2 에서 가장 작은 수는 %d.\n", get_min(root2));
  
     printf("\n 나)\n");
     preorder1(root);
     node_increase(root);
     printf("\n");
     preorder1(root);
     printf("\n");
     printf("%s\n", equal(root, root) ? "같다": "다르다");
     printf("%s\n", equal(root2, root2) ? "같다": "다르다");
     printf("%s\n", equal(root, root2) ? "같다": "다르다");
    
     printf("\n 다)\n");
     clone = copy(root);
     preorder1(root) ;
     printf("\n");
     preorder1(clone) ;
     printf("\n");
}
