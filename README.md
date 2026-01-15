# C++ Habit Tracker

## Overview
C++ Habit Tracker is a command-line application that helps users build and maintain daily habits.  
Users can add habits, mark them as completed for the current day, and track streaks across days.  
The application is designed with a clean CLI interface and structured logic, focusing on correctness and usability.

---

## Features (Implemented)
- Add new habits with custom names
- Mark a habit as completed for today
- Track streak count for each habit
- View all habits with:
  - Habit name
  - Current streak
  - Last completed date
- View habits **not completed today**
- Input validation for menu and habit selection
- Clear, formatted CLI output for better readability

---

## Features (In Progress)
- Save habit data to a file
- Load habit data automatically on program start

---

## Tech Stack
- C++
- STL (`vector`, `string`)
- File I/O (planned)
- `<ctime>` for system date handling
- `<iomanip>` for formatted console output

---

## How It Works (Brief)
- Habits are stored in memory using a `vector` of custom `Habit` objects
- Each habit maintains:
  - Name
  - Current streak
  - Last completed date (`YYYY-MM-DD`)
- The system date is fetched automatically (no manual date input)
- Streaks update only when a habit is marked once per day

---

## Project Status
🟡 **In Progress**  
(Core functionality completed, persistence coming next)

---

## Planned Improvements
- Persistent storage using file save/load
- Improved streak logic (missed-day reset)
- Prevent empty habit names
- Minor UI refinements

---

## Why This Project
This project was built to practice:
- Object-oriented design in C++
- STL usage
- Real-world input handling
- Time/date handling
- Writing maintainable, readable CLI applications
