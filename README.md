# Book-Wise 

## Overview

**Book-Wise** is a console-based Library Management System with user friendly interface written in C++ and based on the concept of OOP's. It is designed to manage book records and member information in a library. The system provides functionalities to update book and member information, display records, borrow and return books, and ensure secure access through a password-protected login. Additionally, it now supports loading and saving book and member data from text files.

## Table of Contents

1. [Overview](#overview)
2. [Data Structures](#data-structures)
3. [Classes and Methods](#classes-and-methods)
   - [LibrarySystem Class](#librarysystem-class)
   - [LibraryLogin Class](#librarylogin-class)
   - [File Handling](#file-handling)
4. [Main Function Workflow](#main-function-workflow)
5. [Features and Functionalities](#features-and-functionalities)
6. [Usage Instructions](#usage-instructions)
7. [Error Handling and Validation](#error-handling-and-validation)
8. [Future Enhancements](#future-enhancements)

## Data Structures

The system uses two primary data structures: **Member Record** and **Book Record**.

### 1. Member Record (`memberRecord`)

The `memberRecord` struct stores information about library members and includes:

- **PID**: Member ID (String)
- **PName**: Member name (String)
- **Phone**: Member phone number (String)
- **BorrowNo**: Number of books currently borrowed (Integer)
- **ReturnNo**: Number of books returned (Integer)
- **BorrowingBook[3][5]**: Array holding details of up to 3 borrowed books:
  - Book ID
  - Book Title
  - Book Category
  - Book Genre
  - Borrow Date
- **ReturningBook[15][5]**: Array holding details of returned books:
  - Book ID
  - Book Title
  - Book Category
  - Book Genre
  - Return Date
- **Next**: Pointer to the next member record (Linked List structure)

### 2. Book Record (`BookRecord`)

The `BookRecord` struct stores information about the books in the library and includes:

- **bID**: Book ID (String)
- **btitle**: Book title (String)
- **category**: Book category (String) (e.g., Fiction, Non-Fiction)
- **genre**: Book genre (String) (e.g., Fantasy, Science, Historical)
- **availability**: Book availability status (Boolean)
- **Next2**: Pointer to the next book record (Linked List structure)

## Classes and Methods

The system is managed through two main classes: `LibrarySystem` and `LibraryLogin`.

### 1. LibrarySystem Class

This class handles core library functionalities, including the newly added file handling methods:

- **`void LoadBooksFromFile()`**: Loads book records from a text file (`booklist.txt`).
- **`void LoadMembersFromFile()`**: Loads member records from a text file (`memberslist.txt`).
- **`void SaveMembersToFile()`**: Saves the member records back to the file.
- **`void AddBook()`**: Adds a new book to the system.
- **`void Addmember()`**: Adds a new member to the system.
- **`void returnbook()`**: Manages returning of borrowed books.
- **`void borrowBook()`**: Manages borrowing of books.
- **`BookRecord* UpdateBook(string bookID, BookRecord* Head2)`**: Updates the details of a book.
- **`void UpdatePInfo()`**: Updates a member's information.

### 2. LibraryLogin Class

The `LibraryLogin` class handles user authentication and extends from `LibrarySystem`.

- **`void login()`**: Authenticates the user by asking for a password (default: "1234").

### 3. File Handling

- **Book Data**: Loaded from `booklist.txt` where each book's ID, title, category, and position are stored.
- **Member Data**: Loaded from `memberslist.txt` where each member's ID, name, phone number, and borrowed book count are stored.
- Both types of data can be modified and saved back to their respective files.

## Main Function Workflow

The `main()` function manages user input and navigation between different services, now including file handling at startup:

1. **Login**: Users must enter a password using the `login()` function.
2. **Load Data**: The system loads books from `booklist.txt` and members from `memberslist.txt`.
3. **Display Main Menu**: Post-login, a menu with options for book services, member services, and exit is displayed.
4. **User Input Handling**:
   - **Book Services**: Manage books, including adding, displaying, searching, and updating records.
   - **Member Services**: Manage members, including adding, viewing borrowing history, updating records, and returning books.
   - **Exit**: Terminates the program.
   - **Invalid Input**: Displays an error message for invalid input.

## Features and Functionalities

### 1. Book Management

- **Add Book**: Adds a new book to the system.
- **Display Books**: Displays all or available books.
- **Search Book**: Search books by title, genre, or category.
- **Update Book**: Update a book's information.
- **Borrow Book**: Allows members to borrow a book if available.
- **Return Book**: Return a previously borrowed book.

### 2. Member Management

- **Add Member**: Adds a new member to the system.
- **Display Borrowing History**: View the last 10 borrowed books of a member.
- **Update Member Info**: Modify a member's details.
- **Return Books**: Record book returns for members.
- **Search Member**: Find a member by ID or name.

### 3. File Handling

- **Load from Files**: Automatically loads members and books from text files when the program starts.
- **Save to File**: Member data is saved to `memberslist.txt` after modifications.

### 4. Authentication

- **Password-Protected Access**: Requires a password to access the system.

## Usage Instructions

1. **Run the Program**: Compile and execute the program in a C++ environment.
2. **Login**: Enter the password when prompted (default: "1234").
3. **Navigate the Menu**: Use the provided options to navigate through book and member services.
4. **Update Records**: Follow prompts to update book and member information.
5. **Exit**: Select the "Exit" option to close the program.

## Error Handling and Validation

- **Incorrect Password Handling**: Users are prompted again for a password if incorrect.
- **Invalid Input Handling**: Validates user inputs, displaying error messages for invalid options.
- **File Not Found**: Displays a message if the required data files cannot be loaded.
- **Member and Book Not Found**: Displays a "not found" message for invalid search inputs.

## Future Enhancements

- **Advanced Search**: Improve search functionality for more detailed criteria.
- **Database Integration**: Store records in a database for persistence and scalability.
- **Enhanced Authentication**: Implement a more secure, dynamic authentication system.
- **Additional Features**: Implement features like book reservation and fines calculation.
- **Graphical User Interface (GUI)**: Add a GUI for improved user interaction.
- **Data Backup**: Enable backup and restore functionality for added data security.
