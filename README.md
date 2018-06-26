# dict-utils
Cross platform library for simple key-value storage (dictionaries) in C99

[![Build Status](https://travis-ci.org/phtdacosta/dict-utils.svg?branch=master)](https://travis-ci.org/phtdacosta/dict-utils)
[![Build status](https://ci.appveyor.com/api/projects/status/pqoyfmhavnm53aur?svg=true)](https://ci.appveyor.com/project/phtdacosta/dict-utils)
[![Average time to resolve an issue](http://isitmaintained.com/badge/resolution/phtdacosta/dict-utils.svg)](http://isitmaintained.com/project/phtdacosta/dict-utils "Average time to resolve an issue")
[![Percentage of issues still open](http://isitmaintained.com/badge/open/phtdacosta/dict-utils.svg)](http://isitmaintained.com/project/phtdacosta/dict-utils "Percentage of issues still open")
[![Misosu integration status](https://img.shields.io/badge/misosu-ready-brightgreen.svg)](https://github.com/phtdacosta/misosu "Misosu integration status")

### Overview:
* Since the C programming language does not offer native support to such useful high level data structures as dictionaries, creating a library that could cover the subject in a grammatically acceptable way was just a matter of time. Without major deep optimizations, the algorithm is currently performing very well.

#### dict-utils will be part of a major project, the development cycle is not going to cease anytime soon.

## Basic usage:
> An example file is available under the "main.c" name, check it out for further testing!
```c
    // A temporary pointer will point to a new dictionary
    Collection *col = initdict();
    // Even accepting any data type, it is a good idea to cast the value properly before
    addrec("key 1", (int*)15930240785, col);
    // Using a given key, the corresponding value will be retrieved
    printf("key 1 retrieved: %d\n", getrec("key 1", col));
    // Using a given key, the corresponding record will be deleted
    delrec("key 1", col);
    // All contents are going to be removed, but the empty dictionary will still exists
    freedict(col);

```

### Warnings:
1. If your decide to free all the dictionary contents, you **must** free the temporary pointer used to create the dictionary, and then point it to null as a security measure. 
2. Closely monitor your RAM usage, even with the library being optimized to use just as little memory as possible.

### Known issues (Feel free to help!):
Currently there are no known issues.