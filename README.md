# C Source Code to HTML Converter

A command-line tool written in C that converts C source code into an HTML file with basic syntax highlighting.

The program reads a `.c` source file, analyzes its contents using a lexical parser, identifies different types of tokens, and generates an HTML file with color-coded syntax.

## Features

* Converts C source code into an HTML file
* Highlights C keywords
* Highlights numbers
* Highlights string literals
* Highlights character literals
* Highlights single-line comments
* Highlights multi-line comments
* Highlights preprocessor directives
* Preserves the original source code formatting
* Escapes special HTML characters such as `<`, `>` and `&`
* Supports custom output file names
* Supports command-line arguments
* Uses a state/token-based parsing approach

## How It Works

The program follows these main steps:

```text
C Source File
      |
      v
Command Line Argument Validation
      |
      v
Read Source File Character by Character
      |
      v
Identify Tokens
      |
      +------------------+
      |                  |
      v                  v
  Keywords          Numbers
      |                  |
      +--------+---------+
               |
               v
         Strings / Characters
               |
               v
        Comments / Preprocessor
               |
               v
        Generate HTML Output
```

The parser reads the source file character by character and identifies different types of tokens.

Each token is then written to the HTML file with an appropriate color.

## Syntax Highlighting

The generated HTML uses the following colors:

| Token Type              | Color   |
| ----------------------- | ------- |
| C Keywords              | Blue    |
| Numbers                 | Red     |
| Strings                 | Brown   |
| Character Literals      | Orange  |
| Comments                | Green   |
| Preprocessor Directives | Purple  |
| Identifiers             | Default |

## Supported Tokens

### Keywords

The program recognizes C keywords such as:

```text
auto
break
case
char
const
continue
default
do
double
else
enum
extern
float
for
goto
if
int
long
register
return
short
signed
sizeof
static
struct
switch
typedef
union
unsigned
void
volatile
while
```

### Numbers

The parser identifies integer and floating-point values.

Example:

```c
int a = 10;
float b = 3.14;
```

The values `10` and `3.14` are highlighted as numbers.

### Strings

String literals are detected and highlighted.

Example:

```c
printf("Hello World");
```

### Character Literals

Character constants are detected and highlighted.

Example:

```c
char ch = '\n';
```

### Comments

Both single-line and multi-line comments are supported.

Single-line comment:

```c
// This is a comment
```

Multi-line comment:

```c
/*
   This is a
   multi-line comment
*/
```

### Preprocessor Directives

Preprocessor directives beginning with `#` are highlighted.

Example:

```c
#include <stdio.h>
#define MAX 100
```

## HTML Character Escaping

Since C source code may contain characters that have special meaning in HTML, the program converts them before writing them to the output file.

For example:

```text
<
>
&
```

are converted to:

```text
&lt;
&gt;
&amp;
```

This allows C code containing comparison operators and other special characters to be displayed correctly in the browser.

## Project Structure

```text
SOURCE-TO-HTML/
│
├── main.c
├── main.h
│
├── arguments.c
│
├── parser.c
├── parser.h
│
├── keywords.c
├── keywords.h
│
├── html.c
├── html.h
│
├── source.c
└── hello.html
```

## File Description

| File          | Description                                           |
| ------------- | ----------------------------------------------------- |
| `main.c`      | Program entry point and overall program flow          |
| `main.h`      | Common definitions, structures, constants and headers |
| `arguments.c` | Validates command-line arguments                      |
| `parser.c`    | Reads and analyzes the C source code                  |
| `parser.h`    | Parser function declarations                          |
| `keywords.c`  | Identifies C keywords and numbers                     |
| `keywords.h`  | Keyword-related function declarations                 |
| `html.c`      | Generates HTML and applies syntax highlighting        |
| `html.h`      | HTML-related function declarations                    |
| `source.c`    | Sample C source file used for testing                 |
| `hello.html`  | Sample generated HTML output                          |

## Requirements

* GCC compiler
* Linux / macOS / Windows with a C compiler
* A web browser to view the generated HTML file

## Compilation

Compile the project using GCC:

```bash
gcc main.c arguments.c parser.c keywords.c html.c -o source_to_html
```

## Running the Program

### Basic Usage

Provide only the input C source file:

```bash
./source_to_html source.c
```

By default, the generated HTML file will be:

```text
output.html
```

### Specify Output File

You can provide a custom HTML output filename:

```bash
./source_to_html source.c output.html
```

### Line Number Option

The program also accepts the `-l` option:

```bash
./source_to_html source.c output.html -l
```

## Example

Given the following C source code:

```c
#include <stdio.h>

int main()
{
    int a = 10;
    float b = 3.14;

    // Display values
    printf("a = %d\n", a);

    return 0;
}
```

The program generates an HTML file where:

* `#include <stdio.h>` is highlighted as a preprocessor directive
* `int`, `float`, `return` are highlighted as keywords
* `10` and `3.14` are highlighted as numbers
* `"a = %d\n"` is highlighted as a string
* `// Display values` is highlighted as a comment

The generated HTML file can then be opened in any web browser.

## Concepts Used

This project demonstrates several important C programming concepts:

* File handling
* Command-line arguments
* Structures
* Enumerations
* Functions
* Header files
* Modular programming
* Character-by-character parsing
* String manipulation
* Lexical analysis
* Conditional statements
* Pointers
* HTML generation

## Future Improvements

Possible improvements include:

* Support for more C syntax
* Better floating-point and hexadecimal number detection
* Improved handling of nested or complex comments
* Better preprocessor directive parsing
* Line number generation
* CSS-based syntax highlighting
* Support for C++ source files
* Improved command-line help
* Better error handling
* Support for larger source files
* More accurate lexical analysis

## Learning Outcome

This project provides practical experience with:

* Parsing source code
* Working with files in C
* Processing command-line arguments
* Token identification
* Generating HTML programmatically
* Working with header files
* Modular C programming
* Understanding the basics of lexical analysis

## Author

**Pratham**
