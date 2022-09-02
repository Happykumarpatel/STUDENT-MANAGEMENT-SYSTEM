//              student managment system

//admin username :-  adminlj
//      password :-  ljiet

//student limit = 25
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//globel variables & arrays
char username[7],password[5];			//for username or passworrd
int choice,stu_no=0;					//for store any choices in integer  && stu_no for how many student registetred


//structure for store students details
struct student{
	char first_name[10],last_name[10],middle_name[15],course[5],branch[5];
	int roll_no;
	int fees;
	
	struct marks{
		int c,math,phy,es;
	}y;
	
	float percentage;
	
}x[25];


//all functions declaration 
void first_page();									//first page design (display project name)
void login_page();									//you can enter system with entering username & password in this page
void main_menu();									//for entering processes 
void add_student(struct student x[25]);				//add student with entering student details
void modify_detail(struct student x[25]);			//you can edit details of students who already registeres 
void search(struct student x[25]);					//to see student details with searching name
void delete_detail(struct student x[25]);			//delete students
void all_stu(struct student x[25]);					//see the details of all students who alredy registered
void mark(struct student x[25]);					//enter marks of 
void add_fees(struct student x[25]);				//enter fees that student pays

void main(){
	
	first_page();			//Welcome to student managment system
	login_page();			//admin login page	
	
}

//first page layout
void first_page(){
	
	system("COLOR 8E");            //colours of text and backgroud
	
	int i;
	printf("\n\n\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	for(i=0;i<7;i++){
	
		printf("\t+ +");
		printf("\t\t\t\t\t\t\t\t\t\t\t\t");
		printf("    + +\n");
	
	}
	
	printf("\t+ +");
	printf("\t\t\t\t\t    WELCOME TO");
	printf("\t\t\t\t\t\t");
	printf("    + +\n");
	
	printf("\t+ +");
	printf("\t\t\t\t\t\t");
	printf("\t\t\t\t\t\t");
	printf("    + +\n");
	
	printf("\t+ +");
	printf("\t\t\t\t\t STUDENT MANAGMENT");
	printf("\t\t\t\t\t");
	printf("    + +\n");
	
	printf("\t+ +");
	printf("\t\t\t\t\t\t");
	printf("\t\t\t\t\t\t");
	printf("    + +\n");
	
	printf("\t+ +");
	printf("\t\t\t\t\t      SYSTEM");
	printf("\t\t\t\t\t\t");
	printf("    + +\n");
	
	
	
	for(i=0;i<10;i++){
	
		printf("\t+ +");
		printf("\t\t\t\t\t\t\t\t\t\t\t\t");
		printf("    + +\n");
	
	}
	
	
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	getchar();
}


//login page
//admin username :-  adminlj
//      password :-  ljiet
void login_page(){
	
	int i,j,t=0;
	
	system("cls");			//to clear screen
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\t\t\t\t\t\t    Login Page\n");
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	//login page starts here
	
	printf("\n\n\n\n\n\n\t\t\t\t\t");
	printf("USERNAME : ");
	scanf("%s",&username);					//entering username
	
	printf("\n\n\t\t\t\t\t");
	printf("PASSWORD : ");
	scanf("%s",&password);					//entering password
	
	
	
	//for moving to the all_process page if username & password are true
	
	if(strcmp(password,"ljiet")==0 && strcmp(username,"adminlj")==0){
		
		main_menu();								
		
	}
	else{
		
		printf("\n\n\t\t\t\t---------------------------------------------------------");

		printf("\n\n\t\t\t\t\tYou entered wrong username or password\n\n");
		
		printf("\t\t\t\t\t(0) : EXIT\n");
		printf("\t\t\t\t\t(1) : RE-ENTER\n");
		
		reenter:							//if admin enter another number
		
		printf("\t\t\t\t\t ");
		scanf("%d",&choice);				//enter choice
		
		switch(choice){
			case 0 : exit(0);				//0 -> exit
					 break;
			case 1 : login_page();			//1 -> re enter username & password
					 break;
			default:printf("\n\n\t\t\t\t\t ");
					printf("Enter 0 or 1\n");
					goto reenter;			//goto reenter and reenter choice
		}
	}	
\
}


//main menu logic
void main_menu(){
	
	system("cls");			       //to clear screen
	system("COLOR 8E");            //colours of text and backgroud
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\t\t\t\t\t\t    MAIN MENU\n");
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	//logic starts with here
	
	printf("\n\n\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\t\t\tTotal registered student : %d\n",stu_no);
	printf("\t\t\t\t\t\tStudent Limit            : %d",25-stu_no);
	printf("\n\t\t\t\t---------------------------------------------------------\n");
	
	printf("\n\n\n\t\t\t\t\t ");
	printf("(0) : ADD STUDENT");
	
	printf("\n\t\t\t\t\t ");
	printf("(1) : MODIFY STUDENT DETAILS");
	
	printf("\n\t\t\t\t\t ");
	printf("(2) : DELETE STUDENT DETAILS");
	
	printf("\n\t\t\t\t\t ");
	printf("(3) : SEARCH STUDENTS");
	
	printf("\n\t\t\t\t\t ");
	printf("(4) : ALL STUDENTS BASIC INFO");
	
	printf("\n\t\t\t\t\t ");
	printf("(5) : ENTER EXAM MARKS");
	
	printf("\n\t\t\t\t\t ");
	printf("(6) : ADD FEES");
	
	printf("\n\t\t\t\t\t ");
	printf("(7) : GO TO LOGIN");
		
	printf("\n\t\t\t\t\t ");
	printf("(8) : exit");
	
	reenter:									//if admin enter another number
	
	printf("\n\t\t\t\t\t  ");					
	scanf("%d",&choice);						//enter number for process
	
	switch(choice){
		case 0 : add_student(x);				
				 break;
		case 1 : modify_detail(x);
				 break;
		case 2 : delete_detail(x);
				 break;
		case 3 : search(x);
				 break;
		case 4 : all_stu(x);
				 break;
		case 5 : mark(x);
				 break;
		case 6 : add_fees(x);
				 break;
		case 7 : login_page();
				 break;
		case 8 : exit(0);
				
		default: printf("\n\n\t\t\t\t---------------------------------------------------------");
				 printf("\n\t\t\t\t\tENTER NO BETWEEN 0 TO 7\n");
				 goto reenter;
	}
}

//add new student
void add_student(struct student x[50]){
	
	int i,n,j,k;
	
	k=25-stu_no;		//to check how many student you add
	
	re:
	printf("\n\n\n\n\t\t\t\t\t");
	printf("How Many Students You want to Add : ");
	scanf("%d",&n);
	
	if(n<=0){
			printf("\n\t\t\t\t\tENTERED POSITIVE NUMBER\n");
			goto re;
	}
	
	if(n>k){
		printf("\n\t\t\t\t\tSTUDENT LIMIT REACHED\n");
		goto re;
	}
		
	
	for(j=0;j<n;j++){
	
	system("cls");			//to clear screen
	fflush(stdin);
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\t\t\t\t\t\tADD STUDENT\n");
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\n\n\t\t\t\t\t\tStudent Number %d",j+1);
	
	printf("\n\n\n\t\t\t\t\t");
	printf("FIRST NAME      :	");
	scanf("%s",&x[stu_no].first_name);
	
	printf("\n\t\t\t\t\t");
	printf("MIDDLE NAME     :	");
	scanf("%s",&x[stu_no].middle_name);
	
	printf("\n\t\t\t\t\t");
	printf("LAST NAME       :	");
	scanf("%s",&x[stu_no].last_name);
	
	roll_no:
	printf("\n\t\t\t\t\t");
	printf("ROLL NO         :	");
	scanf("%d",&x[stu_no].roll_no);
	
	if(x[stu_no].roll_no<=0){
		printf("\n\t\t\t\t\tYou entered wrong roll no");
		goto roll_no;
	}
	for(i=0;i<stu_no;i++){										//to chack that alredy any student added with same rollno
		if(x[i].roll_no==x[stu_no].roll_no){					//is rolll no is same re entering number
			printf("\n\t\t\t\t\tAlready Student Registered with this roll_no.");
			goto roll_no;							
		}
	}
	
	printf("\n\t\t\t\t\t");
	printf("COURSE NAME     :	");
	scanf("%s",&x[stu_no].course);
	
	printf("\n\t\t\t\t\t");
	printf("BRANCH NAME     :	");
	scanf("%s",&x[stu_no].branch);
	
	printf("\n\t\t\t\t\t");
	printf("PAID FEES       :	");
	scanf("%d",&x[stu_no].fees);
	
	stu_no++;
	
	}
	
	main_menu();
}

//modify students datail after registration
void modify_detail(struct student x[50]){
	
	int i,rollno,k=0;
	
	system("cls");			//to clear screen
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\t\t\t\t\t\tMODIFY DETAIL\n");
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	if(stu_no!=0){
		
		reroll:
		printf("\n\n\t\t\t\t\t");
		printf("Entet roll no to modify detail : ");
		scanf("%d",&rollno);
		
		if(rollno<=0){
			printf("\n\t\t\t\t\tENTER CORRECT ROLL NO\n");
			goto reroll;
		}
		
		for(i=0;i<stu_no;i++){
			if(rollno==x[i].roll_no){
			    k=1;
			    system("cls");		           //to clear screen
			    system("COLOR 8E");            //colours of text and backgroud
				fflush(stdin);
				printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
				printf(" + + + + + +\n");
		
				printf("\t\t\t\t\t\tMODIFY DETAIL\n");
		
				printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
				printf(" + + + + + +\n");
		
				printf("\n\n\n\t\t\t\t\t");
				printf("FIRST NAME      :	");
				scanf("%s",&x[i].first_name);
		
				printf("\n\t\t\t\t\t");
				printf("MIDDLE NAME     :	");
				scanf("%s",&x[i].middle_name);
		
				printf("\n\t\t\t\t\t");
				printf("LAST NAME       :	");
				scanf("%s",&x[i].last_name);
		
				printf("\n\t\t\t\t\t");
				printf("ROLL NO         :	");
				scanf("%d",&x[i].roll_no);
			
				printf("\n\t\t\t\t\t");
				printf("COURSE NAME     :	");
				scanf("%s",&x[i].course);
		
				printf("\n\t\t\t\t\t");
				printf("BRANCH NAME     :	");
				scanf("%s",&x[i].branch);
			}
		}
		
		if(k==0){
			printf("\n\n\n\t\t\t\t\tNO STUDENT ADDED WITH THIS ROLL NUMBER\n");
		}
	
	}
	else{
		printf("\n\n\t\t\t\t\t");
		printf("NO RESISTRATION DONE\n");
	}	
	
	printf("\n\n\t\t\t\t---------------------------------------------------------");

	printf("\n\n\t\t\t\t\t(0) : EXIT\n");
	printf("\t\t\t\t\t(1) : MAIN MENU\n");
		
	reeenter:							//if  enter another number
		
	printf("\t\t\t\t\t ");
	scanf("%d",&choice);				//enter choice
		
	switch(choice){
		case 0 : exit(0);				//0 -> exit
				 break;
		case 1 : main_menu();			//1 -> main menu
				 break;
		default:printf("\n\n\t\t\t\t\t ");
				printf("Enter 0 or 1\n");
				goto reeenter;			//goto reenter and reenter choice
	}
}


//search student by his/her name
void search(struct student x[50]){
	
	int i,t=0,rollno;
	
	system("cls");			//to clear screen
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\t\t\t\t\t\tSEARCH DETAIL\n");
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	
	system("cls");			       //to clear screen
	system("COLOR 8E");            //colours of text and backgroud
	
	printf("\n\n\t\t\t\t---------------------------------------------------------\n");
	printf("\n\n\t\t\t\t---------------------------------------------------------\n");
	
	//logic starts with here
	
	if(stu_no!=0){
		
		reroll:
		printf("\n\t\t\t\t\t");
		printf("Enter student's roll no for search : ");
		scanf("%d",&rollno);
		
		if(rollno<=0){
			printf("\n\t\t\t\t\tENTER WRITE ROLL NO\n");
			goto reroll;
		}
		
		system("cls");			       //to clear screen
		system("COLOR 8E");            //colours of text and backgroud
	
	
		for(i=0;i<(stu_no);i++){								//search student detail
			if(rollno==x[i].roll_no){
				t=1;
				
				printf("\n\n\n\t\t\t\t\t");
				printf("FIRST NAME      :	");
				printf("%s",x[i].first_name);
	
				printf("\n\t\t\t\t\t");
				printf("MIDDLE NAME     :	");
				printf("%s",x[i].middle_name);
	
				printf("\n\t\t\t\t\t");
				printf("LAST NAME       :	");
				printf("%s",x[i].last_name);
	
				printf("\n\t\t\t\t\t");
				printf("ROLL NO         :	");
				printf("%d",x[i].roll_no);
	
				printf("\n\t\t\t\t\t");
				printf("COURSE NAME     :	");
				printf("%s",x[i].course);
		
				printf("\n\t\t\t\t\t");
				printf("BRANCH NAME     :	");
				printf("%s",x[i].branch);
			}
		}
		if(t==0){
			printf("\n\n\t\t\t\tNo Student Registered with this Name\n");
		}
	
	}
	else{
		printf("\n\n\n\t\t\t\t\tNO STUDENT ADDED\n");
	}
	

	printf("\n\n\t\t\t\t---------------------------------------------------------\n");
	
	printf("\n\n\t\t\t\t\t(0) : EXIT\n");
	printf("\t\t\t\t\t(1) : MAIN MENU\n");
	
	reenter:							//if  enter another number
		
	printf("\t\t\t\t\t ");
	scanf("%d",&choice);				//enter choice
		
	switch(choice){
		case 0 : exit(0);				//0 -> exit
				 break;
		case 1 : main_menu();			//1 -> main menu
				 break;
		default:printf("\n\n\t\t\t\t\t ");
				printf("Enter 0 or 1\n");
				goto reenter;			//goto reenter and reenter choice
	}		
}



//delete student details by searching details
void delete_detail(struct student x[50]){
	
	int i,t,j,decision,rollno;
	
	system("cls");			//to clear screen
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\t\t\t\t\t\tSEARCH DETAIL\n");
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	

	system("cls");		 	       //to clear screen
	system("COLOR 8E");            //colours of text and backgroud
	
	
	//logic starts with here
	if(stu_no!=0){
		
		reroll:
		printf("\n\t\t\t\t\t");
		printf("Enter student's roll no for search : ");
		scanf("%d",&rollno);
		
		if(rollno<=0){
			printf("\n\n\t\t\t\t\tENTER RIGHT ROLL NO\n");
			goto reroll;
		}
		
		system("cls");		 	       //to clear screen
		system("COLOR 8E");            //colours of text and backgroud
	
		
		printf("\n\n\t\t\t\t---------------------------------------------------------\n");
		printf("\n\t\t\t\t Details\n");
		printf("\n\t\t\t\t---------------------------------------------------------\n");
	
	
	
		for(i=0;i<(stu_no);i++){								//search student detail
			if(rollno==x[i].roll_no){
				t=1;
			
				printf("\n\n\n\t\t\t\t\t");
				printf("FIRST NAME      :	");
				printf("%s",x[i].first_name);
		
				printf("\n\t\t\t\t\t");
				printf("MIDDLE NAME     :	");
				printf("%s",x[i].middle_name);
		
				printf("\n\t\t\t\t\t");
				printf("LAST NAME       :	");
				printf("%s",x[i].last_name);
		
				printf("\n\t\t\t\t\t");
				printf("ROLL NO         :	");
				printf("%d",x[i].roll_no);
		
				printf("\n\t\t\t\t\t");
				printf("COURSE NAME     :	");
				printf("%s",x[i].course);
		
				printf("\n\t\t\t\t\t");
				printf("BRANCH NAME     :	");
				printf("%s",x[i].branch);
		
				printf("\n\n\t\t\t\t---------------------------------------------------------\n");
				printf("\n\n\t\t\t\t\tIf you want to delete this student detail then type   (0)\n");
				printf("\t\t\t\t\tIf you don't want to delete this student detail then type (1)\n");
		
				renter:
		
				printf("\n\t\t\t\t\t");
				scanf("%d",&decision);
		
				switch(decision){
					case 0 : for(j=i;j<stu_no;j++){
					   		 x[j]=x[j+1];
					 		 }
					 		 stu_no--;
							 break;
					case 1 : main_menu();
							 break;
					default: printf("\n\n\t\t\t\t\tYou have to enter number 0 or 1\n");
							 goto renter;
				}
			}
		}
		if(t==0){
			printf("\n\n\t\t\t\tNo Student Registered with this Name\n");
		}
	}
	else{
		printf("\n\n\n\t\t\t\t\tNO STUDENT ADDED\n");
	}
	printf("\n\n\t\t\t\t---------------------------------------------------------\n");
	
	printf("\n\n\t\t\t\t\t(0) : EXIT\n");
	printf("\t\t\t\t\t(1) : MAIN MENU\n");
	
	reenter:							//if  enter another number
		
	printf("\t\t\t\t\t ");
	scanf("%d",&choice);				//enter choice
		
	switch(choice){
		case 0 : exit(0);				//0 -> exit
				 break;
		case 1 : main_menu();			//1 -> main menu
				 break;
		default:printf("\n\n\t\t\t\t\t ");
				printf("Enter 0 or 1\n");
				goto reenter;			//goto reenter and reenter choice
	}	
}


//print all student details
void all_stu(struct student x[50]){
	
	int i;
	
	system("cls");			//to clear screen
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\t\t\t\t\t\tALL STUDENT DETAIL\n");
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\n\n\n\t\t\t\t\t");
	
	if(stu_no!=0){
	
		for(i=0;i<stu_no;i++){
		
			printf("\n\n\n\t\t\t\t\t");
			printf("FIRST NAME      :	");
			printf("%s",x[i].first_name);
	
			printf("\n\n\t\t\t\t\t");
			printf("MIDDLE NAME     :	");
			printf("%s",x[i].middle_name);
	
			printf("\n\n\t\t\t\t\t");
			printf("LAST NAME       :	");
			printf("%s",x[i].last_name);
		
			printf("\n\n\t\t\t\t\t");
			printf("ROLL NO         :	");
			printf("%d",x[i].roll_no);
		
			printf("\n\n\t\t\t\t\t");
			printf("COURSE NAME     :	");
			printf("%s",x[i].course);
		
			printf("\n\n\t\t\t\t\t");
			printf("BRANCH NAME     :	");	
			printf("%s",x[i].branch);
	
			printf("\n\n\t\t\t\t\t");
			printf("PAID FEES       :	");
			printf("%d",x[i].fees);
			
			printf("\n\n\t\t\t\t---------------------------------------------------------\n");
			
		}
	}
	else{
		printf("\n\n\n\t\t\t\t\tNO STUDENT ADDED\n");
	}
	
	printf("\n\n\t\t\t\t---------------------------------------------------------\n");
	
	printf("\n\n\t\t\t\t\t(0) : EXIT\n");
	printf("\t\t\t\t\t(1) : MAIN MENU\n");
	
	reenter:							//if  enter another number
		
	printf("\t\t\t\t\t ");
	scanf("%d",&choice);				//enter choice
		
	switch(choice){
		case 0 : exit(0);				//0 -> exit
				 break;
		case 1 : main_menu();			//1 -> main menu
				 break;
		default:printf("\n\n\t\t\t\t\t ");
				printf("Enter 0 or 1\n");
				goto reenter;			//goto reenter and reenter choice
	}		
}


//marks
void mark(struct student x[50]){
	
	int i,k=0,rollno;
	
	system("cls");			       //to clear screen
	system("COLOR 8E");            //colours of text and backgroud
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\t\t\t\t\t\tALL STUDENT DETAIL\n");
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	if(stu_no!=0){
		
		reroll:
		printf("\n\t\t\t\t\t");
		printf("Enter student's Roll numer for input marks : ");
		scanf("%d",&rollno);
		
		if(rollno<=0){
			printf("\n\n\t\t\t\t\tENTER WRITE ROLL NO\n");
			goto reroll;
		}
	
		for(i=0;i<(stu_no);i++){								//search student detail
			if(rollno==x[i].roll_no){
				k=1;
			
				m1:
				
				printf("\n\n\t\t\t\t\t");
				printf("     C      : ");
				scanf("%d",&x[i].y.c);
			
				if(x[i].y.c>100 || x[i].y.c<0){
					printf("\n\t\t\t\t\tEnter marks out of 100");
					goto m1;
				}
			
				m2:
				
				printf("\n\t\t\t\t\t");
				printf("MATHEMATICS : ");
				scanf("%d",&x[i].y.math);
			
				if(x[i].y.math>100 || x[i].y.math<0){
					printf("\n\t\t\t\t\tEnter marks out of 100");
					goto m2;
				}
			
				m3:
				
				printf("\n\t\t\t\t\t");
				printf("PHYSICS     : ");
				scanf("%d",&x[i].y.phy);
				
				if(x[i].y.phy>100 || x[i].y.phy<0){
					printf("\n\t\t\t\t\tEnter marks out of 100");
					goto m3;
				}
			
				m4:
				
				printf("\n\t\t\t\t\t");
				printf("     ES     : ");
				scanf("%d",&x[i].y.es);
				
				if(x[i].y.es>100 || x[i].y.es<0){
					printf("\n\t\t\t\t\tEnter marks out of 100");
					goto m4;
				}
			
				x[i].percentage=((x[i].y.c+x[i].y.es+x[i].y.math+x[i].y.phy)/4.0);
	
				system("cls");			       //to clear screen
				system("COLOR 8E");            //colours of text and backgroud
		
				printf("\n\n\t\t\t\t---------------------------------------------------------\n");
		
				printf("\n\t\t\t\t\t%s %s %s",x[i].first_name,x[i].middle_name,x[i].last_name);
		
				printf("\n\n\n\n\t\t\t\t\t");
				printf("     C      : ");
				printf("%d",x[i].y.c);
		
				printf("\n\n\t\t\t\t\t");
				printf("MATHEMATICS : ");
				printf("%d",x[i].y.math);
				
				printf("\n\n\t\t\t\t\t");
				printf("PHYSICS     : ");
				printf("%d",x[i].y.phy);
			
				printf("\n\n\t\t\t\t\t");
				printf("     ES     : ");
				printf("%d",x[i].y.es);

				printf("\n\n\n\t\t\t\t\t");
				printf("%d Marks obtained out of 400",(x[i].y.c+x[i].y.es+x[i].y.math+x[i].y.phy));
		
				printf("\n\n\n\t\t\t\t\t");
				printf(" PERCENTAGE  : ");
				printf("%f",x[i].percentage);
				
			}
		}
		
		if(k==0){
			printf("\n\n\n\t\t\t\t---------------------------------------------------------\n");
	
			printf("\t\t\t\t\tNO STUDENT ADDED WITH THIS ROLL NO");
		
		}
	}
	else{
		printf("\n\n\n\t\t\t\t\t\tNO STUDENT ADDED\n");
	}
	

	
	printf("\n\n\n\t\t\t\t---------------------------------------------------------\n");
	
	printf("\n\n\t\t\t\t\t(0) : EXIT\n");
	printf("\t\t\t\t\t(1) : MAIN MENU\n");
	
	reenter:							//if  enter another number
			
	printf("\t\t\t\t\t ");
	scanf("%d",&choice);				//enter choice
		
	switch(choice){
		case 0 : exit(0);				//0 -> exit
				 break;
		case 1 : main_menu();			//1 -> main menu
				 break;
		default:printf("\n\n\t\t\t\t\t ");
				printf("Enter 0 or 1\n");
				goto reenter;			//goto reenter and reenter choice
	}		

			
}


//to add fees
void add_fees(struct student x[50]){
	
	int stu_roll_no,i,k,r;
	char pay[7];
	
	system("cls");			       //to clear screen
	system("COLOR 8E");            //colours of text and backgroud
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	printf("\t\t\t\t\t\tALL STUDENT DETAIL\n");
	
	printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
	printf(" + + + + + +\n");
	
	if(stu_no==0){
		printf("\n\t\t\t\t\tNo Added stdunt");
	}
	else{
		reroll:
		printf("\n\t\t\t\t\t");
		printf("Enter student's roll no  : ");
		scanf("%d",&stu_roll_no);
		
		if(stu_roll_no<=0){
			printf("\n\n\t\t\t\t\tENTER WRITE ROLL NO\n");
			goto reroll;
		}
	
		for(i=0;i<stu_no;i++){
			if(stu_roll_no==x[i].roll_no){
				k=1;
				break;
			}
		}
	
		if(k==0){
			printf("\n\n\n\t\t\t\t\t");
			printf("No student added with this roll number");
		}
		else{
			feere:
			printf("\n\n\n\n\t\t\t\t\t");
			printf("Enter How many rupees paid : ");
			scanf("%d",&r);
			
			if(r<0){
				printf("\n\n\t\t\t\t\tENTER FEES IN POSITIVE NUMBER\n");
				goto feere;
			}
			
			payment:
			printf("\n\n\t\t\t\t\t");
			printf("Enter type of payment      : ");
			fflush(stdin);
			scanf("%s",&pay);
		
			getch();
			
			system("cls");			       //to clear screen
			
			system("COLOR 8E");            //colours of text and backgroud
		
			printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
			printf(" + + + + + +\n");
		
			printf("\t\t\t\t\t\tFEE RECEIPT\n");
		
			printf("\t+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +");
			printf(" + + + + + +\n");
			
			printf("\n\n\n\n\t\t\t\t\t");
			printf("Already Rupees paid : ");
			printf("%d",x[i].fees);
			
			printf("\n\n\n\n\t\t\t\t\t");
			printf("Rupees paid         : ");
			printf("%d",r);
			
			printf("\n\n\t\t\t\t\t");
			printf("Type of payment     : ");
			puts(pay);
			
			x[i].fees=x[i].fees+r;
			
			printf("\n\n\n\n\t\t\t\t\t");
			printf("Total Rupees paid   : ");
			printf("%d",x[i].fees);
			
		}
	}
	
	printf("\n\n\t\t\t\t---------------------------------------------------------\n");
	
	printf("\n\n\t\t\t\t\t(0) : EXIT\n");
	printf("\t\t\t\t\t(1) : MAIN MENU\n");
	
	reenter:							//if  enter another number
		
	printf("\t\t\t\t\t ");
	scanf("%d",&choice);				//enter choice
		
	switch(choice){
		case 0 : exit(0);				//0 -> exit
				 break;
		case 1 : main_menu();			//1 -> main menu
				 break;
		default:printf("\n\n\t\t\t\t\t ");
				printf("Enter 0 or 1\n");
				goto reenter;			//goto reenter and reenter choice
	}		
}
