#include <stdio.h>
#include <stdlib.h>

#ifdef __WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>

typedef struct {
  char title[100];
  char genre[50];
  char studio[50];
  int episodes;
} Anime;

// Function to capture a single character without Enter on Linux/macOS
char getch() {
  struct termios oldt, newt;
  char ch;

  // Get current terminal settings
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  // Disable canonical mode and echoing
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  // Read a single character
  ch = getchar();

  // Restore original terminal settings
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return ch;
}
#endif

void delay(int seconds) {
#ifdef _WIN32
  Sleep(seconds * 1000); // Sleep in milliseconds
#else
  sleep(seconds); // Sleep in seconds
#endif
}

void main_menu(void) {
  char choice;

  while (1) {
    system("clear");
    printf("Welcome to Anime Recommendationer\n");
    printf("1. Show all animes\n");
    printf("2. Sort by genre\n");
    printf("3. Recommend based on preferences\n");
    printf("4. Export recommendations to file\n");
    printf("5. Exit\n");
    printf("Specify your choice: ");

    // Listens for users input
    // Capture a single key press without Enter
#ifdef _WIN32
    choice = _getch(); // Use _getch for Windows
#else
    choice = getch(); // Use custom getch for Linux/macOS
#endif
    printf("%c\n", choice); // Echo the key for clarity

    switch (choice) {
    case '1':
      printf("You chose to show all animes\n");
      // CODE HERE
      delay(2);
      break;
    case '2':
      printf("You chose to sort by genre\n");
      // CODE HERE
      delay(2);
      break;
    case '3':
      printf("You chose to recommend based on preferences\n");
      // CODE HERE
      delay(2);
      break;
    case '4':
      printf("You chose to export recommendations to file\n");
      // CODE HERE
      delay(2);
      break;
    case '5':
      printf("Bye!");
      delay(2);
      return;
    default:
      printf("Invalid input. Choose between 1-5\n");
      delay(2);
    }
  }
}

int main() {
  main_menu();
  return EXIT_SUCCESS;
}
