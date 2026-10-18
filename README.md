# Programming Fundamentals

C++ exercises from my Programming Fundamentals (PF) labs and Programming Day (PD) practice sessions.

## Exercises

| Set | Original repository | Files |
| --- | --- | ---: |
| [PF + PD · Week 2](shared/week-02/) | `pfandpdweek2` | 35 |
| [PF · Lab 3](pf/lab-03/) | `pflab3` | 25 |
| [PF · Lab 4](pf/lab-04/) | `pflab4` | 44 |
| [PF · Lab 5](pf/lab-05/) | `pflab5` | 14 |
| [PF · Lab 6](pf/lab-06/) | `pflab6` | 39 |
| [PF · Lab 7](pf/lab-07/) | `pflab7` | 46 |
| [PF · Lab 9](pf/lab-09/) | `pflab9` | 69 |
| [PD · Week 3](pd/week-03/) | `pdweek3` | 39 |
| [PD · Week 4](pd/week-04/) | `pdweek4` | 45 |
| [PD · Week 5](pd/week-05/) | `pdweek5` | 10 |
| [PD · Week 6](pd/week-06/) | `pdweek6` | 22 |
| [PD · Week 7](pd/week-07/) | `pdweek7` | 28 |
| [PD · Week 9](pd/week-09/) | `pdweek9` | 27 |

## Run an exercise

Each `.cpp` file is a separate program. Compile and run the exercise you want rather than building the whole repository as one application:

```sh
mkdir -p build
g++ -std=c++11 -fpermissive pf/lab-03/task1.cpp -o build/task1
./build/task1
```

The example uses GCC with `-fpermissive` because some early exercises omit the explicit return type on `main`. These are original coursework snapshots and may require adjustments for current compilers.

Some exercises use Windows-specific console functions or headers such as `windows.h` or `conio.h`; those require a compatible Windows compiler or platform-specific changes. Original `.txt` files and compiled executables are retained with the exercises for completeness.

## Repository history

This repository brings together 13 original PF and PD repositories. Every original file and commit is preserved. Each source branch tip is also recorded under a `sources/<repository>/branches/<branch>` tag.

The source-to-folder mapping and original commit IDs are listed in [SOURCES.md](SOURCES.md).
