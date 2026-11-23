/*
 * Author: Aiden Sinclair
 * Program: ExceptionLab
 * Date: November 23, 2026
 * Purpose: Declares the input file utility.
 */
#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <fstream>
#include <string>
void openFileForReading(std::ifstream& file, const std::string& filename);
#endif
