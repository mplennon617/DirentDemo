#include <iostream>
#include <fstream>
#include <dirent.h> // Include this header file to read directories! (Note the '<>' as opposed to '""')

/*******************************************************************
 * CS 2341 - Demo project for reading in files from a directory.
 * Done using Dirent.h.
 *
 * argv[1] - The absolute path to the directory we want to read.
 *******************************************************************/

/**
 * main function.
 *
 * @param argc -    number of command line arguments.
 * @param argv -    char** containing each command line argument.
 *                  argv[1] - the absolute path to the directory we want to read.
 *                      For the demo, set it to "path_to_project/DirentDemo/DirectoryToRead"
 *
 * @return 0 if directory was successfully accessed read, 1 if not.
 */
int main(int argc, char** argv) {
    struct dirent *entry = nullptr; // A dirent object, which stores the contents of a file in a directory.
    DIR *dp = nullptr;              // A DIR object. Think of it as a 'directory iterator' -- it reads through all the files in a directory.

    // Set our 'dir' variable to the absolute directory path.
    std::string dir = argv[1];

    // This will be in the form "<directory>/<current_file>".
    std::string thisFilePath = "";

    dp = opendir(dir.c_str());  // Sets dp to the first file in the directory with path 'dir.'
                                // Think of this as a 'begin()' function for a standard sequential container iterator (std::vector iterator, etc.).

    // If the DIR object (directory iterator) successfully opened a directory, iterate through all files using readdir() in a while loop.
    if (dp != nullptr) {
        // If readdir() executed successfully, perform an iteration of the while loop; otherwise, stop reading.
        while ((entry = readdir(dp))) {
            thisFilePath = dir + "/" + entry->d_name; // This will set 'thisFilePath' to the ABSOLUTE path of the FILE.

            // Often times, directories read include '.' (current directory) and '..' (previous directory).
            // In our implementation, we're ignoring them.
            if (thisFilePath.find_last_of(".") == thisFilePath.size() - 1 || thisFilePath.find_last_of("..") == thisFilePath.size() - 1 ) continue;
            // '.' - current directory. [C:]/<path_to_DirentDemo>/DirectoryToRead
            // '..' - [C:]/<path_to_DirentDemo>/


            // Open up the current file in the directory (absolute path) to read its contents.
            std::ifstream fin(thisFilePath.c_str());

            std::string lineToPrintOut;
            // Reads in the first line of each file.
            getline(fin, lineToPrintOut);

            // Print out contents of the line just read.
            std::cout << lineToPrintOut << std::endl;
        }
    }
    else {
        std::cout << "DirentDemo - main(): Directory not found" << std::endl;
        return 1;
    }

    // Close the directory when done.
    closedir(dp);

    return 0;
}
