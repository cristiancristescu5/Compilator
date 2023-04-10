%{
#include <stdio.h>
#include "source.hpp"
#include "ast.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
int yyerror(const char* s){
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 1;
}
bool ProgramError() {
    if(haveError) {
        yyerror(errorMessage);
        return true;
    }
    return false;
}
char global_type[200]="";
char global_type_right[200]="";
char global_function[200]="";
char returned_type_by_operation[200]="";
char parameter_types_found[200]="";
char global_params[200]="";
char parameter_function_type[200]="";
char typeofret[200]="";
int testare_parametri=0;
int global_type_ready=1;
int global_statement=0;
int if_while_statement=0;
int nr_params;
bool IsMain;
bool IsFunction;
bool IsGlobal;

%}
%union{
    int intval;
    char* strval;
    float floatval;
    struct ast* ast_node;
}
 
%token<strval> TYPE ID FUNCTION CLASS PRIVATE PUBLIC 
%token<intval> INTEGER
%token<strval> BOOLEAN 
%token <strval>STRING CHAR 
%token<floatval> FLOAT
%type<strval> declaratie_variabila declaratii_variabile list_parametri parametru function_calls
%type<strval> varop
%type<ast_node> exp 
%type<intval> eval
%token BEGIN_MAIN END_MAIN 
%token TYPEOF EVAL DECLARE   CONST  IF ELSE FOR WHILE DO
%left OR
%left AND
%left NOT
%left EQ NE LR LE GR GE
%left '+' '@'
%left '/' '%' '*'
%right ASSIGN
%left ACCESS
%start progr


%%
progr : global_stuff functions classes main {printf("program corect sintactic si semantic\n");}
      ;
main: BEGIN_MAIN cod END_MAIN {}
    ;
cod: declaratii_variabile cod {global_type_ready=1;}
    | declaratii_arrays cod {global_type_ready=1;}
    | declaratii_variabile {global_type_ready=1;}
    | declaratii_arrays {global_type_ready=1;}
    | statement cod {global_type_ready=1;}
    | statement {global_type_ready=1;}
    ;

statement: control_statement ';' {global_type_ready=1;}
    |assignment ';' {global_type_ready=1;}
    |declare_class ';' {global_type_ready=1;}
    |access_class ';' {global_type_ready=1;}
    |typeof ';' {global_type_ready=1;}
    |eval ';' {global_type_ready=1;}
    ;
typeof: TYPEOF '(' varop ')'  {
                                global_type_ready=1;
                                printf("\nTipul expresiei de la linia %d este:%s\n",yylineno,typeofret);
                                bzero(typeofret, 200);
                            }

eval: EVAL '(' exp ')' {  global_type_ready=1;
                            
                            // printf("\nTipul expresiei de la linia %d este:%s\n",yylineno,typeofret);
                            // bzero(typeofret, 200);
                           // printf("%d\n",evalAst($3));
                            }

    ;
exp: exp '+' exp {
                    char s[200];
                    strcpy(s, "plus");
                     printf("aici");
                    // buildAst('+', $1, $3, s);
                    printf("aici");
                } 
    |exp '-' exp {
                    char s[200];
                    strcpy(s, "minus");
                    // builAst('-', $1, $3, s);

                }
    |exp '*' exp {
           char s[200];
           strcpy(s, "multiply");
           // buildAst('*', $1, $3, s);
                }

    |exp '/' exp {
        char s[200];
        strcpy(s, "devide");
        // buildAst('/', $1, $3, s);
    }
    |INTEGER {
                char numar[200]="";
                
                int x=$1;
                

               
                char s[200];
                strcpy(s, "NUMBER");
              
               // buildAst(x, 0, 0,s);
      }
declare_class:  DECLARE ID ID {
                                    char clasa[200]="";
                                  char nume[200]="";
                                  strcpy(clasa, $2);
                                  strcpy(nume, $3);
                                  printf("%s\n", nume);
                                  printf("%s\n", clasa);
                                  if(check_if_in_use_class($2)==1){
                                        printf("sunt aici\n");
                                        AddVarClass(clasa,nume);
                                  }
                                  if(ProgramError()){
                                        return -1;
                                    }

}
            | DECLARE ID ID '[' INTEGER ']' {
                                            if(check_if_in_use_class($2)==1){
                                                AddArrClass($2, $3, $5);
                                                
                                            }
                                            if(ProgramError()){
                                                return -1;
                                            }

            }
            ;
access_class: ID ACCESS ID {    //AICI VA TREBUI SA FACI TU CUM TREBUIE PT CLASE
                                // check_if_in_use($1);
                                // if(ProgramError()){
                                //     return -1;
                                // }
                          }
            ;
 assignment: ID ASSIGN varop {
                                global_type_ready=1;
                               
                                char* type1=check_if_in_use_variable($1);
                                if(ProgramError()){
                                    return -1;
                                }
                                
                                
                                // char* var2=$3;
                                // char type2[200];
                                // int ok=0;
                                // for(int i=0;i<strlen(var2)&&ok==0;i++){
                                //     if(var2[i]==' '){
                                //         ok=1;
                                //         var2[i]='\0';
                                //     }
                                // }
                               
                                //strcpy(global_type_right,type1); //x1:=4-4+3+5%3+4+7+z1+x2[1]%z1+x1<sum(i,sum()^)^; SHOULD NOT WORK
                                 //printf("THIS IS THE ASSIGN %s %s\n",type1,returned_type_by_operation); //IT RETURNS THE LAST OPEERATION
                                strcpy(global_type_right,type1);
                                if(strcmp(type1,returned_type_by_operation)==0){
                                    //booleans=0;
                                    //II SCHIMB BALOAREA LUI ID
                                }
                                else{
                                    haveError = true;
                                    char erroring[200]="";
                                    strcpy(erroring,"Right side of assignment ");
                                    strcat(erroring, type1);
                                    strcat(erroring,"is not the same with the left side in terms of types ");
                                    strcat(erroring,returned_type_by_operation);
                                    printf("%s",erroring);
                                    
                                  if(ProgramError()){
                                   return -1;}
                                }
                            }
       | ID '[' INTEGER ']' ASSIGN varop { 
                                global_type_ready=1;
                                
                                char* type1=check_if_in_use_array($1);
                                
                                if(ProgramError()){
                                    return -1;
                                }
                                // char* var2=$3;
                                // char type2[200];
                                // int ok=0;
                                // for(int i=0;i<strlen(var2)&&ok==0;i++){
                                //     if(var2[i]==' '){
                                //         ok=1;
                                //         var2[i]='\0';
                                //     }
                                // }
                               
                                //strcpy(global_type_right,type1); //x1:=4-4+3+5%3+4+7+z1+x2[1]%z1+x1<sum(i,sum()^)^; SHOULD NOT WORK
                                 //printf("THIS IS THE ASSIGN %s %s\n",type1,returned_type_by_operation); //IT RETURNS THE LAST OPEERATION
                                 strcpy(global_type_right,type1);
                                if(strcmp(type1,returned_type_by_operation)==0){
                                    //booleans=0;
                                    //II SCHIMB BALOAREA LUI ID
                                }
                                else{
                                    haveError = true;
                                    strcpy(errorMessage, "Error: Right side of assignment is not the same with the left side in terms of types!");
                                    if(ProgramError()){
                                    return -1;}
                                }
                                        }
        | ID '[' ID ']' ASSIGN varop{ 
                                global_type_ready=1;
                               
                                char* type1=check_if_in_use_array($1);
                                if(ProgramError()){
                                    return -1;
                                }
                                
                                // char* var2=$3;
                                // char type2[200];
                                // int ok=0;
                                // for(int i=0;i<strlen(var2)&&ok==0;i++){
                                //     if(var2[i]==' '){
                                //         ok=1;
                                //         var2[i]='\0';
                                //     }
                                // }
                               
                                //strcpy(global_type_right,type1); //x1:=4-4+3+5%3+4+7+z1+x2[1]%z1+x1<sum(i,sum()^)^; SHOULD NOT WORK
                                // printf("THIS IS THE ASSIGN %s %s\n",type1,returned_type_by_operation); //IT RETURNS THE LAST OPEERATION
                                 strcpy(global_type_right,type1);
                                if(strcmp(type1,returned_type_by_operation)==0){
                                    //booleans=0;
                                    //II SCHIMB BALOAREA LUI ID
                                }
                                else{
                                    haveError = true;
                                    strcpy(errorMessage, "Error: Right side of assignment is not the same with the left side in terms of types!");
                                    if(ProgramError()){
                                    return -1;}
                                }
                                
                              
                                }
        | access_class ASSIGN varop{}
        ;


    varop: varop '+' varop { 
                        char* var2=$3;
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         
                         strcpy(type1,var2);
                         strcpy(typeofret,type1);
                        //printf("%s\n", typeofret);
                        strcpy(parameter_function_type,type1);
                        //printf("%s %s\n", global_type, type1);
                        if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0 ){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation + is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,type1);
                            if_while_statement++;
                            //$$=Operation($1,"+",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                       
                        
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
                        }
     | '{' varop '}' /*{
                //printf("TYPE %s\n", $$);
                
        } */
    |varop '@' varop {
                        char* var2=$3;
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                       
                         strcpy(type1,var2);
                        strcpy(typeofret,type1);
                        //printf("%s\n", typeofret);
                         strcpy(parameter_function_type,type1);
                        // printf("%s %s\n", global_type, type1);
                        if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation @ is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,type1);
                            //$$=Operation($1,"-",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                            strcat(errorMessage, global_type);
                            strcat(errorMessage, "  ");
                            strcat(errorMessage, type1);
                             if(ProgramError()){
                              return -1;}
                          }
                       
                        
                        // printf("VARIABILA 1 %s %s \n",global_type,$3);
     }
    |varop '/' varop {
                        char* var2=$3;
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                       
                         strcpy(type1,var2);
                         strcpy(typeofret,type1);
                        // printf("%s\n", typeofret);
                         strcpy(parameter_function_type,type1);
                        // printf("%s %s\n", global_type, type1);
                        if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation / is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,type1);
                           
                            //$$=Operation($1,"/",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                         
                        // printf("VARIABILA 1 %s %s \n",global_type,$3);
     }
    |varop '*' varop { 
                        char* var2=$3;
                        char type1[200];
                        int ok=0;
                        for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         
                         strcpy(type1,var2);
                         strcpy(typeofret, type1);
                        // printf("%s\n", typeofret);
                         strcpy(parameter_function_type,type1);
                         //printf("%s %s\n", global_type, type1);
                         if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation * is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,type1);
                      
                            //$$=Operation($1,"*",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                      
                        // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
    |varop '%' varop { 
                        char* var2=$3;
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                       
                        strcpy(type1,var2);
                        strcpy(typeofret, type1);
                        // printf("%s\n", typeofret);
                        strcpy(parameter_function_type,type1);
                        // printf("%s %s\n", global_type, type1);
                          if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation * is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,type1);
                          
                            //$$=Operation($1,"%",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                         
                        // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
    |ID {    
                char* type=check_if_in_use_variable($1);
                strcpy(typeofret, type);
                //printf("%s\n", typeofret);
                if(ProgramError()){
                    return -1;
                }
                char type_and_value[200];
                strcpy(type_and_value,type);
                strcat(type_and_value," ");
                strcpy(parameter_function_type,type);
                char number[200];  //THIS CONVERTS A NUMBER TO A CHAR*... THIS IS GOING TO BE AN INTEGER
                
                if(GetValue($1)==0){
                    number[0]='0';
                    number[1]='\0';
                    strcat(type_and_value,number);

                }
                else{
                int copy=GetValue($1);
                int i=0;
                while(copy!=0){
                    number[i]= copy%10+'0';
                    copy=copy/10;
                    i++;
                }
                for (int j=0;j<strlen(number)/2;j++)
                    {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                    }
                    strcat(type_and_value,number);
                }
                $$=type_and_value;
                if(global_type_ready==1){
                   strcpy(global_type,type);
                   global_type_ready=0;
                   strcpy(returned_type_by_operation,type);

                }
            
        }
    |STRING {   char type_and_value[200];
                strcpy(type_and_value,"[string]");
                strcat(type_and_value," ");
                strcat(type_and_value,$1);
                strcpy(typeofret, "[string]");
                printf("THIS IS A STRINGGGG \n");
                strcpy(parameter_function_type,"[string]");
                //printf("%s\n",type_and_value);
                
                if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[string]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[string]");
                }
               strcpy($$,"[string]");
                
            }
     |BOOLEAN {  
                char type_and_value[200];
                strcpy(type_and_value,"[bool]");
                strcat(type_and_value," ");
                strcat(type_and_value,$1);
                 strcpy(typeofret, "[bool]");
                //printf("%s\n", typeofret);
                //printf("%s\n",type_and_value);
                strcpy(parameter_function_type,"[bool]");
                if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[bool]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[bool]");
                }
                
                strcpy($$,"[bool]");
             }
     |INTEGER{ 
        
                   /* char number[200]="";  //THIS CONVERTS A NUMBER TO A CHAR*... THIS IS GOING TO BE AN INTEGER
                     int copy=$1;
                     int minus=0;
                     strcpy(typeofret, "[int]");
                     if(copy<0){
                        copy=copy*(-1);
                         minus=1;
                        }
                     int i=0;
                     char type_and_value[200];
                     strcpy(type_and_value,"[int]");
                    strcat(type_and_value," ");
                         if(copy==0){
                            number[0]='0';
                            number[1]='\0';
                            strcat(type_and_value,number);
                            }
                    else{
                        while(copy!=0){
                            number[i]= copy%10+'0';
                            copy=copy/10;
                            i++;
                    }
                        for (int j=0;j<strlen(number)/2;j++)
                         {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                        }
                    if(minus==1){
                        char number1[200];
                        strcat(number1, "-");
                        strcat(number1, number);
                        strcat(type_and_value,number1);
                    }else{
                            strcat(type_and_value,number);
                        }
                    }
                  strcpy(function_type,"[int]");
                // printf("%s\n", type_and_value);
                 if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[int]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[int]");
                 }
                
                $$=type_and_value;
                */
                char number[200]="";  //THIS CONVERTS A NUMBER TO A CHAR*... THIS IS GOING TO BE AN INTEGER
                int copy=$1;
                int i=0;
                char type_and_value[200];
                 strcpy(typeofret, "[int]");
                strcpy(type_and_value,"[int]");
                strcat(type_and_value," ");
                if(copy==0){
                    number[0]='0';
                    number[1]='\0';
                    strcat(type_and_value,number);
                }
                else{
                        while(copy!=0){
                        number[i]= copy%10+'0';
                        copy=copy/10;
                        i++;
                    }
        
                    for (int j=0;j<strlen(number)/2;j++)
                    {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                    }
                    strcat(type_and_value,number);
                }
                 strcpy(parameter_function_type,"[int]");
                 //printf("%s\n", type_and_value);
                 if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[int]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[int]");
                 }
                 //printf("I entered here %s", type);
               
                $$=type_and_value;
               
                }
    |FLOAT  {
                //char number[200]="";
                // float copy=$1;
                // float aux=copy;
                // if(copy<0){
                //     copy=copy*(-1);
                // }
                //char type_and_value[200];
                //strcpy(type_and_value,"[float]");
               // strcat(type_and_value," ");
                strcpy(typeofret,"[float]");
                // if(copy==0){
                //     number[0]='0';
                //     number[1]='\0';
                //     strcat(type_and_value,number);
                // }else {
                //     int k=0;
                //     while((int)(copy)%10!=0){
                //         copy*=10;
                //         k++;
                //     }
                //     int pow=k;
                //     copy=copy/10;
                //     int i=0;
                //     // if(aux<0){
                //     //     number[0]='-';
                //     //     i=1;
                //     // }

                //     while(copy!=0){
                //         number[i]=(int)(copy)%10-'0';
                //         i++;
                //     }
                //     if(aux>=0){
                //         for (int j=0;j<strlen(number)/2;j++)
                //             {
                        
                //                 char aux=number[j];
                //                 number[j]=number[strlen(number)-j-1];
                //                 number[strlen(number)-j-1]=aux;
                //              }
                //         char number1[201];
                //         strcpy(number1, number);
                //         for(int i=strlen(number1)-1;i>=pow;i--){
                //             number1[i]=number1[i-1];

                //          }
                //         number[pow]='.';
                //         strcat(type_and_value, number);
                //         printf("%s\n", type_and_value);
                //         if(global_type_ready==1){
                //             char type[200];
                //             strcpy(type,"[float]");
                //             strcpy(global_type,type);
                //             global_type_ready=0;
                //             strcpy(returned_type_by_operation,"[float] ");
                //          }
               
                //     }else {
                //         for (int j=1;j<strlen(number)/2;j++)
                //             {
                        
                //                 char aux=number[j];
                //                 number[j]=number[strlen(number)-j-1];
                //                 number[strlen(number)-j-1]=aux;
                //              }
                //         strcat(type_and_value,"-");
                //         char number2[202];
                //         strcat(number2,"-");
                //         strcat(number2,number);
                //         for(int i=strlen(number2)-1;i>=pow;i--){
                //             number2[i]=number2[i-1];

                //          }
                //         number2[pow]='.';
                //         strcat(type_and_value,number2);
                //         printf("%s\n", type_and_value);
                        strcpy(parameter_function_type,"[float]");
                        if(global_type_ready==1){
                            char type[200];
                            strcpy(type,"[float]");
                            strcpy(global_type,type);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[float]");
                         }
                    printf("%s\n",parameter_function_type);
                    $$=parameter_function_type;
                    // }
                    
                // }

            }
    |CHAR{
                char type_and_value[200];
                strcpy(type_and_value,"[char]");
                strcat(type_and_value," ");
                strcpy(typeofret, "[char]");
                strcat(type_and_value,$1);
                //printf("%s\n",type_and_value);
                strcpy(parameter_function_type,"[char]");
                if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[char]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[char]");
                }
                
                $$=type_and_value;
             }
    
    |access_class '^' {}
    |ID '[' INTEGER ']' { 
                    char* type=check_if_in_use_array($1);
                    if(ProgramError()){
                        return -1;
                    }
                strcpy(typeofret, type);
                //printf("%s\n", typeofret);
                strcpy(parameter_function_type,type);
                char type_and_value[200];
                strcpy(type_and_value,type);
                strcat(type_and_value," ");
                
                char number[200];  
                
                if(GetValue($1)==0){
                    number[0]='0';
                    number[1]='\0';
                    strcat(type_and_value,number);

                }
                else{
                int copy=GetValue($1);  /*AICI GETVALUE VA TREBUIE MODIFICAT CA SA MEARGA PT VECTOR*/
                int i=0;
                while(copy!=0){
                    number[i]= copy%10+'0';
                    copy=copy/10;
                    i++;
                }
                for (int j=0;j<strlen(number)/2;j++)
                    {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                    }
                    strcat(type_and_value,number);
                }
               
                $$=type_and_value;
                if(global_type_ready==1){
                   strcpy(global_type,type);
                   global_type_ready=0;
                   strcpy(returned_type_by_operation,type);
                }
                //printf("%s",type);

                }
    |ID '[' ID ']' { 
                char* type=check_if_in_use_array($1);
                if(ProgramError()){
                    return -1;
                }
                strcpy(typeofret, type);
                //printf("%s\n", typeofret);
                 strcpy(parameter_function_type,type);
                char type_and_value[200];
                strcpy(type_and_value,type);
                strcat(type_and_value," ");
                
                char number[200];  
                
                if(GetValue($1)==0){
                    number[0]='0';
                    number[1]='\0';
                    strcat(type_and_value,number);

                }
                else{
                int copy=GetValue($1);  /*AICI GETVALUE VA TREBUIE MODIFICAT CA SA MEARGA PT VECTOR*/
                int i=0;
                while(copy!=0){
                    number[i]= copy%10+'0';
                    copy=copy/10;
                    i++;
                }
                for (int j=0;j<strlen(number)/2;j++)
                    {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                    }
                    strcat(type_and_value,number);
                }
                if(global_type_ready==1){
                   strcpy(global_type,type);
                   global_type_ready=0;
                   strcpy(returned_type_by_operation,type);
                }
                $$=type_and_value;
                
                //printf("%s",type);
              }
    | function_calls '^' {$$=$1;}
    | NOT varop {
                        char* var2=$2;
                        char type1[200];
                        int j=0;
                        int ok=0;
                        for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                        //printf("THIS IS A NOT %s\n", var2);
                        // printf("%s %s\n", global_type, type1);
                        strcpy(parameter_function_type,"[bool]");
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        if(strcmp(returned_type_by_operation,"[bool]")!=0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation NOT is not permitted with these types, only [bool] is admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation ,"[bool]");
                            //$$=Operation($1,"AND",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }        
                }
    |varop AND varop{   
                        char* var2=$3;
                        // printf("THIS IS AN AND %s\n", var2);
                        char type1[200];
                        int j=0;
                        int ok=0;
                        for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                        
                         strcpy(type1,var2);
                        //  printf("THIS IS AN AND %s\n", type1);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                         if(strcmp(returned_type_by_operation,"[bool]")!=0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation AND is not permitted with these types, only [bool] is admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        // printf("%s %s\n", global_type, type1);
                         strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation ,"[bool]");
                            //$$=Operation($1,"AND",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                     
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
                }
    |varop LE varop{
                    char* var2=$3;
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                         strcpy(type1,var2);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        
                        // printf("%s %s\n", global_type, type1);
                        strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,"[bool]");
                             
                            //$$=Operation($1,"LE",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          } 
                        
                       // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
    |varop LR varop {
                        char* var2=$3;
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                         strcpy(type1,var2);
                          if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                       
                        // printf("ACESTA E UN < %s %s\n",global_type_right, type1);
                          strcpy(parameter_function_type,"[bool]");
                        
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,"[bool]");
                           
                            //$$=Operation($1,"LR",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
    |varop OR varop {
                    char* var2=$3;
                        char type1[200];
                        int ok=0;
                        
                       strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                        // printf("THIS IS AN OR %s\n", var2);
                         strcpy(type1,var2);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                         if(strcmp(returned_type_by_operation,"[bool]")!=0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation OR is not permitted with these types, only [bool] is admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        // printf("%s %s\n", global_type, type1);
                        strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation ,"[bool]");
                            //$$=Operation($1,"OR",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                       
                       // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
    |varop GR varop {
                       char* var2=$3;
                        char type1[200];
                        int ok=0;
                        strcpy(typeofret, "[bool]");
                      // printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        // printf("%s %s\n", global_type, type1);
                          strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,"[bool]");
                           
                            //$$=Operation($1,"GR",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                       // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
    |varop GE varop {
                        char* var2=$3;
                        char type1[200];
                        int ok=0;
                        strcpy(typeofret, "[bool]");
                      // printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                          if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        // printf("%s %s\n", global_type, type1);
                          strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,"[bool]");
                          
                            //$$=Operation($1,"GE",$3); 

                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
    |varop EQ varop{
                        char* var2=$3;
                        char type1[200];
                        int ok=0;
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                          if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        // printf("%s %s\n", global_type, type1);
                          strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,"[bool]");
                        
                            //$$=Operation($1,"EQ",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                       // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
    |varop NE varop {
                        char* var2=$3;
                        char type1[200];
                        int ok=0;
                        strcpy(typeofret, "[bool]");
                        //printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        // printf("%s %s\n", global_type, type1);
                          strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0 ){
                             strcpy(returned_type_by_operation,"[bool]");
                
                            //$$=Operation($1,"NE",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
    ;
control_statement: if
                | for
                |while
                ;
for: FOR '(' assignment ';' varop ';' assignment ')' '{' '}' {global_type_ready=1;}
    |FOR '(' assignment ';' varop ';' assignment ')' '{' cod '}' {global_type_ready=1;}
    ;
while: WHILE '(' varop ')' do '{' cod '}' {global_type_ready=1;}
    | WHILE '(' varop ')'do '{''}' {global_type_ready=1;}
    ;
if:  IF '('varop ')' do '{' '}' {global_type_ready=1;}
    | IF '('varop')' do'{' cod '}' ELSE do '{' cod '}' {global_type_ready=1;}
    | IF '('varop')' do '{' '}' ELSE do '{' cod '}' {global_type_ready=1;}
    | IF '('varop ')'do'{' cod '}' ELSE do '{' '}' {global_type_ready=1;}
    | IF '('varop')'do '{' '}' ELSE do '{' '}' {global_type_ready=1;}
    ;
do: DO {global_type_ready=1;}
global_stuff: global_variables global_stuff
            | global_arrays global_stuff
            | global_consts global_stuff
            | global_variables
            |global_arrays
            |global_consts
            ;
global_consts: declaratii_consts
            ;
function_consts: function_declaratii_consts
            |
            ;
function_declaratii_consts: function_declaratie_const';'
                |function_declaratie_const',' function_declaratii_consts
                ;
function_declaratie_const: CONST TYPE ID ASSIGN INTEGER {
                                                AddNewConstNat($2,$3,$5);
                                                if(ProgramError()){
                                                    return -1;
                                                }
                                                DisplayParamsConst($2,$3);}
                 | CONST TYPE ID ASSIGN STRING
                                                {
                                                    AddNewConstString($2,$3,$5);
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                                    DisplayParamsConst($2,$3);
                                                }
                |CONST TYPE ID ASSIGN CHAR  {
                                char* constanta;
                                strcpy(constanta,$5);
                                char c=constanta[0];
                                  AddNewConstChar($2,$3,c);
                                  if(ProgramError()){
                                    return -1;
                                }
                                  DisplayParamsConst($2,$3);
                                }
                |CONST TYPE ID ASSIGN BOOLEAN  {
                                  AddNewConstBoolean($2,$3,$5);
                                  if(ProgramError()){
                                    return -1;
                                }
                                  DisplayParamsConst($2,$3);
                                }
                |CONST TYPE ID ASSIGN FLOAT  {
                                  AddNewConstFloat($2,$3, $5);
                                  if(ProgramError()){
                                    return -1;
                                }
                                  DisplayParamsConst($2,$3);
                                }
                ;
declaratii_consts: declaratie_const';'
                |declaratie_const',' declaratii_consts
                ;
declaratie_const: CONST TYPE ID ASSIGN INTEGER {
                                                AddNewConstNat($2,$3,$5);
                                                if(ProgramError()){
                                                    return -1;
                                                }
                                                }
                 | CONST TYPE ID ASSIGN STRING
                                                {
                                                    AddNewConstString($2,$3,$5);
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                                }
                | CONST TYPE ID ASSIGN CHAR {
                                                     char* constanta;
                                                    strcpy(constanta,$5);
                                                    char c=constanta[0];
                                                    AddNewConstChar($2,$3,c);
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                            }
                | CONST TYPE ID ASSIGN FLOAT {
                                                    AddNewConstFloat($2,$3,$5);
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                            }
                
                | CONST TYPE ID ASSIGN BOOLEAN {
                                                    AddNewConstBoolean($2,$3,$5);
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                            }
                ;
global_arrays: declaratii_arrays 
                ;
function_arrays: function_declaratii_arrays
                | 
                ;
function_declaratii_arrays: function_declaratie_array';' 
                | function_declaratie_array','  function_declaratii_arrays
                ;
function_declaratie_array: TYPE ID '[' INTEGER ']' {
                                            AddNewArray($1,$2,$4);
                                            if(ProgramError()){
                                                return -1;
                                            }
                                            DisplayParamsArray($1,$2,$4);
                                          }
                ; 
declaratii_arrays: declaratie_array';' 
                | declaratie_array','  declaratii_arrays
                ;
declaratie_array: TYPE ID '[' INTEGER ']' {
                                            AddNewArray($1,$2,$4);
                                            if(ProgramError()){
                                                return -1;
                                            }
                                          }
                ;               
global_variables: declaratii_variabile 
                ;
function_variables: function_declaratii_variabile 
                |
                ;  
function_declaratii_variabile: function_declaratie_variabila';' 
                    |function_declaratie_variabila',' function_declaratii_variabile 
                    ;
function_declaratie_variabila: TYPE ':' ID {
                                    AddNewVariable($1,$3);
                                    if(ProgramError()){
                                    return -1;
                                    }
                                    DisplayParams($1,$3);
                                  }
                              
                    ;              
declaratii_variabile: declaratie_variabila';' 
                    |declaratie_variabila',' declaratii_variabile 
                    ;
declaratie_variabila: TYPE ':' ID {
                                    AddNewVariable($1,$3);
                                    if(ProgramError()){
                                    return -1;
                                    }
                                  }
                    ;
functions: declaratii_functii {}
        ;
declaratii_functii: declaratie_functie';' {}
                |declaratie_functie',' declaratii_functii {}
                ;
declaratie_functie: FUNCTION TYPE ID  '(' function_variables '^' function_arrays '^' function_consts ')' '{' cod_functie '}' {AddNewFunction($2,$3); if(ProgramError()){
                                                                                                                                    return -1;
                                                                                                                                }}
                | FUNCTION TYPE ID '(' ')' '{'cod_functie '}' {AddNewFunction($2,$3);
                                if(ProgramError()){
                                    return -1;
                                }
                                }
                ;
cod_functie: cod
            |/*epsilon*/
            ;
classes: declaratii_clase {}
        //| {yyerror("The classes section does not appear"); return -1;}
        ;
declaratii_clase: declaratie_clasa';'  {}
                |declaratie_clasa',' declaratii_clase {}
                ;
declaratie_clasa: CLASS ID '{' '}' {                              AddNewClass($2);
                                                                 if(ProgramError()){
                                                                    return -1;
                                                                        }  }
                | CLASS ID '{' PRIVATE chestii_clasa PUBLIC chestii_clasa '}' {
                                                                                    AddNewClass($2);
                                                                                    if(ProgramError()){
                                                                                return -1;
                                                                                    } 
                                                                                 }
                ;
chestii_clasa: declaratii_clase  chestii_clasa
            | declaratii_variabile chestii_clasa  
            | declaratii_functii chestii_clasa 
            | /*epsilon*/
            ;
function_calls: ID '(' ')' {
                         parameter_types_found[0]='\0';
                                nr_params=0;
                                char* type=check_if_in_use_function($1);
                                $$=type;
                                strcpy(typeofret, global_type);
                               // printf("%s\n", typeofret);
                                 strcpy(parameter_function_type,type);
                                // if(ProgramError()){
                                //     return -1;
                                // }
                                if(global_type_ready==1){
                                strcpy(global_type,type);
                                global_type_ready=0;
                                strcpy(returned_type_by_operation,type);
                                }
                                printf("THIS IS THE FUNCTION NAME %s ",$1); //AICI AM FUNCTION NAME-UL CORECT
                                //in global_params voi avea tipurile ce vin din recursie
                                std::string tp;
                                std::ifstream ReadFunctions;
                                ReadFunctions.open("symbol_table_functions.txt");
                               // printf("THIS IS THE FUNCTION NAME %s \n",$1); //AICI AM FUNCTION NAME-UL CORECT
                                std::fflush(stdout);
                                while(getline(ReadFunctions, tp)) {
                                    
                                    char arr[tp.length() + 1]=""; 
	                                strcpy(arr, tp.c_str());
                                    //printf("%s \n", arr);
                                    char functie[200]="";
                                    strcpy(functie,"Function name:");
                                    strcat(functie,$1);
                                    strcat(functie," ");
                                    if(strstr(arr,functie)!=NULL){
                                        char rezultat[200] = "";
                                        char *p;
                                        char copie[200]="";
                                        strcpy(copie, arr);
                                        p = strtok(copie, "; ");
                                        
                                        while(p)
                                        {
                                            if(p[0] == '[' && (strchr("1234567890", p[1]) == NULL))
                                            strcat(rezultat, p);
                                            p = strtok(NULL, "; ");
                                        }
                                        int d=strlen(global_params);
                                        int d2=strlen(rezultat);
                                        // GLOBAL PARAMS MUST BE NULL HERE
                                        if(strcmp(global_params,rezultat)!=0 && strcmp(global_params,"")!=0){
                                             haveError = true;
                                             printf("Inputted params types: %s, actual types: %s",global_params,rezultat);
                                            strcpy(errorMessage, "Error: The parameters do not match with the function definition!");
                                            if(ProgramError()){
                                            return -1;
                                            }
                                        }    
                                    }
                                }
                                strcpy(parameter_types_found,"");
                                global_function[0]='\0';
                                global_params[0]='\0';
                              
                    }
             | ID '('list_parametri')'{
                                parameter_types_found[0]='\0';
                                nr_params=0;
                                char* type=check_if_in_use_function($1);
                                $$=type;
                                strcpy(typeofret, global_type);
                               // printf("%s\n", );
                                strcpy(parameter_function_type,type);
                                // if(ProgramError()){
                                //     return -1;
                                // }
                                if(global_type_ready==1){
                                strcpy(global_type,type);
                                global_type_ready=0;
                                strcpy(returned_type_by_operation,type);
                                }
                                printf("THIS IS THE FUNCTION NAME %s ",$1); //AICI AM FUNCTION NAME-UL CORECT
                                //in global_params voi avea tipurile ce vin din recursie
                                std::string tp;
                                std::ifstream ReadFunctions;
                                ReadFunctions.open("symbol_table_functions.txt");
                               // printf("THIS IS THE FUNCTION NAME %s \n",$1); //AICI AM FUNCTION NAME-UL CORECT
                                std::fflush(stdout);
                                while(getline(ReadFunctions, tp)) {
                                    
                                    char arr[tp.length() + 1]=""; 
	                                strcpy(arr, tp.c_str());
                                    //printf("%s \n", arr);
                                    char functie[200]="";
                                    strcpy(functie,"Function name:");
                                    strcat(functie,$1);
                                    strcat(functie," ");
                                    if(strstr(arr,functie)!=NULL){
                                        char rezultat[200] = "";
                                        char *p;
                                        char copie[200]="";
                                        strcpy(copie, arr);
                                        p = strtok(copie, "; ");
                                        
                                        while(p)
                                        {
                                            if(p[0] == '[' && (strchr("1234567890", p[1]) == NULL))
                                            strcat(rezultat, p);
                                            p = strtok(NULL, "; ");
                                        }
                                        int d=strlen(global_params);
                                        int d2=strlen(rezultat);
                                        
                                        if(strcmp(global_params,rezultat)!=0){
                                             haveError = true;
                                             printf("Inputted params types: %s, actual types: %s",global_params,rezultat);
                                            strcpy(errorMessage, "Error: The parameters do not match with the function definition!");
                                            if(ProgramError()){
                                            return -1;
                                            }
                                        }    
                                    }
                                }
                                strcpy(parameter_types_found,"");
                                global_function[0]='\0';
                                global_params[0]='\0';
                                  
                              }
            ;
list_parametri: parametru {  strcpy($$,global_params);printf(" Parameters %s\n", $$);
                          }
              | parametru',' list_parametri { strcpy($$,global_params);printf("Parameters %s \n", $1);
              }
              ;
 parametru: varop {
            
            strcpy(parameter_types_found,parameter_function_type);
            //printf("THIS IS FUNCTION TYPE %s", parameter_types_found );
            strcat(global_params,parameter_types_found); //ce returneaza operatia
            }                                      
         ;
%%
int main(int argc, char** argv){
    init();
    yyin=fopen(argv[1], "r");
    yyparse();
}