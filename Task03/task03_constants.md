# Task 3 — Define the constants

The tariff should be defined once at the top of the program:
- `SLAB1_UNITS` = 100
- `SLAB2_UNITS` = 200
- `RATE1_PAISE` = 0
- `RATE2_PAISE` = 225
- `RATE3_PAISE` = 450
- `FIXED_CHARGE_PAISE` = 5000

The names are uppercase with underscores, so they are easy to distinguish from variables. A tariff change is then made in one place. For example, changing `RATE2_PAISE` from 225 to 230 changes the charge for every unit in the second slab consistently.

`#define` is handled by the preprocessor before compilation. It performs textual substitution and has no C type or ordinary variable scope, but it is simple for fixed numeric configuration values. A `const` variable has a type, follows normal scope rules and is easier to inspect in a debugger; it may occupy storage depending on use and compiler optimization. An `enum` is useful for named integer choices such as customer categories, not usually for large monetary values.

For the assignment's tariff table, `#define` macros are a clear and direct fit. In a larger program, const variables or a tariff structure may be preferable for type safety and multiple tariff plans.

## Complexity
The number of slab checks is fixed, so calculating one bill takes O(1) time and O(1) extra space. Changing the representation of constants does not meaningfully change the algorithm's Big-O complexity.
