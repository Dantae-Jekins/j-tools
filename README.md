## j-tools

### totally not useless considering other C libraries 11!!11!

To clarify, i am aware that standart functions are a better solution than creating your own functions, so there are two reasons for making this, first is that i enjoy knowing exactly what my function does, which i could solve by looking the source code for most of the libraries i use, but i'm lazy, and the other reason is for me to train programming logic in C.


- j-compile

    Shell script that i made for myself to easily compile my allegro project, though it's also used for other  things, it contains personal information about the directory so recoding would be needed for it to work in other environments. To elaborate, a local bin folder (~/.local/.bin is a nice alternative) is needed,
    this program compiles and saves it in the place, the reason is that a polluted 
    main folder (with binaries) really bothers me.

<br>

- j-export

    Grouping the files manually and sending them to another repository is really taxing,
    so i made a shell script for that, the first argument is the file path to the j-group's target header, and it'll group automatically the needed headers and the 
    grouper header on a file. You can also specify the target output in the second arg.

<br>

- j_arrays.h

    Stands for vetores, or arrays, it's a file used for array manipulation, i should mention that this is not for strings (character arrays), but for integer arrays, it's functions are for simple operations such as clearing, inverting or copying an array.

<br>

- j_geometry.h

    No need to pay attention to this, it was a header i made to help me think how could i implement real life math into a program, though it is a nice setup if one day i seek to make an actual linear algebra library, i'll have to work with floats which i hate though :(.

<br>

-  j_math.h
    
    Gathers bare-metal functions (with no dependencies) that are explicitly related to mathematical concepts, it's going to further be incremented to work with things such as Linear Algebra and floating points.
    
<br>

- j_sorters.h

    Gathers various sorting algorithms, though their structure is suspicious (i am not sure if the way i made is the optimal way), they work as intended, and no breaks have been included. 
    

<br>

- j_statystyka.h

    Not necessarily for productive functions, statystyka refers to estatística or statistic, currently there's only functions to simplify huge arrays into short ones for easy reading and analysis, that and a random number generator. 
    
<br>

    
- j_strings.h

    String equivalent of j_arrays, it's important to know that this library considers the null character "\0" as a break point, thus not working in integer arrays (which i could use negative numbers as a break, if not expecting one), it's functions are of general use such as to extract length, copies, cutting, and matching.

<br>

- j_transform.h

    Simple, set of functions for data type conversion, specifically number - string - array transformations. 