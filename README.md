# CS2341 - Using Dirent.

## Demo Overview

This is a demo project for SMU CS 2341 - Data Structures. The intent is to provide an example
for using dirent.h to read and analyze contents for all files in a Directory.

## Choosing your Library

There are many libraries that allow you to read contents of files in a directory in C++.

- **dirent.h**....................................A C library (available alongside the C++ standard library).
- **std::filesystem (C++17)**...........Available in C++17 as a new alternative to dirent.
- **boost::filesystem**.....................Where std::filesystem used to live before C++17. You
will need to install boost if you wish to use this library.
  
Whichever library you choose, it's important that you understand how to include the library in your project, and
you know where to find out how your library performs basic directory iterating. In all these libraries, you shouldn't need
to include more than one header file (even if you're copying an entire directory into your project), so if you find yourself
using #include many times, there's probably an easier way you are missing.

Dirent, for example, only requires `#include <dirent.h>`.

## File paths

For the timing demo, we will be using the *Absolute Filepath* to locate the folder with your documents. This means
that you will need to specify the location of this folder from the root directory of your drive
(/C:/, etc. for Windows, / for Mac).

**Important Note for WSL: If you're using WSL but the directory you're looking for is on Windows (/C:), the absolute filepath starts with your mounted drive (/mnt/c/<path_to_directory>/).**

If you're unsure how to get the absolute path of a file:

1. Right click any file in your project 
2. Click 'Copy Path'.
3. Click 'Absolute Path'.
4. The path is saved to the clipboard; paste it where you like.

**Note that absolute filepaths MUST start with a '/'. This is different from relative filepaths, which don't begin with a '/'.**

## Running the project

The project uses a dirent object to access 'DirectoryToRead.' Then, the first line in each
file in 'DirectoryToRead' will be printed out to the console.

You will need to specify ONE command line argument to run this demo.

- `argv[1]` - The ABSOLUTE PATH of the directory to be read. In your case, this argument
will be `/[C:]/<path_to_DirentDemo>/DirectoryToRead`.
  
Hopefully, looking through this code will give you a better understanding of how to apply
directory reading libraries such as Dirent to your final project. If you have any questions,
please reach out to one of us via Slack.

## Ingredients for Directory Reading

Using Dirent.h, there are two key 'ingredients' for reading contents in a directory:

- `struct dirent` object: This will store certain retrievable properties of a file in a directory.
In our case, we use this to retrieve the file name using `direntObj->d_name`, where `d_name` is the
  file name returned as a C-string.
  
**Note: when you open up a file using an fstream, you need to concatenate the file name with the
absolute path to the file, else your fstream will not recognize the file you're trying to read in.*

- `DIR*`: Treat this object as a "directory iterator". This pointer points to the first file
of the directory using `opendir()`. Then, each call to `readdir()` will advance the pointer one
  file. When you have iterated through every file in the directory, close it with `closedir()`.
  

- `opendir()` - Opens the directory.
- `readdir()` - Advances to the next file in the directory.
- `closedir()` - Closes the directory.

**Note: A conditional is included to ignore the '.' and '..' files. '.' refers to the current directory
(in the demo's case: `[C:]/<path_to_DirentDemo>/DirectoryToRead`), while '..' refers to the parent directory
(in the demo's case: `[C:]/<path_to_DirentDemo>/`).*

**Second Note: Yes, there is an assignment inside of a while conditional. This is perfectly
valid code (although this syntax is often not recommended). Assignment operators are typically
used in conditionals to check the boolean result of an assignment. In the demo, the assignment operation
evaluates to true if `entry` is assigned to a valid file, and false otherwise.*

## Resources

Online Documentation: [https://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html](https://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html)

Stack Overflow: [https://stackoverflow.com/questions/25070751/navigating-through-files-using-dirent-h](https://stackoverflow.com/questions/25070751/navigating-through-files-using-dirent-h)

As always, feel free to reach out to us if you have any questions. Happy Parsing!
