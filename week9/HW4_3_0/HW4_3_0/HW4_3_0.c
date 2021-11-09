#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 100

typedef struct {
    int id;
    char name[MAX_STRING];
    char tel[MAX_STRING];
    char dept[MAX_STRING];
} element;

typedef struct TreeNode {
    element data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *search (TreeNode *node, int key)
{
    if (node == NULL)
        return NULL;
    
    if (key == node->data.id) return node;
    else if (key < node->data.id)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode * new_node(element item)
{
    TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode * min_value_node(TreeNode * node)
{
    TreeNode * current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

TreeNode * insert_node (TreeNode * node, element key)
{
    if (node == NULL)
        return new_node(key);
    
    if (key.id < node->data.id)
        node->left = insert_node(node->left, key);
    else
        node->right = insert_node(node->right, key);
    
    return node;
}

TreeNode * delete_node (TreeNode * root, int key)
{
    if (root == NULL) return root;
    
    if (key < root->data.id)
        root->left = delete_node(root->left, key);
    else if (key > root->data.id)
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
            
            root->data = temp->data;
            
            root->right = delete_node(root->right, temp->data.id);
        }
    }
    return root;
}

void print(TreeNode * root)
{
    printf("------------------------------\n");
    printf("학번: %d \n", root->data.id);
    printf("이름: %s \n", root->data.name);
    printf("전화번호: %s \n", root->data.tel);
    printf("학과: %s \n", root->data.dept);
}

void inorder(TreeNode * root) {
    
    if (root) {
        inorder(root->left);
        print(root);
        inorder(root->right);
    }
}

int get_node_count(TreeNode* root)
{
    int count = 0;
    if (root != NULL)
    {
        count = 1 + get_node_count(root->left) + get_node_count(root->right);
    }
    return count;
}

int get_height(TreeNode *root) { // 트리의 높이를 구한다.
  if (!root)
    return 0;
  else {
    int left_h = get_height(root->left); // 왼쪽 서브트리의 높이를 순환호출을 통해 얻는다.
    int right_h = get_height(root->right); // 같은 방법으로 오른쪽 서브트리의 높이를 얻는다.
    return 1 + (left_h > right_h ? left_h : right_h); // 둘 중 큰 값에 1을 더해 반환한다.
  }
}

char askChoice(void)
{
    char choice;
    printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, c<ount>, q<uit>: ");
    scanf("%c", &choice);
    return choice;
}

int main(void)
{
    TreeNode *t = NULL;
    char choice;
    element newElement;
    element ele;
    int key;
    
    while ((choice = askChoice()) != 'q') {
        switch (choice) {
            case 'i':
                printf("학번 입력: ");
                fflush(stdin);
                scanf("%d", &newElement.id);
                fflush(stdin);
                printf("이름 입력: ");
                scanf("%s", newElement.name);
                fflush(stdin);
                printf("전화번호 입력: ");
                scanf("%s", newElement.tel);
                fflush(stdin);
                printf("학과 입력: ");
                scanf("%s", newElement.dept);
                t = insert_node(t, newElement);
                break;
                
            case 'd':
                printf("삭제할 학번 입력 : ");
                fflush(stdin);
                scanf("%d", &key);
                t = delete_node(t, key);
                break;
                
            case 's':
                printf("탐색할 학번 입력 : ");
                scanf("%d", &key);
                
                if (search(t, key) == NULL)
                    printf("id가 %d인 학생은 없습니다.\n", key);
                else {
                    ele = search(t, key)->data;
                    printf("------------------------------\n");
                    printf("학번 : %d\n", ele.id);
                    printf("이름: %s\n", ele.name);
                    printf("전화번호: %s\n", ele.tel);
                    printf("학과 : %s\n", ele.dept);
                    //inorder(search(t,key));
                }
                break;
                
            case 'p':
                printf("학생 정보 학번 순 출력\n");
                inorder(t);
                printf("\n");
                break;
        
            case 'c':
                printf("현재 저장된 학생의 총 수는 %d\n", get_node_count(t));
                break;

        }
        fflush(stdin);
    }
}
