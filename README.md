## j-tools

#### totally not useless considering other C libraries 11!!11!
- j-compile

    Shell script that i made for easy allegro compiling, though it's also used for other thing, it contains personal information about the directory so recoding would be needed so it'd work in other environments. 

<br>

-  j_math.h
    
    Gathers bare-metal functions (with no dependencies) that are explicitly related to mathematical concepts, it's going to further be incremented to work with things such as Linear Algebra and floating points.
    
    - No dependencies

<br>

- j_sorters.h

    Gathers various sorting algorithms, though their structure is suspicious (i am not sure if the way i made is the optimal way), they work as intended, and no breaks have been included. 
    
    _depends on_
    - stdlib.h

<br>

- j_statystyka.h

    Not necessarily for productive functions, statystyka refers to estatística or statistic, currently there's only functions to simplify huge arrays into short ones for easy reading and analysis, that and a random number generator. 
    
    _depends on_
    - stdio.h
    - rand.h

<br>

- j_wektory.h

    Stands for vetores, or arrays, it's a file composed of string manipulation and data conversion functions.
    
    _depends on_
    - j_math.h
    - stdlib.h
