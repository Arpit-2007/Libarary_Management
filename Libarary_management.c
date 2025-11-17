#include <stdio.h>
#include <string.h>

#define MAX 100   // maximum number of books

// Structure to store book information
struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};

// Global variables
struct Book library[MAX];
int count = 0;

// Function declarations
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: 
                printf("Exiting program...\n");
                return 0;
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to add a new book
void addBook() {
    if (count >= MAX) {
        printf("Library is full!\n");
        return;
    }

    struct Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    getchar();

    printf("Enter Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // remove newline

    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0'; // remove newline

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    library[count] = b;
    count++;

    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (count == 0) {
        printf("No books available!\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-10s\n", "ID", "Title", "Author", "Qty");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-20s %-10d\n", 
               library[i].id, library[i].title, library[i].author, library[i].quantity);
    }
}

// Function to search a book by ID
void searchBook() {
    int id, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Quantity: %d\n", library[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Book not found!\n");
}

// Function to issue a book
void issueBook() {
    int id, found = 0;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            found = 1;
            if (library[i].quantity > 0) {
                library[i].quantity--;
                printf("Book issued successfully!\n");
            } else {
                printf("Book not available!\n");
            }
            break;
        }
    }
    if (!found)
        printf("Book not found!\n");
}

// Function to return a book
void returnBook() {
    int id, found = 0;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            library[i].quantity++;
            printf("Book returned successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Book not found!\n");
}
