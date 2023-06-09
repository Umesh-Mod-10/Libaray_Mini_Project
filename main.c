#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    char publication[50];
    char domain[50];
    int id;
    int amount;
};

struct Library {
    struct Book books[50];
    int count;
};

void addBook(struct Library *library, char *title, char *author,char *publication,char *domain, int id, int amount) {
    struct Book newBook = {0};
    strcpy(newBook.title, title);
    strcpy(newBook.author, author);
    strcpy(newBook.publication, publication);
    strcpy(newBook.domain, domain);
    newBook.id = id;
    newBook.amount = amount;
    library->books[library->count++] = newBook;
    puts("\t\t\t\tBook added successfully!\n");
}

void deleteBook(struct Library *library, int id) {
    for (int i = 0; i < library->count; i++) {
        if (library->books[i].id == id) {
            library->books[i] = library->books[--library->count];
            printf("Book deleted successfully!\n\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void searchBook(struct Library *library, int id) {
    for (int i = 0; i < library->count; i++) {
        if (library->books[i].id == id) {
            printf("Book found!\n");
            printf("Title: %s\nAuthor: %s\nPublication: %s\nDomain: %s\nAmount: %d\n", library->books[i].title, library->books[i].author, library->books[i].publication, library->books[i].domain, library->books[i].amount);
            return;
        }
    }
    printf("Book not found.\n");
}


int main() {
    struct Library library = {0};
    int choice, id, amount;
    struct library *l;
    char title[50], author[50];
    char domain[50],publication[50];
    printf("\t\t\t\t\t\tWELCOME TO C_SAMPLE LIBRARY\n");
    begin:
    do {
        printf("\n\nTo Add a book to the list enter 1\n");
        printf("To Delete a book from the list enter 2\n");
        printf("To Search a book from the library enter 3\n");
        printf("To Exit enter 4\n\n\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter Title: ");
                scanf("%s",title);
                printf("Enter Author: ");
                scanf("%s",author);
                printf("Enter Publications: ");
                scanf("%s",publication);
                printf("Enter Domain: ");
                scanf("%s",domain);
                printf("Enter Amount: ");
                scanf("%d",&amount);
                printf("Enter ID: ");
                scanf("%d",&id);
                for(int i = 0; i < 50; i++)
                    if(library.books[i].id == id)
                    {
                        printf("The id is already taken.");
                        goto begin;
                    }
                addBook(&library, title, author,publication,domain, id, amount);
                break;
            case 2:
                printf("Enter id: ");
                scanf("%d", &id);
                deleteBook(&library, id);
                break;
            case 3:
                printf("Enter id: ");
                scanf("%d", &id);
                searchBook(&library, id);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("\n\nInvalid choice. Please enter a valid value.\n");
                goto begin;
        }
    } while (choice != 4);

    return 0;
}
//Creator: Umesh Ramanathan
//GitHub: Umesh-Modded-10