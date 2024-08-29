# Book-Wise 

## Overview

**Book-Wise** is a console-based Library Management System written in C++. It is designed to manage book records and member information in a library. The system provides functionalities to update book and member information, display records, borrow and return books, and ensure secure access through a password-protected login. 

## Table of Contents

1. [Overview](#overview)
2. [Data Structures](#data-structures)
3. [Classes and Methods](#classes-and-methods)
   - [LibrarySystem Class](#librarysystem-class)
   - [LibraryLogin Class](#librarylogin-class)
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
- **BorrowingBook[10][5]**: Array holding details of up to 10 borrowed books:
  - Book ID
  - Book Title
  - Book Category
  - Book Genre
  - Borrow Date
- **ReturningBook[10][5]**: Array holding details of up to 10 returned books:
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

The system is primarily managed through two classes: `LibrarySystem` and `LibraryLogin`.

### 1. LibrarySystem Class

This class contains methods to manage the core functionalities of the library system:

- **`void PLastBorrowedB(memberRecord* Head)`**: Displays the last 10 borrowed books by a specific member.
- **`BookRecord* UpdateBook(string bookID, BookRecord* Head2)`**: Updates the details of a book.
- **`void UpdatePInfo()`**: Updates a member's information.
- **`void DisplayMembers(memberRecord* Head)`**: Displays all members and their borrowed book details.
- **`void displayMemberDetails(memberRecord* member)`**: Helper method to display member details.
- **`void displayLastBorrowedBooks(memberRecord* member)`**: Helper method to display the last borrowed books of a member.
- **`void displayBorrowedBookDetails(const string book[5])`**: Helper method to display details of a borrowed book.
- **`void updateBookDetails(BookRecord* book)`**: Helper method to update a book's details.
- **`string selectGenre()`**: Helper method to select a book genre.

### 2. LibraryLogin Class

The `LibraryLogin` class handles user authentication and extends from `LibrarySystem`.

- **`void Login()`**: Authenticates the user by asking for a PIN.

## Main Function Workflow

The `main()` function drives the program, managing user input and navigating between different services:

1. **Login**: Users must enter a PIN using the `LibraryLogin` class.
2. **Display Main Menu**: Post-login, a menu with options for book services, member services, and exit is displayed.
3. **User Input Handling**:
   - **Book Services**: Placeholder for managing book options.
   - **Member Services**: Placeholder for managing member options.
   - **Exit**: Terminates the program.
   - **Invalid Input**: Displays an error message if an invalid choice is entered.

## Features and Functionalities

### 1. Book Management

- **Update Book Details**: Update book information such as title, category, and genre.
- **Display Borrowed and Returned Books**: Shows details of books borrowed and returned by members.

### 2. Member Management

- **Update Member Information**: Update a member's name and phone number.
- **Display Member Records**: View all members and their borrowed books.

### 3. Authentication

- **Password-Protected Access**: Requires a PIN to access the system, ensuring only authorized users can modify records.

## Usage Instructions

1. **Run the Program**: Compile and execute the program in a C++ environment.
2. **Login**: Enter the password PIN when prompted. The default PIN is "1234".
3. **Navigate the Menu**: Use the provided options to navigate through book and member services.
4. **Update Records**: Follow the prompts to update book and member information.
5. **Exit**: Select the "Exit" option to close the program.

## Error Handling and Validation

- **Incorrect PIN Handling**: If the user enters an incorrect PIN, they are prompted to try again.
- **Invalid Input Handling**: Validates user inputs across functions, displaying an error message for invalid options.
- **Member and Book Not Found**: If a member or book ID is not found, a "not found" message is displayed.

## Future Enhancements

- **Detailed Error Messages**: Provide more specific feedback for errors.
- **Database Integration**: Store records in a database instead of in-memory linked lists to persist data across sessions.
- **Improved Authentication**: Implement a more secure and dynamic authentication system.
- **Extended Features**: Add book reservation, fine calculation, and member history tracking.
- **GUI Interface**: Develop a graphical user interface for a more user-friendly experience.
- **Backup and Restore Functionality**: Enable data backup and restore options for data safety.
+++
