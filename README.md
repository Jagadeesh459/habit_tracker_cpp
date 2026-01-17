give me the commit for readme and check my readme once 

# 🧠 Habit Tracker (C++ CLI Application)

A clean and user-friendly **command-line Habit Tracker** built using **C++**.  
This application helps users build consistency by tracking daily habits, maintaining streaks, and saving progress persistently.

This is a **real, functional C++ project**, not just a practice program.

---

## 🚀 Features

- ➕ Add new habits (empty names are prevented)
- ✅ Mark habits as completed for today
- 🔥 Automatically maintain streaks
- 👀 View all habits with streaks and last completion date
- ⏳ View habits not completed today
- 🗑️ Delete existing habits
- 💾 Save habits to file
- 🔁 Load habits automatically on program start
- 🎨 Colored CLI interface for better user experience

---

## 🧠 How Streaks Work

- If a habit was completed **today or yesterday**, the streak continues
- If a habit was missed for **more than one day**, the streak resets to `0`
- Streak correction is handled safely during **program load**

This ensures streaks always reflect real progress.

---

## 🗂️ Data Storage

-Habit data is stored in a simple text file named:
```
habits.txt
```

-Each habit is saved in the following format:
```
habit_name|streak|last_done_date
```

### Example:
```bash
Workout|5|04-02-2026
Reading|2|03-02-2026
```

> 📌 This file is **automatically created** when you choose the **Save** option in the program.  
> You do **not** need to create or edit it manually.

---

## 🛠️ Tech Stack & Concepts Used

- **Language:** C++
- **Standard Libraries:**
  - `vector`
  - `string`
  - `fstream`
  - `sstream`
  - `ctime`
- **Concepts Used:**
  - Classes & objects
  - File handling (save & load)
  - Date & time handling using system clock
  - Input validation
  - Edge case handling
  - ANSI escape codes for colored CLI output

---

## ▶️ How to Run the Project

### 1️⃣ Compile the program
```bash
g++ habit_tracker.cpp -o habit_tracker
```
2️⃣ Run the executable
```bash
./habit_tracker
```

💡 Recommended: Use a modern terminal (Linux / macOS / Windows Terminal) for proper color support.
