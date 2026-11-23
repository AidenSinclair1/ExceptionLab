/*
 * Author: Aiden Sinclair
 * Program: ExceptionLab
 * Date: November 23, 2026
 * Purpose: Declares overloaded area and perimeter functions.
 */
#ifndef GEOMETRYUTILS_H
#define GEOMETRYUTILS_H
#include <string>
double calculateArea(double side);
double calculatePerimeter(double side);
double calculateArea(double length, double width);
double calculatePerimeter(double length, double width);
double calculateArea(double radius, const std::string& shape);
double calculatePerimeter(double radius, const std::string& shape);
#endif
