### const
4.5.6 Marking variables as constant
The const qualifier declares a variable to be constant:

```c
const int three = 3;   /* this will always be free */
```
It is an error to apply any sort of assignment (=, +=,++, etc.) to a variable qualified asconst`.

4.5.6.1 Pointers to const
A pointer to a region that should not be modified should be declared with const type:

```c
const char *string = "You cannot modify this string.";
```
The const in the declaration above applies to the characters that string points to: string is not const itself, but is instead a pointer to const. It is still possible to make string point somewhere else, say by doing an assignment:

```c
string = "You cannot modify this string either."
```
If you want to make it so that you can't assign to string, put const right before the variable name:

```c
/* prevent assigning to string as well */
const char * const string = "You cannot modify this string.";
```
Now string is a const pointer to const: you can neither modify string nor the values it points to.

Note that const only restricts what you can do using this particular variable name. If you can get at the memory that something points to by some other means, say through another pointer, you may be able to change the values in these memory locations anyway:

```c
int x = 5;
const int *p = &x;
int *q;

*p = 1; /* will cause an error at compile time */
x = 3;  /* also changes *p, but will not cause an error */
```
