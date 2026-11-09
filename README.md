# Pipex - 42 Barcelona

Pipex is a systems programming project from the 42 Barcelona curriculum. The objective is to recreate the behavior of the UNIX shell pipeline mechanism in C. The mandatory program reproduces the exact execution of the shell command: < infile cmd1 | cmd2 > outfile. It manages file descriptors, inter-process communication via pipes, child process creation with fork, and binary execution using execve. The bonus version expands this functionality to handle multiple sequential pipelines (< infile cmd1 | cmd2 | cmd3 ... | cmdN > outfile) as well as here-document redirection (cmd1 << LIMITER | cmd2 >> outfile).

# Prerequisites

To compile and run Pipex, ensure you have:

- A C compiler: gcc or clang
- GNU Make
- Standard C library
- POSIX-compliant operating system (Linux or macOS)

# Configuration

1. Clone the repository:
```bash
git clone https://github.com/adrmarqu/pipex.git
cd pipex
```

No external libraries are required. Pipex uses native POSIX system calls and includes a bundled copy of Libft.

# Execution

### Mandatory Execution (Two Commands)

Compile the mandatory program:
```bash
make
```

Run pipex with the following syntax:
```bash
./pipex infile cmd1 cmd2 outfile
```

This replicates the behavior of:
```bash
< infile cmd1 | cmd2 > outfile
```

Example:
```bash
./pipex input.txt "grep 42" "wc -l" output.txt
```

### Bonus Execution (Multiple Pipes and Here-Document)

Compile the bonus program:
```bash
make bonus
```

1. Multiple Pipes:
```bash
./pipex_bonus infile cmd1 cmd2 cmd3 cmd4 outfile
```
Replicates:
```bash
< infile cmd1 | cmd2 | cmd3 | cmd4 > outfile
```
Example:
```bash
./pipex_bonus input.txt "cat" "grep Barcelona" "tr a-z A-Z" "sort" output.txt
```

2. Here-Document (Append mode):
```bash
./pipex_bonus here_doc LIMITER cmd1 cmd2 outfile
```
Replicates:
```bash
cmd1 << LIMITER | cmd2 >> outfile
```
Example:
```bash
./pipex_bonus here_doc EOF "grep error" "wc -l" log.txt
```

# Project Structure

```
pipex/
├── Makefile                 # Build orchestration for pipex and pipex_bonus
├── include/                 # Header files
│   ├── pipex.h              # Function prototypes and data structures
│   └── color.h              # ANSI terminal formatting macros
├── libft/                   # Bundled custom C utility library
└── src/                     # Source code modules
    ├── main/                # Mandatory implementation
    │   ├── pipex.c          # Entrypoint and process pipeline initialization
    │   ├── child.c          # Child process execution and pipe redirection
    │   ├── path.c           # PATH environment variable parsing and lookup
    │   └── utils.c          # File descriptor cleanup and error handling
    └── bonus/               # Bonus implementation
        ├── pipex_bonus.c    # Entrypoint for multiple pipes and here-doc
        ├── pipe_bonus.c     # Multi-pipe chaining and process loops
        ├── here_doc_bonus.c # Here-document reader and temporary buffering
        ├── path_bonus.c     # Executable path resolver for bonus
        └── utils_bonus.c    # File opening with O_APPEND / O_TRUNC modes
```

# Commands and Makefile Targets

- make or make all: Compiles libft and the mandatory pipex executable
- make bonus: Compiles libft and the bonus pipex_bonus executable
- make clean: Removes compiled object files (.o) in pipex and libft
- make fclean: Removes object files and compiled binaries (pipex, pipex_bonus, libft.a)
- make re: Rebuilds the entire project from scratch

# Technical Highlights

- Process Separation: Spawns discrete processes for each command using fork and collects exit codes using waitpid.
- Pipeline Duplication: Manipulates standard input and standard output streams using dup2 while safely closing unused pipe endpoints to prevent hangs.
- Binary Discovery: Inspects the system PATH environment variable to dynamically locate command binaries, also accepting direct relative (./prog) and absolute (/bin/cat) paths.
- Error Fidelity: Mimics standard shell diagnostic messages and returns proper POSIX exit codes when encountering missing files, permission errors, or unknown commands.

# Author Details

Author: Adrià Márquez Nebot
Github: https://github.com/adrmarqu
LinkedIn: https://www.linkedin.com/in/adria-marquez
Portfolio: https://adrmarqu.github.io
