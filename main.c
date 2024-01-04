
#include <stdio.h>
#include <string.h>
#define MAX_MOVIES 100
#define MAX_ACTORS 100

struct Actor {
    char Name[50];
    char Nationality[50];
    int BirthYear;
};


struct Movie {
    char Title[100];
    int ReleaseYear;
    struct Actor Actors[MAX_ACTORS];
    int NumActors;
};

// Function to input actor details
void inputActor(struct Actor *actor) {
printf("\nPlease enter the name ");
scanf("%s", (*actor).Name); 

printf("Please enter the Nationality ");
scanf("%s", (*actor).Nationality);

printf("Please enter the birthyear of the actor ");
scanf("%d", &(*actor).BirthYear);


  
}

// Function to input movie details
void inputMovie(struct Movie *movie) {
  printf("Please enter the title of the movie: ");
  scanf("%s", (*movie).Title);

  printf("Please enter the release year: ");
  scanf("%d", &(*movie).ReleaseYear);

  
  printf("Please enter the number of actors: ");
  scanf("%d", &(*movie).NumActors);

  for (int i=0; i<(*movie).NumActors; i++) {
    printf("Please enter Actor %d\n", i+1);
    inputActor(&(*movie).Actors[i]);
  }
  
}

// Function to display actor details
void displayActor(struct Actor actor) {
    printf("The name of the actor is: %s\n", actor.Name);
    printf("The nationality of the actor is: %s\n", actor.Nationality);
    printf("The birthyear of the actor is: %d\n", actor.BirthYear);
}

// Function to display movie details
void displayMovie(struct Movie movie) {
  printf("The Title of the movie is: %s\n", movie.Title);
  printf("The release year of the movie is: %d\n", movie.ReleaseYear);
  printf("The number of actors of the movie is: %d\n", movie.NumActors);
  
  for (int i=0; i<movie.NumActors; i++) {
  displayActor(movie.Actors[i]);
}

}
// Function to search movies by actor
void searchMoviesByActor(struct Movie movies[], int numMovies, char actorName[]) {
  int count =0; 
  for (int i=0; i<numMovies; i++) {
      for (int j=0; j<movies[i].NumActors; j++) {
      if (strcmp(actorName, movies[i].Actors[j].Name) == 0) {
        printf("%s\n", movies[i].Title);
        count++;
        }
      }
   }
   if (count ==0) {
    printf("There are no actors belonging to this nationality");
    }  
}

// Function to search actors by nationality
void searchActorsByNationality(struct Movie movies[], int numMovies, char nationality[]) {
    int count =0;  
    for (int i=0; i<numMovies; i++) {
      for (int j=0; j<movies[i].NumActors; j++) {
      if (strcmp(nationality, movies[i].Actors[j].Nationality) == 0) {
        count++;
        printf("%s\n", movies[i].Actors[j].Name);
        }
      }
   }
  if (count ==0) {
    printf("There are no actors belonging to this nationality");
    }  
  }


// Function to search movies by release year
void searchMoviesByYear(struct Movie movies[], int numMovies, int releaseYear) {
  int count = 0;  
  for (int i=0; i<numMovies; i++) {
    if (releaseYear==movies[i].ReleaseYear) {
      displayMovie(movies[i]);
      count++;  
      }
    }
if (count ==0) {
  printf("There are no movies with that release year");
  }
}

// Function to list movies by same actor and year
void listMoviesBySameActorAndYear(struct Movie movies[], int numMovies, char actorName[], int releaseYear) {
   int count =0; 
  for (int i=0; i<numMovies; i++) {
      for (int j=0; j<movies[i].NumActors; j++) {
      if (strcmp(actorName, movies[i].Actors[j].Name) == 0 && releaseYear == movies[i].ReleaseYear) {
        printf("%s\n", movies[i].Title);
        count++;
        }
      }
   }
   if (count ==0) {
    printf("There are no actors who starred that year");
    }  
}



int main() {
    struct Movie movies[MAX_MOVIES];
    int numMovies = 0;

    printf("Movie and Actor Database\n");
    printf("------------------------\n");

    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);
    getchar(); // Consume newline character

    printf("\n");

    for (int i = 0; i < numMovies; i++) {
        printf("Movie %d:\n", i + 1);
        inputMovie(&movies[i]);
        printf("\n");
    }

    printf("Movie Details:\n");
    for (int i = 0; i < numMovies; i++) {
        displayMovie(movies[i]);
    }

    char actorName[50];
    printf("Enter the actor name to search for: ");
    scanf(" %[^\n]s", actorName);
    printf("\n");
    searchMoviesByActor(movies, numMovies, actorName);

    char nationality[50];
    printf("Enter the nationality to search for: ");
    scanf(" %[^\n]s", nationality);
    printf("\n");
    searchActorsByNationality(movies, numMovies, nationality);

    int releaseYear;
    printf("Enter the release year to search for: ");
    scanf("%d", &releaseYear);
    printf("\n");
    searchMoviesByYear(movies, numMovies, releaseYear);

    printf("Enter the actor name to search for: ");
    scanf(" %[^\n]s", actorName);
    printf("Enter the release year to search for: ");
    scanf("%d", &releaseYear);
    printf("\n");
    listMoviesBySameActorAndYear(movies, numMovies, actorName, releaseYear);

    return 0;
}
