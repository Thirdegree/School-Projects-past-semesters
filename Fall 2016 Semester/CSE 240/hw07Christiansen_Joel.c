// Your name here

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// READ BEFORE YOU START:
// This homework is built on homework 06. The given program is an updated version of hw06 solution. It begins by displaying a menu to the user 
// with the add() function from the last homework, as well as some new options: add an actor/actress to a movie, display a list of movies for 
// an actor/actress, delete all movies, display all movies, display a movie by index, and display a list of movies by genre. Your job is to 
// implement the delete_all(), print_by_index(), print_by_genre(), add_actor(), and find_actor() functions. Each has specific instructions 
// included in comments above of the function. A new struct has been inlcuded, which you will use to create a linked list of actors for each 
// movie in your list. You should begin by tracing the helper2 and print_helper functions that are already implemented for you. Not only will 
// this help you in understanding how to define and use pointers, it will help you understand what this program does. You should not change any 
// of the code that you are given, only implement code where you are asked. You may assume that no 2 movies will have the same name.

#pragma warning(disable : 4996) 

typedef enum { action = 0, comedy, thriller } genre;// enumeration type genre

char* gen[] = { "action", "comedy", "thriller" };// used for easy of printing genre

// contains movie information
struct movie {
    struct movie* next;
    struct actor* actors; // added for hw07
    char name[100];
    int rating;
    genre type;
} *list = NULL;

// added for hw07
// contains actor information
struct actor {
    struct actor* next;
    char name[100];
};

// forward declarations
void flush();  
void branching(char c);
void helper(char c);
void add(struct movie* new_movie);

// added for hw07
void helper2(char);
void print_helper(struct movie*);
struct movie* print_all(struct movie*);
void delete_all(struct movie*);
void delete_all_actors(struct actor*);
struct movie* print_by_index(int);
struct movie* print_by_genre(int);
int add_actor(char*, char*);
struct movie* find_actor(char*);

const size_t line_size = 300; // global line_sized used in helper2() function to read input line

int main()
{
    char ch = 'i';

    ungetc('\n', stdin); // inject input buffer with a return character

    printf("Welcome to the movie manager!\n\n");

    do {
        printf("Please enter your selection\n");
        printf("\ta: add a movie\n");

        // added for hw07
        printf("\tb: add an actor/actress to a movie\n");
        printf("\tc: display a list of movies for an actor/actress\n");
        printf("\td: delete all movies\n");
        printf("\te: display all movies\n");
        printf("\tf: display a movie by index\n");
        printf("\tg: display a list of movies by genre\n");

        printf("\tq: quit \n");

        flush(); // flush input buffer
        ch = tolower(getchar());
        branching(ch);
    } while (ch != 113);

    return 0;
}

// flush input buffer. You could use the predefined fflush()
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
        helper(c);
        break;
    case 'b': // add an actor/actress to a movie
    case 'c': // display a list of movies for an actor/actress
    case 'd': // delete all movies
    case 'e': // display all movies
    case 'f': // display a movie by index
    case 'g': // display a list of movies by genre
        helper2(c);
        break;
    case 'q':
        break;
    default:
        printf("Invalid input!\n");
    }

    if (c == 'b' || c == 'c'){
        ungetc('\n', stdin);
    }
}

// (Used for hw06 implementation)
// The helper function is used to determine how much information is needed, and which function to send that information to.
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
    if (c == 'a')
    {
        // stores the genre of the movie into pointer
        printf("What is the genre of the movie? (action/comedy/thriller):\n");
        while (valid_genre < 0)
        {
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
                printf("Please enter a valid genre (action/comedy/thriller).\n");// error handling
        }
    }

    //stores the name of the movie into pointer
    printf("Enter the name of the movie:\n");
    flush();
    fgets(ptr->name, sizeof(ptr->name), stdin);

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
    // added for hw07
    ptr->actors = NULL;

    add(ptr);
}

// See hw06 for full functionality
void add(struct movie* new_movie)
{
    struct movie* follow = list;

    if (list == NULL) // inserting into an empty list
    {
        list = new_movie;
        return;
    }
    else if (list->rating < new_movie->rating) // inserting at the beginning of the list
    {
        new_movie->next = list;
        list = new_movie;
        return;
    }

    struct movie* temp = list->next;

    while (temp != NULL) // inserting inbetween 2 nodes in the list
    {
        if (temp->rating <= new_movie->rating)
        {
            new_movie->next = temp;
            follow->next = new_movie;
            return;
        }
        follow = temp;
        temp = temp->next;
    }
    follow->next = new_movie; // inserting at the end of the list
}

// used for hw07
// The helper2 function is used to determine how much information is needed, and which function to send that information to.
// It uses pointers that are returned from these functions to produce the correct ouput.
// There is no implementation needed here, but you should study this function and know how it works.
// It is always helpful to understand how the code works before implementing new features.
// Do not change anything in this function or the test cases will fail.
void helper2(char c)
{
    int index = 0; // used to print an index
    int genre = -1;
    char* movie_name = (char*)malloc(sizeof(char*));
    char* actor_name = (char*)malloc(sizeof(char*));

    if (c == 'b') // add an actor/actress to a movie
    {
        printf("Enter the actor/actress name:\n");
        flush();
        fgets(actor_name, line_size, stdin);

        printf("Enter the movie they were they in:\n");
        fgets(movie_name, line_size, stdin);

        int result = add_actor(movie_name, actor_name);

        if (result == 0)
        {
            printf("That movie is not in your list, please add that movie first.\n\n");
        }
        else if (result == 1)
        {
            printf("Actor added.\n\n");
        }
        else if (result == -1)
        {
            printf("That actor is already listed for that movie.\n\n");
        }
    }

    if (c == 'c')  // display a list of movies for an actor/actress
    {
        printf("Enter the actor/actress name:\n");
        flush();
        fgets(actor_name, line_size, stdin);

        struct movie* temp = find_actor(actor_name);

        if (temp != NULL)
        {
            printf("That actor/actress is in:\n");
            print_helper(temp);
        }
        else printf("That actor is not in any movies in your list.\n\n", index);

    }

    if (c == 'd')  // delete all movies
    {
        delete_all(list);
        printf("All movies deleted.\n");
    }

    if (c == 'e')  // display all movies
        print_helper(print_all(list));

    if (c == 'f')  // display a movie by index
    {
        printf("Enter an index to print:\n");

        while (index < 1)
        {
            scanf("%d", &index);
            if (index < 1)
                printf("Enter an index greater than 0:\n");
        }

        struct movie* temp = print_by_index(index);

        if (temp != NULL)
        {
            struct actor* ptr = temp->actors;

            printf("Movie at index %d:\n", index);
            printf("Movie: %s", temp->name);
            printf("Rating: %d\n", temp->rating);
            printf("Genre: %s\n", gen[temp->type]);
            printf("Actor/Actress: ");
            if (ptr == NULL)
            {
                printf("no actor/actress listed.\n\n");
            }
            else
            {
                printf("\n");
                while (ptr != NULL)
                {
                    printf("%s", ptr->name);
                    ptr = ptr->next;
                }
                printf("\n");
            }
        }
        else printf("There is no movie at index %d.\n\n", index);
    }

    if (c == 'g')  // display a list of movies by genre
    {
        printf("Select a genre to display\n0. action\n1. comedy\n2. thriller\n");

        while (genre < 0 || genre > 2)
        {
            scanf("%d", &genre);
            if (genre < 0 || genre > 2)
                printf("Select a valid option:\n");
        }

        struct movie* temp = print_by_genre(genre);

        if (temp != NULL)
        {
            printf("%s movies:\n", gen[genre]);
            print_helper(temp);
        }
        else printf("There are no %s movies in the list.\n\n", gen[genre]);
    }
}

// print_helper prints movie information from the parameter "moviesToPrint" in an organized format
// If moviesToPrint is NULL, it prints, "Your list is empty!"
// print_all and print_by_genre (which is to be implemented) use this function to print a desired list of movies
void print_helper(struct movie* moviesToPrint)
{
    struct actor* ptr;

    if (moviesToPrint == NULL)
    {
        printf("Your list is empty!\n");
        return;
    }

    while (moviesToPrint != NULL) // traverse list of movies
    {
        ptr = moviesToPrint->actors;
        printf("Movie: %s", moviesToPrint->name);
        printf("Rating: %d\n", moviesToPrint->rating);
        printf("Genre: %s\n", gen[moviesToPrint->type]);
        printf("Actor/Actress: ");
        if (ptr == NULL)
        {
            printf("no actor/actress listed.\n\n");
        }
        else
        {
            printf("\n");
            while (ptr != NULL) // traverse list of actors
            {
                printf("%s", ptr->name);
                ptr = ptr->next;
            }
            printf("\n");
        }
        moviesToPrint = moviesToPrint->next;
    }

}

// print_all simply returns the parameter that it is given to print all of the movies' information in the parameter.
struct movie* print_all(struct movie* movies)
{
    return movies;
}

// Q1 delete_all (5)
// Recursively delete the entire list of movies. The parameter movies is a pointer to your list.
// You MUST use recursion, or you will recieve a 0 for this part. You must must use comments to indicate the steps of the fantastic four step approach.
// (hint: don't forget to set your list back to NULL)
//this works
void delete_all(struct movie* movies) //formulate the size n problem
{
    // add your code
    if (movies==NULL) {
        return;
    }
    delete_all_actors(movies->actors);
    if (movies->next==0) { //stopping condition & return value
        list = NULL;
        free(movies);
        return; 
    }
    delete_all(movies->next); //Formulate size m problem
    free(movies);  //construct solution.
    return;
}

void delete_all_actors(struct actor* actors) {
    if (actors==NULL) {
        return;
    }
    if (actors->next==0) { //stopping condition & return value
        list = NULL;
        free(actors);
        return; 
    }
    delete_all_actors(actors->next); //Formulate size m problem
    free(actors);  //construct solution.
    return;
}

// Q2 print_by_index (5)
// Traverse your list and return a pointer to a movie in your list at the idex of the given parameter.
// For example, if the index = 1, then you would return the first movie in the list. (At the head, and also, the highest rated movie).
// If the list does not contain the amount that is given by the index, return NULL.
//   For exmample, if you have a list of 1 movie, and index = 2, return NULL.
struct movie* print_by_index(int index)
{
    // add your code
    int i = 1;
    struct movie* current = list;
    while (i<index && current->next!=0) {
        current = current->next;
        i++;
    }
    if (i==index && current!=0) {
        return current;
    }
    return NULL;
}

// Q3 print_by_genre (10)
// Traverse your list and return a new list filled with movies that are of the type given by the integer type parameter.
// Use type-casting to compare the integer value to the genre value associated with each pointer in the list. (see the helper() function for an example)
// The movies in the returned list should contain all of the information available for that movie (ex: name, rating, actors, etc.)
// The list of movies that you return should be in order of rating from highest to lowest (the head should be the highest rated movie.)
// (Keep in mind that your "list" is already sorted by rating!)
// If no movies in your list are of the genre type given by your parameter "type", then return NULL
struct movie* print_by_genre(int type)
{
    // add your code
    struct movie* follow = list;
    struct movie* returnlist = NULL;

    if (list == NULL) // returning for an empty list
    {
        return NULL;
    }

    while (returnlist==NULL && follow!=NULL) { //first item.
        if ((int)follow->type == type) {
            returnlist = follow;
            
        }
        follow = follow->next;
    }
    struct movie* temp = returnlist;

    while (follow!=NULL) // inserting inbetween 2 nodes in the list
    {
        if ((int)follow->type == type)
        {
            temp->next=follow;
            temp = temp->next;
        }
        
        follow = follow->next;
    }
    if (temp!=NULL) {
        temp->next = NULL;
    }
    return returnlist;
}

// Q4 add_actor (15)
// Traverse your list to find a movie in your list with the name that matches the parameter "movie_name"
// Then, add the actor/actress to linked list of "actors" in your linked list of "movies"
// The list of actor/actress should be in alphabetical order. Do this by using the strcmp() method
// For an example of how to access and modify actor information, refer to the helper2 and print_helper functions
//  For example: If John Cena is already in your list of actor/actress, and you add the actor Jon Cena, the list would print as:

//   Actor/Actress: 
//   John Cena
//   Jon Cena

// If the movie is in the list, add the actor/actress to the actor/actress list, and return 1
// If the movie is not in the list, return 0
// Do not add duplicate actor/actress. If John Cena is already in your list of actor/actress, and actor_name == John Cena, return -1;
// NOTE : You can assume that no 2 movies in the list will have the same name
int add_actor(char* movie_name, char* actor_name) //done
{
    // add your code
    struct movie* new_list = list;
    while (new_list!=NULL) {
        if (strcmp(new_list->name,movie_name)==0){
            
            struct actor* new =  (struct actor *)malloc(sizeof(struct actor));
            strcpy(new->name, actor_name);

            if (new_list->actors == NULL) {
                printf("TEST3HERE\n");
                new_list->actors = new;
                return 1;
            }
            if (strcmp(new_list->actors->name, actor_name)==0){
                return -1;
            }
            while (new_list->actors->next!=NULL && strcmp(actor_name, new_list->actors->name)<0) {
                printf("TEST2 HERE\n");
                new_list->actors = new_list->actors->next;
            }

            
            
            struct actor* temp = new_list->actors->next;
            new_list->actors-> next = new;
            new_list->actors->next->next=temp;
            return 1;
        }
        new_list = new_list->next;
        printf("Test1 HERE\n");
    }
    return 0;
}

// Q5 find_actor (15)
// Traverse your list and return a new list filled with movies that include the actor name given by the parameter actor_name
// The movies in the returned list should contain all of the information available for that movie (ex: name, rating, other actors, etc.)
// The list of movies that you return should be in order of rating from highest to lowest (the head should be the highest rated movie.)
// (Keep in mind that your "list" is already sorted by rating!)
// If no movies in your list contain the actor name given by the parameter actor_name, then return NULL
// (hint: this is similar to your print_by_genre function)
struct movie* find_actor(char* actor_name)
{
    // add your code
   struct movie* follow = list;
    struct movie* returnlist = NULL;

    if (list == NULL) // returning for an empty list
    {
        return NULL;
    }

    while (returnlist==NULL && follow!=NULL) { //first item.
        if (strcmp(actor_name, follow->name)==0) {
            returnlist = follow;
            
        }
        follow = follow->next;
    }
    struct movie* temp = returnlist;

    while (follow!=NULL) // inserting inbetween 2 nodes in the list
    {
        if (strcmp(actor_name, follow->name)==0)
        {
            temp->next=follow;
            temp = temp->next;
        }
        
        follow = follow->next;
    }
    if (temp!=NULL) {
        temp->next = NULL;
    }
    return returnlist;
}