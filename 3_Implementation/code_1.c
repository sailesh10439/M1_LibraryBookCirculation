#include<stdio.h>
#include<stdlib.h>
struct book{
char AuthName[20];  
char BookName[20];
int count;
struct book* next;
};
struct student{
char name[20];
char phonenumber[11];
char AuthName[20];
char BookName[20];
int id;
struct student* next;
};
struct book* insert_into_books(struct book* book_head, char AuthorName[], char BookName[], int count)
{
struct book* temp = book_head;
while(temp!=NULL){
if(strcmp(temp->AuthName,AuthorName)==0 && strcmp(temp->BookName,BookName)==0)
{
break;
}
temp = temp->next;
}
if(temp==NULL){
struct book* newnode = (struct book*)malloc(sizeof(struct book));
strcpy(newnode->AuthName,AuthorName);
strcpy(newnode->BookName,BookName);
newnode->count = count;
newnode->next = book_head;
book_head = newnode;
return book_head;
}
temp->count = temp->count + count;
return book_head;
}
struct book* delete_book(struct book* book_head, char AuthorName[], char BookName[]){
struct book* temp = book_head;
while(temp!=NULL){
if(strcmp(temp->AuthName,AuthorName)==0 && strcmp(temp->BookName,BookName)==0){
break;
}
temp = temp->next;
}
if(temp==NULL){
printf("Book not present to delete\n\n\n");
return book_head;
}
if(temp->count==0){
printf("Book not present to delete\n\n\n");
return book_head;
}
temp->count = temp->count - 1;
printf("Book Deleted\n\n\n");
return book_head;
}
struct student* issue_book(struct student* student_head, struct book* book_head, char AuthorName[], char BookName[], char StudentName[], char phonenumber[], int id){
struct book* temp = book_head;
while(temp!=NULL){
if(strcmp(temp->AuthName,AuthorName)==0 && strcmp(temp->BookName,BookName)==0){
break;
}
temp = temp->next;
}
if(temp==NULL){
printf("Sorry!! Book not present\n\n\n");
return student_head;
}
if(temp->count==0){
printf("Sorry!! Book not present\n\n\n");
return student_head;
}
temp->count = temp->count - 1;
struct student* newnode = (struct student*)malloc(sizeof(struct student));
strcpy(newnode->name,StudentName);
strcpy(newnode->phonenumber,phonenumber);
strcpy(newnode->AuthName,AuthorName);
strcpy(newnode->BookName,BookName);
newnode->id = id;
newnode->next = student_head;
student_head = newnode;
printf("Book Issued. Happy Reading!!!!\n\n\n");
return student_head;
}
struct student* submit_book(struct student* student_head, struct book* book_head, char AuthorName[], char BookName[], char StudentName[], char phonenumber[], int id){
struct student* temp = student_head;
while(temp!=NULL){
if(strcmp(temp->name,StudentName)==0 && strcmp(temp->phonenumber,phonenumber)==0&&temp->id==id&&strcmp(temp->AuthName,AuthorName)==0&&strcmp(temp->BookName,BookName)==0) break;
temp = temp->next;
}
if(temp==NULL){
printf("Sorry!! Entered details are wrong. Please try again\n\n\n");
return student_head;
}
struct book* temp2 = book_head;
while(temp2!=NULL){
if(strcmp(temp2->AuthName,AuthorName)==0 && strcmp(temp2->BookName,BookName)==0) break;
temp2 = temp2->next;
}
temp2->count = temp2->count + 1;
if(student_head==temp){
student_head = student_head->next;
free(temp);
printf("Book submitted Successfully\n\n\n");
return student_head;
}
struct student* temp3 = student_head;
while(temp3->next!=temp) temp3 = temp3->next;
temp3->next = temp->next;
free(temp);
printf("Book submitted Successfully\n\n\n");
return student_head;
}
int main(){
printf("\n\n\n");
printf("Welcome to Student Library Management System\n\n\n");
struct book* book_head = NULL;
struct student* student_head = NULL;
while(1){
printf("1. Add Book\n");
printf("2. Delete Book\n");
printf("3. Issue Book\n");
printf("4. Submit Book\n");
printf("5. View Books\n");
printf("6. View issued Books\n");
printf("7. Exit\n");
printf("Enter your choice : ");
int num;
scanf("%d",&num);
if(num==1){
char AuthorName[20];
char BookName[20];
int count;
printf("Please enter Author Name : ");
scanf("%s",AuthorName);
printf("Please enter Book Name : ");
scanf("%s",BookName);
printf("Please enter Book Count : ");
scanf("%d",&count);
book_head = insert_into_books(book_head,AuthorName,BookName,count);
printf("Book Added Successfully\n\n\n");
}
else if(num==2){
char AuthorName[20];
char BookName[20];
printf("Please enter Author Name : ");
scanf("%s",AuthorName);
printf("Please enter Book Name : ");
scanf("%s",BookName);
book_head = delete_book(book_head,AuthorName,BookName);
}
else if(num==3){
char AuthorName[20];
char BookName[20];
char StudentName[20];
char phonenumber[15];
int id;
printf("Please enter Author Name : ");
scanf("%s",AuthorName);
printf("Please enter Book Name : ");
scanf("%s",BookName);
printf("Please enter student name : ");
scanf("%s",StudentName);
printf("Please enter student phone number : ");
scanf("%s",phonenumber);
printf("Please enter student id : ");
scanf("%d",&id);
student_head = issue_book(student_head,book_head,AuthorName,BookName,StudentName,phonenumber,id);
}
else if(num==4){
char AuthorName[20];
char BookName[20];
char StudentName[20];
char phonenumber[15];
int id;
printf("Please enter Author Name : ");
scanf("%s",AuthorName);
printf("Please enter Book Name : ");
scanf("%s",BookName);
printf("Please enter student name : ");
scanf("%s",StudentName);
printf("Please enter student phone number : ");
scanf("%s",phonenumber);
printf("Please enter student id : ");
scanf("%d",&id);
student_head = submit_book(student_head,book_head,AuthorName,BookName,StudentName,phonenumber,id);
}
else if(num==5){
struct book* temp = book_head;
if(temp==NULL) printf("No books to show\n");
else{
while(temp!=NULL){
if(temp->count!=0) printf("Book Name : %s, Author Name : %s, Book Count : %d\n", temp->BookName, temp->AuthName, temp->count);
temp = temp->next;
}
}
printf("\n");
}
else if(num==6){
struct student* temp = student_head;
if(temp==NULL) printf("No books Issued!!\n");
else{
while(temp!=NULL){
printf("Student Name : %s, Student Phone Number : %s, Student id : %d, Book Author Name : %s, Book Name : %s\n",temp->name, temp->phonenumber,temp->id, temp->AuthName,temp->BookName);
temp = temp->next;
}
}
}
else if(num==7){
printf("\n\n\nClosing Student Library Management System\n\n\n");
break;
}
}
}

