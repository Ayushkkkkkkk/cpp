#include<stdio.h>

int main(){
	FILE *InputFIle = fopen("abcd.txt" , "r");
	
	if(InputFIle == NULL){
		perror("error opeing the file");
		return 1;
	}
	
	char data[1000];
	
	while(fscanf(InputFIle , " %[^\n] " , data)==1){
		printf("%s\n",data);
	}
	
	// gets(data);
	
	fclose(InputFIle);
	
}