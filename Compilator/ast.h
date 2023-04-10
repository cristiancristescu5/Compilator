
#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ast{

    struct ast *left;
    struct ast *right;
    char op[100];
    int operand;
}AST;


struct ast *buildAst(int operand, struct ast *left, struct ast *right, char op[100]){
    struct ast *ast_node=(ast *) malloc(sizeof(struct ast));

//     ast_node->operand=operand;
//     strcpy(ast_node->op, op);

//     ast_node->left=left;
//     ast_node->right=right;


    return ast_node;

}

int evalAst(struct ast *root){
//     if(root->left==0 && root->right==0){
//         if(strcmp(root->op, "NUMBER")==0){
//             return root->operand;
//         }
//     }else return 0;

//     if(strcmp(root->op, "plus")==0){

//         return evalAst(root->left) + evalAst(root->right);
//     }

//     if(strcmp(root->op, "minus")==0){
//         return evalAst(root->left) - evalAst(root->right);
//     }

//     if(strcmp(root->op, "multiply")==0){
//         return evalAst(root->left) * evalAst(root->right);
//     }

//     if(strcmp(root->op, "devide")==0){
//         return evalAst(root->left) / evalAst(root->right);
//     }
    return 0;
 }








#endif