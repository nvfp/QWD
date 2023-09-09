// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "utils.h"

// int main(int argc, char *argv[]) {

//     struct Logger logger;

//     // Assign the methods to the instance
//     logger.debug = debug;
//     logger.info = info;
//     logger.warning = warning;
//     logger.error = error;

//     // logger.debug("hi");
//     // logger.info("hi");
//     // logger.warning("hi");
//     // logger.error("hi");
//     // logger.debug("hi");

//     // printf("Running...\n");

//     // if (argc == 1) {
//     //     printf("Usage: %s [command]\n", argv[0]);
//     //     return 1;
//     // }

//     char *command = argv[1];

//     printf("Command: %s\n", command);

//     if (strcmp(command, "q") == 0) {
//         system("git rev-list --count HEAD");
//     } else if (strcmp(command, "qw") == 0) {
//         system("git branch");
//     } else if (strcmp(command, "w") == 0) {
//         system("git log -3");
//     } else if (strcmp(command, "wd") == 0) {
//         system("git diff --cached");
//     } else if (strcmp(command, "123") == 0) {
//         char* currentTime = getCurrentTime();
//         if (currentTime != NULL) {
//             printf("Current Time: %s\n", currentTime);
//             free(currentTime);
//         }
//     } else {
//         printf("Invalid command: %s\n", command);
//         return 1;
//     }

//     return 0;
// }

// // COMMANDS = {
// //     'q': "git add .",
// //     'wd': "git status",
// //     'qw': "git diff",
// //     's': "git reset",
// // }

















#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// struct Commands {
//     char key;
//     const char* commandStr;
// };
// struct Commands commands[] = {
//     {'q', "git add ."},
//     {'w', "git status"},
//     {'d', "git diff"},
//     {'s', "git reset"},

//     {'qwd', "git reset"},
// };


// Function to extract the last line from a multiline string
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

int do_qwd()
{
    // info("Running `git status`");
    // system("git status");

    // info(
    //     "Will execute these commands (destructive):\n"
    //     "git add .\n"
    //     "git commit -m \"this is a dev commit\" -m \"<AUTO-GENERATED>\"\n"
    //     "git branch\n"
    //     "git status"
    // );
    // printf("Press Enter to continue, CTRL+C to abort\n");
    
    // char usrInput[256];
    // if (fgets(usrInput, sizeof(usrInput), stdin) == NULL) {
    //     // Handle CTRL+C here if needed
    //     return 1; // Exit with an error code
    // }
    // debug("Running...");
    // // exit(1);  // debugging purposes

    // info("Running `git add .`");
    // system("git add .");

    // // <capturing>

    // FILE *fp;
    // char buffer[1024];
    // char *output = NULL;
    // size_t output_size = 0;

    // // Replace "foo" with the command you want to run
    // fp = popen("git diff --cached --stat --compact-summary", "r");

    // if (fp == NULL) {
    //     perror("popen");
    //     return 1;
    // }
    
    // // Read the output in chunks
    // while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    //     size_t chunk_size = strlen(buffer);
    //     output = realloc(output, output_size + chunk_size + 1);
        
    //     if (output == NULL) {
    //         perror("realloc");
    //         return 1;
    //     }
        
    //     strcpy(output + output_size, buffer);
    //     output_size += chunk_size;
    // }
    
    // // Close the file pointer
    // pclose(fp);
    
    // // Now, 'output' contains the captured output
    // // printf("Captured Output:\n================\n%s\n=========================\n", output);
    
    // // Don't forget to free the dynamically allocated memory
    // // free(output);  // do not free here, free it after doing `git commit`

    // // </capturing>

    // info("Running `git commit -m \"this is a dev commit\" -m \"<AUTO-GENERATED>\"`");
    // // system("git commit -m \"this is a dev commit\" -m \"%s\"", output);  // wrong way
    // // char output[] = "Some dynamic message";
    
    // // char command[512];  // Adjust the size as needed
    // // // Use sprintf to create the formatted string
    // // sprintf(command, "git commit -m \"this is a dev commit\" -m \"%s\"", output);
    // // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    // // char *output = "your_output_string_here";
    // // Calculate the length of the output string
    // int outputLength = strlen(output);
    // // Calculate the total length of the command string
    // int commandLength = outputLength + 50; // 50 for the fixed part of the command
    // // Dynamically allocate memory for the command array
    // char *command = (char *)malloc(commandLength);
    // if (command == NULL) {
    //     fprintf(stderr, "Memory allocation failed.\n");
    //     return 1;
    // }
    // // Use sprintf to create the command
    // snprintf(command, commandLength, "git commit -m \"this is a dev commit\" -m \"%s\"", output);
    // // // Your command is now ready to use
    // // printf("Command: %s\n", command);
    // // // Don't forget to free the dynamically allocated memory
    // // free(command);
    
    // // Execute the command using system
    // int result = system(command);
    // // Check the result if needed
    // if (result == 0) {
    //     printf("Command executed successfully.\n");
    // } else {
    //     printf("Command failed to execute.\n");
    // }
    // free(output);  // here we go

    // info("Running `git branch`");
    // system("git branch");

    // info("Running `git status`");
    // system("git status");








    info("Running `git status`");
    system("git status");

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

    info("Running `git add .`");
    system("git add .");

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


    // store the multi line string to env
    // if (setenv("AUTO_COMMIT_MSG", output, 0) != 0) {
    //     perror("Failed to set environment variable");
    //     return 1;
    // }
    

    info("Running `git commit -m \"this is a dev commit\" -m \"<AUTO-GENERATED>\"`");
    // int command_length = snprintf(NULL, 0, "git commit -m \"this is a dev commit\" -m \"%s\"", output) + 1;
    // char *command = (char *)malloc(command_length);
    // if (command == NULL) {
    //     printf("Memory allocation failed.\n");
    //     return 1;
    // }
    // snprintf(command, command_length, "git commit -m \"this is a dev commit\" -m \"%s\"", output);
    // system(command);
    // free(command);

    // // update
    // char* x = NULL; // Initialize x as a NULL pointer
    // size_t x_size = 0; // Initialize the size of x

    // // Initialize x with the first line of y
    // x = (char*)malloc(strlen("git commit -m \"this is a dev commit\"") + 1);
    // if (x == NULL) {
    //     printf("Memory allocation failed");
    //     return 1;
    // }
    // strcpy(x, "git commit -m \"this is a dev commit\"");

    // // Split y into lines and concatenate each line to x
    // const char* delimiter = "\n";
    // const char* line = strtok((char*)output, delimiter);

    // while (line != NULL) {
    //     // Calculate the new size needed for x
    //     size_t new_size = x_size + strlen(" -m \"") + strlen(line) + strlen("\"") + 1;

    //     // Reallocate memory for x
    //     char* temp = (char*)realloc(x, new_size);
    //     if (temp == NULL) {
    //         perror("Memory reallocation failed");
    //         free(x); // Free previously allocated memory
    //         return 1;
    //     }
    //     x = temp;
        
    //     // Concatenate the current line to x
    //     strcat(x, " -m \"");
    //     strcat(x, line);
    //     strcat(x, "\"");

    //     x_size = new_size;

    //     // Get the next line
    //     line = strtok(NULL, delimiter);
    // }
    // system(x);
    // // Free dynamically allocated memory
    // free(x);


    // char commit_command[102400]; // Adjust the buffer size as needed
    // snprintf(commit_command, sizeof(commit_command), "git commit -m \"this is a dev commit\" -m \"%s\"", getenv("AUTO_COMMIT_MSG"));
    // system(commit_command);


    // char command[102400];
    // FILE *pipe;

    // sprintf(command, "git commit -m \"this is a dev commit\" -m \"%s\"", output);
    // pipe = popen(command, "r");
    // if (pipe == NULL) {
    //     printf("Failed to run command\n");
    //     return 1;
    // }
    // pclose(pipe);


    // <this is working but unreadable>
    // char command[102400];
    // char escaped_commit_message[102400];
    // FILE *pipe;
    // int i, j;
    // for (i = 0, j = 0; i < strlen(output); i++, j++) {
    //     if (output[i] == '\n') {
    //         escaped_commit_message[j++] = '\\';
    //         escaped_commit_message[j] = 'n';
    //     } else {
    //         escaped_commit_message[j] = output[i];
    //     }
    // }
    // escaped_commit_message[j] = '\0';
    // sprintf(command, "git commit -m \"this is a dev commit\" -m \"%s\"", escaped_commit_message);
    // pipe = popen(command, "r");
    // if (pipe == NULL) {
    //     printf("Failed to run command\n");
    //     return 1;
    // }
    // pclose(pipe);
    // </this is working but unreadable>


    // <this works best but not well formatted>
    // char command[102400];
    // char *line;
    // FILE *pipe;
    // sprintf(command, "git commit -m \"this is a dev commit\"");
    // line = strtok(output, "\n");
    // while (line != NULL) {
    //     sprintf(command + strlen(command), " -m \"%s\"", line);
    //     line = strtok(NULL, "\n");
    // }
    // pipe = popen(command, "r");
    // if (pipe == NULL) {
    //     printf("Failed to run command\n");
    //     return 1;
    // }
    // pclose(pipe);
    // free(output);
    // <this works best but not well formatted>


    // didnt work
    // // Get the last line and remove it from the original string
    // char* last_line = get_last_line_and_remove_from_original(output);
    // // Construct the 'git commit' command
    // char command[102400];
    // sprintf(command, "git commit -m \"this is a dev commit: %s\"", last_line);
    // // Append the remaining lines to the 'git commit' command
    // char* line = strtok(output, "\n");
    // while (line != NULL) {
    //     strcat(command, " -m \"");
    //     strcat(command, line);
    //     strcat(command, "\"");
    //     line = strtok(NULL, "\n");
    // }
    // // Run the 'git commit' command
    // FILE* pipe = popen(command, "r");
    // if (pipe == NULL) {
    //     printf("Failed to run command\n");
    //     return 1;
    // }
    // pclose(pipe);
    // free(output);
    // // Free dynamically allocated memory for last_line
    // free(last_line);


    printf("original output:\n%s\n", output);
    char command[102400];
    // char *last_line;
    char *line;
    FILE *pipe;
    // last_line = strrchr(output, '\n') + 1; // Find the start of the last line
    // *(last_line - 1) = '\0'; // Remove the last line from the original string
    // vvvvvvvv
    char* last_line = strrchr(output, '\n'); // Find the start of the last line
    size_t last_line_length = strlen(last_line); // Calculate the length of the last line
    *last_line = '\0'; // Remove the last line from the original string
    printf("Last line: %s\n", last_line + 1); // Print the last line
    printf("Modified output:\n%s\n", output); // Print the modified output
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

    info("Running `git branch`");
    system("git branch");

    info("Running `git status`");
    system("git status");
}

int do_d()
{
    info("Running `git status`");
    system("git status");
    info("Running `git branch`");
    system("git branch");

    // confirmation
    info(
        "Will execute these commands (destructive):\n"
        // "git pull\n"
        // "git status\n"
        // "git branch\n"
        "git checkout -b up"
    );
    printf("Press Enter to continue, CTRL+C to abort\n");
    char usrInput[256];
    if (fgets(usrInput, sizeof(usrInput), stdin) == NULL) {
        // Handle CTRL+C here if needed
        return 1; // Exit with an error code
    }
    debug("Running...");
    
    info("Running `git checkout -b up`");
    system("git checkout -b up");
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
            // "=====\n"
            "\n"
            "#Safe commands\n"
            "q   : git rev-list --count HEAD\n"
            "qw  : git branch\n"
            "w   : git log -3\n"
            "wd  : git diff --cached\n"
            "ww  : git status\n"
            "wdwd: git diff --cached --stat --compact-summary\n"

            "\n"
            "#Destructive\n"
            "qwd: make a commit\n"
            "d  : make new branch named 'up'\n"
            "dd : git push origin up\n"
        );
        return 0;
    }

    char *command = argv[1];

    // printf("Command: %s\n", command);

    if (strcmp(command, "q") == 0) {
        info("git rev-list --count HEAD");
        system("git rev-list --count HEAD");
    } else if (strcmp(command, "qw") == 0) {
        info("git branch");
        system("git branch");
    } else if (strcmp(command, "w") == 0) {
        info("git log -3");
        system("git log -3");
    } else if (strcmp(command, "wd") == 0) {
        info("git diff --cached");
        system("git diff --cached");
    } else if (strcmp(command, "ww") == 0) {
        info("git status");
        system("git status");
    } else if (strcmp(command, "wdwd") == 0) {
        info("git diff --cached --stat --compact-summary");
        system("git diff --cached --stat --compact-summary");

    } else if (strcmp(command, "qwd") == 0) {
        do_qwd();

    } else if (strcmp(command, "d") == 0) {
        do_d();

    } else if (strcmp(command, "dd") == 0) {
        info("git push origin up");
        system("git push origin up");
    // } else if (strcmp(command, "123") == 0) {
    //     char* currentTime = getCurrentTime();
    //     if (currentTime != NULL) {
    //         printf("Current Time: %s\n", currentTime);
    //         free(currentTime);
    //     }
    } else {
        printf("Invalid command: %s\n", command);
        return 1;
    }

    return 0;
}
