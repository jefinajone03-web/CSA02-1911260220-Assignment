# Task 4 — Use macros safely

## Safe macro examples
```c
#define RUPEES_TO_PAISE(rupees) ((long)(rupees) * 100L)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
```

Parentheses matter because the preprocessor substitutes text. Without them, `SQUARE(a + 1)` written as `x*x` expands to `a + 1 * a + 1`, which follows operator precedence and does not mean `(a + 1)` squared. Parenthesising both the parameter and the whole expression fixes this for ordinary side-effect-free arguments.

`MAX` can evaluate an argument more than once. For example, `MAX(i++, j)` may increment `i` during the comparison and again if the first expression is selected. Avoid passing expressions with side effects to such macros. A normal function or static inline function evaluates each argument once.

## Preprocessor expansion
Run:
```sh
gcc -E Task04/task04_macros.c -o Task04/task04_macros.i
```
Then inspect `Task04/task04_macros.i`. The output includes expanded macro text and system-header expansions; it can be long.

## Inline alternative
A `static inline` function such as `square_int(int x)` or `max_int(int a, int b)` has type checking and evaluates each parameter once. The compiler may inline it or emit a call. A macro is expanded at every use, which can increase generated code size when used many times; an inline function gives the compiler more control. A call and a macro expansion are both generally treated as O(1) for these small operations, but exact machine-level cost depends on compiler optimization.

## Complexity
Each macro or inline calculation shown performs a fixed number of operations: O(1) time and O(1) auxiliary space. If a macro body is copied at k use sites, source / generated code size can grow with k; a shared function can reduce duplication, although optimization may inline it.
