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
    int availableSeats;
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
        printf("[3] Exit\n");

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
    system("cls");
    char busNumber[10];
    char location[] = "busDetails\\bus_details.txt";

    // Get input from the user for the bus details
    struct Bus bus;
    printf("Enter Bus Number: ");
    scanf("%s", busNumber);
    printf("Enter Source: ");
    scanf("%s", bus.source);
    printf("Enter Destination: ");
    scanf("%s", bus.destination);
    printf("Enter Capacity: ");
    scanf("%d", &bus.capacity);
    printf("Enter Fare: ");
    scanf("%d", &bus.fare);
    printf("Enter Available Seats: ");
    scanf("%d", &bus.availableSeats);

    FILE *fptr;
    fptr = fopen(location, "a");

    // Write the bus details to the file
    fprintf(fptr, "%s,%s,%s,%d,%d,%d,\n", busNumber, bus.source, bus.destination, bus.capacity, bus.fare, bus.availableSeats);

    // Close the file
    fclose(fptr);

    printf("Bus details added successfully!\n");
}

// function to deleteBusDetails
void deleteBusDetails()
{
    char busNumber[10];
    char location[] = "busDetails\\bus_details.txt";

    printf("Enter Bus Number to Delete: ");
    scanf("%s", busNumber);

    char tempLocation[] = "busDetails\\temp.txt";
    FILE *fptr1, *fptr2;
    fptr1 = fopen(location, "r");
    fptr2 = fopen(tempLocation, "w");

    char buffer[500];
    while (fgets(buffer, 500, fptr1))
    {
        if (strstr(buffer, busNumber) == NULL)
        {
            fputs(buffer, fptr2);
        }
    }

    fclose(fptr1);
    fclose(fptr2);

    if (remove(location) == 0 && rename(tempLocation, location) == 0)
        printf("Bus Details Deleted Successfully!\n");
    else
        printf("Failed to Delete Bus Details.\n");
}
