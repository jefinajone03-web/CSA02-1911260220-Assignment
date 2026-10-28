# Task 1 — Understand the problem and identify the data

## Inputs
- **Household number:** identifies which customer the bill belongs to. It should be stored in an integer type large enough for the co-operative's customer ID range.
- **Previous and current meter readings:** whole-number register values from 0 through 65535 for the stated meter.
- **Category:** identifies the tariff category if the co-operative later uses different tariffs. An enum or a small integer code can represent it.

## Computed values and outputs
- **Units consumed:** current reading minus previous reading, adjusted for one rollover of the 16-bit register.
- **Energy charge:** calculated by applying each tariff slab to the units in that slab.
- **Fixed charge:** a constant charge applied to the bill.
- **Total bill:** energy charge plus fixed charge, stored and printed in paise / rupees and paise.

## Constants and rules
- Meter maximum: 65535 for the stated 16-bit register.
- First slab: first 100 units free; units 101–200 at 225 paise each; units above 200 at 450 paise each.
- Fixed charge: 5000 paise (Rs 50.00).
- The bill must not be negative. Total must equal fixed charge plus energy charge. The same tariff constants should be used throughout the program.

## Assumptions
- The register is 16-bit and at most one rollover occurs between readings.
- Readings are valid values from 0 to 65535 and the current reading is the later reading.
- The example tariff applies to every household; a category field is retained for future expansion.
- Tax, subsidies, late fees and arrears are outside this assignment's stated calculation.

## Alternative: storing readings as text
A reading such as `"01530"` can be stored as a character array. The program must validate that every character is a digit, convert the string to an integer, and then compare or subtract the converted values. For d digits, conversion and comparison take O(d) time. A fixed-width text reading uses O(d) space, while an integer reading uses O(1) space per reading. Text preserves leading zeroes, but adds validation and conversion work.
