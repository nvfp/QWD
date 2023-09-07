#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [command]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];

    if (strcmp(command, "q") == 0) {
        system("git rev-list --count HEAD");
    } else if (strcmp(command, "qw") == 0) {
        system("git branch");
    } else if (strcmp(command, "w") == 0) {
        system("git log -3");
    } else if (strcmp(command, "wd") == 0) {
        system("git diff --cached");
    } else {
        printf("Invalid command: %s\n", command);
        return 1;
    }

    return 0;
}
