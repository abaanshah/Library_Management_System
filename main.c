#include <stdio.h>

struct Book{
  int book_id;
  char book_name[100];
  char author_name[100];
  char category[100];
  int qty;
  int avail_status;
  
  
};

struct Member{
  int member_id;
  char full_name[100];
  char contact_number[15];
  char email_address[100];
  int issued_books;
};



//------------ADD BOOK-------------
void addBook(){
  printf("\nENTER BOOK DETAILS TO ADD BOOK\n");
  struct Book b;
  FILE *fileptr;
  fileptr=fopen("books.txt","a");
  
  printf("ENTER BOOK ID: ");
  scanf("%d",&b.book_id);

  printf("ENTER BOOK NAME: ");
  scanf("%s",b.book_name);

  printf("ENTER AUTHOR NAME: ");
  scanf("%s",b.author_name);

  printf("Enter Category: ");
  scanf("%s", b.category);

  printf("Enter Quantity: ");
  scanf("%d", &b.qty);

  printf("Enter Availability Status (1/0): ");
  scanf("%d", &b.avail_status);
  
  printf("\nAdding Book please wait.....\n");

    fprintf(fileptr,"%d | %s | %s | %s | %d | %d\n",
            b.book_id,
            b.book_name,
            b.author_name,
            b.category,
            b.qty,
            b.avail_status);

    fclose(fileptr);
    printf("Book Added Successfully\n");
}


//------------VIEW BOOK-------------
void viewBooks(){

    struct Book b;

    FILE *fileptr;

    fileptr = fopen("books.txt","r");

    printf("\nBOOK RECORDS\n\n");

    while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
        &b.book_id,
        b.book_name,
        b.author_name,
        b.category,
        &b.qty,
        &b.avail_status) != EOF){

        printf("Book ID: %d\n",b.book_id);
        printf("Book Name: %s\n",b.book_name);
        printf("Author Name: %s\n",b.author_name);
        printf("Category: %s\n",b.category);
        printf("Quantity: %d\n",b.qty);
        printf("Availability: %d\n",b.avail_status);
        printf("\n");

    }

    fclose(fileptr);

}


//------------SEARCH BOOK-------------
void searchBook(){

    int search_id;
    int found = 0;

    struct Book b;

    FILE *fileptr;

    printf("Enter Book ID To Search: ");
    scanf("%d",&search_id);

    fileptr = fopen("books.txt","r");

    while(fscanf(fileptr,"%d %s %s %s %d %d",
        &b.book_id,
        b.book_name,
        b.author_name,
        b.category,
        &b.qty,
        &b.avail_status) != EOF){

        if(search_id == b.book_id){

            printf("\nBOOK FOUND\n\n");

            printf("Book ID: %d\n",b.book_id);
            printf("Book Name: %s\n",b.book_name);
            printf("Author Name: %s\n",b.author_name);
            printf("Category: %s\n",b.category);
            printf("Quantity: %d\n",b.qty);
            printf("Availability: %d\n",b.avail_status);

            found = 1;

            break;
        }
    }

    if(found == 0){
        printf("Book Not Found\n");
    }

    fclose(fileptr);

}

//------------DELETE BOOK-------------
void deleteBook(){

    int delete_id;
    int found = 0;

    struct Book b;

    FILE *fileptr;
    FILE *tempptr;

    printf("Enter Book ID To Delete: ");
    scanf("%d",&delete_id);

    fileptr = fopen("books.txt","r");

    tempptr = fopen("temp.txt","w");

    while(fscanf(fileptr,"%d %s %s %s %d %d",
        &b.book_id,
        b.book_name,
        b.author_name,
        b.category,
        &b.qty,
        &b.avail_status) != EOF){

        if(delete_id == b.book_id){

            found = 1;

        }
        else{

            fprintf(tempptr,"%d %s %s %s %d %d\n",
                b.book_id,
                b.book_name,
                b.author_name,
                b.category,
                b.qty,
                b.avail_status);
        }
    }

    fclose(fileptr);
    fclose(tempptr);

    remove("books.txt");

    rename("temp.txt","books.txt");

    if(found == 1){
        printf("Book Deleted Successfully\n");
    }
    else{
        printf("Book Not Found\n");
    }

}



void updateBook(){

    int update_id;
    int found = 0;

    struct Book b;

    FILE *fileptr;
    FILE *tempptr;

    printf("Enter Book ID To Update: ");
    scanf("%d",&update_id);

    fileptr = fopen("books.txt","r");

    tempptr = fopen("temp.txt","w");

    while(fscanf(fileptr,"%d %s %s %s %d %d",
        &b.book_id,
        b.book_name,
        b.author_name,
        b.category,
        &b.qty,
        &b.avail_status) != EOF){

        if(update_id == b.book_id){

            found = 1;

            printf("Enter New Book Name: ");
            scanf("%s",b.book_name);

            printf("Enter New Author Name: ");
            scanf("%s",b.author_name);

            printf("Enter New Category: ");
            scanf("%s",b.category);

            printf("Enter New Quantity: ");
            scanf("%d",&b.qty);

            printf("Enter New Availability Status: ");
            scanf("%d",&b.avail_status);
        }

        fprintf(tempptr,"%d %s %s %s %d %d\n",
            b.book_id,
            b.book_name,
            b.author_name,
            b.category,
            b.qty,
            b.avail_status);
    }

    fclose(fileptr);
    fclose(tempptr);

    if(found == 1){

        remove("books.txt");
        rename("temp.txt","books.txt");

        printf("Book Updated Successfully\n");
    }
    else{

        remove("temp.txt");

        printf("Book Not Found\n");
    }

}


void addMember(){

    struct Member m;

    FILE *fileptr;

    fileptr = fopen("members.txt","a");

    printf("Enter Member ID: ");
    scanf("%d",&m.member_id);

    printf("Enter Full Name: ");
    scanf("%s",m.full_name);

    printf("Enter Contact Number: ");
    scanf("%s",m.contact_number);

    printf("Enter Email Address: ");
    scanf("%s",m.email_address);

    fprintf(fileptr,"%d %s %s %s\n",
        m.member_id,
        m.full_name,
        m.contact_number,
        m.email_address);

    fclose(fileptr);

    printf("Member Added Successfully\n");

}

void issueBook(){

    int issue_id;
    int found = 0;

    struct Book b;

    FILE *fileptr;
    FILE *tempPtr;

    printf("Enter Book ID To Issue: ");
    scanf("%d",&issue_id);

    fileptr = fopen("books.txt","r");

    tempPtr = fopen("temp.txt","w");

    while(fscanf(fileptr,"%d %s %s %s %d %d",
        &b.book_id,
        b.book_name,
        b.author_name,
        b.category,
        &b.qty,
        &b.avail_status) != EOF){

        if(issue_id == b.book_id){

            found = 1;

            if(b.qty > 0){

                b.qty--;

                if(b.qty == 0){
                    b.avail_status = 0;
                }

                printf("Book Issued Successfully\n");
            }
            else{

                printf("Book Not Available\n");
            }
        }

        fprintf(tempPtr,"%d %s %s %s %d %d\n",
            b.book_id,
            b.book_name,
            b.author_name,
            b.category,
            b.qty,
            b.avail_status);
    }

    fclose(fileptr);
    fclose(tempPtr);

    if(found == 1){

        remove("books.txt");
        rename("temp.txt","books.txt");
    }
    else{

        remove("temp.txt");

        printf("Book Not Found\n");
    }

}

void returnBook(){

    int return_id;
    int found = 0;

    struct Book b;

    FILE *fileptr;
    FILE *tempPtr;

    printf("Enter Book ID To Return: ");
    scanf("%d",&return_id);

    fileptr = fopen("books.txt","r");

    tempPtr = fopen("temp.txt","w");

    while(fscanf(fileptr,"%d %s %s %s %d %d",
        &b.book_id,
        b.book_name,
        b.author_name,
        b.category,
        &b.qty,
        &b.avail_status) != EOF){

        if(return_id == b.book_id){

            found = 1;

            b.qty++;

            b.avail_status = 1;

            printf("Book Returned Successfully\n");
        }

        fprintf(tempPtr,"%d %s %s %s %d %d\n",
            b.book_id,
            b.book_name,
            b.author_name,
            b.category,
            b.qty,
            b.avail_status);
    }

    fclose(fileptr);
    fclose(tempPtr);

    if(found == 1){

        remove("books.txt");
        rename("temp.txt","books.txt");
    }
    else{

        remove("temp.txt");

        printf("Book Not Found\n");
    }

}



int main(){

    int choice;

    while(1){

        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");

        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Add Member\n");
        printf("7. Issue Book\n");
        printf("8. Return Book\n");
        printf("9. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                AddBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                updateBook();
                break;

            case 5:
                deleteBook();
                break;

            case 6:
                addMember();
                break;

            case 7:
                issueBook();
                break;

            case 8:
                returnBook();
                break;

            case 9:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}