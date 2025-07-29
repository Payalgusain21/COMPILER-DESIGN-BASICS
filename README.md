# COMPILER-DESIGN-BASICS

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: PAYAL GUSAIN

*INTERN ID*: CT04DH1488

*DOMAIN*: C LANGUAGE

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH

This C program is designed to function as a basic lexical analyzer, in this the analyzer focuses on identifying three main types of tokens:  keywords, identifiers, and operators, which are essential building blocks of any programming language.

At the beginning of the program, the required header files are included. The stdio.h header is used for basic input and output operations, while string.h is included for string manipulation functions like strcmp(), and ctype.h provides functions such as isalnum() which help determine whether a character is alphanumeric (used in token classification).

Next, two key arrays are defined. The first is a two-dimensional character array named keywords that contains a list of 32 reserved words used in the C programming language. These include fundamental control structures (if, else, while, for), data types (int, float, char, double, etc.), storage class specifiers (static, extern, register), and other core language keywords. The second array, operators, is a string of commonly used arithmetic and assignment operators such as +, -, *, /, and =. These are the symbols the lexical analyzer is designed to detect.

To detect whether a token is a keyword or an operator, two utility functions are implemented: isKeyword() and isOperator().
-> The isKeyword() function takes a string input and compares it to each item in the keywords array using strcmp(). If a match is found, it returns 1, indicating that the token is a recognized keyword. If no match is found, it returns 0, which typically means the token is an identifier or something else. 
-> The isOperator() function works in a similar way, but instead checks if a single character matches any character in the operators array.

The main() function begins by opening the source file in read mode using fopen(). A buffer is declared to temporarily store sequences of characters that may represent a token (e.g., a variable name, a keyword, or a number). If the file cannot be opened, an error message is printed and the program exits.

The core of the lexical analysis happens in a while loop that continues until end-of-file (EOF) is reached. The fgetc() function is used to read characters one at a time. If the character is alphanumeric or an underscore, it's part of a potential token, so it's added to the buffer. Once a non-alphanumeric character (like a space, operator, or symbol) is encountered, the current buffer is null-terminated (\0) and evaluated.

After a complete token is formed and stored in the buffer, the program processes it in a specific sequence to determine its type. It first checks whether the token is a keyword using the isKeyword() function, which compares the buffer with a list of predefined C keywords. If it doesn’t match any keyword, the program then checks if the first character is a digit using the isdigit() function—if so, it classifies the token as a number. If neither condition is met, the token is assumed to be an identifier, such as a variable or function name.

The result of each token classification is printed using the printf() function, along with a specific label that clearly identifies the type of token detected. Tokens are labeled as [Keyword], [Number], or [Identifier], depending on their classification based on the earlier checks. This output makes it easy to distinguish the role of each token in the source code.

If the current character being read is not alphanumeric and does not belong to a valid token — such as an operator or delimiter like ;, :, (, or ) — it is not added to the buffer. Instead, the buffer index is simply reset, allowing the program to skip non-token characters when appropriate. Operators, however, are still checked separately using the isOperator() function, and if identified as valid, they are printed as recognized tokens with the appropriate tag.

By continuing this process for each character in the source file until the end is reached, the program effectively breaks down the source code into its basic components. This allows for structured and organized tokenization of the input file. Although the program handles a limited set of token types, it successfully performs the core functions of lexical analysis. It demonstrates how source code is read, interpreted, and divided into meaningful units at the very first stage of compilation.

*APPLICATION*: Compiler Development-> It's used to tokenize source code, which helps the compiler understand and parse programming instructions.

*EDITOR PLATFORM*: Visual Studio Code

*LIBRARY*: <stdio.h>,<stdlib.h>,<ctype.h>

*LANGUAGE*: C

*OUTPUT*: <img width="1920" height="1020" alt="Image" src="https://github.com/user-attachments/assets/f201c281-d1c4-4605-837d-ec99db849a05" />
