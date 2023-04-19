// header files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

// struct defination
struct Bus
{
    char source[50];
    char destination[50];
    int capacity;
    int fare;
};

// function definitions

void addBusDetails();
void deleteBusDetails();
void editBusDetails();

// adminMenu defination

void adminMenu()
{
    int choice;
    while (1)
    {
        printf("\nWelcome to Admin Menu\n");
        printf("[1] Add Bus Details\n");
        printf("[2] Delete Bus Details\n");
        printf("[3] Edit Bus Details\n");
        printf("[4] Exit\n");

        printf("--> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Add Bus Details Case\n");
            addBusDetails(); // Function to add bus details
            break;
        case 2:
            printf("Delete Bus Details Case\n");
            deleteBusDetails(); // Function to delete bus details
            break;
        case 3:
            printf("Edit Bus Details Case\n");
            editBusDetails(); // Function to edit bus details
            break;
        case 4:
            printf("Exiting Admin Menu\n");
            return;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}

// Function to add bus details
void addBusDetails()
{
    char busNumber[10];
    char location[] = "busDetails\\";

    // Get input from the user for the bus details
    struct Bus bus;
    printf("Enter Bus Number: ");
    scanf("%s", busNumber);
    strcat(location, busNumber);
    FILE *fptr;
    fptr = fopen(location, "w");

    printf("Enter Source: ");
    scanf("%s", bus.source);
    printf("Enter Destination: ");
    scanf("%s", bus.destination);
    printf("Enter Capacity: ");
    scanf("%d", &bus.capacity);
    printf("Enter Fare: ");
    scanf("%d", &bus.fare);

    // Write the bus details to the file
    fprintf(fptr, "%s,%s,%d,%d\n", bus.source, bus.destination, bus.capacity, bus.fare);

    // Close the file
    fclose(fptr);

    printf("Bus details added successfully!\n");
}

// function to deleteBusDetails
void deleteBusDetails()
{
    char busNumber[10];
    char location[] = "busDetails\\";

    printf("Enter Bus Number to Delete: ");
    scanf("%s", busNumber);

    strcat(location, busNumber);
    if (remove(location) == 0)
        printf("Bus Details Deleted Successfully!\n");
    else
        printf("Failed to Delete Bus Details.\n");
}

void editBusDetails()
{

    char busNumber[10];
    char source[40];
    char destination[40];
    int capacity;
    int fare;

    printf("Enter Bus Number to Edit Details: ");
    scanf("%s", busNumber);

    char location[] = "busDetails\\";
    strcat(location, busNumber);
    FILE *fptr;
    fptr = fopen(location, "r+");

    fscanf(fptr, "%[^,],%[^,],%d,%d\n", source, destination, &capacity, &fare);
    printf("Existing Details:\n");
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("Capacity: %d\n", capacity);
    printf("Fare: %d\n", fare);

    printf("Enter New Details:\n");
    printf("Enter Source: ");
    scanf("%s", source);
    printf("Enter Destination: ");
    scanf("%s", destination);
    printf("Enter Capacity: ");
    scanf("%d", &capacity);
    printf("Enter Fare: ");
    scanf("%d", &fare);

    rewind(fptr);
    fprintf(fptr, "%s,%s,%d,%d\n", source, destination, capacity, fare);

    fclose(fptr);
    printf("Details updated successfully!\n");
}