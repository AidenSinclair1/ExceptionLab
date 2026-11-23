/*
 * Author: Aiden Sinclair
 * Program: ExceptionLab
 * Date: November 23, 2026
 * Purpose: Implements custom exception constructors and what() methods.
 */
#include "Exceptions.h"
FileOpenException::FileOpenException(const std::string& msg) : message(msg) {}
const char* FileOpenException::what() const noexcept { return message.c_str(); }
ParseException::ParseException(const std::string& msg) : message(msg) {}
const char* ParseException::what() const noexcept { return message.c_str(); }
