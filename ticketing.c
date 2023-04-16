// header files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

// functions decleration
void bookTickets();
int mainMenu();
void displayBusRoutes();

// variables declaration
struct busRoutes
{
    char source[20];
    char destination[20];
    float fare;
};

void bookTickets()
{
    while (1)
    {
        switch (mainmenu())
        {
        case 1:
            printf("View Available Buses Case");
            break;
        case 2:
            printf("Login Case\n");
            break;
        case 3:
            printf("Exit Case\n");
            exit(0);
        default:
            break;
        }
    }
}

int mainMenu()
{
}

// chat gpt

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_ROUTES 100
// #define MAX_LENGTH 50

// // Structure for storing a single bus route
// struct bus_route {
//     char source[MAX_LENGTH];
//     char destination[MAX_LENGTH];
//     float fare;
// };

// // Function for adding a new bus route to the file
// void add_bus_route(struct bus_route route) {
//     FILE *fp;
//     fp = fopen("bus_routes.txt", "a");
//     if (fp == NULL) {
//         printf("Error opening file\n");
//         return;
//     }
//     fprintf(fp, "%s %s %.2f\n", route.source, route.destination, route.fare);
//     fclose(fp);
// }

// // Function for displaying all bus routes stored in the file
// void display_bus_routes() {
//     FILE *fp;
//     struct bus_route route;
//     fp = fopen("bus_routes.txt", "r");
//     if (fp == NULL) {
//         printf("Error opening file\n");
//         return;
//     }
//     printf("Source\tDestination\tFare\n");
//     while (fscanf(fp, "%s %s %f\n", route.source, route.destination, &route.fare) != EOF) {
//         printf("%s\t%s\t\t%.2f\n", route.source, route.destination, route.fare);
//     }
//     fclose(fp);
// }

// // Main function to add bus routes
// int main() {
//     int option;
//     struct bus_route route;
//     printf("Welcome to the Bus Route Management System\n");
//     do {
//         printf("\nPlease select an option:\n");
//         printf("1. Add a new bus route\n");
//         printf("2. Display all bus routes\n");
//         printf("3. Exit\n");
//         scanf("%d", &option);
//         switch (option) {
//             case 1:
//                 printf("Enter source: ");
//                 scanf("%s", route.source);
//                 printf("Enter destination: ");
//                 scanf("%s", route.destination);
//                 printf("Enter fare: ");
//                 scanf("%f", &route.fare);
//                 add_bus_route(route);
//                 printf("Bus route added successfully!\n");
//                 break;
//             case 2:
//                 display_bus_routes();
//                 break;
//             case 3:
//                 printf("Exiting program...\n");
//                 break;
//             default:
//                 printf("Invalid option\n");
//         }
//     } while (option != 3);
//     return 0;
// }

// chat gpt 2

// Function for checking if a bus route exists in the file
// void check_bus_route_exists() {
//     FILE *fp;
//     struct bus_route route;
//     char source[MAX_LENGTH], destination[MAX_LENGTH];
//     int found = 0;
//     fp = fopen("bus_routes.txt", "r");
//     if (fp == NULL) {
//         printf("Error opening file\n");
//         return;
//     }
//     printf("Enter source: ");
//     scanf("%s", source);
//     printf("Enter destination: ");
//     scanf("%s", destination);
//     while (fscanf(fp, "%s %s %f\n", route.source, route.destination, &route.fare) != EOF) {
//         if (strcmp(route.source, source) == 0 && strcmp(route.destination, destination) == 0) {
//             printf("Bus route exists with fare %.2f\n", route.fare);
//             found = 1;
//             break;
//         }
//     }
//     if (!found) {
//         printf("Bus route not found\n");
//     }
//     fclose(fp);
// }
