

void userMenu()
{
    int choice;
    while (1)
    {

        printf("\nWelcome to User Menu\n");
        printf("[1] Book Ticket\n");
        printf("[2] Cancel Ticket\n");
        printf("[3] Exit\n");

        printf("--> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // printf("Book Ticket Case\n");
            bookTicket();
            break;
        case 2:
            // printf("Cancel Ticket Case\n");
            cancelTicket();
            break;
        case 3:
            printf("Exiting User Menu\n");
            return;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}

void bookTicket()
{
    char source[50], destination[50];
    int seats;
    system("cls");
    printf("Enter your source: ");
    scanf("%s", source);
    printf("Enter your destination: ");
    scanf("%s", destination);

    char location[] = "data\\busDetails\\bus_details.txt";
    FILE *fptr;
    fptr = fopen(location, "r");

    if (fptr == NULL)
    {
        printf("\nNo buses available!\n");
        return;
    }

    char buffer[500];
    int found = 0;
    system("cls");
    printf("\nAvailable Buses:\n");
    while (fgets(buffer, 500, fptr))
    {
        char *busNumber = strtok(buffer, ",");
        char *busSource = strtok(NULL, ",");
        char *busDestination = strtok(NULL, ",");
        int capacity = atoi(strtok(NULL, ","));
        int fare = atoi(strtok(NULL, ","));
        int availableSeats = atoi(strtok(NULL, ","));

        if (strcmp(busSource, source) == 0 && strcmp(busDestination, destination) == 0)
        {
            found = 1;
            printf("\nBus Number: %s\n", busNumber);
            printf("Source: %s\n", busSource);
            printf("Destination: %s\n", busDestination);
            printf("Capacity: %d\n", capacity);
            printf("Fare: %d\n", fare);
            printf("Available Seats: %d\n", availableSeats);

            printf("Enter number of seats to book: ");
            scanf("%d", &seats);

            if (seats > availableSeats)
            {
                printf("Sorry, only %d seats are available!\n", availableSeats);
            }
            else
            {
                int ticketID = rand();

                char ticketLocation[] = "data\\ticketDetails\\ticket_details.txt";
                FILE *ticketFile;
                ticketFile = fopen(ticketLocation, "a");
                fprintf(ticketFile, "%d,%s,%s,%s,%d,%d,%d\n", ticketID, busNumber, source, destination, seats, fare * seats, 0);
                fclose(ticketFile);

                char tempLocation[] = "data\\busDetails\\temp.txt";
                FILE *fptr1, *fptr2;
                fptr1 = fopen(location, "r");
                fptr2 = fopen(tempLocation, "w");

                char temp[500];
                while (fgets(temp, 500, fptr1))
                {
                    if (strstr(temp, busNumber) != NULL)
                    {
                        int updatedSeats = availableSeats - seats;
                        fprintf(fptr2, "%s,%s,%s,%d,%d,%d,\n", busNumber, busSource, busDestination, capacity, fare, updatedSeats);
                    }
                    else
                    {
                        fputs(temp, fptr2);
                    }
                }

                fclose(fptr1);
                fclose(fptr2);
                fclose(fptr);

                if (remove(location) == 0 && rename(tempLocation, location) == 0)
                {
                    printf("Ticket Booked Successfully!\n Your Ticket ID is : %d\n\n", ticketID);
                    return;
                }
                else
                {
                    printf("Failed to Book Ticket.\n");
                    return;
                }
            }
        }
    }

    if (found == 0)
    {
        printf("\nNo buses found between %s and %s!\n", source, destination);
    }
}

void cancelTicket()
{
    char ticketID[10];
    printf("Enter Ticket ID to Cancel: ");
    scanf("%s", ticketID);

    char location[] = "data\\ticketDetails\\ticket_details.txt";
    char tempLocation[] = "data\\ticketDetails\\temp.txt";
    FILE *fptr1, *fptr2;
    fptr1 = fopen(location, "r");
    fptr2 = fopen(tempLocation, "w");

    char buffer[500];
    while (fgets(buffer, 500, fptr1))
    {
        if (strstr(buffer, ticketID) == NULL)
        {
            fputs(buffer, fptr2);
        }
    }

    fclose(fptr1);
    fclose(fptr2);

    if (remove(location) == 0 && rename(tempLocation, location) == 0)
    {
        printf("Ticket Cancelled Successfully!\n\n");
    }
    else
    {
        printf("Failed to Cancel Ticket.\n\n");
    }
}