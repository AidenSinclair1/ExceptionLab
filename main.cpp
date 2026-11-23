/*
 * Author: Aiden Sinclair
 * Program: ExceptionLab - Shape File Parser
 * Date: November 23, 2026
 * Purpose: Reads one shape record per line, calculates its measurements,
 *          and handles file, parsing, and invalid-dimension exceptions.
 */
#include "Exceptions.h"
#include "FileUtils.h"
#include "GeometryUtils.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

int main() {
    const std::string filename = "shapes.txt";
    std::ifstream inputFile;

    try {
        openFileForReading(inputFile, filename);
    } catch (const FileOpenException& ex) {
        std::cerr << "File error: " << ex.what() << std::endl;
        return 1;
    }

    std::string line;
    int lineNumber = 0;
    std::cout << std::fixed << std::setprecision(2);

    // Read whole records, not individual tokens. Unknown shape dimensions
    // therefore cannot accidentally be parsed as additional shape names.
    while (std::getline(inputFile, line)) {
        ++lineNumber;
        if (line.empty()) continue;

        std::istringstream record(line);
        std::string shape;
        if (!(record >> shape)) continue;

        try {
            if (shape == "square") {
                double side;
                if (!(record >> side)) throw std::invalid_argument("Missing or invalid square side.");
                std::cout << "Square | Area: " << calculateArea(side)
                          << " | Perimeter: " << calculatePerimeter(side) << std::endl;
            } else if (shape == "rectangle") {
                double length, width;
                if (!(record >> length >> width))
                    throw std::invalid_argument("Missing or invalid rectangle dimensions.");
                std::cout << "Rectangle | Area: " << calculateArea(length, width)
                          << " | Perimeter: " << calculatePerimeter(length, width) << std::endl;
            } else if (shape == "circle") {
                double radius;
                if (!(record >> radius)) throw std::invalid_argument("Missing or invalid circle radius.");
                std::cout << "Circle | Area: " << calculateArea(radius, shape)
                          << " | Circumference: " << calculatePerimeter(radius, shape) << std::endl;
            } else {
                throw ParseException("Unknown shape '" + shape + "'.");
            }
        } catch (const ParseException& ex) {
            std::cerr << "Line " << lineNumber << " - Parse error: " << ex.what() << std::endl;
        } catch (const std::invalid_argument& ex) {
            std::cerr << "Line " << lineNumber << " - Invalid data: " << ex.what() << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Line " << lineNumber << " - Unexpected error: " << ex.what() << std::endl;
        }
    }

    inputFile.close();
    std::cout << "Finished processing " << lineNumber << " line(s)." << std::endl;
    return 0;
}
