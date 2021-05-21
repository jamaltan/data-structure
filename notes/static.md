### pointer
4.8.6 Static functions

By default, all functions are global; they can be used in any file of your program whether or not a declaration appears in a header file. To restrict access to the current file, declare a function `static`, like this:

```c
static void
helloHelper(void)
{
    puts("hi!");
}

void
hello(int repetitions)
{
    int i;

    for(i = 0; i < repetitions; i++) {
        helloHelper();
    }
}
```

[examples/functions/staticHello.c](https://www.cs.yale.edu/homes/aspnes/classes/223/examples/functions/staticHello.c)

The function `hello` will be visible everywhere. The function `helloHelper` will only be visible in the current file.

It's generally good practice to declare a function static unless you intend to make it available, since not doing so can cause **namespace conflicts**, where the presence of two functions with the same name either prevent the program from linking or—even worse—cause the wrong function to be called. The latter can happen with library functions, since C allows the programmer to override library functions by defining a new function with the same name. Early on in my career as a C programmer, I once had a program fail in a spectacularly incomprehensible way because I'd written a `select` function without realizing that `select` is a core library function in Unix.
