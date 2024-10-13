#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

// Error Codes
#define ERR_MEM_ALLOC 0 // Memory allocation error
#define DIV_BY_ZERO 1   // Division by zero error
#define COMPLEX_RES 2   // The result is a complex number
#define POSITIVE_FUNC 3   // The result is a complex number
#define INDEX_OUT_OF_RANGE 4   // The index is out of range


static const char *error_messages[];

// Specific Index Defined table with error messages
static const char *error_messages[] = {
    [ERR_MEM_ALLOC] = "Error occurred during memory allocation",
    [DIV_BY_ZERO] = "Division by zero error occurred",
    [COMPLEX_RES] = "The result will be a complex number which is out of scope",
    [POSITIVE_FUNC] = "The mathmatical function accepts only non zero positive values",
    [INDEX_OUT_OF_RANGE] = "The index is out of range"
};

#endif //ERROR_HANDLING_H
