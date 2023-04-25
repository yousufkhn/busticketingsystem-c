// header files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

// variable definitions

// function definitions
int menu();
void createAccount();
void login();
void manageBus();
void adminLogin();
void userMenu();
void bookTicket();
void cancelTicket();
void adminMenu();

// main function
void mainMenu()
{
    system("cls");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*      Welcome to Our Bus Ticketing System   *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("\nPress any key to continue...");
    getchar();
    system("cls");
    while (1)
    {
        switch (menu())
        {
        case 1:
            // printf("Create New Account Case\n");
            createAccount();
            break;
        case 2:
            // printf("Login Case\n");
            login();
            break;
        case 3:
            // printf("Admin Login Case\n");
            adminLogin();
            break;
        case 4:
            printf("Exit Case\n");
            exit(0);

        default:
            break;
        }
    }
}

// main menu function

int menu()
{
    int choice;
    printf("[1] Create New Account\n");
    printf("[2] Login\n");
    printf("[3] Admin Login\n");
    printf("[4] Exit\n");

    printf("--> ");
    scanf("%d", &choice);
    return choice;
}

void createAccount()
{
    char username[20];
    char password[20];
    char location[] = "data\\users\\";
    int buffer;

    system("cls");
    printf("Enter New UserName : ");
    scanf("%s", username);
    fflush(stdin);
    // getch();

    fflush(stdin);

    strcat(location, username);
    FILE *fptr;
    fptr = fopen(location, "w");

    printf("Create Password : ");
    scanf("%s", password);

    fprintf(fptr, "%s", password);

    fclose(fptr);

    system("cls");
    printf("------------------------------\n");
    printf("Account Created Succesfully!\n");
    printf("------------------------------\n");
}

void login()
{
    char username[20];
    char inputPassword[20];
    char location[] = "data\\users\\";
    char correctPassword[20];
    FILE *fptr;

    system("cls");

    printf("Enter Your UserName : ");
    scanf("%s", username);

    strcat(location, username);

    fptr = fopen(location, "r");

    if (fptr == NULL)
    {
        printf("UserName does not exists\n");
    }

    else
    {
        printf("Enter Your Password: ");
        scanf("%s", inputPassword);
        fscanf(fptr, "%s", correctPassword);
        if (strcmp(inputPassword, correctPassword) == 0)
        {
            printf("SuccessFully Logged In\n");
            userMenu();
        }
        else
        {
            printf("Incorrect Password \n");
            printf("Redirecting to Login Page\n");
        }
    }
}

void adminLogin()
{
    char inputPassword[20];
    char location[] = "data\\users\\admin";
    char correctPassword[20];
    FILE *fptr;

    fptr = fopen(location, "r");

    system("cls");

    printf("Enter Admin Password: ");
    scanf("%s", inputPassword);
    fscanf(fptr, "%s", correctPassword);
    if (strcmp(inputPassword, correctPassword) == 0)
    {
        printf("SuccessFully Logged In\n");
        adminMenu();
    }
    else
    {
        printf("Incorrect Password \n");
        printf("Redirecting to Login Page\n");
    }
}
