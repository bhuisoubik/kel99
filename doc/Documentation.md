# KEL99 Documentation
[**Kel99**](https://www.github.com/soubikbhuiwk007/kel99) is a high-level eso-lang that mostly uses keywords for its operations. It is designed to be more beginner friendly. The language is still not so matured. So it might happen you may
find a bug, then feel free to create an [Issue](https://github.com/soubikbhuiwk007/kel99/blob/master/ISSUE.md).

An esoteric programming language (or Esolang) is a programming language designed to test the boundaries of computer programming language design, as a proof of concept, as software art, as a hacking interface to another language, or as a joke.

## Get Started
#### Prerequisite
1. `g++`
2. `make`
#### Build
(**By git**) Run the following commands in your terminal
```shell
$ git clone https://www.github.com/soubikbhuiwk007/kel99
$ cd kel99
$ make
```

(**Locally**) Download the project as a zip file and extract it. Move to the project's root dir and run the command in your terminal.
```shell
$ make
```
#### Installation
1. [Build](#Build) the project.
2. Add the location of the root folder to %PATH% env variable.

### Table Of Contents
1. [Value](#Value)
2. [Output](#Output)
3. [Input](#Input)
4. [Variables](#Variables)
5. [Operations](#Operations)
6. [Type Conversion](#Type-Conversion)
7. [Loops](#Loops)
8. [Not Supported](#Not-Supported)
### Useful Links:
1. [Ascii Char Table (source: w3schools.com)](https://www.w3schools.com/charsets/ref_html_ascii.asp)

## Syntax
It uses Flags to define data type (String or Int) of a value.<br>
And mostly every operations is done in keywords. <br>

### Value
To represent a `value` the text should be inside `(` & `)`. The first character will set the value's `flag` ( i.e `I` for `INT` & `S` for `STRING` ) succeeding by `-` to represent the end of the `flag`. After this, write the `ascii char code (number)` of the character you want to be in the value succeeding by `|` to represent the end of the number. For full ASCII Ref. check
[Ascii Char Table](https://www.w3schools.com/charsets/ref_html_ascii.asp).

Example:<br>
The string `Hello`. <br>
**Kel99**
```
(S-72|101|108|108|111|)
```
**Python Equivalent:**
```python
"Hello"
```
The number (int) `10`. <br>
**Kel99**
```
(I-49|48|)
```
**Python Equivalent**
```python
10
```
#
### Output
In **kel99** the `out` keyword is use to print `values` or `variables` to console. Use the `out` keyword before any `value` or `variable`.

Example:<br>
Print `Hello` to console.<br>
**Kel99**
```
out (S-72|101|108|108|111|)
```
**Python Equivalent**
```python
print("Hello")
```
#
### Input
In **kel99** the `in` keyword is use to take user input from console. By default every input returns a `STRING` value. 

Example:<br>
Take `input` & store it in a `variable`<br>
**Kel99**
```
[s] : in
```
**Python Equivalent**
```python
s = input()
```

**Note: `input` only returns `STRING`. To get `INT` you can convert the `STIRNG` value to `INT`**

Example:<br>
**Kel99**
```
[s] : in
tconv [s] I
```
**Python Equivalent**
```python
s = int(input())
```
#
### Variables
To declare & store values in `variable`, the `variable_name` should be inside `[` and `]`. The `:` represents assignment operator. Any `value` in right side of `:` is the `value` the `variable` stores.

Example:<br>
Store the number `10` in a variable called `var`. <br>
**Kel99**
```
[var] : (I-49|48|)
```
**Python Equivalent**
```python
var = 10
```
#
### Operations
Here, keywords like `ad`, `df`, `ml`, `dv`, `md`, are used to do arithmetic operations.
| Kel99 Operators | Python Operators |
|:---------------:|:----------------:|
|`ad`| `+` |
|`df`| `-` |
|`ml`| `*` |
|`dv`| `/` |
|`md`| `%` |

#### Syntax
```
operator VALUE1 VALUE2
______________________
Example : ad (I-50|) (I-52|)
```

Operations can be used to change the original value like:
**Kel99**
```
[num] : (I-49|)
ad [num] (I-50|)
```
**Python Equivalent**
```python
num = 1
num += 2
```
Operations can also be used to set value to a variable (after operations), like:<br>
**Kel99**<br>
Sum of two (`a`,`b`) variables. <br>
**Note:** This will not change the value of `a` & `b`<br>
```
[a] : (I-49|)
[b] : (I-50|)
[sum] : ad [a] [b]
```
**Python Equivalent**
```python
a = 1
b = 2
sum = a + b
```
#
### Type Conversion
The `tconv` keyword is used to convert a `variable`'s type.<br>
**Syntax**
```
tconv [variable_name] Flag
```
**Flags**<br>
In Kel99, there two types of `flag` (`Int` & `String`).
|Type|Flag|
|:--:|:--:|
|Int|`I`|
|String|`S`|

Example:<br>
Change `String` type to `Int` of the variable `num`.<br>
**Kel99**
```
[num] : (S-50|)
tconv [num] I
```
**Python Equivalent**
```python
num = "2"
num = int(num)
```
Change `Int` type to `String` of variable `s`.<br>
**Kel99**
```
[s] : (I-51|)
tconv [s] S
```
**Python Equivalent**
```python
s = 3
s = str(s)
```
#
### Loops
Here, loops are used for repeated execution for a limited number of time. The `loop` keyword is used for starting a loop following by a `int` `value` and the `endloop` keyword is used for denoting the end of `loop`. <br>
**Syntax**
```
loop VALUE
some code..
endloop
```
Example:<br>
Print 10 - 1<br>
**Kel99**
```
[num] : (I-49|48|)
loop [num]
    out [num]
    out (S-10|)
    df [num] (I-49|)
endloop
```
**Python Equivalent**
```python
num = 10
for i in range(0, 10):
    print(num)
    num -= 1
```
#
### Not Supported
**KEL99** doesn't support:
1. Booleans
2. If Blocks
3. Errors

> Soon these will be launched.
***
