#include <bits/stdc++.h> //This header file contanins all the basic libraries of oops
#ifdef _WIN32
#include <conio.h> // for Windows
#else
#include <termios.h>
#include <unistd.h>
#endif
using namespace std;

/*The Library Management System 
the system designed to be used by the library admin and the members
Techniques used: 
1. linked list
2. array*/

class allsingle;
class memberRecord;
class BookRecord;
class hellyeah;

// Drclare the Head of the linked list


memberRecord* Head = NULL; //members linkedlist 
BookRecord* Head2 = NULL; //Book linkedlist 
/*decalre some public veriable */
int place = 0, place2 = 0, posi = 0;
char choice, option1, option2;
int position;

string Booktitle, bcateg, bgenre, borrowdate, bkid, pid;

string PIDInput; //member number
string PNameInput; //member name
string PhoneInput; //member phone
string BorrowingBookInput[3][5];/*book ID- book titl -book-borrowing date-*/
string ReturningBookInput[15][5];
int BorrowNoInput;/*number of borrowing book*/

string bIDInput;
string btitleInput;
string categoryInput;
string genreInput;
bool availabilityInput;
/*declare the genres*/
string genre1 = "Fantasy";
string genre2 = "Science";
string genre3 = "Historical";
string genre4 = "Realistic";
string genre5 = "Fan";
string genre6 = "Narrative";
string genre7 = "Biography";
string genre8 = "Periodicals";
string genre9 = "Self-help";
string genre10 = "Reference";
string category1 = "Fiction";
string category2 = "Non-Fiction";

 bool SearchP(string pid, memberRecord* Head);
 void InsertArbitraryp(string memberid, string pname, string phone, int index);
 void InsertArbitraryb(string bid, string Btitle, string bcategory, string bgerne, bool avaiable, int index);


class allsingle
{
    public:
    virtual void nogf()=0;
};
class memberRecord: public allsingle
{
    public:
    /*declare the linked list variables*/
    string PID; //member number
	string PName; //member name
	string Phone; //member phone
	int BorrowNo;/*number of borrowing book*/
	int ReturnNo;/*number of returing book*/
	string BorrowingBook[3][5];/*ID- titl -category-genre-date*/
	string ReturningBook[15][5];
	memberRecord* Next; /*linked list next*/
	

friend void InsertArbitraryp(string memberid, string pname, string phone, int index);
friend void InsertArbitraryb(string bid, string Btitle, string bcategory, string bgerne, bool avaiable, int index);
friend bool SearchP(string pid, memberRecord* Head);
    memberRecord()
    {

    }
    void nogf()
    {

    }
	/*search function for member */
// bool SearchP(string pid, memberRecord* Head) 
// {
// 	memberRecord* MyCurrent = Head;
// 	while (MyCurrent != NULL) {
// 		if (MyCurrent->PID == pid) {
// 			return true;
// 		}
// 		else {
// 			MyCurrent = MyCurrent->Next; //go to next record
// 		}
// 	}
// 	return false;
// }
	/*add member account*/

void SaveMembersToFile() {
        ofstream fout("memberslist.txt"); // Open in default mode (truncate existing content)
        memberRecord* MyCurrent = Head;

        while (MyCurrent != NULL) {
            fout << "member Id =" << MyCurrent->PID << endl;
            fout << "member name =" << MyCurrent->PName << endl;
            fout << "member phone =" << MyCurrent->Phone << endl;
            fout << "member borrowed books =" << MyCurrent->BorrowNo << endl << endl; // Leave a blank line
            MyCurrent = MyCurrent->Next; // Move to the next member
        }
        
        fout.close();
    }


void Addmember() {
    cout << "\nPlease fill up the following requirements: \n" << endl;
    cout << "Enter member ID: "; cin >> PIDInput;

    if (SearchP(PIDInput, Head) == true) {
        cout << "\n This ID has been used before !!\n" << endl;
    } else {
        getchar();
        cout << "Enter member Name: "; getline(cin, PNameInput, '\n');
        cout << "Enter Phone No: "; getline(cin, PhoneInput, '\n');
        cout << "Enter the position you want to save the record: "; cin >> position;

        // Add member to the linked list
        InsertArbitraryp(PIDInput, PNameInput, PhoneInput, position);
        place++;

        // Save the current members to the file
        SaveMembersToFile();
    }
}


};
class BookRecord:public allsingle
{
    public:
    string bID;/*book ID*/
	string btitle; /*book title*/
	string category; /*book category*/
	string genre; /*book genre */
	bool availability; /*book availability*/
	BookRecord* Next2;/*linked list next*/
friend void InsertArbitraryp(string memberid, string pname, string phone, int index);
friend void InsertArbitraryb(string bid, string Btitle, string bcategory, string bgerne, bool avaiable, int index);
friend bool SearchP(string pid, memberRecord* Head);
    BookRecord()
    {
        
    }
    void nogf()
    {
        
    }
	/*function to store the book details such as id, title, categorey, genre, avaiability*/
void AddBook(){
	cout << "\nPlease fill up the following requirements: \n" << endl;
	cout << "Enter Book ID: "; cin >> bIDInput;
	if (Searchb(bIDInput, Head2) == true) {
		cout << "\n This ID has been used before !!\n" << endl;}
	else {
		getchar();
		cout << "Enter Book Title: "; getline(cin, btitleInput, '\n');
		cout << "Enter Book Category(1. Fiction  2. Non-Fiction): "; cin >> option1;
		if (option1 == '1') {
			categoryInput = category1;
			cout << "Enter Book genre: ";
			cout << "1. Fantasy   2. Science   3. Historical  4. Realistic  5. Fan\nEnter one option:  ";
			cin >> option2;
			if (option2 == '1') {
				genreInput = genre1;
			}
			else if (option2 == '2') {
				genreInput = genre2;
			}
			else if (option2 == '3') {
				genreInput = genre3;
			}
			else if (option2 == '4') {
				genreInput = genre4;
			}
			else {
				genreInput = genre5;
			}
		}
		else {
			categoryInput = category2;
			cout << "Enter Book genre: ";
			cout << "1. Fantasy   2. Science   3. Historical  4. Realistic  5. Fan\nEnter one option:  ";
			cin >> option2;
			if (option2 == '1') {
				genreInput = genre6;
			}
			else if (option2 == '2') {
				genreInput = genre7;
			}
			else if (option2 == '3') {
				genreInput = genre8;
			}
			else if (option2 == '4') {
				genreInput = genre9;
			}
			else {
				genreInput = genre10;
			}
		}
		availabilityInput = true;
		cout << "Enter the position you want to save the recode: "; cin >> position;

        ofstream fout;
        fout.open("booklist.txt", ios::app);
        
        // Write the book details and add a blank line after each record
		fout << endl;
        fout << "\n book Id =" << bIDInput << endl;
        fout << " book name =" << btitleInput << endl;
        fout << " book category =" << categoryInput << endl;
        fout << " book position =" << position << endl; // Leave a blank line after the book details
        
        fout.close();
        


		InsertArbitraryb(bIDInput, btitleInput, categoryInput, genreInput, availabilityInput, position);
		place2++;
	}
	return;
}
/*display record info*/
void DisplayBook(BookRecord* Head) {
	BookRecord* MyCurrent1 = Head;
	if (MyCurrent1 == NULL) {/*checking if the linked list is empty or not*/
		cout << "NO recode yet!!, please insert new recodes first..." << endl;}
	while (MyCurrent1 != NULL) { /*displaying the inserted nodes*/
		cout << " Book ID           : " << MyCurrent1->bID << endl;
		cout << " Book title        : " << MyCurrent1->btitle << endl;
		cout << " Book category     : " << MyCurrent1->category << endl;
		cout << " Book Genre        : " << MyCurrent1->genre << endl;
		cout << " Book availability(1=True & 0= False) : " << MyCurrent1->availability << endl;
		cout << "|------------------------------------------------------------------|" << endl;
		MyCurrent1 = MyCurrent1->Next2;// go to next
	}
}

/*display the avaiable books*/
void DisplayBookA(BookRecord* Head) {
	BookRecord* MyCurrent1 = Head;
	if (MyCurrent1 == NULL) {
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	while (MyCurrent1 != NULL) {
		if (MyCurrent1->availability == true) {

			cout << " Book ID           : " << MyCurrent1->bID << endl;
			cout << " Book title        : " << MyCurrent1->btitle << endl;
			cout << " Book category     : " << MyCurrent1->category << endl;
			cout << " Book Genre        : " << MyCurrent1->genre << endl;
			cout << " Book availability(1=True & 0= False) : " << MyCurrent1->availability << endl;
		}
		cout << "|-------------------------------------------------------------------------|" << endl;
		MyCurrent1 = MyCurrent1->Next2;// go to next
	}
}
/*search book*/
BookRecord* SearchBook(string title, BookRecord* Head) {
	BookRecord* MyCurrent = Head;
	if (MyCurrent == NULL) {
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	while (MyCurrent != NULL) { 
		if (MyCurrent->btitle == title|| MyCurrent->genre == title|| MyCurrent->category == title || MyCurrent->availability == true) {
			cout << " Book ID           : " << MyCurrent->bID << endl;
			cout << " Book title        : " << MyCurrent->btitle << endl;
			cout << " Book category     : " << MyCurrent->category << endl;
			cout << " Book Genre        : " << MyCurrent->genre << endl;
			cout << " Book availability(1=True & 0= False) : " << MyCurrent->availability << endl;
			cout << "|-------------------------------------------------------------------------|" << endl;
			return MyCurrent;
		}
		else {
			MyCurrent = MyCurrent->Next2; //go to next record
		}
	}
	return NULL;
}
/*search the avaiability*/
bool Searchb(string bid, BookRecord* Head)
{
	BookRecord* MyCurrent = Head;
	while (MyCurrent != NULL) {
		if (MyCurrent->bID == bid) {
			return true;
		}
		else {
			MyCurrent = MyCurrent->Next2; //go to next record
		}
	}
	return false;
}
/*return the book*/
void returnbook() {
	memberRecord* MyCurrent1 = Head;
	string memberid,bid;
	cout << "\nEnter member ID: "; cin >> memberid;
	cout << "\nEnter Book ID to return it: "; cin >> bid;
	if (MyCurrent1 == NULL) {
		cout << "NO recode yet!!, please insert new recodes first..." << endl;}
	while (MyCurrent1 != NULL) {
		if (memberid == MyCurrent1->PID) {
			for (int i = 0; i < MyCurrent1->BorrowNo; i++){
				if (MyCurrent1->BorrowingBook[i][0] == bid) {
					for (int ii = MyCurrent1->ReturnNo; ii < MyCurrent1->ReturnNo+1; ii++)
					{   /*copy the date from the borrow book array into the returning book array*/
						MyCurrent1->ReturningBook[ii][0] = MyCurrent1->BorrowingBook[ii][0];
						MyCurrent1->ReturningBook[ii][1] = MyCurrent1->BorrowingBook[ii][1];
						MyCurrent1->ReturningBook[ii][2] = MyCurrent1->BorrowingBook[ii][2];
						MyCurrent1->ReturningBook[ii][3] = MyCurrent1->BorrowingBook[ii][3];
						MyCurrent1->ReturningBook[ii][4] = MyCurrent1->BorrowingBook[ii][4];}
					/*making the book avaiable again*/
					BookRecord* reader = Head2;
					while (reader != NULL){
						if (reader->bID == bid) {
							reader->availability = true;
							break;}
						reader = reader->Next2;}
					/*deleting the returning book from the borrow book array*/
					int a, j, k;
					int NoColumn = 5;
					int NORows = 3;
					for (a = 0; a < NORows; a++) {
						for (k = a; k < NORows - 1; k++) {
							for (j = 0; j < NoColumn; j++) {
								MyCurrent1->BorrowingBook[k][j] = MyCurrent1->BorrowingBook[k + 1][j];}
						}
						a--;
						NORows--;
					}
				}		
			}
			MyCurrent1->ReturnNo += 1;/*increase the number of the returning book*/
			MyCurrent1->BorrowNo -= 1;/*decreasing the number of the borrowed book*/
			cout << "\n <!> The book has been returned successfully  <!>\n";
			break;
		}
		else
		{
			MyCurrent1 = MyCurrent1->Next;// go to next
		}
	}
}
/*borrow a book*/
void borrowBookp(string piD, memberRecord* Head) {
	memberRecord* MyCurrent2 = Head;
	while (MyCurrent2 != NULL){
		if (MyCurrent2->BorrowNo >=3) {/*if the number of the borrow book is equal or less than 3 will be allowed*/
			cout << "\n <!>  The member has reached the maximum number of borrowing books(which is 3 books)<!>\n";
			cout << "\nNoted: The member may return one of the borrowed book to be able to borrow a new book\n";
			break;}
		if (MyCurrent2->PID == pid) {
			cout << "\nNote: return the book within 15 days after the borrowing date!\n";
			cout << "Enter borrowing date(Y/M/D): "; cin >> borrowdate;
			for (int i = MyCurrent2->BorrowNo; i < MyCurrent2->BorrowNo+1; i++){
				MyCurrent2->BorrowingBook[i][0] = bkid;/*copying the book detail into borrowbook array*/
				MyCurrent2->BorrowingBook[i][1] = Booktitle;
				MyCurrent2->BorrowingBook[i][2] = bcateg;
				MyCurrent2->BorrowingBook[i][3] = bgenre;
				MyCurrent2->BorrowingBook[i][4] = borrowdate;}		
			MyCurrent2->BorrowNo += 1;/*increase the number of the borrow books*/
			cout << "The Borrowing Details" << endl;/*displaying the borrow book details*/
			cout << " member ID         : " << MyCurrent2->PID << endl;
			cout << " member Name       : " << MyCurrent2->PName << endl;
			cout << " Book ID           : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo-1][0] << endl;
			cout << " Book title        : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][1] << endl;
			cout << " Book category     : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][2] << endl;
			cout << " Book Genre        : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][3] << endl;
			cout << " Borrow Date       : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][4] << endl;
			cout << "|-------------------------------------------------------------------------|" << endl;
			break;
		}
		else
			MyCurrent2 = MyCurrent2->Next;/*go to the next record*/
	}
}
void borrowBook(string biD,BookRecord* Head2) {
	BookRecord* MyCurrent1 = Head2;
	while (MyCurrent1 != NULL) {
		if (MyCurrent1->bID == biD && MyCurrent1->availability == true) {
			bkid= MyCurrent1->bID; /*getting the book details*/
			Booktitle = MyCurrent1->btitle;
			bcateg = MyCurrent1->category;
			bgenre = MyCurrent1->genre;
			cout << "Enter member ID: "; cin >> pid;
			if (SearchP(pid, Head) == false)/*checking the member id*/
			{
				cout << "\nThis PID is not avaiable yet. Pls try again with new ID\n" << endl;
				break;}
			else {
				borrowBookp(pid,Head); /*calling the borrow function*/
				MyCurrent1->availability = false;/*set the borrowed book to not available*/
				break;
			}
		}
		else
			MyCurrent1 = MyCurrent1->Next2;
	}
}
void SearchPRecord(memberRecord* Head) {
	memberRecord* MyCurrent1 = Head;
	string sname;
	cout << "\nEnter member Name or ID: "; cin >> sname;
	if (MyCurrent1 == NULL) {
		cout << "NO recode yet!!, please insert new recodes first..." << endl;}
	while (MyCurrent1 != NULL) {
		if (sname == MyCurrent1->PName || sname == MyCurrent1->PID) {
			cout << " member ID              : " << MyCurrent1->PID << endl;
			cout << " member Name            : " << MyCurrent1->PName << endl;
			cout << " member Phone NO        : " << MyCurrent1->Phone << endl;
			cout << " Number of borrowed book: " << MyCurrent1->BorrowNo << endl;
			cout << " The borrowed books: \n" << endl;
			for (int i = 0; i < MyCurrent1->BorrowNo; i++)
			{
				cout << " Book ID                : " << MyCurrent1->BorrowingBook[i][0] << endl;
				cout << " Book title             : " << MyCurrent1->BorrowingBook[i][1] << endl;
				cout << " Book category          : " << MyCurrent1->BorrowingBook[i][2] << endl;
				cout << " Book Genre             : " << MyCurrent1->BorrowingBook[i][3] << endl;
				cout << " Borrow Date            : " << MyCurrent1->BorrowingBook[i][4] << endl;
				cout << "|------------------------------------------------|" << endl;
			}
			break;
		}
		else
		{
			MyCurrent1 = MyCurrent1->Next;// go to next
		}
	}
}
/*display last 10 borrowed book*/
void PLastBorrowedB(memberRecord* Head) {
    memberRecord* MyCurrent1 = Head;
    string name;
    cout << "\nEnter member Name or ID: "; 
    cin >> name;

    if (MyCurrent1 == NULL) {
        cout << "NO record yet!!, please insert new records first..." << endl;
        return;
    }

    while (MyCurrent1 != NULL) {
        if (name == MyCurrent1->PName || name == MyCurrent1->PID) {
            cout << " member ID              : " << MyCurrent1->PID << endl;
            cout << " member Name            : " << MyCurrent1->PName << endl;
            cout << " member Phone NO        : " << MyCurrent1->Phone << endl;
            cout << " Number of borrowed book: " << MyCurrent1->BorrowNo << endl;
            cout << " The borrowed books: \n" << endl;

            int start = max(0, MyCurrent1->ReturnNo - 10); // Start index for displaying last 10 books
            for (int i = start; i < MyCurrent1->ReturnNo; i++) {
                cout << " Book ID                : " << MyCurrent1->ReturningBook[i][0] << endl;
                cout << " Book title             : " << MyCurrent1->ReturningBook[i][1] << endl;
                cout << " Book category          : " << MyCurrent1->ReturningBook[i][2] << endl;
                cout << " Book Genre             : " << MyCurrent1->ReturningBook[i][3] << endl;
                cout << " Borrow Date            : " << MyCurrent1->ReturningBook[i][4] << endl;
                cout << "|------------------------------------------------|" << endl;
            }
            return;
        }
        MyCurrent1 = MyCurrent1->Next;
    }
    cout << "Member not found." << endl;
}

/*update the book record*/
BookRecord* UpdateBook(string biD, BookRecord* Head) {
	BookRecord* MyCurrent1 = Head;
	string Booktitle, bcategory, bgenre;
	while (MyCurrent1 != NULL) { 
		if (MyCurrent1->bID == biD) { 
			getchar();
			cout << "Enter Book title: ";
			getline(cin, Booktitle, '\n');
			cout << "Enter Book Category(1. Fiction  2. Non-Fiction): "; cin >> option1;
			if (option1 == '1') {
				bcategory = category1;
				cout << "\nBook genres: ";
				cout << "1. Fantasy   2. Science   3. Historical  4. Realistic  5. Fan\nEnter one option:  ";
				cin >> option2;
				if (option2 == '1') {
					bgenre = genre1;
				}
				else if (option2 == '2') {
					bgenre = genre2;
				}
				else if (option2 == '3') {
					bgenre = genre3;
				}
				else if (option2 == '4') {
					bgenre = genre4;
				}
				else {
					bgenre = genre5;
				}
			}
			else {
				bcategory = category2;
				cout << "Book genres: ";
				cout << "1. Fantasy   2. Science   3. Historical  4. Realistic  5. Fan\nEnter one option:  ";
				cin >> option2;
				if (option2 == '1') {
					bgenre = genre6;
				}
				else if (option2 == '2') {
					bgenre = genre7;
				}
				else if (option2 == '3') {
					bgenre = genre8;
				}
				else if (option2 == '4') {
					bgenre = genre9;
				}
				else {
					bgenre = genre10;
				}
			}
			MyCurrent1->btitle = Booktitle;
			MyCurrent1->category = bcategory;
			MyCurrent1->genre = bgenre;
			cout << "The New Details" << endl;
			cout << " Book ID           : " << MyCurrent1->bID << endl;
			cout << " Book title        : " << MyCurrent1->btitle << endl;
			cout << " Book category     : " << MyCurrent1->category << endl;
			cout << " Book Genre        : " << MyCurrent1->genre << endl;
			cout << " Book availability(1=True & 0= False) : " << MyCurrent1->availability << endl;
			cout << "|-------------------------------------------------------------------------|" << endl;
			return MyCurrent1;
		}
		else
			MyCurrent1 = MyCurrent1->Next2; 	
	}
	return NULL;
}
/*update member info*/
void UpdatePInfo() {
    memberRecord* MyCurrent = Head;
    cout << "Enter member ID: "; 
    cin >> PIDInput; // getting the member record

    while (MyCurrent != NULL) {
        if (MyCurrent->PID == PIDInput) { // find the member record
            cout << "\nPlease fill up The new info: \n" << endl;
            getchar();
            cout << "Enter member Name: "; getline(cin, PNameInput, '\n');
            cout << "Enter Phone No   : "; getline(cin, PhoneInput, '\n');
            MyCurrent->PName = PNameInput; // assigning the new data
            MyCurrent->Phone = PhoneInput;
            break;
        }
        MyCurrent = MyCurrent->Next; // go to next record
    }

    // Save the updated member list to the file
    if (Head != NULL) {
        Head->SaveMembersToFile();  // Call SaveMembersToFile from Head or any instance of memberRecord
    }
}


/*display members records with the active borrowed books*/
void Displaymembers(memberRecord* Head) {
	memberRecord* MyCurrent1 = Head;
	if (MyCurrent1 == NULL) {
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	while (MyCurrent1 != NULL) {
		cout << " member ID              : " << MyCurrent1->PID << endl;
		cout << " member Name            : " << MyCurrent1->PName << endl;
		cout << " member Phone NO        : " << MyCurrent1->Phone << endl;
		cout << " Number of borrowed book: " << MyCurrent1->BorrowNo << endl;
		cout << " The borrowed books: \n"<<endl;
		for (int i = 0; i < MyCurrent1->BorrowNo; i++)
		{
			cout << " Book ID                : " << MyCurrent1->BorrowingBook[i][0] << endl;
			cout << " Book title             : " << MyCurrent1->BorrowingBook[i][1] << endl;
			cout << " Book category          : " << MyCurrent1->BorrowingBook[i][2] << endl;
			cout << " Book Genre             : " << MyCurrent1->BorrowingBook[i][3] << endl;
			cout << " Borrow Date            : " << MyCurrent1->BorrowingBook[i][4] << endl;
			cout << "|------------------------------------------------|" << endl;
		}
		MyCurrent1 = MyCurrent1->Next;// go to next
	}
}



};

class hellyeah:public memberRecord , public BookRecord
{
	public:
	hellyeah()
	{

	}
	void nogf()
	{

	}
	
	
	string getPasswordInput() {
        string password = "";
        char ch;
    
        cout << "Enter Password: ";
    
        #ifdef _WIN32
        while ((ch = getch()) != '\r') { // Windows
            if (ch == 8 && password.length() > 0) { // Backspace key
                cout << "\b \b";
                password.pop_back();
            } else if (ch != 8) {
                password.push_back(ch);
                cout << "*";
            }
        }
        #else
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt); // get current terminal attributes
        newt = oldt;
        newt.c_lflag &= ~ECHO; // disable echoing
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply changes
        while ((ch = getchar()) != '\n') { // Linux/Unix
            if (ch == 127 && password.length() > 0) { // Backspace key
                cout << "\b \b";
                password.pop_back();
            } else if (ch != 127) {
                password.push_back(ch);
                cout << "*";
            }
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal attributes
        #endif
    
        cout << endl;
        return password;
    }
    
    void login() {
        string password;
        cout << "\n       <=======>  Book-Wise (Library Management System) <=======>\n";
    	cout << "\nEnter Password PIN To Access: ";
    	
        password = getPasswordInput();
        
        if (password == "1234") {
            cout << "\n  <>  Correct PIN <> \n";
    		system("pause");
    		system("cls");
        } else {
            cout << "\n  <> Wrong PIN <>\n";
    		login();
        }
    }
    
// 	void Login() {
// 	string pin;
//     pin = getPasswordInput();
    
// 	cout << "\n       <=======>  Library Management System(LMS) <=======>\n";
// 	cout << "\nEnter Password PIN To Access: "; cin >> pin;
// 	if (pin == "1234") {
// 		cout << "\n  <>  Correct PIN <> \n";
// 		system("pause");
// 		system("cls");
// 	}
// 	else {
// 		cout << "\n  <> Wrong PIN <>\n";
// 		Login();
// 	}
// }
};
/*insert new record arbitrary for member */
void InsertArbitraryp(string memberid, string pname, string phone, int index)
{
	memberRecord* New_node = new memberRecord; // create new node
	New_node->PID = memberid;    // Assign the variable to its data
	New_node->PName = pname;
	New_node->Phone = phone;
	New_node->BorrowNo = 0;
	New_node->ReturnNo = 0;
	if (index <= place) {
		if (index == 0) { //insert at the beginning
			memberRecord* Position = new memberRecord;
			Position->PID = memberid;    // Assign the variable to its data
			Position->PName = pname;
			Position->Phone = phone;
			Position->BorrowNo = 0;
			Position->ReturnNo = 0;
			Position->Next = Head;
			Head = Position;}
		else if (index == place) { //insert at the end of the linked list
			memberRecord* Position2 = new memberRecord; //create new node
			Position2->PID = memberid;    // Assign the variable to its data
			Position2->PName = pname;
			Position2->Phone = phone;
			Position2->BorrowNo = 0;
			Position2->ReturnNo = 0;
			Position2->Next = NULL;   // assign the next of the position to NULL
			if (Head == NULL)
				Head = Position2; // insert at the beginning of the linked list
			else { //insert at the end of the linked list
				memberRecord* MyCurrent1 = Head;//create new node that equal the head 
				while (MyCurrent1->Next != NULL) {//while will work until it reaches the NULL(end of linked list)
					MyCurrent1 = MyCurrent1->Next; // move from position to the next one until reach the end of the linked list
				}
				MyCurrent1->Next = Position2; // my last position->next in the linked list ->
			}                                 //-> will be equal the position that the new recode will be saved at
		}
		else { //insert at the given position
			memberRecord* new_record = new memberRecord; // create new node
			new_record->PID = memberid;    // Assign the variable to its data
			new_record->PName = pname;
			new_record->Phone = phone;
			new_record->BorrowNo = 0;
			new_record->ReturnNo = 0;
			memberRecord* prev = Head; //create new node and assgin it to the head of the linked list
			for (int i = 0; i < index - 1; i++)
				prev = prev->Next;
			new_record->Next = prev->Next;
			prev->Next = new_record;
		}
	}
	else if (index > place)
	{
		memberRecord* Position2 = new memberRecord; // create new recode
		Position2->PID = memberid;    // Assign the variable to its data
		Position2->PName = pname;
		Position2->Phone = phone;
		Position2->BorrowNo = 0;
		Position2->ReturnNo = 0;
		Position2->Next = NULL;
		if (Head == NULL) {
			Head = Position2; // insert at the beginning of the linked list
		}
		else {
			memberRecord* MyCurrent1 = Head; //insert at the end of the linked list
			while (MyCurrent1->Next != NULL) {//while will work until it reaches the NULL(end of linked list)
				MyCurrent1 = MyCurrent1->Next;}
			MyCurrent1->Next = Position2;
		}
	}
}
/*search function for member */
bool SearchP(string pid, memberRecord* Head) 
{
	memberRecord* MyCurrent = Head;
	while (MyCurrent != NULL) {
		if (MyCurrent->PID == pid) {
			return true;
		}
		else {
			MyCurrent = MyCurrent->Next; //go to next record
		}
	}
	return false;
}

/*insert arbitrary book*/
void InsertArbitraryb(string bid, string Btitle, string bcategory, string bgerne, bool avaiable, int index) {
    BookRecord* New_node = new BookRecord; // create new node
    New_node->bID = bid;
    New_node->btitle = Btitle;
    New_node->category = bcategory;
    New_node->genre = bgerne;
    New_node->availability = avaiable;

    if (index <= place2) {
        if (index == 0) { // Insert at the beginning
            New_node->Next2 = Head2;
            Head2 = New_node;
        } else { // Insert at the given position
            BookRecord* temp = Head2;
            for (int i = 0; i < index - 1 && temp->Next2 != NULL; i++) {
                temp = temp->Next2;
            }
            New_node->Next2 = temp->Next2;
            temp->Next2 = New_node;
        }
    } else { // Insert at the end if index exceeds size
        if (Head2 == NULL) {
            Head2 = New_node;
        } else {
            BookRecord* temp = Head2;
            while (temp->Next2 != NULL) {
                temp = temp->Next2;
            }
            temp->Next2 = New_node;
        }
    }
    place2++; // Update place2 to reflect added node
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


void LoadBooksFromFile() {
    ifstream fin("booklist.txt");

    // Check if the file was opened successfully
    if (!fin.is_open()) {
        //cout << "Error: Could not open booklist.txt file" << endl;
        return;
    }

    string line, bid, title, category;
    bool availability;
    int position;

    //cout << "Loading books from file..." << endl;

    while (getline(fin, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        // Debugging: Print the current line being processed
        //cout << "Processing line: " << line << endl;

        // Parse the book ID
        if (line.find("book Id =") != string::npos) {
            bid = trim(line.substr(line.find("=") + 1)); // Extract and trim book ID
            //cout << "Found book ID: " << bid << endl;

            // Read and parse the next line for the book name
            getline(fin, line);
            title = trim(line.substr(line.find("=") + 1)); // Extract and trim book name
            //cout << "Found book name: " << title << endl;

            // Read and parse the next line for the book category
            getline(fin, line);
            category = trim(line.substr(line.find("=") + 1)); // Extract and trim book category
            //cout << "Found book category: " << category << endl;

            // Read and parse the next line for the book position
            getline(fin, line);
            string pos_str = trim(line.substr(line.find("=") + 1)); // Extract and trim book position
            position = stoi(pos_str); // Convert position to integer
            //cout << "Found book position: " << position << endl;

            // All books are available by default
            availability = true;

            // Insert the book into the linked list
            InsertArbitraryb(bid, title, category, "", availability, position);
        }
    }

    fin.close();
    cout << "Finished loading books." << endl;
}

void LoadMembersFromFile() {
    ifstream fin("memberslist.txt");
    
    // Check if the file was opened successfully
    if (!fin.is_open()) {
        cout << "Error: Could not open memberslist.txt file" << endl;
        return;
    }

    string line, memberID, memberName, memberPhone;
    int borrowedBooks;

    cout << "Loading members from file..." << endl;

    while (getline(fin, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        // Parse the member ID
        if (line.find("member Id =") != string::npos) {
            memberID = trim(line.substr(line.find("=") + 1)); // Extract and trim member ID

            // Read and parse the next line for the member name
            getline(fin, line);
            memberName = trim(line.substr(line.find("=") + 1)); // Extract and trim member name

            // Read and parse the next line for the member phone
            getline(fin, line);
            memberPhone = trim(line.substr(line.find("=") + 1)); // Extract and trim member phone

            // Read and parse the next line for borrowed books count
            getline(fin, line);
            borrowedBooks = stoi(trim(line.substr(line.find("=") + 1))); // Extract and trim borrowed books count

            // Insert the member into the linked list
            InsertArbitraryp(memberID, memberName, memberPhone, 0); // 0 for position, can be adjusted if needed
            // Set the borrowed book count here if needed, depending on your implementation
        }
    }

    fin.close();
    cout << "Finished loading members." << endl;
}


/*login page*/


/*the main function of the system */
int main() {
	hellyeah obj;
	string sbtitle;
	string bookid, borrowid;
	obj.login();
	system("color 2");/*changing the color to green*/
	
	LoadBooksFromFile();
	LoadMembersFromFile();

	do{
		cerr << "\n\n       <=======>  Book-Wise (Library Management System) <=======>\n"
			"  1. Book Services       2. members Services     3. Exit"<<endl;
		cout << "Enter one choice: "; cin >> choice;
		switch (choice){
		case '1':
			do{
				cerr << "\n\n       <=======>  Book Service  <=======>\n"
					"  1. Add New Book    2. Display Books   3. Search Book\n  4. Update Book Information    5. Back" << endl;
				cout << "Enter one choice: "; cin >> choice;
				switch (choice)
				{
				case '1':
					obj.AddBook();
					break;
				case '2':
					cout << "\n1. Display all books.     2. Display the avaiable books only. \nEnter one option: "; cin >> choice;
					if (choice == '1') {
						obj.DisplayBook(Head2);
					}
					else {
						obj.DisplayBookA(Head2);
					}
					cout << "\nDo you want to borrow any book: (1. Yes  2. NO): "; cin >> choice;
					if (choice == '1') {

						cout << "Enter Book ID: "; cin >> borrowid;
						obj.borrowBook(borrowid, Head2);
					}
					else {
						cout << "\n Backing to the main menu....\n" << endl;
					}
					break;
				case '3':
					getchar();
					cout << "\nEnter the book title or category or genre to search: "; getline(cin, sbtitle, '\n');
					obj.SearchBook(sbtitle, Head2);
					cout << "\nDo you want to borrow any book: (1. Yes  2. NO): "; cin>> choice;
					if (choice == '1') {
						
						cout << "Enter Book ID: "; cin >> borrowid;
						obj.borrowBook(borrowid, Head2);
					}
					else {
						cout << "\n Backing to the main menu....\n" << endl;
					}
					break;
				case '4':
					cout << "\nEnter Book ID to update: "; cin >> bookid;
					obj.UpdateBook(bookid, Head2);
					break;
				case '5':
					cout << "\n Backing to the main menu....\n" << endl;
					break;
				default:
					cerr << "\n\n <!!!>    Wrong Choice   <!!!>" << endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice != '5');
			break;
		case '2':
			do
			{
				cerr << "\n\n       <=======>  members Service  <=======>\n"
					"  1. Add New member    2. Display the last 10 books borrowed by a member\n"
					"  3. Search member     4. Update member Info       5. Return a Borrowed book\n"
					"  6. View all members with active book borrowed.   7. Back" << endl;
				cout << "Enter one choice: "; cin >> choice;
				switch (choice)
				{
				case '1':
					obj.Addmember();
					break;
				case '2':
					obj.PLastBorrowedB(Head);
					break;
				case '3':
					obj.SearchPRecord(Head);
					break;
				case '4':
					obj.UpdatePInfo();
					break;
				case '5':
					obj.returnbook();
					break;
				case '6':
					obj.Displaymembers(Head);
					break;
				case '7':
					cout << "\n Backing to the main menu....\n" << endl;
					break;
				default:
					cerr << " <!!!>    Wrong Choice   <!!!>" << endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice != '7');
			break;
		case '3':
			cout <<"\n <***>  See You Soon ! :)    <***>\n"<<endl;
			break;
		default:
			cerr << "\n\n <!!!>    Wrong Choice   <!!!>"<<endl;
			break;
		}
		system("pause");/*pause the screen until the user press a key*/
		system("cls");/*clean the old displayed menu*/
	} while (choice != '3');
	return 0;
}
