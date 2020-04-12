# AddressBook

I build a simple address book using C. The user will give the necessary information and your program has to save 
and keep that information in a text file.
Program have 4 abilities below:
•	List all records.
Program will display all the records.
•	Update a record.
User can update a record’s phone number or address.
•	Create a new record.
User can create a new record.
•	Delete a record.
User can delete a record with using its id.
All records have fields as first name, last name, phone, address and id:
struct recordData {
       int id;
       char firstName[15];
       char lastName[15];
       long double phoneNum;
       char adress[100]; 
 };

When updating or deleting a record, your program firstly has to take the id as input and check 
if this id exists in the address book. If it exists, then your program can update or delete the specified record.
When creating a new record, your program firstly has to take the id as input to check if this id exists in the address book.
If it does not exist, then your program has to take first name, last name, phone and address as input and create the new record.

1. todo .
	1.1 problem now,total records 4(id 1,2,3,4),when i select delete choice ,it tip which id to delete ,i input 5 ,but the record of id 4 is delete tip success,but not delete in file..
		should fix this bug.
		
	1.2 when delete one record success. but show list again ,it will have repeat record .