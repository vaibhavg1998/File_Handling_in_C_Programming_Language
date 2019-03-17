#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void home();
void home2();
void home3();
void home4();
int pass(char*a);
void password1();
void password2();
void showno();
void showmass();
void showname();
void showsymbol();
void editno();
void editmass();
void editname();
void editsymbol();


int main()
{
	home();
}

void home()
{
	char a;
	printf("                                welcome");
	printf("\n                     This is modern periodic table.     \n  here you can search or edit details about any eliment with the help of \n   1.'atomic no.'\n   2.'atomic mass'\n   3.'name of the element'\n   4.'symbol of ehe element'");
	printf("\n\npress 'b' for back!                                     press 'n' for next page!        \n" );
	scanf(" %c",&a);

	if(a=='n')
	{
		system("cls");
		home2();
	}
	else if(a=='b')
	{
		system("cls");
		password1();
	}
	else
	{
		system("cls");
		printf("entered reference was wrong!!!!!!!!!!!!!!!!!!!!!!!!!!\n \n \n ");
		home();
	}
}

void home2()
{
	char a;
	getchar();
	printf("       CHOSE YOUR CHOICE FROM THE GIVEN DATA \n\n   1. To show the imformation about the element.\n   2. To edit the details of the elememts in the database.\n\n ");
	printf("Entre 'b' to go BACK to the home page.\n\n\n\t");
	scanf("%c",&a);

	if (a =='1')
	{
		system("cls");
		home3();
	}
	else if(a == '2')
	{
		system("cls");
		password2();
	}
	else if(a=='b')
	{
		system("cls");
		home();
	}
	else
	{
		system("cls");
		printf("entered reference was wrong!!!!!!!!!!!!!!!!!!!!! \n\n\n");
		home();
	}
}


void home3()
{
	char a;
	system("cls");
	printf("For the display of the data of the elements select the preference you wanted.\n");
	printf("\n   press - 1 for 'atomic no.'\n   press - 2 for 'atomic mass'\n   press - 3 for 'name of the element'\n   press - 4 for 'symbol of ehe element'\n\n");
	printf("Enter 'b' if you want to ga 'BACK'.\n            ");
	scanf(" %c",&a);

	if(a=='1')
	{
		system("cls");
		showno();
	}
	else if(a=='2')
	{
		system("cls");
		showmass();
	}
	else if(a=='3')
	{
		system("cls");
		printf("enter the name of the element \n");
		showname();
	}
	else if(a == '4')
	{
		system("cls");
		printf("enter the symbol of the element \n");
		showsymbol();
	}
	else if(a == 'b')
	{
		system("cls");
		home2();
	}
	else
	{
		system("cls");
		printf("entered reference was wrong!!!!!!!!!!!!!!!!!!!!! \n\n\n");
		home();
	}
}


void home4()
{
	char a;
	system("cls");
	printf("For editing select the type of the data you want for searching\n");
	printf("\n   press - 1 for 'atomic no.'\n   press - 2 for 'atomic mass'\n   press - 3 for 'name of the element'\n   press - 4 for 'symbol of ehe element'\n\n");
	printf("Enter 'b' if you want to ga 'BACK'.\n            ");
	scanf(" %c",&a);
	
	if(a=='1')
	{
		system("cls");
		editno();
	}
	else if(a=='2')
	{
		system("cls");
		editmass();
	}
	else if(a=='3')
	{
		system("cls");
		editname();
	}
	else if(a=='4')
	{
		system("cls");
		editsymbol();
	}
	else if(a == 'b')
	{
		system("cls");
		home2();
	}
	else
	{
		system("cls");
		printf("entered reference was wrong!!!!!!!!!!!!!!!!!!!!! \n\n\n");
		home();
	}
}


int pass(char *a)
{
	char p[2][20]= {"vaibhavgupta",
                    "vaibhavg"
                   };
	int i,w;
 	for(i=0;i<2;i++)
 	{
 		w=strcmp(p[i],a);
	   	if (w==0)
	   		break;
	}   
	if (w==0)
		return 0;
	else        
		return 1;
}

void password1()
{
	char a[20];
	abc:
	{
		printf("   PLEASE ENTER THE PASSWORD FOR THE DISPLAYING OF THE DATA\n\n                     ");
		scanf("%s",a);
		if (pass(a)==0)
		{
			system("cls");
			home();
		}
		else
		{
			system("cls");
			printf ("         !!!!!!!!!!!WRONG PASSWORD !!!!!!!!!!!!!!!    \n         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
	    }
	}
	if (pass(a)!=0)
		goto abc;
}

void password2()
{
	char a[20];
	printf("   PLEASE ENTER THE PASSWORD TO EDIT THE CONTENTS OF THE SYSTEM FILES.\n\n                         ");
	scanf("%s",a);
	if (pass(a)==0)
	{
		system("cls");
		home4();
	}
	else
	{
		system("cls");
		printf ("      !!!!!!!!!!!WRONG PASSWORD !!!!!!!!!!!!!!!    \n      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
		home2();
	}
}

void showno()
{
	char name[15],sym[3],i;
	int no,w;
	float mass;
	FILE *p;
	printf("enter the atomic no.\n ");
	scanf("%d",&w);
	p=fopen("vaibhavperiodic.txt","r");
	while(1)
	{
		fscanf(p,"%d %s %s %f",&no,name,sym,&mass);
		if(no==w)
			break;
	}
	system("cls");
	printf("   ATOMIC NO. = '%d'\n   NAME OF THE ELEMENT = '%s'\n   SYMBOL OF THE ELEMENT = '%s'\n   ATOMIC MASS = '%f a.m.u.'\n\n\n",no,name,sym,mass);
	printf("      ENTER 'b' TO GO BACK.                    ENTER 'e' TO EXIT THE PROGRAM.\n\n\t\t\t\t");
	scanf("%s",&i);
	if (i=='b')
		home3();
	else if (i=='e')
		exit(1);
	else
		home();
	fclose(p);
}

void showmass()
{
	char name[15],sym[3],i;
	int no,w;
	float mass;
	FILE *p;
	printf("enter the atomic mass \n  ");
	scanf("%d",&w);
	w=w/2;
	p=fopen("vaibhavperiodic.txt","r");
	while(1)
	{
		fscanf(p,"%d %s %s %f",&no,name,sym,&mass);
		if(no==w)
			break;
	}
	system("cls");
	printf("   ATOMIC NO. = '%d'\n   NAME OF THE ELEMENT = '%s'\n   SYMBOL OF THE ELEMENT = '%s'\n   ATOMIC MASS = '%f a.m.u.'\n\n\n",no,name,sym,mass);
	printf("      ENTER 'b' TO GO BACK.                    ENTER 'e' TO EXIT THE PROGRAM.\n\n\t\t\t\t");
	scanf("%s",&i);
	if (i=='b')
		home3();
	else if (i=='e')
		exit(1);
	else
		home();
	fclose(p);
}

void showname()
{
	char i,q[15],name[15],sym[3];
	int no;
	float mass;
	FILE *p;
	scanf("%s",q);
	p=fopen("vaibhavperiodic.txt","r");
	while(1)
	{
		fscanf(p,"%d %s %s %f",&no,name,sym,&mass);
		if((strcmpi(q,name)==0))
		break;
	}
	system("cls");
	printf("   ATOMIC NO. = '%d'\n   NAME OF THE ELEMENT = '%s'\n   SYMBOL OF THE ELEMENT = '%s'\n   ATOMIC MASS = '%f a.m.u.'\n\n\n",no,name,sym,mass);
	printf("      ENTER 'b' TO GO BACK.                    ENTER 'e' TO EXIT THE PROGRAM.\n\n\t\t\t\t");
	scanf("%s",&i);
	if (i=='b')
		home3();
	else if (i=='e')
		exit(1);
	else
		home();
	fclose(p);
}

void showsymbol()
{
	char i,q[3],name[15],sym[3];
	int no;
	float mass;
	FILE *p;
	scanf("%s",q);
	p=fopen("vaibhavperiodic.txt","r");
	while(1)
	{
		fscanf(p,"%d %s %s %f",&no,name,sym,&mass);
		if(strcmpi(q,sym)==0)
			break;
	}
	system("cls");
	printf("   ATOMIC NO. = '%d'\n   NAME OF THE ELEMENT = '%s'\n   SYMBOL OF THE ELEMENT = '%s'\n   ATOMIC MASS = '%f a.m.u.'\n\n\n",no,name,sym,mass);
	printf("      ENTER 'b' TO GO BACK.                    ENTER 'e' TO EXIT THE PROGRAM.\n\n\t\t\t\t");
	scanf("%s",&i);
	if (i=='b')
		home3();
	else if (i=='e')
		exit(1);
	else
		home();
	fclose(p);
}

void editno()
{
	char name[15],sym[3],a,i,q;
	int no,w;
	float mass;
	FILE *p;
	FILE *np;
	p=fopen("vaibhavperiodic.txt","r");
	np=fopen("vaibhavperiodic_temp.txt","w");
	printf("ENTER THE ATOMIC NO. OF THE ELEMENT =\n\t");
	scanf("%d",&w);
	while(!feof(p))
	{
		fscanf(p,"%d %s %s %f ",&no,name,sym,&mass);
		if(no==w)
		{
			printf("\n\t\tEnter the corresponding data background you wand to edit : \n\n");
			abc:
			{
				printf("   press - 1 for 'atomic no.'\n   press - 2 for 'atomic mass'\n   press - 3 for 'name of the element'\n   press - 4 for 'symbol of ehe element'\n\n\t");
				scanf(" %c",&q);
				if(q=='1')
				{
					printf("\n   ATOMIC NO. = ");
					scanf("%d",&no);
				}
				else if(q=='2')
				{
					printf("\n   ATOMIC MASS = ");
					scanf("%f",&mass);
				}
				else if(q=='3')
				{
					printf("\n   NAME OF THE ELEMENT = ");
					scanf("%s",name);
				}
				else if(q == '4')
				{
					printf("\n   SYMBOL OF THE ELEMENT = ");
					scanf("%s",sym);
				}
			}
			printf("\n\n\t\tdo you want to edit more details,or re-enter the last details Y/N\n\n\t");
			getchar();
			scanf("%c",&a);
			if(a=='y'||a=='Y')
				goto abc;
			else if(a=='N'||a=='n')
				fprintf(np,"%d %s %s %f\n",no,name,sym,mass);
			else
				home();
		}
		else
			fprintf(np,"%d %s %s %f\n",no,name,sym,mass);
	}
	fclose(p);
	fclose(np);
	remove("vaibhavperiodic.txt");
	rename("vaibhavperiodic_temp.txt","vaibhavperiodic.txt");
	printf("\n\n      ENTER 'b' TO GO BACK.                    ENTER 'e' TO EXIT THE PROGRAM.\n\n\t\t\t\t");
	scanf("%s",&i);
	if (i=='b')
		home3();
	else if (i=='e')
		exit(1);
	else
		home();
}

void editmass()
{
	char name[15],sym[3],i,q,a;
	int no,w;
	float mass;
	FILE *p;
	FILE *np;
	printf("ENTER THE ATOMIC MASS OF THE ELEMENT = \n");
	scanf("%d",&w);
	w=w/2;
	p=fopen("vaibhavperiodic.txt","r");
	np=fopen("vaibhavperiodic_temp.txt","w");
	while(!feof(p))
	{
		fscanf(p,"%d %s %s %f ",&no,name,sym,&mass);
		if(no==w)
		{
			printf("\n\t\tEnter the corresponding data background you wand to edit : \n\n");
			abc:
			{
				printf("   press - 1 for 'atomic no.'\n   press - 2 for 'atomic mass'\n   press - 3 for 'name of the element'\n   press - 4 for 'symbol of ehe element'\n\n\t");
				scanf(" %c",&q);
				if(q=='1')
				{
					printf("\n   ATOMIC NO. = ");
					scanf("%d",&no);
				}
				else if(q=='2')
				{
					printf("\n   ATOMIC MASS = ");
					scanf("%f",&mass);
				}
				else if(q=='3')
				{
					printf("\n   NAME OF THE ELEMENT = ");
					scanf("%s",name);
				}
				else if(q == '4')
				{
					printf("\n   SYMBOL OF THE ELEMENT = ");
					scanf("%s",sym);
				}
			}
			printf("\n\n\t\tdo you want to edit more details,or re-enter the last details Y/N\n\n\t");
			getchar();
			scanf("%c",&a);
			if(a=='y'||a=='Y')
				goto abc;
			else if(a=='N'||a=='n')
				fprintf(np,"%d %s %s %f\n",no,name,sym,mass);
			else
				home();
		}
		else
			fprintf(np,"%d %s %s %f\n",no,name,sym,mass);
	}
	fclose(p);
	fclose(np);
	remove("vaibhavperiodic.txt");
	rename("vaibhavperiodic_temp.txt","vaibhavperiodic.txt");
	printf("\n\n      ENTER 'b' TO GO BACK.                    ENTER 'e' TO EXIT THE PROGRAM.\n\n\t\t\t\t");
	getchar();
	scanf("%s",&i);
	if (i=='b')
		home3();
	else if (i=='e')
		exit(1);
	else
		home();
}

void editname()
{
	char name[15],sym[3],i,w[15],q,a;
	int no;
	float mass;
	FILE *p;
	FILE *np;
	printf("ENTER THE NAME OF THE ELEMENT = \n");
	scanf("%s",w);
	p=fopen("vaibhavperiodic.txt","r");
	np=fopen("vaibhavperiodic_temp.txt","w");
	while(!feof(p))
	{
		fscanf(p,"%d %s %s %f ",&no,name,sym,&mass);
		if(strcmpi(w,name)==0)
		{
			printf("\n\t\tEnter the corresponding data background you wand to edit : \n\n");
			abc:
			{
				printf("   press - 1 for 'atomic no.'\n   press - 2 for 'atomic mass'\n   press - 3 for 'name of the element'\n   press - 4 for 'symbol of ehe element'\n\n\t");
				scanf(" %c",&q);
				if(q=='1')
				{
					printf("\n   ATOMIC NO. = ");
					scanf("%d",&no);
				}
				else if(q=='2')
				{
					printf("\n   ATOMIC MASS = ");
					scanf("%f",&mass);
				}
				else if(q=='3')
				{
					printf("\n   NAME OF THE ELEMENT = ");
					scanf("%s",name);
				}
				else if(q == '4')
				{
					printf("\n   SYMBOL OF THE ELEMENT = ");
					scanf("%s",sym);
				}
			}
			printf("\n\n\t\tdo you want to edit more details,or re-enter the last details Y/N\n\n\t");
			getchar();
			scanf("%c",&a);
			if(a=='y'||a=='Y')
				goto abc;
			else if(a=='N'||a=='n')
				fprintf(np,"%d %s %s %f\n",no,name,sym,mass);
			else
				home();
		}
		else
			fprintf(np,"%d %s %s %f\n",no,name,sym,mass);
	}
	fclose(p);
	fclose(np);
	remove("vaibhavperiodic.txt");
	rename("vaibhavperiodic_temp.txt","vaibhavperiodic.txt");
	printf("\n\n      ENTER 'b' TO GO BACK.                    ENTER 'e' TO EXIT THE PROGRAM.\n\n\t\t\t\t");
	scanf("%s",&i);
	if (i=='b')
		home3();
	else if (i=='e')
		exit(1);
	else
		home();
}


void editsymbol()
{
	char name[15],sym[3],i,w[3],q,a;
	int no;
	float mass;
	FILE *p;
	FILE *np;
	printf("ENTER THE SYMBOL OF THE ELEMENT = \n");
	scanf("%s",w);
	p=fopen("vaibhavperiodic.txt","r");
	np=fopen("vaibhavperiodic_temp.txt","w");
	while(!feof(p))
	{
		fscanf(p,"%d %s %s %f ",&no,name,sym,&mass);
		if(strcmpi(w,sym)==0)
		{
			printf("\n\t\tEnter the corresponding data background you wand to edit : \n\n");
			abc:
			{
				printf("   press - 1 for 'atomic no.'\n   press - 2 for 'atomic mass'\n   press - 3 for 'name of the element'\n   press - 4 for 'symbol of ehe element'\n\n\t");
				scanf(" %c",&q);
				if(q=='1')
				{
					printf("\n   ATOMIC NO. = ");
					scanf("%d",&no);
				}
				else if(q=='2')
				{
					printf("\n   ATOMIC MASS = ");
					scanf("%f",&mass);
				}
				else if(q=='3')
				{
					printf("\n   NAME OF THE ELEMENT = ");
					scanf("%s",name);
				}
				else if(q == '4')
				{
					printf("\n   SYMBOL OF THE ELEMENT = ");
					scanf("%s",sym);
				}
			}
			printf("\n\n\t\tdo you want to edit more details,or re-enter the last details Y/N\n\n\t");
			getchar();
			scanf("%c",&a);
			if(a=='y'||a=='Y')
				goto abc;
			else if(a=='N'||a=='n')
				fprintf(np,"%d %s %s %f\n",no,name,sym,mass);
			else
				home();
		}
		else
			fprintf(np,"%d %s %s %f\n",no,name,sym,mass);
	}
	fclose(p);
	fclose(np);
	remove("vaibhavperiodic.txt");
	rename("vaibhavperiodic_temp.txt","vaibhavperiodic.txt");
	printf("\n\n      ENTER 'b' TO GO BACK.                    ENTER 'e' TO EXIT THE PROGRAM.\n\n\t\t\t\t");
	scanf("%s",&i);
	if (i=='b')
		home3();
	else if (i=='e')
		exit(1);
	else
		home();
}