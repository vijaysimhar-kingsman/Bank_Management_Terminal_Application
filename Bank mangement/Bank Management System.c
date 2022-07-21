//Console Based application to Handle a Bank management System.
//																-- Surendar sir
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
//#include<dos.h>
//#include<graphics.h>
struct address{
	char h_no[10];
	int pin_code;
	char vill[50];
};
struct details{
	char ac_num[9];
	char name[100];
	char bank[6];
	float balance;
	char Aadhar[12];
	char mob_num[10];
	char dob[10];
	struct address addr;
	int pin;
};
void welcome();
void login(FILE *);
void read_details();
void create_ac(FILE*);
void pin_genrtn();
void pin_change();
void Home(char []);
void Deposit(char []);
void withdraw(char []);
void check_bal(char []);
void money_trans(char []);
void edit_details();
void ac_trans();
void add_transact(char [],float);
void know_transact(char []);
void know_details(char []);
void save_data(char []);
void trans_save_data(struct details ,char []);
char* get_time();
void type_text(char *, unsigned );
void cprint(char [],int );
void go(char []);
struct address addr;
char name[100], Aadhar[12],ac_num[9],mob_num[10], bank[6],dob[10];// problem with gets its not taking first input..
float balance;
int pin;
FILE *cust; // customer data file...
//struct details customer;
struct details trans;
void main()
{
	//welcome();
	char choose[1]; char creat='2',log='1';
	system("setterm -bold on");
	cprint("\t\t1. Login\n\n\t\t2.Create an Accout\n\n",33);
	system("setterm -bold off");
	while(1){
		cprint("Choose Your Option : ",34);
		scanf("%s",choose);
		if(isdigit(choose[0])){
			if(choose[0]==creat){
				create_ac(cust);
				break;}
			else if(choose[0]==log){
				login(cust);
				break;}
			else
				cprint("Invalid selection \n",31);
			}
		else{
			cprint("Invalid selection \n",31);
			//sleep(2);
			}
	}
	Home(ac_num);
}
void welcome(){
printf("\033[1;31m");
printf("\t_______________________________________________________________________________________________________________\n");
printf("\t---------------------------------------------------------------------------------------------------------------\n");
	sleep(1);
	printf("\033[1;33m");
	type_text("\n\n\t\t\t\t   LOADING",100);
	type_text(" ...\n\n",700);
	//delay(3000);	
	printf("\033[1;35m");
	printf("\n\t\t\t");
	type_text( "__________WELCOME TO__________\n\n",100); sleep(1);
	printf("\033[1;36m");
	printf(" \t\t\t* * * *        * * * *        * * * *    \n"); sleep(1);
	printf(" \t\t\t*      *       *      *       *      *   \n"); sleep(1);
	printf(" \t\t\t* * * *        * * * *        * * * *    \n"); sleep(1);
	printf(" \t\t\t*      *       *      *       *      *   \n"); sleep(1);
	printf(" \t\t\t* * * * IGG    * * * *        * * * *  ANK    \n\n"); sleep(1);
	printf("\033[01;31m");
	printf("\t\t\t\t\t\t\t");
	printf("BOSS");type_text(" ",1000);
	printf("OF");type_text(" ",1000);
	printf("THE");type_text(" ",1000);
	printf("BANKS");type_text(" ",1000);
	printf("\n\n");
	sleep(1);
	printf("\033[1;31m");
printf("\t_________________________________________________________________________________________________________________\n");
printf("\t-----------------------------------------------------------------------------------------------------------------\n\n");
printf("\033[0;m");
sleep(2);
}
void login(FILE *cust){
		cprint("Enter A/C num:  ",34);
		scanf("%s",ac_num);
		
		char file_name[13], buff;
		strcpy(file_name,ac_num);
		strcat(file_name,".txt");
		/*fprintf(cust,"%c",'*');// to check file exist or not..
		fclose(cust);
		cust=fopen(file_name,"r");
		buff=getc(cust);*/
		if((access(file_name,F_OK))!=-1){
			//printf("%s\n %s\n %s\n %.2f\n %s\n %s\n",customer.ac_num,customer.name,customer.bank,customer.balance,customer.Aadhar ,customer.mob_num);
			//fclose(cust);
			cust=fopen(file_name,"r");
			char buff1[9];
			fscanf(cust," %s %s %s %f %s %s %s %s %d %s %d" ,buff1,name,bank,&balance,Aadhar ,mob_num,dob,addr.h_no,&addr.pin_code,addr.vill,&pin);
			int ent_pin, opt=1;
			cprint("\nEnter your PIN  :  ",34);
			scanf("%d",&ent_pin);
			while(!(ent_pin==pin)){
				cprint("Wrong Password\n\n",31);
				cprint("Enter Correctly... \npress 1. to Re enter\n 2. to exit\n3. forgot password\n\n",33);
				scanf("%d",&opt);
				if(opt==1){
					cprint("\nEnter your PIN  :  ",34);
					scanf("%d",&ent_pin);
					}
				else if(opt==2){
					cprint("Exiting",33);
					type_text("...",300);
					printf("\n\n");
					cprint("**********************************************  THANK YOU ************************************************",33);
					sleep(2);
					exit(0);
					}
				else if(opt==3){
					printf("Please Kindly contact the Branch\n\n");
					exit(0);
				}
				else{
					cprint("Enter Correctly... \n",31);
					cprint("press 1. to re enter\t 2. to exit\n",34);}
				}
			fclose(cust);
			}
		else{
			cprint("Please enter a valid account number...\n\n",31);
			login(cust);
			}

		
		
	}

void read_details(){
		cprint("Enter your details....\n",33);
		cprint("Enter your name: \n",34);
		scanf("%s",name);
		//scanf("%s",x);
		cprint("Enter your Aadhar number: \n",34);
		scanf("%s",Aadhar);
		//gets(Aadhar);
		cprint("Enter your mobile number: \n",34);
		scanf("%s",mob_num);
		//gets(mob_num);
		cprint("Enter Your Date of birth :\n",34);
		scanf("%s",dob);
		cprint("Enter you Address :-",33);
		cprint("\nHouse number : ",34);
		scanf("%s",addr.h_no);
		cprint("\nPin code : ",34);
		scanf("%d",&addr.pin_code);
		cprint("\n village / city : ",34);
		scanf("%s",addr.vill);
		}	
void create_ac(FILE* cust){
		int bank_num;
		system("setterm -bold on");
		cprint("CHOOSE A BANK : \n",34);
		printf("\t1.WWB ( World Wide Bank )\n");
		printf("\t2.CSESE (  Bank )\n");
		printf("\t3.PDFB (  Bank )\n");
		printf("\t4.MSB ( MILD STEEL Bank )\n");
		printf("\t5.RBI ( RISERVE BANK OF INDIA )\n");
		system("setterm -bold off");
		int match=0;
		while(!match){
			scanf("%d",&bank_num);
			if(bank_num==1){
				strcpy(bank,"WWE"); match++;}
			else if(bank_num==2){
				strcpy(bank,"CSESE"); match++;}
			else if(bank_num==3){
				strcpy(bank,"PDFB"); match++;}
			else if(bank_num==4){
				strcpy(bank,"MSB"); match++;}
			else if(bank_num==5){
				strcpy(bank,"RBI"); match++;}
			else {
				cprint("Choose correct option\n",31);
				}
			}
		//strcpy(customer.bank,bank);
		FILE *pa; // prev_acnum file pointer
		read_details();
		char p_acnum[9];
		pa=fopen("prev_acnum.txt","r");
		fscanf(pa,"%s",p_acnum);
		fclose(pa);
		int inc_ind;
		for(int i=8;i>0;i--){
			if(p_acnum[i]=='9')
				p_acnum[i]='0';
			else{
				inc_ind=i;
				break;}
			}
		for(int i=0;i<9;i++){
			if(i==inc_ind)
				ac_num[i]=(char)((int)p_acnum[i]+1);
			else
				ac_num[i]=p_acnum[i];
			}
		char file_name[13];
		strcpy(file_name,ac_num);
		strcat(file_name,".txt");
		cust=fopen(file_name,"a");
		printf("\033[1;33m");
		printf("Thanks for Using our services....\n");
		printf(" ...Your Account is successfully created..\n");
		printf("\033[1;34m");
		printf(" Your account number in %s bank is : \n",bank);
		printf("\t\t\t\t\t%s\n",ac_num);
		system("setterm -bold off");
		printf(" PLEASE generate your pin to further services \n");
		pin_genrtn();
		char buff1[9];
		//fprintf(cust,"%s\t%s\t%s\t%f\t%s\t%s\t%d\n",ac_num,name,bank,balance=0,Aadhar,mob_num,pin);
		fprintf(cust," %s %s %s %f %s %s %s %s %d %s %d" ,ac_num,name,bank,balance,Aadhar ,mob_num,dob,addr.h_no,addr.pin_code,addr.vill,pin);
		fclose(cust);
		//fseek(bank,0,SEEK_SET);
		pa=fopen("prev_acnum.txt","w");
		fprintf(pa,"%s\n",ac_num);
		fclose(pa);
		save_data(ac_num);
		printf("Please Login to continue ...\n");
			exit(0);
	}
void pin_genrtn(char ac_num[]){
	printf("\033[0;33m");
	printf("choose your PIN with minimum 4 digits for best security \n");
	printf("\033[0;m");
	int a=1;
	while(a){
		printf("Enter New PIN : ");
		scanf("%d",&pin);
		printf("Confirm PIN : ");
		int conf_pin;
		scanf("%d",&conf_pin);
		if(pin==conf_pin){
			cprint("PIN is successfully generated \n",33);
			a=0;
			pin=pin;
		}
		else
			cprint("PIN didn't match \n\n",31);
	}
	
}
void Home(char ac_num[]){
	system("clear");
	int opt;int a=1;
	system("setterm -bold on");
	printf("\033[1;31m"); 
	printf("\t\t\xB2\xB2 HOME \xB2\xB2\n\n");
	printf("\033[1;32m");
	printf("\t\t1.DEPOSIT\n");
	printf("\t\t2.WITHDRAW\n");
	printf("\t\t3.MONEY TRANSFER\n");
	printf("\t\t4.ACCOUNT TRANSFER\n");
	printf("\t\t5.BALANCE ENQUIRY\n");
	printf("\t\t6.KNOW TRANSACTIONS\n");
	printf("\t\t7.PIN CHANGE\n");
	printf("\t\t8.KNOW YOUR DETAILS\n");
	printf("\t\t9.EDIT DETAILS\n");
	printf("\t\t10. Exit");
	system("setterm -bold off");
	printf("\033[0;m"); 
	while(a!=0){
		a=0;
		scanf("%d",&opt);
		if(opt==1)
			return Deposit(ac_num);
		else if(opt==2)
			return withdraw(ac_num);
		else if(opt==3)
			return money_trans(ac_num);
		else if(opt==4)
			return ac_trans(ac_num);
		else if(opt==5)
			return check_bal(ac_num);
		else if(opt==6)
			return know_transact(ac_num);
		else if(opt==7){
			pin_change();
			}
		else if(opt==8)
			 know_details(ac_num);
		else if(opt==9)
			 edit_details(ac_num);
		else if(opt==10){
			save_data(ac_num);
			exit(0);}
		else{
			cprint("\nchoose correctly:",31);
			a++;}	
	}
}
void save_data(char ac_num[]){
	FILE *temp;
	char file_name[13];
	strcpy(file_name,ac_num);
	char bank1[6];
	strcpy(bank1,bank);
	strcat(file_name,".txt");
	temp=fopen("temp.txt","w");
	cust= fopen(file_name,"r");
	fprintf(temp,"%s %s %s %.2f %s %s %s %s %d %s %d\n" ,ac_num,name,bank,balance,Aadhar ,mob_num,dob,addr.h_no,addr.pin_code,addr.vill,pin);
	int line_c=0; char c;
	while((c=getc(cust))!=EOF){ //transaction data appending to temp...
		if(line_c>0)
			putc(c,temp);
		else if(c=='\n')
			line_c++;
	}
	fclose(cust);
	fclose(temp);
	remove(file_name);
	rename("temp.txt",file_name);
}
void trans_save_data(struct details trans,char trans_ac[]){
	FILE *temp;
	char file_name[13];
	//printf("%s\n",trans_ac);
	strcpy(file_name,trans_ac);
	strcat(file_name,".txt");
	//printf("%s\n",file_name);
	temp=fopen("temp.txt","w");
	cust= fopen(file_name,"r");
	//printf("Name : %s",trans.name);
	//printf("%s %s %s %.2f %s %s %s %s %d %s %d" ,trans_ac,trans.name,trans.bank,trans.balance,trans.Aadhar ,trans.mob_num,trans.dob,trans.addr.h_no,trans.addr.pin_code,trans.addr.vill,trans.pin);
	fprintf(temp," %s %s %s %.2f %s %s %s %s %d %s %d" ,trans_ac,trans.name,trans.bank,trans.balance,trans.Aadhar ,trans.mob_num,trans.dob,trans.addr.h_no,trans.addr.pin_code,trans.addr.vill,trans.pin);
	int line_c=0; char c;
	while((c=getc(cust))!=EOF){ //transaction data appending to temp...
		if(line_c>0)
			putc(c,temp);
		else if(c=='\n')
			line_c++;
	}
	fclose(temp);
	fclose(cust);
	remove(file_name);
	rename("temp.txt",file_name);
	}
void Deposit(char ac_num[]){
	float amt;
	cprint("Enter amount to be deposited : ",34);
	scanf("%f",&amt);
	int prev_bal=balance;
	balance+=amt;
	add_transact(ac_num,prev_bal);
	sleep(1);
	printf("Processing");
	type_text(" ....\n",200);
	printf("Thank you .. \nYou have successfully deposited %.2f amout in your acoount( %s ) \n\n",amt,bank);
	go(ac_num);
}
void withdraw(char ac_num[]){
	float amt;
	cprint("Enter amount to be withdrawn : ",34);
	scanf("%f",&amt);
	float prev_bal=balance;
	if(amt>prev_bal)
		cprint("\tInsuffiecnt cash in your account \n",31);
	else{
		balance-=amt;
		add_transact(ac_num,prev_bal);
		printf("\033[1;37m");
		sleep(1);
		printf("Processing");
		type_text(" ....\n",200);
		printf("\033[0;m");
		printf("Thank you .. \nYou have successfully withdrawn  %.2f amout from your acoount( %s ) \n\n",amt,bank);
			}
	go(ac_num);
}
void check_bal(char ac_num[]){
	printf("\t--> Bank Balance: %.2f \n",balance);
	go(ac_num);
}
void money_trans(char ac_num[]){
	char trans_ac[9]; float amt; char t_buff[9];
	cprint("Enter a/c num which have to be tranferred : ",34);
	scanf("%s",trans_ac);
	FILE *ta;
	char ta_file[13];
	for(int i=0;i<13;i++)
		ta_file[i]=trans_ac[i];
	strcpy(ta_file,trans_ac);
	strcat(ta_file,".txt");
	ta=fopen(ta_file,"r");
	if(!(access(ta_file,F_OK)!=-1)){
		cprint("Enter Valid account number \n ",31);
		money_trans(ac_num);
		}
	else{
		strcpy(t_buff,trans_ac);
		cprint("\nEnter amount to be tranfered  :  ",34);
		scanf("%f",&amt);
		if(balance<amt){
			cprint("Insufficient Balance\n\n",31 );
			sleep(2);
			Home(ac_num);
			}
		
		fscanf(ta," %s %s %s %f %s %s %s %s %d %s %d" ,trans.ac_num,trans.name,trans.bank,&trans.balance,trans.Aadhar ,trans.mob_num,trans.dob,trans.addr.h_no,&trans.addr.pin_code,trans.addr.vill,&trans.pin);
		float prev_amt=balance;
		balance-=amt;
		save_data(ac_num);
		add_transact(ac_num,prev_amt);
		prev_amt=trans.balance;
		trans.balance += amt;
		int i;
		for(i=0;i<9;i++)
			t_buff[i]=trans_ac[i];
		t_buff[i]='\0';
		trans_save_data(trans,t_buff);
		add_transact(trans_ac,prev_amt);
		printf("The amount sucessfully Tranfered \n");
		
	}
	fclose(ta);
	go(ac_num);
}
void ac_trans(){
	char new_bank[6];
	cprint("New bank name: ",34);
	scanf("%s",new_bank);
	strcpy(bank,new_bank);
	printf("\nYou have successfully tranfered your bank to %s bank\n\n",bank);
	go(ac_num);
}
void edit_details(){
	read_details();
	cprint("\nYou have successfully edited your details\n\n",33);
	go(ac_num);

}
void know_details(char ac_num[]){
	save_data(ac_num);
	printf("\033[1;35m");
	printf("\tAccount holder Name : %s\n \tAccount number : %s\n\t Aadhar number : %s\n \tMobile number :%s\n \tDate of birth: %s\n \tHouse num:  %s\n\t city/village: %s\n\t Pin code : %d\n\t",name,ac_num,Aadhar,mob_num,dob,addr.h_no,addr.vill,addr.pin_code);
	printf("\033[1;34m");
	printf("\n\tTHANK YOU\n");
	printf("\033[0;m");
	
	printf("Enter\n\t1 ->   Home\n");
	printf("\n\t2 ->   Exit");
	int choose;
	scanf("%d",&choose);
	if(choose==1)
		Home(ac_num);	
	else if(choose==2)
		//save_data(ac_num);
		exit(0);
}
void add_transact(char ac_num[],float prev_bal){
	char file_name[13];
	strcpy(file_name,ac_num);
	strcat(file_name,".txt");
	cust= fopen(file_name,"a");

	time_t rawtime;
	struct tm * timeinfo;
	char date_time [80];
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (date_time, 80,"%d-%m-%Y %H:%M:%S",timeinfo);
	
	float change=balance-prev_bal;
	fprintf(cust,"%s\t%.2f\t%.2f\t %.2f\n",date_time,prev_bal,change,balance);
	fclose(cust);
	
}
void know_transact(char ac_num[]){
	char file_name[13];
	strcpy(file_name,ac_num);
	strcat(file_name,".txt");
	cust= fopen(file_name,"r");
	char c,fd[10],td[10]; float prev_bal,change;
	char buff1[10],buff2[10]; int i;
	printf(" Get transactions \n");
	cprint("from date (dd-mm-yyyy) : ",34);
	scanf("%s",fd);
	//printf("to date  (dd-mm-yyyy) : ");
	//scanf("%s",td);
	while((c=getc(cust))!=EOF){
		if(c=='\n')
			break;
		}
	/*for(i=0;i<10;i++)
		/buff2[i]=td[i];
	buff2[i]='\0';*/
	for(i=0;i<10;i++)
		buff1[i]=fd[i];
	buff1[i]='\0';
	int a=1; 
	char date[10],time[8];
	//printf("%s\n",buff1);
	cprint("\nDate\t time\t Prev_bal\t amt_changed\t curr_balance\n",32);
	while(1){
		//printf("Her'");
		if(a){
			fscanf(cust,"%s %s %f %f %f",date,time,&prev_bal,&change,&balance);
			//printf("%s\n",date);
			//printf("%d",(strcmp(date,buff1)));
			sleep(2);
			if((strcmp(date,buff1))){
				//fscanf(cust,"%s %s %f %f %f",date,time,&prev_bal,&change,&balance);
				while((fscanf(cust,"%s %s %f %f %f",date,time,&prev_bal,&change,&balance))!=EOF /*&& (strcmp(date,buff2))*/){
					printf("%s\t %s\t %.2f\t %.2f\t %.2f\n",date,time,prev_bal,change,balance);
					//printf("%s",date);
					sleep(1);
					}
				break;
				}
			a++;
			}
		else{
			if((c=getc(cust)=='\n' ))
				a=1;
				}
	}
	go(ac_num);
}
void type_text(char *s, unsigned ms_delay)
{
   unsigned usecs = ms_delay * 1000; /* 1000 microseconds per ms */

   for (; *s; s++) {
      putchar(*s);
      fflush(stdout); /* alternatively, do once: setbuf(stdout, NULL); */
      usleep(usecs);
   }
}
void cprint(char str[],int col_code){
	printf("\033[1;%dm",col_code);
	printf("%s",str);
	printf("\033[1;0m");
}
void go(char ac_num[]){
	cprint("Enter\n\t1 ->   login\n",35);
	cprint("\t2 ->   Exit",35);
	int choose;
	scanf("%d",&choose);
	if(choose==1)
		Home(ac_num);	
	else if(choose==2)
		save_data(ac_num);
}
void pin_change(){
	int ent_pin;
	cprint("Enter a Old pin : ",34);
	scanf("%d",&ent_pin);
	if(ent_pin==pin){
		pin_genrtn(ac_num);
		printf("Please login for continue\n\n");
		save_data(ac_num);}
	else{
		cprint("Wrong PIN\n",34);
		printf("Enter\n 1. Re enter\n2.exit\n3.Forgott passord\n");
		int choose;
		scanf("%d",&choose);
		if(choose==1){
			pin_change(ac_num);
			printf("Please login for continue\n\n");
			save_data(ac_num);
			exit(0);}
		else if(choose==2)
			
			exit(0);
		else if(choose==3)
			printf("Please Kindly request at the branch\n");
		Home(ac_num);}
}
