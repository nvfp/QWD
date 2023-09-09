#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char* getCurrentTime() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char* timeStr = (char*)malloc(9 * sizeof(char));
    if (timeStr != NULL) {
        strftime(timeStr, 9, "%H:%M:%S", timeinfo);
    }
    return timeStr;
}

void debug(const char* msg) {
    char* currentTime = getCurrentTime();
    if (currentTime != NULL) {
        printf("[%s] DEBUG: %s\n", currentTime, msg);
        free(currentTime);
    }
}

void info(const char* msg) {
    char* currentTime = getCurrentTime();
    if (currentTime != NULL) {
        printf("[%s] INFO: %s\n", currentTime, msg);
        free(currentTime);
    }
}

void warning(const char* msg) {
    char* currentTime = getCurrentTime();
    if (currentTime != NULL) {
        printf("[%s] WARNING: %s\n", currentTime, msg);
        free(currentTime);
    }
}

void error(const char* msg) {
    char* currentTime = getCurrentTime();
    if (currentTime != NULL) {
        printf("[%s] ERROR: %s\n", currentTime, msg);
        free(currentTime);
    }
    exit(1);
}
