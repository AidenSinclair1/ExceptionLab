/*
 * Author: Aiden Sinclair
 * Program: ExceptionLab
 * Date: November 23, 2026
 * Purpose: Calculates square, rectangle, and circle measurements.
 */
#include "GeometryUtils.h"
#include <stdexcept>
namespace {
const double PI = 3.14159265358979323846;
void checkPositive(double value, const std::string& label) {
    if (value <= 0.0) throw std::invalid_argument(label + " must be greater than zero.");
}
}
double calculateArea(double side) { checkPositive(side, "Square side"); return side * side; }
double calculatePerimeter(double side) { checkPositive(side, "Square side"); return 4.0 * side; }
double calculateArea(double length, double width) {
    checkPositive(length, "Rectangle length"); checkPositive(width, "Rectangle width");
    return length * width;
}
double calculatePerimeter(double length, double width) {
    checkPositive(length, "Rectangle length"); checkPositive(width, "Rectangle width");
    return 2.0 * (length + width);
}
double calculateArea(double radius, const std::string& shape) {
    if (shape != "circle") throw std::invalid_argument("Circle calculation requires circle tag.");
    checkPositive(radius, "Circle radius"); return PI * radius * radius;
}
double calculatePerimeter(double radius, const std::string& shape) {
    if (shape != "circle") throw std::invalid_argument("Circle calculation requires circle tag.");
    checkPositive(radius, "Circle radius"); return 2.0 * PI * radius;
}
