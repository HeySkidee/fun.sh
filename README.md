# fun.sh

Terminal-based utility for good times!

This project follows the "learn by building" philosophy, where I implemented various C concepts by creating something fun

## Features

-   Dark humor jokes via the JokeAPI
-   Random fun facts
-   Weather information for any city using wttr.in
-   Color-coded terminal interface

## Installation

### Windows

1. Download the latest release from [releases](https://github.com/HeySkidee/fun.sh/releases/download/v0.1.0/)
2. Option 1: Run directly from the downloaded location
3. Option 2:
    ```powershell
    # Create directory
    mkdir "C:\Program Files\fun"
    # Move executable
    move fun.exe "C:\Program Files\fun\"
    # Add to PATH (run in PowerShell as Administrator)
    [Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\Program Files\fun", "Machine")
    ```

### Linux

1. Download the latest release from [releases]()
2. Make it executable:
    ```bash
    chmod +x fun_linux
    ```
3. Run directly:
    ```bash
    ./fun_linux
    ```
4. Optional - Install system-wide:
    ```bash
    sudo mv fun_linux /usr/local/bin/fun
    ```

## Technical Implementation Details

The project implements various C programming concepts:

-   Screen manipulation using ANSI escape codes
    -   `\033[2J` - Clear screen
    -   `\033[H` - Move cursor to top-left
-   Color coding output using ANSI color codes and then resetting the color
-   External API interaction using `system()` and `curl`
-   Using `fgets` instead of `scanf` for better string input handling
-   Seeding random numbers with `srand(time(NULL))` then generating random numbers `rand()`
-   String manipulation with `strcspn` to remove newlines

## Dependencies

-   GCC or any C compiler
-   curl installed on your system

## Future improvements

-   Add more interactive features
