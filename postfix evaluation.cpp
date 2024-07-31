#include<stdio.h>
#include<ctype.h>
#include<math.h>
float stack[100];
int top=-1;
void push(char x){
	stack[++top]=x;
}
float pop(){
	return stack[top--];
}
int main(){
	char exp[20],*e;
	float num1,num2,ans;
	printf("Enter the expression: ");
	scanf("%s",exp);
	printf("Your entered expression is:");
	printf("%s",exp);
	e=exp;
	while(*e!='\0'){
		if(isdigit(*e))
			push(*e-48);
		else{
			num1=pop();
			num2=pop();
			switch(*e){
				case '+':ans=num2+num1;
							break;
				case '-':ans=num2-num1;
							break;
				case '*':ans=num2*num1;
							break;
				case '/': ans=num2/num1;
							break;
				case '^': ans=pow(num2,num1);
							break;
			}
			push(ans);
		}
		e++;
	}
	printf("\nAnswer is %f\n",ans);
	return 0;
}
