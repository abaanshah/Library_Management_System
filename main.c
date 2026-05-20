#include <stdio.h>
#include <string.h>

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
  
    printf("\n----------ADD BOOKS----------\n");

    struct Book b;
    struct Book check;

    int found = 0;

    FILE *fileptr;
    FILE *checkptr;

    checkptr = fopen("books.txt","r");

    if(checkptr != NULL){

        printf("ENTER BOOK ID: ");
        scanf("%d",&b.book_id);

        while(fscanf(checkptr,"%d | %s | %s | %s | %d | %d",
            &check.book_id,
            check.book_name,
            check.author_name,
            check.category,
            &check.qty,
            &check.avail_status) != EOF){

            if(b.book_id == check.book_id){

                found = 1;

                break;
            }
        }

        fclose(checkptr);

        if(found == 1){

            printf("Book ID Already Exists!!!\n");

            return;
        }
    }
    else{

        printf("ENTER BOOK ID: ");
        scanf("%d",&b.book_id);
    }

    fileptr = fopen("books.txt","a");

    if(fileptr == NULL){

        printf("File Cannot Be Opened\n");

        return;
    }

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

    fprintf(fileptr,"%d | %s | %s | %s | %d | %d",
        b.book_id,
        b.book_name,
        b.author_name,
        b.category,
        b.qty,
        b.avail_status);

    fclose(fileptr);

    printf("\nBook Added Successfully!!!\n");
}
//------------VIEW BOOK-------------
void viewBooks(){

    printf("\n----------VIEW BOOKS----------\n\n");

    struct Book b[100];
    struct Book temp;

    FILE *fileptr;

    int count = 0;
    int i,j;

    fileptr = fopen("books.txt","r");

    if(fileptr == NULL){
    printf("File Cannot Be Opened\n");
    return;
    }

    while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
        &b[count].book_id,
        b[count].book_name,
        b[count].author_name,
        b[count].category,
        &b[count].qty,
        &b[count].avail_status) != EOF){

        count++;
    }

    fclose(fileptr);

    for(i=0;i<count-1;i++){

        for(j=0;j<count-i-1;j++){

            if(b[j].book_id > b[j+1].book_id){

                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }

    for(i=0;i<count;i++){

        printf("Book ID: %d\n",b[i].book_id);
        printf("Book Name: %s\n",b[i].book_name);
        printf("Author Name: %s\n",b[i].author_name);
        printf("Category: %s\n",b[i].category);
        printf("Quantity: %d\n",b[i].qty);
        printf("Availability: %d\n",b[i].avail_status);

        printf("\n");
    }
}

//------------SEARCH BOOK-------------
void searchBook(){

    printf("\n----------SEARCH BOOK----------\n");
    
    int choice;
    int search_id;
    int found = 0;
    char search_name[100];
    char search_author[100];
    struct Book b;

    FILE *fileptr;
    fileptr = fopen("books.txt","r");

    if(fileptr == NULL){
    printf("File Cannot Be Opened\n");
    return;
    }

    printf("1. Search By ID\n");
    printf("2. Search By Name\n");
    printf("3. Search By Author\n");

    printf("Enter Your Choice: ");
    scanf("%d",&choice);


    if(choice == 1){

        printf("Enter Book ID To Search: ");
        scanf("%d",&search_id);

        while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
            &b.book_id,
            b.book_name,
            b.author_name,
            b.category,
            &b.qty,
            &b.avail_status) != EOF){

            if(search_id == b.book_id){

                printf("\nBOOK FOUND!!!\n\n");

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
    }

    else if(choice == 2){

        printf("Enter Book Name To Search: ");
        scanf("%s",search_name);

        while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
            &b.book_id,
            b.book_name,
            b.author_name,
            b.category,
            &b.qty,
            &b.avail_status) != EOF){

            if(strcmp(search_name,b.book_name) == 0){

                printf("\nBOOK FOUND!!!\n\n");

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
    }

    else if(choice == 3){

        printf("Enter Author Name To Search: ");
        scanf("%s",search_author);

        while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
            &b.book_id,
            b.book_name,
            b.author_name,
            b.category,
            &b.qty,
            &b.avail_status) != EOF){

            if(strcmp(search_author,b.author_name) == 0){

                printf("\nBOOK FOUND!!!\n\n");

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
    }

    if(found == 0){
        printf("Book Not Found!!!\n");
    }

    fclose(fileptr);
}

//----------UPDATE BOOK-----------
void updateBook(){

    int update_id;
    int found = 0;
    struct Book b;
    FILE *fileptr;
    FILE *tempptr;
    fileptr = fopen("books.txt","r");
    tempptr = fopen("temp.txt","w");

    if(fileptr == NULL || tempptr==NULL){
    printf("File Cannot Be Opened\n");
    return;
    }

    printf("\n-----------UPDATE BOOK-----------\n");
    printf("\nEnter Book ID To Update: ");
    scanf("%d",&update_id);

    while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
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

        fprintf(tempptr,"%d | %s | %s | %s | %d | %d\n",
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
        printf("Book Updated Successfully!!!\n");
    }
    else{
        remove("temp.txt");
        printf("Book Not Found!!!\n");
    }
}

//------------DELETE BOOK-------------
void deleteBook(){

    printf("\n-----------DELETE BOOK-----------\n");

    int delete_id;
    int found = 0;
    struct Book b;
    FILE *fileptr;
    FILE *tempptr;

    fileptr = fopen("books.txt","r");
    tempptr = fopen("temp.txt","w");

    if(fileptr == NULL || tempptr==NULL){
    
    printf("File Cannot Be Opened\n");
    return;

    }
    
    printf("\nEnter Book ID To Delete: ");
    scanf("%d",&delete_id);

    while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
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

            fprintf(tempptr,"%d | %s | %s | %s | %d | %d\n",
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

    if(found == 1){
        remove("books.txt");
        rename("temp.txt","books.txt");
        printf("\nBook Deleted Successfully!!!\n");
    }
    else{
        remove("temp.txt");
        printf("\nBook Not Found!!!\n");
    }
}

//----------ADD MEMBER-----------
void addMember(){

    printf("\n-----------ADD MEMBER-----------\n");

    struct Member m;
    struct Member check;

    int found = 0;

    FILE *fileptr;
    FILE *checkptr;

    checkptr = fopen("members.txt","r");

    if(checkptr != NULL){

        printf("\nEnter Member ID: ");
        scanf("%d",&m.member_id);

        while(fscanf(checkptr,"%d | %s | %s | %s",
            &check.member_id,
            check.full_name,
            check.contact_number,
            check.email_address) != EOF){

            if(m.member_id == check.member_id){

                found = 1;

                break;
            }
        }

        fclose(checkptr);

        if(found == 1){

            printf("Member ID Already Exists!!!\n");

            return;
        }
    }
    else{

        printf("\nEnter Member ID: ");
        scanf("%d",&m.member_id);
    }

    fileptr = fopen("members.txt","a");

    if(fileptr == NULL){

        printf("File Cannot Be Opened\n");

        return;
    }

    printf("Enter Full Name: ");
    scanf("%s",m.full_name);

    printf("Enter Contact Number: ");
    scanf("%s",m.contact_number);

    printf("Enter Email Address: ");
    scanf("%s",m.email_address);

    fprintf(fileptr,"%d | %s | %s | %s",
        m.member_id,
        m.full_name,
        m.contact_number,
        m.email_address);

    fclose(fileptr);

    printf("\nMember Added Successfully!!!\n");
}

//----------VIEW MEMBER----------
void viewMembers(){

    struct Member m;
    FILE *fileptr;
    fileptr = fopen("members.txt","r");

    if(fileptr == NULL){
    printf("File Cannot Be Opened\n");
    return;
    }

    printf("\n-----------VIEW MEMBER-----------\n");

   while(fscanf(fileptr,"%d | %s | %s | %s",
        &m.member_id,
        m.full_name,
        m.contact_number,
        m.email_address) != EOF){

        printf("Member ID: %d\n",m.member_id);
        printf("Full Name: %s\n",m.full_name);
        printf("Contact Number: %s\n",m.contact_number);
        printf("Email Address: %s\n",m.email_address);

        printf("\n");
    }

    fclose(fileptr);
}

//----------DELETE MEMBER(extra feature)----------
void deleteMember(){

    printf("\n----------DELETE MEMBER----------\n");
    int delete_id;
    int found = 0;
    struct Member m;
    FILE *fileptr;
    FILE *tempptr;

    fileptr = fopen("members.txt","r");
    tempptr = fopen("temp.txt","w");

    if(fileptr == NULL || tempptr==NULL){
    printf("File Cannot Be Opened\n");
    return;
    }

    printf("Enter Member ID To Delete: ");
    scanf("%d",&delete_id);

    while(fscanf(fileptr,"%d | %s | %s | %s",
        &m.member_id,
        m.full_name,
        m.contact_number,
        m.email_address) != EOF){

        if(delete_id == m.member_id){
            found = 1;
        }
        else{

            fprintf(tempptr,"%d | %s | %s | %s\n",
                m.member_id,
                m.full_name,
                m.contact_number,
                m.email_address);
        }
    }

    fclose(fileptr);
    fclose(tempptr);

    if(found == 1){

        remove("members.txt");
        rename("temp.txt","members.txt");

        printf("\nMember Deleted Successfully!!!\n");
    }
    else{

        remove("temp.txt");
        printf("Member Not Found!!!\n");
    }
}

//----------ISSUE BOOK----------
void issueBook(){

    int issue_id;
    int found = 0;
    struct Book b;
    FILE *fileptr;
    FILE *tempptr;

    fileptr = fopen("books.txt","r");
    tempptr = fopen("temp.txt","w");

    if(fileptr == NULL || tempptr==NULL){
    printf("File Cannot Be Opened\n");
    return;
    }

    printf("\n-----------ISSUE BOOK-----------\n");
    printf("\nEnter Book ID To Issue: ");
    scanf("%d",&issue_id);

    while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
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
                printf("Book Issued Successfully!!!\n");
            }
            else{
                printf("Book Not Available!!!\n");
            }
        }

        fprintf(tempptr,"%d | %s | %s | %s | %d | %d\n",
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
    }

    else{
        remove("temp.txt");
        printf("Book Not Found\n");
    }
}

//----------RETURN BOOK----------
void returnBook(){

    int return_id;
    int found = 0;
    struct Book b;
    FILE *fileptr;
    FILE *tempptr;

    fileptr = fopen("books.txt","r");
    tempptr = fopen("temp.txt","w");

    if(fileptr == NULL || tempptr==NULL){
    printf("File Cannot Be Opened\n");
    return;
    }

    printf("\n-----------RETURN BOOK----------\n");
    printf("Enter Book ID To Return: ");
    
    scanf("%d",&return_id);

    while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
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
            printf("Book Returned Successfully!!!\n");
        }

        fprintf(tempptr,"%d | %s | %s | %s | %d | %d\n",
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
    }
    else{
        remove("temp.txt");
        printf("Book Not Found!!!\n");
    }
}

//----------ANALYTICS SECTION-----------
void analytics(){

    printf("\n----------ANALYTICS----------\n");

    struct Book b;
    struct Member m;

    FILE *bookptr;
    FILE *memberptr;
    bookptr = fopen("books.txt","r");
    memberptr = fopen("members.txt","r");

    if(bookptr == NULL || memberptr==NULL){
    printf("File Cannot Be Opened\n");
    return;
    }

    int total_titles = 0;
    int available_books = 0;
    int issued_books = 0;
    int total_members = 0;

    while(fscanf(bookptr,"%d | %s | %s | %s | %d | %d",
        &b.book_id,
        b.book_name,
        b.author_name,
        b.category,
        &b.qty,
        &b.avail_status) != EOF){

        total_titles++;

        available_books += b.qty;

        if(b.avail_status == 0){
            issued_books++;
        }
    }

    fclose(bookptr);

    while(fscanf(memberptr,"%d | %s | %s | %s",
        &m.member_id,
        m.full_name,
        m.contact_number,
        m.email_address) != EOF){

        total_members++;
    }

    fclose(memberptr);

    printf("\nTotal Book Titles: %d\n",total_titles);
    printf("Total Books Available: %d\n",available_books);
    printf("Issued Book Titles: %d\n",issued_books);
    printf("Total Members: %d\n",total_members);

}

//----------GENERATE BOOKS REPORT----------
void generateBooksReport(){

    struct Book b;
    FILE *fileptr;
    FILE *reportptr;

    fileptr = fopen("books.txt","r");
    reportptr = fopen("books_report.txt","w");

    if(fileptr == NULL || reportptr==NULL){
    printf("File Cannot Be Opened\n");
    return;
    }

    fprintf(reportptr,"\n-----------BOOKS RECORD-----------\n\n");

    while(fscanf(fileptr,"%d | %s | %s | %s | %d | %d",
        &b.book_id,
        b.book_name,
        b.author_name,
        b.category,
        &b.qty,
        &b.avail_status) != EOF){

        fprintf(reportptr,"Book ID: %d\n",b.book_id);
        fprintf(reportptr,"Book Name: %s\n",b.book_name);
        fprintf(reportptr,"Author Name: %s\n",b.author_name);
        fprintf(reportptr,"Category: %s\n",b.category);
        fprintf(reportptr,"Quantity: %d\n",b.qty);
        fprintf(reportptr,"Availability: %d\n",b.avail_status);
        fprintf(reportptr,"\n");
    }

    fclose(fileptr);
    fclose(reportptr);
    printf("Books Report Generated Successfully!!!\n");
}

//----------GENERATE MEMBERS REPORT----------
void generateMembersReport(){

    struct Member m;
    FILE *fileptr;
    FILE *reportptr;

    fileptr = fopen("members.txt","r");
    reportptr = fopen("members_report.txt","w");

    if(fileptr == NULL || reportptr==NULL){
        printf("File Cannot Be Opened\n");
        return;
    }
    

    fprintf(reportptr,"\n-----------MEMBERS RECORD-----------\n\n");

    while(fscanf(fileptr,"%d | %s | %s | %s",
        &m.member_id,
        m.full_name,
        m.contact_number,
        m.email_address) != EOF){

        fprintf(reportptr,"Member ID: %d\n",m.member_id);
        fprintf(reportptr,"Full Name: %s\n",m.full_name);
        fprintf(reportptr,"Contact Number: %s\n",m.contact_number);
        fprintf(reportptr,"Email Address: %s\n",m.email_address);

        fprintf(reportptr,"\n");
    }

    fclose(fileptr);
    fclose(reportptr);
    printf("Members Report Generated Successfully!!!\n");
}

//----------MAIN FUNCTION----------
int main(){
    int choice;
    while(1){
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Add Member\n");
        printf("7. View Members\n");
        printf("8. Delete Member\n");
        printf("9. Issue Book\n");
        printf("10.Return Book\n");
        printf("11.Analytics Section\n");
        printf("12.Generate Books Report\n");
        printf("13.Generate Members Report\n");
        printf("14.Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                addBook();
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
                viewMembers();
                break;

            case 8:
                deleteMember();
                break;

            case 9:
                issueBook();
                break;
                
            case 10:
                returnBook();
                break;
            case 11:
                analytics();
                break;

            case 12:
                generateBooksReport();
                break;

            case 13:
                generateMembersReport();
                break;

            case 14:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}