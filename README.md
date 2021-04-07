# KEL99
### The Keyword Esoteric Language
**KEL99** is a high-level eso-lang that mostly uses keywords for its operations. It is designed to be more beginner friendly. The language is still not so matured. For those of you who doesn't know what an Esolang is.. An esoteric programming language (or Esolang) is a programming language designed to test the boundaries of computer programming language design, as a proof of concept, as software art, as a hacking interface to another language, or as a joke.

## Syntax
It uses Flags to define data type (String or Int) of a value.<br>
And mostly every operations is done in keywords <br>
##### Hello, World! example in KEL99
```
out (S-72|101|108|108|111|44|32|87|111|114|108|100|33|)
```
## Building from Source
#### Prerequisite
1. `g++` 9.2.0^
2. `make` 3.82.90^
#### Build
(**By git**) Run the following commands in your terminal
```
git clone https://www.github.com/soubikbhuiwk007/kel99
cd kel99
make
```

(**Locally**) Download the project as a zip file and extract it. Move to the project's root dir and run the command in your terminal.
```
make
```
#### Installation
1. [Build](#Build) the project.
2. Add the location of the root folder to %PATH% env variable.
#### Clean
Run the following command in your terminal
```
make clean
```
## Documentation
For full documentation see the [Github Gist]().

## Examples
##### Hello, World!
```
out (S-72|101|108|108|111|44|32|87|111|114|108|100|33|)
```
##### Add 1 + 2 in a Variable and print the Variable
```
[sum] : ad (I-49|) (I-50|)
out [sum]
```
##### Print 1-10 numbers
```
[num] : (I-49|48|)
loop [num]
    out [num]
    out (S-10|)
    df [num] (I-49|)
endloop
```
##### Factorial of a number from Input
```
[num] : in
tconv [num] I
[fact] : (I-49|)
loop [num]
    ml [fact] [num]
    df [num] (I-49|)
endloop
out [fact]
```
#### For more example take a look at the `kl` folder in `root` dir.
## Issue
To Report an Issue, see the [ISSUE GuideLines](ISSUE.md).

### This project is licensed under [MIT License](./LICENSE).
***