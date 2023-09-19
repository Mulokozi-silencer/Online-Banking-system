#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user {
	char phone[50];
	char ac[50];
	char password[50];
	float balance;
};

int main(){
	struct user usr,usr1;
	FILE *fp;
	char filename[50],phone[50],pword[50];
	int opt,choice;
	char cont = 'y';
	float amount;
	
	printf("\nWhat do you want to do?");
	printf("\n\n1. Register an account");
	printf("\n2. Login to an account");
	
	printf("\n\nYour choice:\t");
	scanf("%d",&opt);
	
	if(opt == 1){
		system("cls");
		printf("Enter your account number:\t");
		scanf("%s",usr.ac);
		printf("Enter your phone number:\t");
		scanf("%s",usr.phone);
		printf("Enter your new password:\t");
		scanf("%s",usr.password);
		usr.balance = 0;
		strcpy(filename,usr.phone);
		fp = fopen(strcat(filename,".dat"),"w");
		fwrite(&usr,sizeof(struct user),1,fp);
		if(fwrite != 0){
			printf("\n\nAccount successfully registered");
		}else {
			printf("\n\nSomething went wrong!! please try again");
		}
		fclose(fp);
	}
	if(opt == 2){
		system("cls");
		printf("\nPhone number:\t");
		scanf("%s",phone);
		printf("Password:\t");
		scanf("%s",pword);
		strcpy(filename,phone);
		fp =fopen(strcat(filename,".dat"),"r");
		if(fp == NULL){
			printf("\nAccount number not registered");
		}else{
		fread(&usr,sizeof(struct user),1,fp);
		fclose(fp);
		if(!strcmp(pword,usr.password)){
			printf("\n\tWelcome %s",usr.phone);
		while(cont == 'y'){
			system("cls");
			printf("\n1. Balance inquiry");
			printf("\n2. Deposit cash");
			printf("\n3. Withdraw cash");
			printf("\n4. Online transfer");
			printf("\n5. Password change");
			printf("\n\nEnter your choice:\t");
			scanf("%d",&choice);
			
			switch(choice){
				case 1:
					printf("\nYour current balance is Tsh.%.2f",usr.balance);
					break;
				case 2: 
				    printf("\nEnter the amount:\t");
				    scanf("%f",&amount);
				    usr.balance += amount;
				    fp = fopen(filename,"w");
				    fwrite(&usr,sizeof(struct user),1,fp);
				    if(fwrite != NULL) printf("\nSuccessfully deposited.");
				    fclose(fp);
				    break;
				case 3:
					printf("\nEnter the amount:\t");
				    scanf("%f",&amount);
				    usr.balance -= amount;
				    fp = fopen(filename,"w");
				    fwrite(&usr,sizeof(struct user),1,fp);
				    if(fwrite!= NULL) printf("\nYou have withdrawn Tsh.%.2f",amount);
				    fclose(fp);
				    break;
				case 4:
					printf("\nPlease enter the phone number to transfer the balance:\t");
					scanf("%s",&phone);
					printf("\nPlease enter the amount to transfer:\t");
					scanf("%f",&amount);
	
					if(amount > usr.balance) printf("\nInsufficient balance");
					else{
						strcpy(filename,phone);
						fp = fopen(strcat(filename,".dat"),"r");
						if(fp = NULL){
							printf("\nAccount number not registered");
							return 0;
						}
					    fread(&usr1,sizeof(struct user),1,fp);
					    fclose(fp);
					    fp = fopen(filename,"w");
					    usr1.balance += amount;
					    fwrite(&usr1,sizeof(struct user),1,fp);
					    
					    fclose(fp);
					    if(fwrite != NULL){
					    	printf("\nYou have successfully transfered Tsh.%.2f to %s",amount,phone);
					    	strcpy(filename,usr.phone);
					    	fp = fopen(strcat(filename,".dat"),"w");
					    	usr.balance -= amount;
					    	fwrite(&usr,sizeof(struct user),1,fp);
					    	fclose(fp);
						}	
					}
				        break;
				case 5:
					printf("\nEnter your new passowrd:\t");
					scanf("%s",pword);
					fp = fopen(filename,"w");
					strcpy(usr.password,pword);
					fwrite(&usr,sizeof(struct user),1,fp);
					if(fwrite != NULL) 
					printf("\nPassword successfully changed");
					break;
		        	}
			printf("\nDo you want to continue the transaction [y/n]:\t");
			scanf("%s", &cont);
		}	
	}
	else {
			printf("\nInvalid Password");
		}
    }
}
	return 0;
}
