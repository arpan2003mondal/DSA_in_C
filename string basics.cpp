#include<stdio.h>
#include<string.h>
int main (){
	//char str[]="HELLO world";
	char str[100];
	printf("Enter your string---- ");
	
	
	//gets(str);// -------- gets is used to take input from the user
	//scanf("%s",str);  // - ------ using & before str will give an error
	fgets(str,15,stdin);  // ---  input string --- fgets(string_name,string size,stdin) -- stdin-> string.h  
	
	
	printf("%s\n",str);
	puts(str);//  ------- puts is used to print the string
	return 0;
}
