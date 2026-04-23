#include <stdlib.h>

#include "tree.h"
#include "./../list/list.h"
#include "./../queue/queue.h"
#include "./../stack/stack.h"

Tree *tree_create(){
    Tree *p = malloc(sizeof(Tree));

    if (p != NULL){
        p -> size = NULL;
        p -> root = NULL;
    }
    return p;
}

TreeNode *tree_search(Tree *tree, void *data, int (*cmp)(void *, void *)){

    if (tree -> root == NULL || tree -> size == 0){
        return NULL;
    }

    TreeNode *current = tree -> root;

    while (current != NULL){
        int value = cmp(data, current -> data);

        if (value < 0){
            current = current -> left;
        }

        else if (value > 0){
            current = current -> right;
        }

        else {
            return current;
        }
        
        return NULL;
    }
}

void tree_insert(Tree *tree, void *data, int (*cmp)(void *, void *)) {
    TreeNode *newnode = malloc(sizeof(TreeNode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    
    if (tree->root == NULL || tree->size == 0) {
        tree->root = newnode;
        tree->size += 1;
        return;
    }

    TreeNode *current = tree->root;
    
    while (1) {
        int comparaison = cmp(data, current->data);
        
        if (comparaison < 0) {

            if (current->left == NULL) {
                current->left = newnode;
                tree->size += 1;
                return;
            }

            else {
                current = current->left;
            }
        }

        else if (comparaison > 0) {

            if (current->right == NULL) {
                current->right = newnode;
                tree->size += 1;
                return;
            } 
            
            else {
                current = current->right;
            }
        }

        else {
            free(newnode);
            return;
        }
    }
}

List *tree_bfs(Tree *tree){
    
    if (tree->root == NULL || tree-> size == 0){
        return NULL;
    }

    List *result = list_create();
    Queue *queue = queue_create();
    queue_enqueue(queue, tree->root);

    while (queue -> size != 0){
        TreeNode *current = queue_dequeue(queue);
        list_append(result, current->data);

        if (current -> left != NULL){
            queue_enqueue(queue, current -> left);
        }

        if (current -> right != NULL){
            queue_enqueue(queue, current -> right);
     } 
    }
    return result;
}

List *tree_dfs(Tree *tree){

    if (tree -> root == 0 || tree -> size == 0){
        return NULL;
    }

    Stack *stack = stack_create();
    stack_push(stack, tree -> root);
    List *result = list_create();

    while (stack -> size != 0){
        TreeNode *current = stack_pop(stack);
        list_append(result, current -> data);

        if (current -> right != NULL){
            stack_push(stack, current -> right);
        }

        if (current -> left != NULL){
            stack_push(stack, current -> left);
        }
    }
    return result;
}   

void tree_destroy(Tree *tree){

    if (tree == NULL || tree->root == NULL || tree -> size = 0){
        return;
    }
    
    TreeNode *current = tree->root;
    Stack *stack1 = stack_create();
    Stack * stack2 = stack_create();

    stack_push(stack1, tree->root);

    while (stack1->size != 0){
        TreeNode *current =stack_pop(stack1);

        if(current->left != NULL){
            stack_push(stack1, current->left);
        }

        if (current->right != NULL){
            stack_push(stack1, current->right);
        }

        stack_push(stack2, current);
    }

    while (stack2->size != 0){
        TreeNode *current = stack_pop(stack2);
        free(current);
    }
    
    stack_destroy(stack1);
    stack_destroy(stack2);
    free(tree);
}
