#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
//defining the properties of the fields used in the program
#define ID 20
#define NAME 50
#define FIRSTNAME 50
#define LASTNAME 50
#define PHONE 20
#define ADRESS 100
#define SIZE 30
#define size 200
void listRecord();
void listRecordVerify();
void createRecord();
void deleteRecord();
void Exit();
int count=0;
char info[SIZE];

struct recordData {
       char id[ID];//id use char is ok.
       char firstName[FIRSTNAME];
       char lastName[LASTNAME];
       char phoneNum[PHONE];
       char adress[ADRESS];
       char Target[NAME];
 }record,*record1;

//initializing the files used in the program
FILE *AddressBook;
FILE *fdel;

int main()
{
  int choice=0;
    printf("\n     Welcome \n");
    printf("\n 1-List all records\n");
    printf(" 2-Update a record\n");
    printf(" 3-Create a new record\n");
    printf(" 4-Delete a record\n");
    printf(" 5-Exit the program\n");
    printf("\n Enter your choice: ");

    scanf("%i",&choice);

    switch (choice){

	    case 1:
//	   		 listRecord();
                listRecordVerify();
	    break;

	    case 2:
		    //updateRecord();
		    main();
	    break;

	    case 3:
	    	createRecord();
	    break;

	    case 4:
	    	deleteRecord();
	    break;

	    case 5:
	    	exit(0);
	    break;

		case 6:
			break;
	    default:
			printf("**Invalid Input.**\n");
 	}
	getchar();
	return 0;

 }

 void listRecord(){

  char choice1;
  AddressBook = fopen("AddressBook.txt","r");
  puts("\nNo   Name     LName     Phone          Address\n");
  puts("==   ====     ======    ========       =======");
  do
  {
    if(fgets(info,SIZE,AddressBook) !=  NULL){//add NULL judge ,
        printf("%s",info);
    }
  }while(!feof(AddressBook));

  fclose(AddressBook);
  main();
}
/**
verify fgets return NULL for (only carriage return);
*/
void listRecordVerify(){

  char choice1;
  int num = 0;
  AddressBook = fopen("AddressBook.txt","r");
  puts("\nNo   Name     LName     Phone          Address\n");
  puts("==   ====     ======    ========       =======");
  do
  {
    if(fgets(info,SIZE,AddressBook) !=  NULL){//add NULL judge ,
        printf("%s",info);
    }

//    fgets(info,SIZE,AddressBook);
//    printf("%s",info);
    num++;
  }while(!feof(AddressBook));
    printf("listRecordVerify list finish, num=%d",num);

  fclose(AddressBook);
  main();
}


void createRecord(){
  char choice3;

 		//opening the AddressBook file
    AddressBook = fopen("AddressBook.txt","a+");
    fprintf(AddressBook,"\n");//new line

    printf("\n createRecord Enter the record number to create a new record : ");
    scanf("%s",record.id);
    printf("\ncreateRecord Enter the first name :");
    scanf("%s",record.firstName);
    printf("\ncreateRecord Enter the last name :");
    scanf("%s",record.lastName);
    printf("\ncreateRecord Enter the phone number :");
    scanf("%s",record.phoneNum);
    printf("\n createRecord Enter the adress(enter the adress by combined words) :");
    scanf("%s",record.adress);

    fprintf(AddressBook,"%s    %s    %s    %s    %s",record.id,record.firstName,record.lastName,record.phoneNum,record.adress);

   	fclose(AddressBook);
	main();
}

void deleteRecord(){

    FILE *AddressBook,*fdel;
    char number[20];

    printf("\n============================");
    printf("\n            DELETE");
    printf("\n============================\n\n");
    fflush(stdin);
    printf("deleteRecord Enter the record number to delete :");
    scanf("%s", number);
    AddressBook=fopen("AddressBook.txt","r");
    fdel=fopen("del.txt","w");
    int find_same_id_by_delete = 0;
	while(!feof(AddressBook)){
		fscanf(AddressBook,"%s %s %s %s %s\n",
	             record.id, record.firstName, record.lastName, record.phoneNum,
	             record.adress);
	    //delete line
	    if(stricmp(number, record.id)!=0){
	    	fprintf(fdel,"%s %s %s %s %s\n",
	             record.id, record.firstName, record.lastName, record.phoneNum,
	             record.adress);
	    }else {
	    	find_same_id_by_delete = 1;
	    }

    }
    printf("deleteRecord find_same_id_by_delete=%d\n",find_same_id_by_delete);
    fclose(AddressBook);
    fclose(fdel);

    if(find_same_id_by_delete == 1){
    	printf("deleteRecord %s %s %s %s %s\n",
     		record.id, record.firstName, record.lastName, record.phoneNum,
     		record.adress);
     	remove("AddressBook.txt");
	    rename("del.txt","AddressBook.txt");

	    printf("deleteRecord Successully Deleted.");
    }else {
    	printf("deleteRecord %s %s\n",number," id not find of record\n");
    }

    main();

}

void Exit()
{
  exit(0);
}
