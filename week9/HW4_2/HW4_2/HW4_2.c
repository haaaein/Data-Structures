#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *search (TreeNode *node, int key)
{
    if (node == NULL)  return NULL;
    if (key == node->key) return node;
    else if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode * new_node(int item)
{
    TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode * insert_node (TreeNode * node, int key)
{
    if (node == NULL) return new_node(key);
    
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else
        node->right = insert_node(node->right, key);
    
    return node;
}

TreeNode * min_value_node(TreeNode * node)
{
    TreeNode * current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

int get_minimum(TreeNode *node)
{
    while (node->left != NULL)
        node = node->left;
    return node->key;
}

int get_maximum(TreeNode *node)
{
    while (node->right != NULL)
        node = node->right;
    return node->key;
}

TreeNode * delete_node (TreeNode * root, int key)
{
    if (root == NULL) return root;
    
    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    
    else {
        if (root->left == NULL) {
            TreeNode * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode * temp = root->left;
            free(root);
            return temp;
        }
        else {
            TreeNode * temp = min_value_node(root->right);
            
            root->key = temp->key;
            
            root->right = delete_node(root->right, temp->key);
        }
    }
    return root;
}

void preorder1(TreeNode * root) {
    if (root) {
        printf("%d ", root->key);
        preorder1(root->left);
        preorder1(root->right);
    }
}

int get_node_count(TreeNode* root)
{
    int count = 0;
    if (root != NULL) {
        count = 1 + get_node_count(root->left) + get_node_count(root->right);
    }
    return count;
}

int get_height(TreeNode *root)
{
    int height = 0;
    
    if (root != NULL) {
        height = max(get_height(root->left) , get_height(root->right));
        //return 1 + (left_h > right_h ? left_h : right_h);
    }
    return height;
    
}

char askChoice(void)
{
    char choice;
    printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, h<eight>, c<ount>, m<ax>, n<min>, q<uit>: ");
    scanf("%c", &choice);
    return choice;
}

int main(void)
{
    TreeNode *t = NULL;
    char choice;
    element newElement;
    element key;
    
    while ((choice = askChoice()) != 'q') {
        switch (choice) {
            case 'i':
                printf("????????? key??? ?????? : ");
                fflush(stdin);
                scanf("%d", &newElement);
                t = insert_node(t, newElement);
                break;
            case 'd':
                printf("????????? key ??? ?????? : ");
                fflush(stdin);
                scanf("%d", &key);
                t = delete_node(t, key);
                break;
            case 's':
                printf("????????? key ??? ?????? : ");
                scanf("%d", &key);
                if (search(t, key) != NULL)
                    printf("??????\n");
                else
                    printf("??????\n");
                break;
            case 'p':
                preorder1(t);
                printf("\n");
                break;
            case 'h':
                printf("????????? ????????? %d\n", get_height(t));
                break;
            case 'c':
                printf("????????? ????????? %d\n", get_node_count(t));
                break;
            case 'm':
                printf("?????? ??? ?????? %d\n", get_maximum(t));
                break;
            case 'n':
                printf("?????? ?????? ?????? %d\n", get_minimum(t));
                break;
            
        }
        fflush(stdin);
    }
}
