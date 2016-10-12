#include <stdio.h>
#include <string.h>
#include <ctype.h>

// READ BEFORE YOU START:
// This program begins by displaying a menu to the user with options to add a movie, delete a movie, and search for a movie in a list. Your job is to implement the 
// add(), search(), recommendation(), and delete_one() functions. Each has specific instructions included in comments above of the function. You will be doing all
// of this using a linked list, unlike in hw05 where you were using an array of structures. You should begin by tracing the helper function that is already 
// implemented for you. Not only will this help you in understanding how to define and use pointers, it will help you understand what this program does. 
// You should not change any of the code that you are given, only implement code where you are asked.

#pragma warning(disable : 4996) 

typedef enum { action = 0, comedy, thriller } genre;// enumeration type genre

char* gen[] = { "action", "comedy", "thriller" };// used for easy of printing genre

struct movie {
    struct movie* next;
    char name[100];
    int rating;
    genre type;
} *list = NULL;

// forward declarations
void flush();
void branching(char c);
void helper(char c);
//These have been ordered in a way of suggested completion. You will need to complete search() before you start delete_one()
void add(struct movie* new_movie);                  // 15 points
struct movie* search(struct movie* movie);          // 10 points
struct movie* recommendation(struct movie* movie);  // 10 points
void delete_one(struct movie* movie);               // 15 points


int main()
{
    char ch = 'i';

    ungetc('\n', stdin);                    // inject input buffer with a return character

    printf("Welcome to the movie manager!\n\n");

    do {
        printf("Please enter your selection\n");
        printf("\ta: add a movie\n");
        printf("\td: delete a movie\n");
        printf("\ts: search for movie rating\n");
        printf("\tr: recommend a movie based on genre\n");
        printf("\tq: quit \n");

        flush();                            // flush input buffer
        ch = tolower(getchar());
        branching(ch);
    } while (ch != 113);

    return 0;
}

// flush input buffer
void flush()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// branch to different tasks
void branching(char c)
{
    switch (c) {
    case 'a':
    case 'd':
    case 's':
    case 'r':
        helper(c);
        break;
    case 'q':
        break;
    default:
        printf("Invalid input!\n");
    }

    if (c == 's' || c == 'd'){
        ungetc('\n', stdin);
    }
}

// Q0. The helper function is used to determine how much information is needed, and which function to send that information to.
// It uses pointers that are returned from these functions to produce the correct ouput.
// There is no implementation needed here, but you should study this function and know how it works.
// It is always helpful to understand how the code works before implementing new features.
// Do not change anything in this function or the test cases will fail.
void helper(char c) {

    char* input_genre = (char*)malloc(100);
    int valid_genre = -1;

    // create new temporary pointers
    struct movie *ptr = (struct movie *)malloc(sizeof(struct movie));
    struct movie *temp;

    // if you are adding a movie or requesting a recommendation
    if (c == 'a' || c == 'r')
    {
        // stores the genre of the movie into pointer
        while (valid_genre < 0)
        {
            printf("What is the genre of the movie? (action/comedy/thiller):\n");
            scanf("%s", input_genre);

            if (strcmp(input_genre, "action") == 0)
            {
                valid_genre++;
                ptr->type = (genre)0;// type casting
            }
            else if (strcmp(input_genre, "comedy") == 0)
            {
                valid_genre++;
                ptr->type = (genre)1;
            }
            else if (strcmp(input_genre, "thriller") == 0)
            {
                valid_genre++;
                ptr->type = (genre)2;
            }
            else
                printf("Please enter a valid genre (action/comedy/thiller).\n");// error handling

            if (c == 'r' && valid_genre == 0)
            {
                temp = recommendation(ptr);// send genre to recommendation function
                if (temp == NULL) printf("There are no movies with that genre.\n");
                else printf("The highest rated %s movie in your list is %s\n", gen[temp->type], temp->name);
                return;// exit back to menu
            }
        }
    }

    //stores the name of the movie into pointer
    printf("Enter the name of the movie:\n");
    flush();
    fgets(ptr->name, sizeof(ptr->name), stdin);

    // if you are searching
    if (c == 's')
    {
        temp = search(ptr);
        if (temp == NULL)
        {
            printf("Movie not found.\n");
        }
        else
            printf("The rating for that movie is: %d\n", temp->rating);
        return;// exit back to menu
    }// send name to search function

    // if you are deleting
    else if (c == 'd')
    {
        temp = search(ptr);// check to see if movie is in list
        if (temp == NULL)// movie is not in list
        {
            printf("Movie not found.\n");
        }
        else
        {
            delete_one(temp);
            printf("Movie been deleted.\n");
        }
        return;// exit back to menu
    }// send name to delete_one function if it exists

    int input = -1;

    //stores the rating of the movie into pointer
    while (input < 1 || input > 10)
    {
        printf("What is your rating of the movie? (1-10):\n");
        scanf("%d", &input);

        if (input >= 1 && input <= 10)
            ptr->rating = input;
        else
            printf("Please enter a rating between 1 and 10.\n");
    }

    // always set next equal to NULL before adding to a list so that if it is placed at the end of the list, you know where to stop traversing
    ptr->next = NULL;

    add(ptr);
}

// Q1: add (15)
// Similar to hw05, you will be inserting into a list of movies sorted by their rating.
// Differing from hw05, there is no limit to how many movies can be in this list.
// "list" is initialized as NULL. Use this as your 'head' of the list and insert into it accordingly. 
// There are 4 possibilities for inserting into the list:
//  - inserting into an empty list
//  - inserting at the beginning of the list
//  - inserting inbetween 2 nodes in the list
//  - inserting at the end of the list
// The short segment of code is given to you to help you get started. You will need to define new variables and pointers as needed.
//
// If a movie with the same rating already exists in the list, you should replace that position with the new movie, and move that movie to the next position.
//
// For example, if you have the list that contains:
//
//  Movie: The Hunger Games
//  Rating: 8
//
//  Movie: Mission Impossible
//  Rating: 7
//
// And you were to add the movie "The Sound of Music" with a rating of 8, your new list should be:
//
//  Movie: The Sound of Music
//  Rating: 8
//
//  Movie: The Hunger Games
//  Rating: 8
//
//  Movie: Mission Impossible
//  Rating: 7
void add(struct movie* new_movie)
{

    if (list == NULL) // inserting into an empty list
    {
        list = new_movie;
        new_movie->next = NULL;
        return;
    }
    struct movie* nextMovie = list;

    while (nextMovie->rating>new_movie->rating) {
        nextMovie = nextMovie->next;
    }
    struct movie* n = nextMovie->next;
    nextMovie->next = new_movie;
    nextMovie->next = n;
    return;
}

// Q2: search (10)
// In this function, you are passed a struct movie* parameter named movie to find the rating of a requested movie.
// Stored inside the location this pointer is pointing to, is the name of the movie that you want to find in your list (movie->name)
// You need to return a pointer to a node in your list that contains that movie's information (that will include movie->rating)
// (You must return a pointer to a node in your list! Do not create a temporary pointer that just includes the rating, it will fail test cases!)
// To find that pointer, you need to traverse your list. If that movie name does not exist in your list, return NULL.
struct movie* search(struct movie* movie)
{
    // CODE HERE
    struct movie* nextMovie = list;
    while (nextMovie->name != movie->name && nextMovie!=NULL) {
        nextMovie = nextMovie->next;
    }
    return nextMovie;
}

// Q3: recommendation (10)
// In this function, you are passed a struct movie* parameter named movie to find the highest rated movie of a given genre.
// Stored inside the location this pointer is pointing to, is a genre. Notice that genre is an enumeration.
// You will use this genre to find the highest rated movie in your list containing that genre. (Don't over-complicate this, your list is already sorted by rating!)
// You need to return a pointer to a node in your list that contains that movie's information (name and rating)
// (You must return a pointer to a node in your list! Do not create a temporary pointer that just includes the name and rating, it will fail test cases!)
// If no movies of that genre exist in your list, return NULL.
struct movie* recommendation(struct movie* movie)
{
    // CODE HERE
    struct movie* nextMovie = list;
    while (nextMovie->type != movie->type && nextMovie!=NULL) {
        nextMovie = nextMovie->next;
    }
    return nextMovie;
}

// Q4: delete_one (15)
// In this function, you are passed a struct movie* parameter named movie to delete the corresponding movie in your list.
// Stored inside the location this pointer is pointing to, is the name of the movie that you want to delete from your list (movie->name)
// Because the search function is called before this function to see if the movie exists, you can assume that the movie exists in the list.
// You will need to find the movie and delete it using proper memory management to ensure no memory leaks.
void delete_one(struct movie* movie)
{
    // CODE HERE
    struct movie* nextMovie = list;
    while (nextMovie->next->name != movie->name) {
        nextMovie = nextMovie->next;
    }
    struct movie* del = nextMovie->next;
    nextMovie->next = nextMovie->next->next;
    free(del);
    return;
}