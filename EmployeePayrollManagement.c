/*Employee Payroll Management System (Using Linked List)
You are developing an Employee Payroll Management System using a singly linked list to store
and manage employee salary details. The system should allow the following operations:
1. Add a new employee's salary details (insert at the end).
2. Remove an employee by their Employee ID (deletion).
3. Search for an employee by their Employee ID (traversing and comparing).
4. Display all employees sorted by Employee ID.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int id;
    char name[100];
    int salary;
    struct node* next;
};

struct node* head = NULL;

void addEmployee() {
    struct node *newNode;
    newNode= malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Employee Name: ");
    scanf("%s", newNode->name);

    printf("Enter Salary: ");
    scanf("%d", &newNode->salary);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Employee added successfully.\n");
}

void removeEmployee() {
    int id;
    printf("Enter Employee ID to remove: ");
    scanf("%d", &id);

    struct node *temp = head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Employee removed successfully.\n");
}

void searchEmployeeById() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    struct node* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Employee Found - ID: %d, Name: %s, Salary: %d\n", temp->id, temp->name, temp->salary);
            return;
        }
        temp = temp->next;
    }

    printf("No employee found with ID: %d\n", id);
}

void displayEmployeesSorted() {
    if (head == NULL) {
        printf("No employee records to display.\n");
        return;
    }

    struct node* sorted = NULL;
    struct node* current = head;

    while (current != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        *newNode = *current;
        newNode->next = NULL;

        if (sorted == NULL || newNode->id < sorted->id) {
            newNode->next = sorted;
            sorted = newNode;
        } else {
            struct node* temp = sorted;
            while (temp->next != NULL && temp->next->id < newNode->id)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }

        current = current->next;
    }

    printf("\nEmployees (Sorted by ID):\n");
    struct node* temp = sorted;
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Salary: %d\n", temp->id, temp->name, temp->salary);
        temp = temp->next;
    }

    while (sorted != NULL) {
        struct node* del = sorted;
        sorted = sorted->next;
        free(del);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Employee Payroll Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Search Employee by ID\n");
        printf("4. Display All Employees (Sorted by ID)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee();
            break;
            case 2: removeEmployee();
            break;
            case 3: searchEmployeeById();
            break;
            case 4: displayEmployeesSorted();
            break;
            case 5: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

