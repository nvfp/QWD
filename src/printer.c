#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

typedef struct {
    int r;
    int g;
    int b;
} RGB;

RGB hexToRGB(const char *hexString) {
    RGB rgbColor;
    sscanf(hexString, "%02x%02x%02x", &rgbColor.r, &rgbColor.g, &rgbColor.b);
    return rgbColor;
}


// const char* Colored(const char* text, const char* fg, const char* bg)  # bg currently not supported to reduce complexity
/**
 * fg must be in format "ffffff" (red), "000000" (black), etc. (without "#" prefix)
*/
const char* Colored(const char* text, const char* fg)
{
    RGB fg_rgb = hexToRGB(fg);

    char *result = (char *)malloc(strlen(text) + 200); // Allocate enough space for the result
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    // Create the ANSI escape code for the foreground color
    sprintf(result, "\033[38;2;%d;%d;%dm%s\033[0m", fg_rgb.r, fg_rgb.g, fg_rgb.b, text);

    return result;
}

void printer(const char* text)
{
    char* currentTime = getCurrentTime();
    if (currentTime != NULL) {

        // put the clock at the end for readability
        size_t total_length = strlen(text) + strlen("vvvvvvvvvv  [HH:MM:SS] vvvvvvvvvv") + 1; // +1 for the null terminator
        char* concat = (char*)malloc(total_length);
        if (concat == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }
        // Construct the concatenated string
        sprintf(concat, "vvvvvvvvvv %s [%s] vvvvvvvvvv", text, currentTime);

        const char *coloredText = Colored(concat, "ead76c");
        printf("%s\n", coloredText);
        free(currentTime);
    }
}
void printer_closing(const char* text)
{
    size_t total_length = strlen(text) + strlen("^^^^^^^^^^  ^^^^^^^^^^^^^^^^^^^^^") + 1; // +1 for the null terminator
    char* concat = (char*)malloc(total_length);
    if (concat == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    // Construct the concatenated string
    sprintf(concat, "^^^^^^^^^^ %s ^^^^^^^^^^^^^^^^^^^^^", text);

    const char *coloredText = Colored(concat, "ead76c");
    printf("%s\n", coloredText);
}
void printer_header(const char* command)  // to tell which command is running
{
    char* currentTime = getCurrentTime();
    if (currentTime != NULL) {

        size_t total_length = strlen(command) + strlen("###########  [HH:MM:SS] ###########") + 1; // +1 for the null terminator
        char* concat = (char*)malloc(total_length);
        if (concat == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }
        // Construct the concatenated string
        sprintf(concat, "########### %s [%s] ###########", command, currentTime);

        const char *coloredText = Colored(concat, "669acd");
        printf("%s\n", coloredText);
        free(currentTime);
    }
}
