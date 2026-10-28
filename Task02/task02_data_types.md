# Task 2 — Choose the data types

## Recommended choices
- `meter_t` (`unsigned short`): stores a meter register from 0 to 65535. Check the actual size with `sizeof` and the limit with `USHRT_MAX`.
- `unsigned int`: stores units consumed and loop counts; the district scale of 800,000 households fits comfortably.
- `int` or `unsigned long long`: suitable for a household identifier depending on the numbering policy. The assignment does not specify the ID range, so this should be confirmed.
- `long`: stores bill amounts in paise in the supplied Linux/GCC environment. For a portable system, use `int64_t` from `stdint.h` when a guaranteed 64-bit integer is required.
- `enum`: represents a small, fixed list of customer categories.
- `char` array: stores a category label or formatted output, not the arithmetic meter value.

## Typical sizes on a 64-bit GCC/Linux system
`char`: 1 byte; `short`: 2 bytes; `int`: 4 bytes; `long`: 8 bytes; `long long`: 8 bytes; `float`: 4 bytes; `double`: 8 bytes. These are common system results, not universal guarantees; `sizeof` on the target compiler is the evidence.

## Limits
Use `limits.h` (`CHAR_MIN`, `CHAR_MAX`, `SHRT_MIN`, `SHRT_MAX`, `USHRT_MAX`, `INT_MIN`, `INT_MAX`, `LONG_MIN`, `LONG_MAX`, `LLONG_MIN`, `LLONG_MAX`) and `float.h` (`FLT_MAX`, `DBL_MAX`, `FLT_DIG`, `DBL_DIG`) to inspect ranges and precision. The exact values depend on the implementation. For the stated meter, `USHRT_MAX` should be 65535 if unsigned short is the intended 16-bit register.

## Why store paise as an integer?
Binary floating-point cannot represent many decimal fractions exactly. If many bills are added, tiny errors can accumulate and a displayed value may differ by a paisa after rounding. Store money as whole paise in an integer, and convert to rupees only when displaying it. Each addition is O(1) time and each amount occupies O(1) space.

### Example of floating-point risk
A decimal value such as 0.1 is not represented exactly in binary floating-point. Repeating additions such as 0.1 across 4,000 records can produce a value close to, but not necessarily exactly, 400.0. The exact displayed result depends on the compiler and evaluation details. Integer paise avoids this issue for amounts that are whole paise.

## Rollover
For a 16-bit unsigned meter, the register wraps after 65535. If the previous reading is 65400 and the current reading is 120, consumption is (65536 - 65400) + 120 = 256 units. Unsigned arithmetic models the wrap; the result is not a negative bill or negative consumption.

## Complexity
Both integer readings and converted text readings need O(1) arithmetic after conversion. Text conversion costs O(d) per reading for d digits and uses O(d) storage; integer storage uses O(1) space.
