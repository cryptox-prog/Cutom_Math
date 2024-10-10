#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

// Error Codes
#define ERR_MEM_ALLOC 1 // Memory allocation error
#define DIV_BY_ZERO 2   // Division by zero error
#define COMPLEX_RES 3   // The result is a complex number
#define POSITIVE_FUNC 4   // The result is a complex number
#define INDEX_OUT_OF_RANGE 5   // The index is out of range

// Declare the error_messages array in the .h file
static const char* error_messages[];

// Hash table with error messages
static const char* error_messages[] = {
    [ERR_MEM_ALLOC] = "Error occurred during memory allocation",
    [DIV_BY_ZERO] = "Division by zero error occurred",
    [COMPLEX_RES] = "The result will be a complex number which is out of scope",
    [POSITIVE_FUNC] = "The mathmatical function accepts only non zero positive values",
    [INDEX_OUT_OF_RANGE] = "The index is out of range"
};

#endif
