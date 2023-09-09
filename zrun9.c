// this file is for dev process so we can run the main.c easier
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  // to get terminal size

int main(int argc, char *argv[]) {

    if (system("gcc src/main.c src/utils.c -o test_exe") != 0) {
        fprintf(stderr, "Compilation failed\n");
        return 1;
    }
    
    // Build the command to run test_exe and pass all command-line arguments
    char command[256] = "test_exe"; // Assuming a maximum of 256 characters for the command
    for (int i = 1; i < argc; i++) {
        // Append each argument to the command
        snprintf(command + strlen(command), sizeof(command) - strlen(command), " %s", argv[i]);
    }

    // get terminal size (Windows)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    int cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    // printf("Terminal size: %dx%d\n", rows, cols);

    // separator (#TODO: refactor this soon)
    for (int i = 0; i < cols; i++) {
        printf("=");
    }
    printf("\n");

    if (system(command) != 0) {

        // separator (#TODO: refactor this soon)
        for (int i = 0; i < cols; i++) {
            printf("=");
        }
        fprintf(stderr, "\nExecution failed\n");
        return 1;
    }

    // separator (#TODO: refactor this soon)
    for (int i = 0; i < cols; i++) {
        printf("=");
    }
    fprintf(stderr, "\nExecution done\n");

    return 0;
}
