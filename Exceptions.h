/*
 * Author: Aiden Sinclair
 * Program: ExceptionLab
 * Date: November 23, 2026
 * Purpose: Declares custom exceptions for file and parsing errors.
 */
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>
class FileOpenException : public std::exception {
public:
    explicit FileOpenException(const std::string& msg);
    const char* what() const noexcept override;
private:
    std::string message;
};
class ParseException : public std::exception {
public:
    explicit ParseException(const std::string& msg);
    const char* what() const noexcept override;
private:
    std::string message;
};
#endif
