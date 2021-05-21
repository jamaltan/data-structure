### pointer

#### Void pointer
A special pointer type is void *, a "pointer to void". Such pointers are declared in the usual way:

```c
void *nothing;      /* pointer to nothing */
```
Unlike ordinary pointers, you can't dereference a void * pointer or do arithmetic on it, because the compiler doesn't know what type it points to. However, you are allowed to use a void * as a kind of "raw address" pointer value that you can store arbitrary pointers in. It is permitted to assign to a void * variable from an expression of any pointer type; conversely, a void * pointer value can be assigned to a pointer variable of any type. An example is the return value of malloc or the argument to free, both of which are declared as void *. (Note that K&R suggests using an explicit cast for the return value of malloc. This is now acknowledged by the authors to be an error, which arose from the need for a cast prior to the standardization of void * in ANSI C. See http://cm.bell-labs.com/cm/cs/cbook/2ediffs.html.)

```c
int *block;

block = malloc(sizoef(int) * 12);  /* void * converted to int * before assignment */
free(block);                       /* int * converted to void * before passing to free */
```
If you need to use a void * pointer as a pointer of a particular type in an expression, you can cast it to the appropriate type by prefixing it with a type name in parentheses, like this:

```c
int a[50];          /* typical array of ints */
void *p;            /* dangerous void pointer */

a[12] = 17;         /* save that valuable 17 */
p = a;              /* p now holds base address of a */

printf("%d\n", ((int *) p)[12]);  /* get 17 back */
```
Usually if you have to start writing casts, it's a sign that you are doing something wrong, and you run the danger of violating the type system—say, by tricking the compiler into treating a block of bits that are supposed to be an int as four chars. But violating the type system like this will be necessary for some applications, because even the weak type system in C turns out to be too restrictive for writing certain kinds of "generic" code that work on values of arbitrary types.

