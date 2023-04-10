#ifndef SOURCE_HPP
#define SOURCE_HPP
#include <string.h>
#include <stdbool.h>
#include<cstring>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <iostream>

#define MAX_VARS 1000
#define MAX_VAR_NAME 256
#define MAX_ERROR 1000
#define MAX_STRVAL 10000
#define MAX_PARAMETERS 100

struct variable {
  char* dataType;
  char* varName;
  int val=0;
  bool isConstant, isInitialized;
};
struct Arrays {
  char* ArrayName;
  char* dataType;
  int size;
  //struct data *values;
};
struct Function {
  char* dataType;
  char *functionName;
  char* parameters[MAX_PARAMETERS]; //aici voi retine tipul fiecarui parametru
  int nrParams=0;
  bool isDefined;
};
struct clasa{
  char *classname;
  bool isdefined;
  int nrvars;
  std::vector <variable> var[100];
  std::vector <Function> fun[100];

};
extern bool haveError;
extern char errorMessage[MAX_ERROR];
void init();
void AddNewVariable(char*, char *);
void AddNewArray(char*,char*, int);
void AddNewConstNat(char*,char*,int);
void AddNewConstString(char*,char*,char*);
void AddNewConstBoolean(char*,char*, char*);
void AddNewConstChar(char*,char*, char);
void AddNewConstFloat(char*,char*,float);
void AddNewFunction(char*,char*);
void DisplayParams(char*,char*);
void DisplayParamsConst(char*,char*);
void DisplayParamsArray(char*,char*,int);
void Unique(char*);
char* check_if_in_use_variable(char*);
int check_if_in_use_class(char*);
char* check_if_in_use_array(char*);
char* check_if_in_use_function(char*);
int GetValue(char*);
void AddNewClass(char*);
void AddVarClass(char* tip, char* name);
void AddArrClass(char*, char*, int);
char* Operation(char*,const char*,char*);
#endif