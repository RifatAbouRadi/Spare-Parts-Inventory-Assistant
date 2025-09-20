# Spare-Parts-Inventory-Assistant


## Project Description
This program simulates a simple spare parts inventory assistant.  
The assistant greets the user, asks which part they need, and checks against an internal database of available parts (`hydraulic pump`, `PLC module`, and `servo motor`).  
The program also handles two special queries:
- *"Do you actually have any parts?"*  
- *"Is there anything in stock at all?"*  

If one of these is entered, the assistant responds with the total number of parts in stock and lists them.  

The program continues looping until the user requests a part that is available.  
Only then does the program exit with a confirmation message.

---

## Features
- Takes user input for requested part  
- Handles special queries (case-sensitive, exact text)  
- Checks if the requested part is in inventory  
- Loops until a valid part is found  
- Exits only after confirming that a part is available  

---

## Files
- `main.c` → The source code of the program  
- `README.md` → This documentation  

---

## How to Compile and Run

### Option 1: Run in an Online C Compiler
If GCC is not available, you can use an online C compiler such as:  
👉 [Programiz Online C Compiler](https://www.programiz.com/c-programming/online-compiler/)  

### Option 2: Compile with GCC locally
```bash
gcc main.c 
inventory.exe   # on Windows
