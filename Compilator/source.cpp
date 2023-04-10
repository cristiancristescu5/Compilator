#include "source.hpp"
int nrParams, nrVars, nrVectors, nrFunctions, nrCampuri, nrClasses, nrInstances, nextVarId, nextFunctionId, nextClassId;
bool haveError;
char errorMessage[MAX_ERROR], campuri[MAX_VARS][MAX_VAR_NAME];
std::vector<variable> Variables;
std::vector<Arrays> Vectors;
std::vector<Function> Functions;
std::vector<clasa> classes;
std::ofstream PrintVariables("symbol_table.txt");
std::fstream ReadVariables("symbol_table.txt");
std::ofstream PrintFunctions("symbol_table_functions.txt");


void init(){
    nrVars = nrVectors = nrFunctions = nrCampuri = nrClasses = nrInstances = 0;
    nextVarId = nextFunctionId = nextClassId = 0;
    haveError = false;
    errorMessage[0] = '\0';
}
void AddNewVariable(char* type, char *varName) {
    Unique(varName);
    Variables.push_back(variable());
    Variables[nrVars].dataType=type;
    Variables[nrVars].varName=varName;
    Variables[nrVars].isConstant=false;
    Variables[nrVars].isInitialized=false;
    Variables[nrVars].val=0;
    ++nrVars;
     
    if (PrintVariables.is_open())
    {
        PrintVariables << type<<" "<<varName<<" Predefined value:None"<<std::endl;
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void AddNewArray(char* type, char *varName, int size) {
    Unique(varName);
    Vectors.push_back(Arrays());
    Vectors[nrVectors].dataType=type;
    Vectors[nrVectors].ArrayName=varName;
    Vectors[nrVectors].size=size;
    ++nrVectors;
     if (PrintVariables.is_open())
    {
        PrintVariables << type<<" "<<varName<<"["<<size<<"]"<<" Predefined value: None"<<std::endl;
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void AddNewConstNat(char* type, char *varName, int number) {
    Unique(varName);
    Variables.push_back(variable());
    Variables[nrVars].dataType=type;
    Variables[nrVars].varName=varName;
    Variables[nrVars].isConstant=true;
    Variables[nrVars].isInitialized=true;
    ++nrVars;
     if (PrintVariables.is_open())
    {
        PrintVariables << "CONST"<<type<<" "<<varName<<" "<<" Predefined value:"<<number<<std::endl;
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void AddNewConstString(char* type, char *varName, char* _string ) {
    Unique(varName);
    Variables.push_back(variable());
    Variables[nrVars].dataType=type;
    Variables[nrVars].varName=varName;
    Variables[nrVars].isConstant=true;
    Variables[nrVars].isInitialized=true;
    ++nrVars;
     if (PrintVariables.is_open())
    {
        PrintVariables << type<<" "<<varName<<" "<<" Predefined value: "<<_string<<std::endl;
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void AddNewConstChar(char* type, char *varName, char value ) {
    Unique(varName);
    Variables.push_back(variable());
    Variables[nrVars].dataType=type;
    Variables[nrVars].varName=varName;
    Variables[nrVars].isConstant=true;
    Variables[nrVars].isInitialized=false;
    ++nrVars;
     if (PrintVariables.is_open())
    {
        PrintVariables << type<<" "<<varName<<" "<<" Predefined value: "<<value<<std::endl;
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void AddNewConstFloat(char* type, char *varName,float value ) {
    Unique(varName);
    Variables.push_back(variable());
    Variables[nrVars].dataType=type;
    Variables[nrVars].varName=varName;
    Variables[nrVars].isConstant=true;
    Variables[nrVars].isInitialized=false;
    ++nrVars;
     if (PrintVariables.is_open())
    {
        PrintVariables << type<<" "<<varName<<" "<<" Predefined value: "<<value<<std::endl;
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void AddNewConstBoolean(char* type, char *varName,char*value ) {
    Unique(varName);
    Variables.push_back(variable());
    Variables[nrVars].dataType=type;
    Variables[nrVars].varName=varName;
    Variables[nrVars].isConstant=true;
    Variables[nrVars].isInitialized=false;
    ++nrVars;
     if (PrintVariables.is_open())
    {
        PrintVariables << type<<" "<<varName<<" "<<" Predefined value: "<<value<<std::endl;
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void AddNewFunction(char*type,char* NameFunction){
    Unique(NameFunction);
    Functions.push_back(Function());
    Functions[nrFunctions].dataType=type;
    Functions[nrFunctions].functionName=NameFunction;
    Functions[nrFunctions].isDefined=true;
    ++nrFunctions;
    if (PrintFunctions.is_open())
    {
        PrintFunctions <<"Function type:"<<type<<" "<<"Function name:"<<NameFunction<<" "<<std::endl;
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}


void DisplayParams(char*type,char* varFunction){
    if (PrintFunctions.is_open())
    {
        PrintFunctions <<type<<" "<<varFunction<<";";
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void DisplayParamsConst(char*type,char* varFunction){
    if (PrintFunctions.is_open())
    {
        PrintFunctions <<"CONST"<<type<<" "<<varFunction<<";";
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void DisplayParamsArray(char*type, char* varFunction, int size){
if (PrintFunctions.is_open())
    {
        PrintFunctions <<type<<" "<<varFunction<<"["<<size<<"];";
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}

char* check_if_in_use_variable(char* variableName){
    for(int i=0;i<nrVars;i++){
        if(strcmp(Variables[i].varName,variableName)==0){
            //printf("THIS IS WHAT I WANT TO PRINT %s %s\n",variableName,Variables[i].dataType );
            return Variables[i].dataType;
        }
    }
     haveError=true;
    strcpy(errorMessage, "Error: This variable was not declared! You should declare:");
    strcat(errorMessage, variableName);
    return Variables[0].dataType;
}
char* check_if_in_use_array(char* variableName){
    for(int i=0;i<nrVectors;i++){
        if(strcmp(Vectors[i].ArrayName,variableName)==0){
            return Vectors[i].dataType;
        }
    }
    haveError=true;
    strcpy(errorMessage, "Error: This array was not declared! You should declare:");
    strcat(errorMessage, variableName);
    return Vectors[0].dataType;
}
char* check_if_in_use_function(char* variableName){
    for(int i=0;i<nrFunctions;i++){
        if(strcmp(Functions[i].functionName,variableName)==0){
            return Functions[i].dataType;
        }
    }
     haveError=true;
    strcpy(errorMessage, "Error: This function was not declared! You should declare:");
    strcat(errorMessage, variableName);
    return Functions[0].dataType;
}
void AddNewClass(char* name){
    Unique(name);
    classes.push_back(clasa());
    classes[nrClasses].classname=name;
    classes[nrClasses].isdefined=true;
    printf("%s\n", name);
    ++nrClasses;
}
int check_if_in_use_class(char *name){
    for(int i=0; i<nrClasses;i++){
        if(strcmp(classes[i].classname,name)==0){
            return 1;
        }
    }
    haveError=true;
    strcpy(errorMessage, "Error: This class was not defined! You should declare it");
    // printf("Error: This class was not defined! You should declare it\n");
    return 0;

}
void AddArrClass(char* tip, char* nume, int size ){
    Unique(nume);
    Vectors.push_back(Arrays());
    Vectors[nrVectors].dataType=tip;
    Vectors[nrVectors].ArrayName=nume;
    Vectors[nrVectors].size=size;
    ++nrVectors;
     if (PrintVariables.is_open())
    {
        PrintVariables << tip<<" "<<nume<<"["<<size<<"]"<<" Predefined value: None"<<std::endl;
    }
    else
    {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }
}
void AddVarClass(char* tip, char* name){
        Unique(name);
        Variables.push_back(variable());
        Variables[nrVars].dataType=tip;
        Variables[nrVars].varName=name;
        Variables[nrVars].isConstant=false;
        Variables[nrVars].isInitialized=false;
        Variables[nrVars].val=0;
        ++nrVars;
        if (PrintVariables.is_open())
             {
                PrintVariables << tip<<" "<<name<<" "<<" Predefined value: None"<<std::endl;
             }
            else
        {
        //If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file\n!";
    }

}


void Unique(char* varName){
    for(int i=0;i<nrVars;i++){
        if(strcmp(Variables[i].varName,varName)==0){
            haveError=true;
            strcpy(errorMessage, "Error: variable already exists. You should modify: ");
            strcat(errorMessage, varName);
            return;
        }
    }
    for(int i=0;i<nrVectors;i++){
        if(strcmp(Vectors[i].ArrayName,varName)==0){
            haveError=true;
            strcpy(errorMessage, "Error: array already exists! You should modify:");
            strcat(errorMessage, varName);
            return;
        }
    }
    for(int i=0;i<nrFunctions;i++){
        if(strcmp(Functions[i].functionName,varName)==0){
            haveError=true;
            strcpy(errorMessage, "Error: Function already exists! You should modify:");
            strcat(errorMessage, varName);
            return;
        }
    }
}
int GetValue(char* varName ){

    for(int i=0;i<nrVars;i++){
        if(strcmp(varName,Variables[i].varName)==0){
            return Variables[i].val;
        }
    }
    return 0 ;
}
char* Operation(char* var1,const  char* op, char* var2){
    char*rez;
    if (strcmp(op, "+") == 0) {
        //rez = SumFunction(var1, var2);
    }

    if (strcmp(op, "-") == 0) {
        //rez = MinusFunction(var1, var2);
    }
    if (strcmp(op, "*") == 0) {
        //rez = TimesFunction(var1, var2);
    }
    if (strcmp(op, "/") == 0) {
        //rez = FractionFunction(var1, var2);
    }
    if (strcmp(op, "%") == 0) {
        //rez = ModFunction(var1, var2);
    }

    if (strcmp(op, "AND") == 0) {
        //rez = AndFunction(var1, var2);
    }
    if (strcmp(op, "OR") == 0) {
        //rez = OrFunction(var1, var2);
    }
    if (strcmp(op, "LE") == 0) {
        //rez = LeFunction(var1, var2);
    }
    if (strcmp(op, "GE") == 0) {
        //rez = GeFunction(var1, var2);
    }
    if (strcmp(op, "EQ") == 0) {
        //rez = EqFunction(var1, var2);
    }
    if (strcmp(op, "NE") == 0) {
        //rez = NeqFunction(var1, var2);
    }
    if (strcmp(op, "LR") == 0) {
        //rez = LsFunction(var1, var2);
    }
    if (strcmp(op, "GR") == 0) {
        //rez = GrFunction(var1, var2);
    }
    if (strcmp(op, "NOT") == 0) {
        //rez = GrFunction(var1, var2);
    }
    return rez;
}





