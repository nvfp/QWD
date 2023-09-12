#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "printer.h"

char* get_last_line_and_remove_from_original(char* str) {
    char* last_line = NULL;
    // Find the last occurrence of '\n' in the string
    char* last_newline = strrchr(str, '\n');
    if (last_newline != NULL) {
        // Extract the last line
        last_line = strdup(last_newline + 1);
        // Remove the last line from the original string
        *last_newline = '\0';
    }
    return last_line;
}
void remove_trailing_newline(char *str) {
    int len = strlen(str);
    // Check if the last character is a newline
    if (len > 0 && str[len - 1] == '\n') {
        // Replace it with a null terminator
        str[len - 1] = '\0';
    }
}

int do_qwd()
{
    printer("Running: git status");
    system("git status");
    printer_closing("Running: git status");

    info(
        "Will execute these commands (destructive):\n"
        "git add .\n"
        "git commit -m \"this is a dev commit\" -m \"<AUTO-GENERATED>\"\n"
        "git branch\n"
        "git status"
    );
    printf("Press Enter to continue, CTRL+C to abort\n");
    
    char usrInput[256];
    if (fgets(usrInput, sizeof(usrInput), stdin) == NULL) {
        // Handle CTRL+C here if needed
        return 1; // Exit with an error code
    }
    debug("Running...");

    printer("Running: git add .");
    system("git add .");
    printer_closing("Running: git add .");

    // <capturing>

    FILE *fp;
    char buffer[1024];
    char *output = NULL;
    size_t output_size = 0;

    fp = popen("git diff --cached --stat --compact-summary", "r");

    if (fp == NULL) {
        perror("popen");
        return 1;
    }
    
    // Read the output in chunks
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        size_t chunk_size = strlen(buffer);
        output = realloc(output, output_size + chunk_size + 1);
        
        if (output == NULL) {
            perror("realloc");
            return 1;
        }
        
        strcpy(output + output_size, buffer);
        output_size += chunk_size;
    }    
    // Close the file pointer
    pclose(fp);


    printer("Running: git commit -m \"this is a dev commit\" -m \"<AUTO-GENERATED>\"");
    remove_trailing_newline(output);  // This is the problem causing why changing the last line seems to have failed.
    char command[102400];
    char *line;
    FILE *pipe;
    char *last_line = output;
    char *current = output;
    while (*current) {
        if (*current == '\n') {
            last_line = current + 1;  // Move to the next character after the newline
        }
        current++;
    }
    char *lastNewline = strrchr(output, '\n');
    if (lastNewline != NULL) {
        // Null-terminate the string at the last newline character
        *lastNewline = '\0';
    }
    sprintf(command, "git commit -m \"this is a dev commit: %s\"", last_line + 1);
    line = strtok(output, "\n");
    while (line != NULL) {
        sprintf(command + strlen(command), " -m \"%s\"", line);
        line = strtok(NULL, "\n");
    }
    pipe = popen(command, "r");
    if (pipe == NULL) {
        printf("Failed to run command\n");
        return 1;
    }
    pclose(pipe);
    free(output);
    printer_closing("Running: git commit -m \"this is a dev commit\" -m \"<AUTO-GENERATED>\"");

    printer("Running: git branch");
    system("git branch");
    printer_closing("Running: git branch");

    printer("Running: git status");
    system("git status");
    printer_closing("Running: git status");
}

int do_d()
{
    printer("Running: git status");
    system("git status");
    printer_closing("Running: git status");

    printer("Running: git branch");
    system("git branch");
    printer_closing("Running: git branch");

    // confirmation
    info(
        "Will execute these commands (destructive):\n"
        "git checkout -b up"
    );
    printf("Press Enter to continue, CTRL+C to abort\n");
    char usrInput[256];
    if (fgets(usrInput, sizeof(usrInput), stdin) == NULL) {
        // Handle CTRL+C here if needed
        return 1; // Exit with an error code
    }
    debug("Running...");
    
    printer("Running: git checkout -b up");
    system("git checkout -b up");
    printer_closing("Running: git checkout -b up");

    return 0;
}

int do_dwd()
{
    printer("Running: git status");
    system("git status");
    printer_closing("Running: git status");

    printer("Running: git branch");
    system("git branch");
    printer_closing("Running: git branch");

    // confirmation
    info(
        "Will execute these commands (destructive):\n"
        "git checkout main\n"
        "git pull\n"
        "git branch -D up\n"
        "git branch"
    );
    printf("Press Enter to continue, CTRL+C to abort\n");
    char usrInput[256];
    if (fgets(usrInput, sizeof(usrInput), stdin) == NULL) {
        // Handle CTRL+C here if needed
        return 1; // Exit with an error code
    }
    debug("Running...");
    
    printer("Running: git checkout main");
    system("git checkout main");
    printer_closing("Running: git checkout main");
    
    printer("Running: git pull");
    system("git pull");
    printer_closing("Running: git pull");
    
    printer("Running: git branch -D up");
    system("git branch -D up");
    printer_closing("Running: git branch -D up");
    
    printer("Running: git branch");
    system("git branch");
    printer_closing("Running: git branch");

    return 0;
}

int do_wdw(int argc, char *argv[])
{
    // // Check if there are at least two arguments (including the program name)
    // if (argc < 2) {
    //     printf("Usage: %s <string1> <string2> ...\n", argv[0]);
    //     return 1; // Exit with an error code
    // }

    // // Calculate the total length of the concatenated string
    // int totalLength = 0;
    // for (int i = 1; i < argc; i++) {
    //     totalLength += strlen(argv[i]);
    // }

    // // Allocate memory for the concatenated string
    // char *concatenated = (char *)malloc(totalLength + 1);

    // // Initialize the concatenated string as an empty string
    // strcpy(concatenated, "");

    // // Concatenate the strings (excluding the first one)
    // for (int i = 1; i < argc; i++) {
    //     strcat(concatenated, argv[i]);
    // }

    // // Print the concatenated string
    // printf("Concatenated string: %s\n", concatenated);

    // // Don't forget to free the allocated memory
    // free(concatenated);





    // debugging purposes
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }




    // if (argc < 2) {
    //     printf("Not enough arguments.\n");
    //     return 1;
    // }
    if (argc < 3) {
        error("need at least 1 commit message word.\n");
        return 1;
    }

    // Initialize an empty string to store the result
    char result[8192] = "";

    // // Start from the second argument (index 1) and concatenate them with spaces
    // for (int i = 1; i < argc; i++) {
    // Start from the 3rd argument (index 2) and concatenate them with spaces
    for (int i = 2; i < argc; i++) {
        strcat(result, argv[i]);
        if (i < argc - 1) {
            strcat(result, " ");
        }
    }

    // Print the concatenated string
    // printf("Concatenated arguments: %s\n", result);

    char command[9000];
    sprintf(command, "git commit -m \"%s\"", result);
    printf("command: %s\n", command);

    printer("Running: git status");
    system("git status");
    printer_closing("Running: git status");

    // confirmation
    info("Will execute these commands (destructive):");
    info("git add .");
    info(command);
    printf("Press Enter to continue, CTRL+C to abort\n");
    char usrInput[256];
    if (fgets(usrInput, sizeof(usrInput), stdin) == NULL) {
        // Handle CTRL+C here if needed
        return 1; // Exit with an error code
    }
    debug("Running...");

    printer("Running: git commit");
    system(command);
    printer_closing("Running: git commit");

    return 0;
}

int main(int argc, char *argv[]) {

    struct Logger logger;
    logger.debug = debug;
    logger.info = info;
    logger.warning = warning;
    logger.error = error;

    if (argc == 1) {
        printf(
            "USAGE\n"
            "\n"
            "#Safe commands\n"
            "q   : git rev-list --count HEAD\n"
            "qw  : git branch\n"
            "w   : git log -3\n"
            "wd  : git diff --cached\n"
            "ww  : git status\n"
            "wdwd: git diff --cached --stat --compact-summary\n"
            "qdq : git diff --cached --stat --compact-summary\n"
            "\n"
            "#Destructive\n"
            "qwd: make commit with auto-generated commit message\n"
            "d  : make new branch named 'up'\n"
            "dd : git push origin up\n"
            "dwd: back to main branch\n"
            "wdw: easy commit typing no double quotes needed\n"
        );
        return 0;
    }

    char *command = argv[1];

    if (strcmp(command, "q") == 0) {
        info("git rev-list --count HEAD");
        system("git rev-list --count HEAD");
    } else if (strcmp(command, "qw") == 0) {
        info("git branch");
        system("git branch");
    } else if (strcmp(command, "w") == 0) {
        printer_header("`git log -3`");
        info("git log -3");
        system("git log -3");
    } else if (strcmp(command, "wd") == 0) {
        info("git diff --cached");
        system("git diff --cached");
    } else if (strcmp(command, "ww") == 0) {
        printer_header("`git status`");
        printer("Running: git status");
        // info("git status");
        system("git status");
        printer_closing("Running: git status");
    } else if (strcmp(command, "wdwd") == 0) {
        info("git diff --cached --stat --compact-summary");
        system("git diff --cached --stat --compact-summary");
    } else if (strcmp(command, "qdq") == 0) {
        printer_header("`qdq command..`");

        printer("Running: git status");
        system("git status");
        printer_closing("Running: git status");

        printer("Running: git branch");
        system("git branch");
        printer_closing("Running: git branch");


    } else if (strcmp(command, "qwd") == 0) {
        do_qwd();

    } else if (strcmp(command, "d") == 0) {
        do_d();

    } else if (strcmp(command, "dd") == 0) {
        info("git push origin up");
        system("git push origin up");

    } else if (strcmp(command, "dwd") == 0) {
        do_dwd();

    } else if (strcmp(command, "wdw") == 0) {
        printer_header("`wdw command..`");
        do_wdw(argc, argv);


    } else {
        printf("Invalid command: %s\n", command);
        return 1;
    }

    return 0;
}
