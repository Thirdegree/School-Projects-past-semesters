// Your name here
// This homework exercise array of structures and their operations, flush, and file

// READ BEFORE YOU START:
// This program begins by displaying a menu to the user with options to add a movie, display the list, or quit and save the list. Your job is to implement the 
// add(), display(), save(), and load() functions. Each has specific instructions included in comments above the scope of the function. A few things to consider 
// are that you are given a global integer named count and an integer max defined in main. Use count to keep track of the amount of movies are stored in your list.
// max is the maximum amount of movies that you can store in your list. It is important for you to use these accordingly. Calling save() and load() has already been
// implemented for you. You only need to complete the function. You should not change any of the code that you are given, only implement code where you are asked.

#include <stdio.h>   
#include <string.h>
#include <ctype.h>

#pragma warning(disable: 4996)

struct movie {
    char name[100];
    int rating;
};

int count = 0; // The amount of movies currently stored in your list (initialized at 0)

struct movie list[30]; // initialize movie list

// forward declaration of functions
void flush();
void branching(char, int);
void read(int);
void add(char*, int, struct movie*, int);
void display();
void save(char* fileName);
void load(char* fileName);

int main()
{
    int max = 5; // The maximum total amount of movies that you can store in your list

    load("Favorite_Movie_List.txt");

    char ch = 'i';

    ungetc('\n', stdin); // inject input buffer with a return character

    printf("Welcome to your favorite movie manager!\n\n");

    do
    {
        printf("Please enter your selection:\n");
        printf("\ta: add a new movie to your list\n");
        printf("\td: display the movies in your list\n");
        printf("\tq: quit and save your list\n");

        flush(); // flush input buffer
        ch = tolower(getchar());
        branching(ch, max);
    } while (ch != 113);


    save("Favorite_Movie_List.txt");

    return 0;
}

void flush()
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// branch to different tasks
void branching(char c, int max)
{
    switch (c)
    {
    case 'a':
        read(max);
        break;
    case 'd':
        display();
        break;
    case 'q':
        break;
    default:
        printf("Invalid input!\n");
    }
}

// This function is already implemented for you. It prompts for and stores a movie along with a rating for that movie.
// It then calls the add() function (which is to be implemented) sending over those parameters (along with list, and max).
void read(int max)
{
    int input = -1;
    int rating;
    char movie_name[100];

    printf("Enter the name of the movie:\n");
    flush();
    fgets(movie_name, sizeof(movie_name), stdin);

    while (input < 1 || input > 10)                                 //This does not work as intended.
    {
        printf("What is your rating of the movie? (1-10):\n");
        scanf("%d", &input);

        if (input >= 1 && input <= 10)
            rating = input;
        else
            printf("Please enter a rating between 1 and 10.\n");
    }

    add(movie_name, rating, list, max);
}

//  Q1: add (30)
//  This function is used to insert a new movie name (char* movie_name) and rating (int rating) into your list.
//  Your list of movies should be sorted by rating, so you need to search for the correct index to add into your list.
//  (index 0 should be the highest rated movie, index 1 should be the 2nd highest rated movie, etc.)
//  Use the global integer variable "count" to keep track of how many movies you have in your list.
//
//  In main, 'max' is defined as the maximum total amount of movies that you can store in your list. 'max' has been passed to this function, use it accordingly.
//  Use 'max' so that if you were to change the value of max, your program would work the same (graders will change max for testing your sort).
//  You can change the value of 'max' in main in order to test your code.
//
//  If a movie is entered with a rating that is too low to make the list, print: "\nThis movie is not one of your favorites!\n\n".
//  (hint: you should increase count for each movie you add, but not if you are adding to a list that already contains the 'max' amount of movies)
//
//  You are not required to use pointer operations for your list but you may do so if you'd like. list/max are only passed to this function for testing purposes.
//
//  If a movie with the same rating already exists in the list, you should replace that index with the new movie, and move that movie to the next index.
//
//  For example, if you have the list that contains:
//
//      Movie: The Hunger Games
//      Rating: 8
//
//      Movie: Mission Impossible
//      Rating: 7
//
//  And you were to add the movie "The Sound of Music" with a rating of 8, your new list should be:
//
//      Movie: The Sound of Music
//      Rating: 8
//
//      Movie: The Hunger Games
//      Rating: 8
//
//      Movie: Mission Impossible
//      Rating: 7
//
//  (Unless max is set to 2, then it would just contain the 2 highest rated movies)
void add(char* movie_name, int rating, struct movie* list, int max)
{
    // CODE HERE
    struct movie n;
    strcpy(n.name, movie_name);
    n.rating = rating;
    int oldCount = count;
    int added = 0;
    if (count == 0) {
        list[0] = n;
        count++;
    } else {    
        int i;
        for (i=0;i<count;i++){ 
            if (list[i].rating <= n.rating) {
                if (i==max-1) {
                    list[i] = n;
                    added = 1;
                    count++;
                    break;
                }
                struct movie old = list[i];
                int k;
                for (k=i+1;k<=max;k++) {
                    struct movie ne = list[k];
                    list[k] = old;
                    old = ne;
                }
                list[i] = n;
                added = 1;
                count++;
                break;
            }
        }
        if (count == oldCount) {
            list[count] = n;
            added = 1;
            count++;

        }
    }
    if (!added) {
        printf("\nThis movie is not one of your favorites!\n\n");
    }
    
}

//  Q2: display (10)
//  Traverse your list and print the movies with their coorespoonding rating in the following format:
//
//      Movie: The Sound of Music
//      Rating: 8
//
//      Movie: The Hunger Games
//      Rating: 8
//
//      Movie: Mission Impossible
//      Rating: 7
//
//  If the list is empty, print: "Your list is empty!\n"
//  (hint: Use can use your global integer value "count" to see how many movies are in your list)
void display()
{
    // CODE HERE
    if (count == 0) {
        printf("Your list is empty!\n");
    }
    int i;
    for (i=0;i<count;i++){
        if (list[i].rating >0) {
            printf("Movie: %s\nRating: %d\n\n",list[i].name, list[i].rating);
        }
    }
}

//  Q3: save (5)
//  Save your list to the text file name stored in "fileName"
//  A portion of the code has already been implemented for you.
//  All you need to do is write the name of the movie and the rating to a file.
void save(char* fileName)
{
    FILE* file;

    file = fopen(fileName, "wb");
    if (file == NULL)
    {
        return;
    }
    else
    {
        fwrite(&count, sizeof(count), 1, file);
        int i;
        for (i = 0; i < count; i++)
        {
            //CODE HERE
            fprintf(file, "%s\n", list[i].name);
            fprintf(file, "%d\n", list[i].rating);
        }
        fclose(file);
    }
}

//  Q4: load (5)
//  Load your list from the text file name stored in "fileName"
//  A portion of the code has already been implemented for you.
//  All you need to do is read the name of the movie and the rating from a file.
void load(char* fileName)
{
    FILE* file;

    file = fopen(fileName, "rb");
    if (file == NULL)
    {
        return;
    }
    else
    {
        fread(&count, sizeof(count), 1, file);
        int i;
        for (i = 0; i < count; i++)
        {
            //CODE HERE
            struct movie n;
            fscanf(file, "%s\n", &n.name);
            int rating = -1;
            fscanf(file, "%d\n", &n.rating);
        }
        fclose(file);
    }
}