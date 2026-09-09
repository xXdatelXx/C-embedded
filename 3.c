#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
    char title[100];
    float price;
    int pages;
    char language[30];
    float weight;
    int year;

    struct Book *next;
} Book;

Book *createBook(const char *title, float price, int pages,
                 const char *language, float weight, int year)
{
    Book *book = malloc(sizeof(Book));

    if (book == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }

    strcpy(book->title, title);
    book->price = price;
    book->pages = pages;
    strcpy(book->language, language);
    book->weight = weight;
    book->year = year;

    book->next = NULL;

    return book;
}

void addBook(Book **head, Book *book)
{
    if (*head == NULL)
    {
        *head = book;
        return;
    }

    Book *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = book;
}

void printBooks(Book *head)
{
    Book *current = head;

    while (current != NULL)
    {
        printf("-----------------------------\n");
        printf("Title: %s\n", current->title);
        printf("Price: %.2f\n", current->price);
        printf("Pages: %d\n", current->pages);
        printf("Language: %s\n", current->language);
        printf("Weight: %.0f g\n", current->weight);
        printf("Year: %d\n", current->year);

        current = current->next;
    }

    printf("-----------------------------\n");
}

void freeBooks(Book *head)
{
    Book *current = head;

    while (current != NULL)
    {
        Book *next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    Book *head = NULL;

    addBook(&head, createBook(
                       "Harry Potter and the Philosopher's Stone",
                       15.99,
                       223,
                       "English",
                       350,
                       1997));

    addBook(&head, createBook(
                       "Harry Potter and the Chamber of Secrets",
                       16.99,
                       251,
                       "English",
                       400,
                       1998));

    addBook(&head, createBook(
                       "Harry Potter and the Prisoner of Azkaban",
                       17.99,
                       317,
                       "English",
                       450,
                       1999));

    addBook(&head, createBook(
                       "Harry Potter and the Goblet of Fire",
                       19.99,
                       636,
                       "English",
                       700,
                       2000));

    addBook(&head, createBook(
                       "Harry Potter and the Order of the Phoenix",
                       21.99,
                       766,
                       "English",
                       800,
                       2003));

    addBook(&head, createBook(
                       "Harry Potter and the Half-Blood Prince",
                       20.99,
                       607,
                       "English",
                       750,
                       2005));

    addBook(&head, createBook(
                       "Harry Potter and the Deathly Hallows",
                       22.99,
                       607,
                       "English",
                       750,
                       2007));

    printBooks(head);

    freeBooks(head);

    return 0;
}