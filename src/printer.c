

// DIDNT work
// typedef struct {
//     int r;
//     int g;
//     int b;
// } RGB;

// RGB hex_to_rgb(const char *hex_color) {
//     char color[7];
//     strcpy(color, hex_color);
//     if (color[0] == '#') {
//         memmove(color, color + 1, strlen(color));
//     }
    
//     int r, g, b;
//     sscanf(color, "%2x%2x%2x", &r, &g, &b);
    
//     RGB rgb;
//     rgb.r = r;
//     rgb.g = g;
//     rgb.b = b;
    
//     return rgb;
// }



// next prototypes (ref: https://stackoverflow.com/questions/3723846/convert-from-hex-color-to-rgb-struct-in-c)


// #include <stdio.h>

// // Define the RGB structure
// struct RGB {
//     float r;
//     float g;
//     float b;
// };

// // Function prototype
// struct RGB colorConverter(int hexValue);

// int main() {
//     // int hexValue = 0xFFA500; // Replace with your desired hexadecimal color value
//     int hexValue = 0xFFFFFF; // Replace with your desired hexadecimal color value

//     // Call the colorConverter function
//     struct RGB rgbColor = colorConverter(hexValue);

//     // Print the RGB values
//     printf("R: %.2f, G: %.2f, B: %.2f\n", rgbColor.r, rgbColor.g, rgbColor.b);

//     return 0;
// }

// // Your colorConverter function implementation here
// struct RGB colorConverter(int hexValue) {
//     struct RGB rgbColor;
//     rgbColor.r = ((hexValue >> 16) & 0xFF) / 255.0;  // Extract the RR byte
//     rgbColor.g = ((hexValue >> 8) & 0xFF) / 255.0;   // Extract the GG byte
//     rgbColor.b = (hexValue & 0xFF) / 255.0;          // Extract the BB byte

//     return rgbColor;
// }


// #include <stdio.h>

// int main() {
//     // char *str = "0000FF";
//     // char *str = "FFFFFF";
//     char *str = "000000";
//     int r, g, b;

//     // Use sscanf to parse the hexadecimal string
//     sscanf(str, "%02x%02x%02x", &r, &g, &b);

//     // Print the RGB values
//     printf("R: %d, G: %d, B: %d\n", r, g, b);

//     return 0;
// }


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

// example
// int main() {
//     // char *str = "0000FF";
//     // char *str = "ffffff";
//     char *str = "000000";
//     RGB color = hexToRGB(str);

//     // Print the RGB values
//     printf("R: %d, G: %d, B: %d\n", color.r, color.g, color.b);

//     return 0;
// }




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

        // size_t total_length = strlen(text) + strlen("vvvvvvvvvv [HH:MM:SS]  vvvvvvvvvv") + 1; // +1 for the null terminator
        // char* concat = (char*)malloc(total_length);
        // if (concat == NULL) {
        //     perror("Memory allocation failed");
        //     exit(1);
        // }
        // // Construct the concatenated string
        // sprintf(concat, "vvvvvvvvvv [%s] %s vvvvvvvvvv", currentTime, text);

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
    // const char *coloredText = Colored(text, "ead76c");
    // printf("^^^^^^^^^^^^^^^^^^^^^ %s ^^^^^^^^^^\n", coloredText);

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

        // size_t total_length = strlen(command) + strlen(currentTime) + strlen("########### []  ###########") + 1; // +1 for the null terminator
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
