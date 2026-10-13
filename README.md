# C++ Flashcard Study App

A console application I built for my Computer Science II course to help users study their own questions and answers. Users can create flashcards, review them in a random order, and save the remaining cards for another session.

## Features

- Create cards with a question and answer.
- Reveal an answer when ready.
- Mark whether an answer was correct.
- Track consecutive correct responses during a session.
- Choose to remove a card after five correct responses or keep studying it.
- Save and reload cards using a text file.

## Skills Practiced

C++ classes, pointers, dynamic memory management, vectors, file storage, input handling, and UML design.

## How to Run

You need a C++ compiler with C++11 support or newer.

Open a terminal in the project folder and build with GCC:

```bash
g++ -std=c++11 -include limits main.cpp -o flashcards
```

The build command supplies the `<limits>` header used by the program.

Run on Windows:

```powershell
.\flashcards.exe
```

Run on macOS or Linux:

```bash
./flashcards
```

Keep `classes.h` beside `main.cpp` when compiling. Run the application from the project folder so it can read and update `flashcard.txt`.

## Using the App

1. Choose **1** to create a card.
2. Choose **2** to study.
3. Press Enter to reveal an answer, then mark it correct or incorrect.
4. Choose **3** to save the remaining cards and exit.

The included `flashcard.txt` starts empty, so create a card before studying.

## Project Files

- `main.cpp` — menus, study flow, and file handling.
- `classes.h` — flashcard and deck classes.
- `flashcard.txt` — saved questions and answers.
- `docs/` — project blueprints and UML diagrams.

## Project Scope

Questions and answers are saved between sessions. Correct-answer counters reset when the application restarts. Cards are selected randomly, so the same card can appear more than once in a row.


**Course:** Computer Science II  
**Date:** December 2, 2023
