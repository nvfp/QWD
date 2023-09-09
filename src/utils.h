#ifndef UTILS_H
#define UTILS_H

// Function prototype for getCurrentTime
char* getCurrentTime();

// Define a "Logger" structure to mimic a class
struct Logger {
    void (*info)();
    void (*debug)();
    void (*warning)();
    void (*error)();
};

// Function prototypes for methods
void debug(const char* msg);
void info(const char* msg);
void warning(const char* msg);
void error(const char* msg);

#endif
