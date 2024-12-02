CUSTOM SHELL-COMMAND SHELL INTERPRETER

This program implements a simple Custom Shell in C++ that allows users to:

Manage variables with basic commands like set and get.
View a history of entered commands.
Execute external system commands in a thread-safe manner.
The shell continuously prompts the user for input until the exit command is entered.


Operations:

i)Set variables:
  Stores a variable with a specified value in an internal data structure.
  format: set<variable name><value>

ii)Get variables:
  Retrieves and displays the value of a specified variable. If the variable doesn't exist, it outputs "Variable not found."
 format: get<variable name>

iii)Command History:
   Displays the last 10 commands entered by the user.
   format: history

iv)Execute System Commands:
   Executes the command in a separate thread using std::system.
   format: Any valid system command (e.g., ls, dir, echo Hello).

v)Exit the Shell:
  Terminates the shell.
  format: exit



Libraries used:

  <iostream>: For input and output.
  <string>: To handle string operations.
  <vector>: (Included for potential extensions but not actively used).
  <unordered_map>: To store variables.
  <queue>: To maintain command history.
  <sstream>: For parsing commands.
  <thread>: For thread-based execution.
  <cstdlib>: For std::system command execution.


Code Breakdown

i)Main Function:
Instantiates the Customshell class and starts the shell loop using run().
ii)Class: Customshell:
Contains methods to handle various commands and features.
Methods:
run():

The main loop of the shell. Continuously accepts user input and processes commands.
processcommand():

Parses the input command and determines which operation to perform:
set → Calls setvariable()
get → Calls getvariable()
history → Calls printhistory()
Others → Calls executecommand()
addtohistory():

Adds a command to the history queue. Maintains a maximum of 10 commands.
printhistory():

Outputs the list of recent commands.
setvariable():

Stores a variable name and value in an unordered map.
getvariable():

Retrieves a variable's value from the map or reports if it is not found.
executecommand():

Executes external system commands using std::system in a separate thread.






