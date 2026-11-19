# Kaun Banega Crorepati Quiz Game

A console-based quiz inspired by the TV show *Kaun Banega Crorepati*, written in C.
It includes eight multiple-choice questions about C programming, score tracking, colored terminal output, and a 50-50 lifeline.

## How it works

- Each question has four options (A, B, C, D).
- Press **L** once per question to use the 50-50 lifeline, which hides two wrong options.
- A correct answer increases the score.
- The final score out of 8 and a short performance message are shown at the end.

## Features

- Interactive quiz gameplay
- 50-50 lifeline
- Colored console output using ANSI codes
- Case-insensitive input handling
- Automatic score calculation

## How to run

```bash
gcc KBC.c -o kbc
./kbc
```

Colors work in terminals that support ANSI escape codes.

## Tech stack

C language · ANSI escape codes for terminal colors
