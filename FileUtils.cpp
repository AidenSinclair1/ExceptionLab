/*
 * Author: Aiden Sinclair
 * Program: ExceptionLab
 * Date: November 23, 2026
 * Purpose: Opens a file or throws FileOpenException.
 */
#include "FileUtils.h"
#include "Exceptions.h"
void openFileForReading(std::ifstream& file, const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) throw FileOpenException("Unable to open file: " + filename);
}
