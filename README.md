# CSA02 Assignment 3 — Reliable Electricity Billing

**Student:** S Jefina Jone  
**Register number:** 1911260220

## Contents
- `Task01/task01_analysis.md` — problem analysis and assumptions
- `Task02/task02_data_types.md` — data types, money precision, and rollover
- `Task02/task02_rollover.c` — meter rollover demonstration
- `Task03/task03_constants.md` — tariff constants and design notes
- `Task03/task03_billing.c` — slab billing implementation
- `Task04/task04_macros.md` — safe macros and inline alternatives
- `Task04/task04_macros.c` — macro and inline-function demonstration
- `VALIDATION_RESULTS.txt` — outputs recorded during local GCC validation

## Compile and run
Run these from the repository root using GCC:

```sh
gcc -std=c11 -Wall -Wextra -pedantic Task02/task02_rollover.c -o rollover
./rollover

gcc -std=c11 -Wall -Wextra -pedantic Task03/task03_billing.c -o billing
./billing

gcc -std=c11 -Wall -Wextra -pedantic Task04/task04_macros.c -o macros
./macros

gcc -E Task04/task04_macros.c -o Task04/task04_macros.i
```

Task 1 is analysis only and does not require a separate executable. The supplied output record reflects validation in the preparation environment; run the commands on your own computer and capture your own screenshots if your instructor requires personal execution evidence.
