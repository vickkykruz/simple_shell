## Simple Shell
<p align="center"><img src="https://www.tutorialbar.com/wp-content/uploads/3546580_a73b-2048x1152.jpeg" alt="simple shell"></p>

### Concept Of This Project
<p>A shell is a program that provides an interface between the user and the operating system. It allows users to interact with the operating system by entering commands and receiving output. The shell acts as a command interpreter, executing commands and providing the results to the user.</p>
<p>Here is a general overview of how a shell works:</p>

#### 1. Command Input:
<p> The user enters a command into the shell, typically by typing it in the terminal. The command can be a built-in shell command or an external program.</p>

#### 2. Parsing:
<p>The shell parses the command entered by the user, breaking it down into individual components. This includes identifying the command itself, any arguments or options, and any redirection or piping instructions.</p>

#### 3. Command Execution:
<p> Depending on the type of command, the shell takes appropriate action. If the command is a built-in shell command (e.g., changing directories), the shell executes it directly. If the command is an external program, the shell searches for the program in the system's directories and then executes it.</p>

#### 4. Input/Output Handling:
<p> The shell manages input/output for the executed command. This involves handling standard input (stdin), standard output (stdout), and standard error (stderr). The shell can redirect input or output using symbols like ">" for output redirection or "<" for input redirection. It can also enable piping, which allows the output of one command to be used as input for another command.</p>

#### 5. Process Control:
<p> When executing external programs, the shell creates a new process to run the program. It manages process control, which includes creating, terminating, and monitoring processes. The shell may also provide job control, allowing users to run multiple commands simultaneously or in the background.</p>

#### 6. Environment Management:
<p> The shell manages the environment in which commands are executed. It maintains a set of environment variables that can be accessed by the user or the running programs. Environment variables store information such as paths to executable files or user preferences.</p>

#### 7. Command Completion and History: 
<p> Command completion helps users by suggesting or automatically completing commands or filenames as they type. Command history allows users to access previously executed commands and re-execute them with ease.</p>

### Algorithm Of This Project
1. Prompt the user to enter the command.
2. Read the command from the user.
3. Parse the command to idenity the commmand itself (arguments, options, redirection, and piping instructions).
4. If the command is a built-in shell command:
    <pre>
    a. Execute the built-in command
    b. Go to step 1.
    </pre>
5. If the command is an external program:
    <pre>
    a. Search for the program system directories
    b. if the program is found
        a. Create a new process to run the program
        b. Set up input/output redirection if specified
        c. Execute the program
        d. Wait for the program to finish
    a. If the program is not found:
        a. Display an error message
    a. Go to step 1.
    </pre>
6. Continue the shell execution until the user exits

### Flowchart of this project
<p align="center"><img src="https://i.ibb.co/nPVswf0/Screenshot-20230708-103555.png" alt="Flowchart for simple shell project" /></p>

### Collabrators for this project
1. Onwuegbuchulem Victor Chukwuemeka <onwuegbuchulemvic02@gmail.com>
2. Adeola johnson <johnsamxy@gmail.com>

<p align="center"> ALX AFRICA </p>
