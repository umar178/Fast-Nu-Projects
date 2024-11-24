#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 10

typedef struct {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
} Movie;

void addMovie(Movie movies[], int *count);
void searchByGenre(Movie movies[], int count);
void displayAllMovies(Movie movies[], int count);

int main() {
    Movie movies[MAX_MOVIES];
    int movieCount = 0;

    int choice;
    do {
        printf("\nMovie Management System\n");
        printf("1. Add a New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &movieCount);
                break;
            case 2:
                searchByGenre(movies, movieCount);
                break;
            case 3:
                displayAllMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie database is full!\n");
        return;
    }

    printf("Enter movie title: ");
    getchar(); 
    fgets(movies[*count].title, 50, stdin);
    strtok(movies[*count].title, "\n"); 

    printf("Enter genre: ");
    fgets(movies[*count].genre, 30, stdin);
    strtok(movies[*count].genre, "\n");

    printf("Enter director: ");
    fgets(movies[*count].director, 50, stdin);
    strtok(movies[*count].director, "\n");

    printf("Enter release year: ");
    scanf("%d", &movies[*count].releaseYear);

    printf("Enter rating (0.0 to 10.0): ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("Movie added successfully!\n");
}

void searchByGenre(Movie movies[], int count) {
    char genre[30];
    printf("Enter genre to search: ");
    getchar();
    fgets(genre, 30, stdin);
    strtok(genre, "\n");

    printf("\nMovies in the genre '%s':\n", genre);
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("Title: %s, Director: %s, Year: %d, Rating: %.1f\n",
                   movies[i].title, movies[i].director, movies[i].releaseYear, movies[i].rating);
        }
    }
}

void displayAllMovies(Movie movies[], int count) {
    printf("\nAll Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Genre: %s, Director: %s, Year: %d, Rating: %.1f\n",
               movies[i].title, movies[i].genre, movies[i].director, movies[i].releaseYear, movies[i].rating);
    }
}
