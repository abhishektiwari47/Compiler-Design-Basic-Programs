#include<stdio.h>

//A function for checking for keywords
int isKeyword(char code[]){
 int i, flag = 0;
 char keywords[32][10] = {
 "break","case","char","const","continue","default",
 "do","double","else","for","if","int","return","sizeof",
 "struct","switch","union","void","while","main","cout","cin",
 };
 for(i = 0; i < 22; ++i){
  if(strcmp(keywords[i], code) == 0){
  flag = 1;
  break;
 }
}
 return flag;
}
 
int main(){
char ch, code[15], operators[] = "+-*/%=<>", delimiter[ ]="<>,;()[]{}";
FILE *fp=fopen("1_Lexical_Analyzer.txt","r");
int i,j=0;
//opening the codefile and storing it in fp 
//checking if the file does not exist
   if(fp == NULL)
   {
   printf("error while opening the file\n");
   return 0;
   }
while((ch = fgetc(fp)) != EOF){
   for(i = 0; i < 6; ++i){
//checking for operators and delimiter, in the code
   if(ch == operators[i])
    printf("%c is Operator\n", ch);
   }
   for(i=0;i<10; ++i){
   	if(ch==delimiter[i])
   	 printf("%c is Delimiter\n", ch);
   }
   
//checking for code to keyword or collection of identifiers
   if(isalnum(ch))
    code[j++] = ch;
   else if((ch == ' ' || ch == '\n') && (j != 0)){
   code[j] = '\0';
   j = 0;    
   if(isKeyword(code) == 1)
    printf("%s is keyword\n", code);
   else
    i=0;
    while(code[i]!='\0'){
    	printf("%c is an identifier\n ",code[i]);
    	i++;
	}
   } 
 }
fclose(fp);
return 0;
}
