// header files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "admin.c"

// variable definitions

// function definitions
int menu();
void createAccount();
void login();
void manageBus();
void adminLogin();

// main function
void start()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("Create New Account Case\n");
            createAccount();
            break;
        case 2:
            printf("Login Case\n");
            login();
            break;
        case 3:
            printf("Admin Login Case\n");
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

// create new account function

void createAccount()
{
    char username[20];
    char password[20];
    char location[] = "users\\";

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
    // printf("%s", password);

    fprintf(fptr, "%s", password);

    fclose(fptr);
    // printf("%s", location);
}

void login()
{
    char username[20];
    char inputPassword[20];
    char location[] = "users\\";
    char rightPassword[20];
    FILE *fptr;

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
        fscanf(fptr, "%s", rightPassword);
        if (strcmp(inputPassword, rightPassword) == 0)
        {
            printf("SuccessFully Logged In\n");
        }
        else
        {
            printf("Incorrect Password \n");
            printf("Redirecting to Menu\n");
        }
    }
}

void adminLogin()
{
    char inputPassword[20];
    char location[] = "users\\admin";
    char rightPassword[20];
    FILE *fptr;

    fptr = fopen(location, "r");

    printf("Enter Admin Password: ");
    scanf("%s", inputPassword);
    fscanf(fptr, "%s", rightPassword);
    if (strcmp(inputPassword, rightPassword) == 0)
    {
        printf("SuccessFully Logged In\n");
        adminMenu();
    }
    else
    {
        printf("Incorrect Password \n");
        printf("Redirecting to Menu\n");
    }
}