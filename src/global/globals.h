#pragma once

#include <stdbool.h>
#include <stddef.h>
/*
 * Authors: Ryan Brispat, Joshua Turpijn
 * Programme: Pre-Master Software Engineering
 * Date: 02 / 04 / 2023
 * 
 * This file defines Global input/output files
*/
struct globals {
    int line;
    int col;
    int verbose;
    char *input_file;
    char *output_file;
};

extern struct globals global;
extern void GLBinitializeGlobals(void);
