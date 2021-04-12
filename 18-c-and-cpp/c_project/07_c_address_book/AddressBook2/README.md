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

#1.	i find some bugs.
	1.1 problem now,total records 4(id 1,2,3,4),when i select delete choice ,it tip which id to delete ,i input 5 ,but the record of id 4 is deleted,and tip success,but not delete really in file.
		should fix this bug.
		
	1.2 when delete one record success. but when show list again ,it will have repeat record ,last item will repeat.
		
	1.3 List all records. some time it will have repeat record ,last item will repeat.
		1.3.1 file mode :use a+ to use r replace.
		
		1.3.2 i find cause on 20201011 ,when i open the AddressBook.txt ,the cursor at the new line ,only new line.
			when the new line has content ,empty content,this new line will show normal.
		
			cause:
			feof(.) method ,for new line(only Carriage return ,crlf) ,mean not end.
			fgets(...) method ,this line end,this method read end.
			
			