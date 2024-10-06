#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

// Error Codes
#define ERR_MEM_ALLOC 'M' // Memory allocation error
#define DIV_BY_ZERO 'Z' // Division by zero error
#define COMPLEX_RES 'C' // The result is a compex number

// Hash table with error messages
const char* error_messages[] {
    [ERR_MEM_ALLOC] = "Error occured during memory allocation",
    [DIV_BY_ZERO] =   "Division y zero error occured",
    [COMPLEX_RES] = "The result will be a complex number which is out of scope"
};

#endif
