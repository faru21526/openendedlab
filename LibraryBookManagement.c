/*Library Book Management System
You are developing a simple Library Book Management System that keeps track of books
available in a library. The system should allow the following operations:
1. Add a new book to the collection.
2. Remove a book by its unique book ID.
3. Search for a book by its title.
4. Display all books in sorted order by book ID.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char titleName[100];
    char author[100];
} Book;

Book library[MAX_BOOKS];
int count = 0;

void addBook() {
    if (count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Title: ");
    scanf("%s", library[count].titleName);

    printf("Enter Author Name: ");
    scanf("%s", library[count].author);

    count++;
    printf("Book added successfully.\n");
}

void removeBook() {
    int id, found = 0;
    printf("Enter Book ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }
            count--;
            printf("Book removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

void searchBookById() {
    int id, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("Book Found - ID: %d, Title: %s, Author: %s\n",
                   library[i].id, library[i].titleName, library[i].author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with ID: %d\n", id);
    }
}

void sortBooksById() {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (library[j].id < library[minIndex].id) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Book temp = library[i];
            library[i] = library[minIndex];
            library[minIndex] = temp;
        }
    }
}

void displayBooks() {
    if (count == 0) {
        printf("No books in library.\n");
        return;
    }

    sortBooksById();
    printf("\nBooks in Library (Sorted by Book ID):\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n",
               library[i].id, library[i].titleName, library[i].author);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book by ID\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: removeBook(); break;
            case 3: searchBookById(); break;
            case 4: displayBooks(); break;
            case 5: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}


