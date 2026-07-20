# 🏏 Cricket Tournament Scorecard in C

A command-line Cricket Tournament Scorecard program written in C that takes match results from multiple teams, calculates points, sorts them by ranking, and displays a formatted scorecard table.

---

## 🎯 How It Works

- Enter how many teams are in the tournament
- For each team, enter their match stats (played, won, lost, drawn)
- The program **automatically calculates points**
- Teams are **sorted by points** (highest first)
- A clean **formatted scorecard table** is displayed

---

## 📊 Points System

| Result | Points |
|--------|--------|
| Win    | 2 pts  |
| Draw   | 1 pt   |
| Loss   | 0 pts  |

---

## 📁 Project Structure
cricket-scorecard/
│
|-- scorecard.c     # Main source code
├── README.md       # Project documentation
└── Output.png      #Output image

---

## ⚙️ How to Compile & Run

### On Linux / Mac
```bash
gcc scorecard.c -o scorecard
./scorecard
```

### On Windows
```bash
gcc scorecard.c -o scorecard.exe
scorecard.exe
```

> Make sure **GCC** is installed:
> - Linux: `sudo apt install gcc`
> - Mac: `xcode-select --install`
> - Windows: Install [MinGW](https://www.mingw-w64.org/)

---

## 💡 Example Usage
Enter the number of teams: 3
--- Team 1 ---
Enter the name of team 1: India
Enter the number of matches played by India: 5
Enter the number of matches won by India: 4
Enter the number of matches lost by India: 0
Enter the number of matches drawn by India: 1
--- Team 2 ---
Enter the name of team 2: Australia
Enter the number of matches played by Australia: 5
Enter the number of matches won by Australia: 3
Enter the number of matches lost by Australia: 1
Enter the number of matches drawn by Australia: 1
--- Team 3 ---
Enter the name of team 3: England
Enter the number of matches played by England: 5
Enter the number of matches won by England: 1
Enter the number of matches lost by England: 3
Enter the number of matches drawn by England: 1

**Output:**
CRICKET TOURNAMENT SCORECARD
| Team Name           Played   Won   Lost  Draw  Points |
| India               5        4     0     1     9      |
| Australia           5        3     1     1     7      |
| England             5        1     3     1     3      |

---

## ✅ Features

- Input validation — won't crash if you type letters instead of numbers
- Handles any number of teams dynamically
- Auto sorts teams by points (highest to lowest)
- Clean formatted table output
- Simple and beginner-friendly C code

---

## 🚧 Known Limitations

- Team names cannot contain spaces (e.g. use `SriLanka` not `Sri Lanka`)
- No file saving — results are shown on screen only
- No tie-breaker logic if two teams have equal points

---

## 🔮 Future Improvements

- [ ] Add net run rate (NRR) as a tie-breaker
- [ ] Save scorecard to a `.txt` file
- [ ] Allow team names with spaces
- [ ] Add match-by-match result entry
- [ ] Color-coded terminal output

---

## 👩‍💻 About

Built by **[SWATI SWAROOP]** as a C programming practice project.  
Concepts used: structs, arrays, loops, sorting, formatted output, input validation.

---