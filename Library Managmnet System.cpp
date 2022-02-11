#include <iostream>
#include <string>
using namespace std;

struct Book //making a book structure
{
	int ID=0;// initializing book variables that specify different attributes of the book
	string BookName;
	string author; 
	string ISBN;
	int pages=0;
	int issuestatus = 0;
	string IssuedBy;
	string IssuedOn;
	string ReturnDate;

	void PrintBookDetail() //function to Show the detail of a particular book
	{
		cout << "\nThe Detail of the book is";
		cout << "\nBook Name: " << BookName;
		cout << "\nID: " << ID;
		cout << "\nAuthor: "<< author;
		cout << "\nISBN: "<< ISBN;
		cout << "\nPages: "<< pages;
		
		if (issuestatus==0) // using IF ElSE to verify and print more book detail 
		{
			cout << "\nBook is not issued";
		}
		else
		{
			cout << "\nIssued By: " << IssuedBy;
			cout << "\nIssued On: " << IssuedOn;
			cout << "\nReturn Date: " << ReturnDate;
		}
	}

};

struct BookList // making a structure for the list of 10 books 
{
	Book book[10];// array of 10 book variables of Book Structure 
	Book delbook;// empty array for deleting book list data by copying it into book[10] list 
	
	void PrintBookList() // a function for printing book list
	{
		
		cout << "\nFollowing is the Book List:";
		for (int i = 0; i < 10; i++)// printing book list using for loop
		{
			cout <<"\n" << i+1 <<"." << book[i].BookName; // printing book names in the list
		}
	}
	
	int index = 0;// index variable is the index at which books are stored and is outside function scopes so that it can be accessed by all functions
	
	void AddBookList() // function for adding 10 books the book list
	{
		cout << "\nYou can only add 10 books to the list!";
		for (index; index<10;index++) // using for loop to add 10 books to the list 
		{
			
			cout << "\nEnter Information of Book " << index + 1;
			cin.ignore();

			cout << "\nBook Name: ";
				getline(cin, book[index].BookName);	
				
			cout << "\nID: ";
				cin >> book[index].ID;
				cin.ignore();

			cout << "\nAuthor: ";
				getline(cin, book[index].author);
				
			cout << "\nISBN: ";
				getline(cin, book[index].ISBN);
			cin.ignore();
			
			cout << "\nPages: ";
				cin >> book[index].pages;
				cin.ignore();

				cout << "\nIssue Status(0 for NO and 1 for YES): ";
				cin >> book[index].issuestatus;
				if (book[index].issuestatus == 0); // using issuetatus variable in IF ELSE to retrieve more info  
				else {
					cout << "\nIssued By: ";
					getline(cin, book[index].IssuedBy);
					
					cout << "\nIssued On: ";
					getline(cin, book[index].IssuedOn);
					
					cout << "\nReturn Date: ";
					getline(cin, book[index].ReturnDate);
					
				}
				if (index == 9)// using IF ELSE on index variable to check if list is complete or not
				{
					cout << "List Complete! Cannot Add Anymore Books.";
				}
				else {
					int condition = 0;
					cout << "Add another Book? (0 for NO and 1 for YES): "; // asking user if user wants to add more to list or not
					cin >> condition;
					if (condition == 0)
						break;
					else
						continue;
				}
		}
	}

    void sortascend()// sorting books in ascending order on ID basis
	{
		
		for (int i=0;i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++) 
			{
				if (book[i].ID > book[j].ID)
				{
					int temp = 0;
					temp = book[i].ID;
					book[i].ID = book[j].ID;
					book[j].ID = temp;
				}
			}
		}
		
	}

	void sortdescend() // sorting books in descending order on ID basis
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++) 
			{
				if (book[i].ID < book[j].ID)
				{
					int temp = 0;
					temp = book[i].ID;
					book[i].ID = book[j].ID;
					book[j].ID = temp;
				}
			}
		}
		
	}

	void AddBook() // adding an individual book to the book list
	{
		if (index == 9) //  checking if list is complete
		{
			cout << "\nList Complete! Cannot Add Anymore Books.";
		}
		else {
			cout << "\nAdding Book at Index " << index + 1;
			cout << "\nEnter Information of Book ";
			cin.ignore();

			cout << "\nBook Name: ";
			getline(cin, book[index].BookName);
			
			cout << "\nID: ";
			cin >> book[index].ID;
			cin.ignore();

			cout << "\nAuthor: ";
			getline(cin, book[index].author);
			
			cout << "\nISBN: ";
			getline(cin, book[index].ISBN);
			
			cout << "\nPages: ";
			cin >> book[index].pages;
			cin.ignore();

			cout << "\nIssue Status(0 for NO and 1 for YES): ";
			cin >> book[index].issuestatus;
			cin.ignore();
			if (book[index].issuestatus == 0);
			else {
				cout << "\nIssued By: ";
				getline(cin, book[index].IssuedBy);
				
				cout << "\nIssued On: ";
				getline(cin, book[index].IssuedOn);
				
				cout << "\nReturn Date: ";
				getline(cin, book[index].ReturnDate);
				index++;
			}
		}
	}
};

struct Student // making a Student structure for student detail variables 
{
	int stdID=0;
	string StdName;
	int regno=0;
	int BooksIssued=0;// check variable to see if any book is issued to the student
	int IssuedBookID=0; // id of the issued to the student

	void Printstudentdetail() // function to print student details
	{
		cout << "\nID: " << stdID;
		cout << "\nName: " << StdName;
		cout << "\nRegistration Number: " << regno;
		cout << "\nBooks Issued: " << BooksIssued;
		if (BooksIssued == 0); // using IF ELSE to check if any book is issued 
		else
		{
			cout << "\nID of the Issued Book is " << IssuedBookID; // if any book is issued its ID will be printed
		}
	}
};

struct Studentlist // making a structure for student list
{
	Student std[10]; // making a list of 10 students
	Student delstd; // making an empty list incase to delete a student list

	void PrintStudentList() // funtion to print list of students
	{
		cout << "\nFollowing is the Student List:";
		for (int i = 0; i < 10; i++)
		{
			cout << "\n" <<i+1 <<"." << std[i].StdName; // printing student names in the list
		}
	}

	int stdindex = 0;

	void AddStudentList() // adding students to the student list using this function
	{
		cout << "\nYou can only add 10 Students to the list!";
		for (stdindex; stdindex < 10; stdindex++)//  using for loop to add 10 students
		{
        	cout << "\nEnter Information of Student " << stdindex + 1;
			cin.ignore();

			cout << "\nName: ";
			getline(cin, std[stdindex].StdName);
			
			cout << "\nRegistration Number: ";
			cin >> std[stdindex].regno;

			cout << "\nID: ";
			cin >> std[stdindex].stdID;

			cout << "\nBook Issued(0 for NO and 1 for YES): ";
			cin >> std[stdindex].BooksIssued;
			cin.ignore();

			if (std[stdindex].BooksIssued == 1) // checking if any book is issued 
			{
				cout << "\nID of Issued Book: ";// asking user for the issued book ID
				cin >> std[stdindex].IssuedBookID;

				cout << "\nStudent saved Successfully! ";
			}
			else
			{
				cout << "\nStudent saved Successfully! ";
			}

			if (stdindex == 9) // checking if the list is complete
			{
				cout << "\nList Complete! Cannot Add Anymore Students.";
			}
			else {
				int condition = 0;
				cout << "\nAdd another Student? (0 for NO and 1 for YES): ";// asking user if user wants to add another student to the list or quit
				cin >> condition;

				if (condition == 0)
					break;
				else
					continue;
			}
        }
	}

	void AddStudent() // function to add individual student to the list
	{
		if (stdindex == 9) // checking if the list is complete
		{
			cout << "\nList Complete! Cannot Add Anymore Students.";
		}
		else {
			cout << "\nEnter Information of Student " << stdindex + 1;
			cin.ignore();

			cout << "\nName: ";
			getline(cin, std[stdindex].StdName);
			
			cout << "\nRegistration Number: ";
			cin >> std[stdindex].regno;

			cout << "\nID: ";
			cin >> std[stdindex].stdID;

			cout << "\nBook Issued(0 for NO and 1 for YES): ";
			cin >> std[stdindex].BooksIssued;
			cin.ignore();

			if (std[stdindex].BooksIssued == 1)// checking if any book is issued to the student
			{
				cout << "\nID of Issued Book: ";

				cin>> std[stdindex].IssuedBookID;// getting ID of the issued Book
				cout << "\nStudent saved Successfully! ";
			}
			else
			{
				cout << "\nStudent saved Successfully! ";
			}
		}
	}
};

struct Library // making a library function 
{
	BookList booklist; // declaring a booklist instance to
	BookList delbooklist; // declaring an empty Booklist instance to delete a book list by copying blank list into main list
	Studentlist stdlist; // declaring a student list instance
	Studentlist delstdlist;// declaring an empty student list instance to delete list by copying blank list into main list 

	void IssueBook() // issuing a book to a student
	{
		int bookselect = 0;
		int stdselect = 0;
		cout << "\nSelect a Book from the List:\n";
		booklist.PrintBookList();// priting book list
		cin >> bookselect;// getting index from the book list
		bookselect--;
		cout << "\nSelect a Student from the List:\n";
		stdlist.PrintStudentList(); // printing a student list from
		cin >> stdselect;
		stdselect--;
		stdlist.std[stdselect].IssuedBookID = booklist.book[bookselect].ID; // copying the book ID in the student issued book ID
		stdlist.std[stdselect].BooksIssued = 1; // decalring that book is issued to the student by changing its booksissued value to 1
		cout << "\nBook has been issued to the selected student!";
	}

	void ReturnBook() // making a function for returning a book
	{
		
		int selectstd;
		cout << "\nHeres a list of Students That have Issued a Book from the Library:";
		for (int i = 0; i < 10; i++) // using for loop to print student list
		{
			cout << "\n" << i+1 << "." << stdlist.std[i].StdName;
			if (stdlist.std[i].BooksIssued == 1)// using IF ElSE to print and let user know that which students have issued book from library
			{
				cout << "(1 Book Issued)";

			}
			else;
				 
		}
		cout << "\nSelect a Student: ";
		cin >> selectstd; // selecting a student from the 
		cout << "\nThe Book with ID " << stdlist.std[selectstd-1].IssuedBookID << " was issued to this Student\nIt has been Returned!\nThank you";
		stdlist.std[selectstd-1].BooksIssued = 0; //resetting the Booksissued variable to 0 
	}
	void Deletebooklist() // making a delete list function
	{
		booklist = delbooklist; // copying an empty list in the Book List to delete it
		cout << "\bBook List Deleted Successfully!\n";
		booklist.index = 0;
	}

	void Deletestdlist() // making a student list delete function
	{
		stdlist = delstdlist;// copying an empty list in the Student List to delete it
		cout << "\bStudent List Deleted Successfully!\n";
		stdlist.stdindex = 0;
	}


	
};

void mainmenu(Library lib) // Declaring A main menu function
{
	int a; // switch select variable
	cout << "\nMAIN MENU\n\n1. Student\n2. Book\n3. List\n4. Library\n5. Exit \n";
	cin >> a;
	cout << "\n";
	switch (a) // using a Switch Statement to select from menu
	{
	case 1:
	{
		int b;// switch select variable
		cout << "\n1. Add new Student\n2. Print Student Detail\n3. Print Student List\n4. Delete Student\n5. Go Back \n";
		cin >> b;
		cout << "\n";
		switch (b) // using a Switch Statement to select from submenu
		{
		case 1:
			cout << "\n";
			lib.stdlist.AddStudent();
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;

		case 2:
			int c;
			cout << "\nSelect a Student from below: \n";
			lib.stdlist.PrintStudentList(); //calling the print students list function
			cout << "\n";
			cin >> c;
			cout << "\n";
			lib.stdlist.std[c-1].Printstudentdetail(); // calling the print detail function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		case 3:

			cout << "\n";
			lib.stdlist.PrintStudentList(); //calling the print students list function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 4:
			int d;
			cout << "\nSelect a Student from below: \n";
			lib.stdlist.PrintStudentList();//calling the print students list function
			cout << "\n";
			cin >> d;
			cout << "\n";
			lib.stdlist.std[d - 1]= lib.stdlist.delstd; // deleting student from list by copying the empty delstd instance to the the main instance
			cout << "\nStudent Deleted Successfully! \n";
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 5:
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		}
	}
	break;

    case 2:
	{
		int e;// switch select variable
		cout << "\n1. Add new Book\n2. Show All Books\n3. Print Book detail\n4. Delete Book\n5. Go Back\n ";
		cin >> e;
		switch (e)// using a Switch Statement to select from submenu
		{
		case 1:
			cout << "\n";
			lib.booklist.AddBook(); // calling the add book function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		case 2:
			cout << "\n";
			lib.booklist.PrintBookList();// calling the print book list function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 3:
			int f;
			cout << "\nSelect a Book from the list below: \n";
			lib.booklist.PrintBookList();// calling the print book list function
			cin >> f;
			cout << "\n";
			lib.booklist.book[f-1].PrintBookDetail(); // calling the print book details function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 4:
			int g;
			cout << "\nSelect a Book from the list below: \n";
			lib.booklist.PrintBookList(); // calling the print book list function
			cin >> g;
			cout << "\n";
			lib.booklist.book[g - 1]= lib.booklist.delbook; // deleting book by copying empty instance into the main instance 
			cout << "\nBook Deleted Successfully! \n";
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 5:
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		}
	}
	break;
	
	case 3:
	{
		int h;// switch select variable
		cout << "\n1. Print Book List\n2. Print Student List\n3. Add book List\n4. Add Student list\n5. Sort book list by ID(ascending)\n6. Sort book list by ID(descending)\n7. Delete Book List\n8. Delete Student List\n9. Go Back \n";
		cin >> h;
		switch (h)// using a Switch Statement to select from submenu
		{
		
	    case 1:
			cout << "\n";
			lib.booklist.PrintBookList(); // calling the print book function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 2:
			cout << "\n";
			lib.stdlist.PrintStudentList();//calling the print students list function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 3:
			cout << "\n";
			lib.booklist.AddBookList();// calling the adding function that adds books to the list 
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 4:
			cout << "\n";
			lib.stdlist.AddStudentList(); // calling the adding function that adds students to the list 
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 5:
			cout << "\n";
			lib.booklist.sortascend(); // calling the ascending sorting function 
			cout << "\n";
			lib.booklist.PrintBookList();// calling the print function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 6:
			cout << "\n";
			lib.booklist.sortdescend(); // calling the descending Sorting function
			cout << "\n";
			lib.booklist.PrintBookList();// calling the print function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 7:
			lib.Deletebooklist(); // calling the delete function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 8:
			lib.Deletestdlist(); // calling the delete function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 9:
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		}
	}
	break;
	
	case 4:
	{
		int j;// switch select variable
		cout << "\n1. Issue a Book\n2. Return a Book\n3. Go Back\n ";
		cin >> j;
		switch (j)// using a Switch Statement to select from submenu
		{
		case 1:
			lib.IssueBook(); // calling the Issue book Function
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 2:
			lib.ReturnBook(); // Calling the return book fucntion
			cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
		
		case 3:
            cout << "\n";
			mainmenu(lib);// Calling the Main menu function
			break;
        }
	}
	break;
	
	case 5: // Exiting Program and Displaying an Exiting Statement 
		cout << " \nExiting Program!\n\n";
    }
}

int main()
{
	Library lib1; // Declaring a Library instance
	cout << "WELCOME TO THE LIBRARY SYSTEM\n";
	mainmenu(lib1); // Calling the Main menu function
}
