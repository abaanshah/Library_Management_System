# Library Management System in C

A console-based Library Management System developed using the C programming language.  
This project manages books and members using file handling and supports different library
operations like adding books, searching, issuing, returning, analytics, and report generation.


# Features

## Book Management
- Add Book
- View Books
- Search Book by:
  - ID
  - Name
  - Author
- Update Book Details
- Delete Book

## Member Management
- Add Member
- View Members
- Delete Member

## Library Operations
- Issue Book
- Return Book

## Analytics Section
- Total Book Titles
- Total Books Available
- Issued Book Titles
- Total Members

## Report Generation
- Generate `books_report.txt`
- Generate `members_report.txt`


# Concepts Used

- C Programming
- Functions
- Structures
- Arrays
- File Handling
- Pointers
- Loops & Conditions
- Searching Algorithms
- Bubble Sort
- Basic Error Handling



# Additional Improvements Added

- Duplicate ID validation for Books and Members
- File open error handling
- Bubble Sort used for sorted book viewing
- Linear Search used for searching operations
- Menu-driven interface



# Files Used

- `main.c`
- `books.txt`
- `members.txt`
- `books_report.txt`
- `members_report.txt`

# Screenshots

Output screenshots are available inside the `output_screenshots` folder.


# How To Run

1. gcc main.c -o main  (compile)
2. .\main (run command windows)  ||  ./main(run command Linux/Mac)