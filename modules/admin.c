// header files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

// function definitions

void addBusDetails();

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
            // deleteBusDetails(); // Function to delete bus details
            break;
        case 3:
            printf("Edit Bus Details Case\n");
            // editBusDetails(); // Function to edit bus details
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

struct Bus
{
    char source[50];
    char destination[50];
    int capacity;
    int fare;
};

// Function to add bus details
void addBusDetails()
{
    char busNumber[10];
    char location[] = "busDetails\\";
    // Open the file for appending
    // FILE *fp = fopen("bus_details.txt", "a");

    // Check if the file was opened successfully
    // if (fp == NULL)
    // {
    //     printf("Error: Unable to open file!\n");
    //     return;
    // }

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
