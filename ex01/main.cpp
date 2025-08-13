#include <iostream>
#include <exception>
#include <cstdlib>
#include <vector>
#include <ctime>

#include <ex01/Span.hpp>

int main() {
    // This is a basic test for the Span class
    try {
        Span span(10);
        span.addNumber(1);
        span.addNumber(10);
        span.addNumber(5);
        span.addNumber(23);

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;

        span.addNumber(100);
        span.addNumber(13);

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;

        span.deleteNumber(5);
        span.deleteNumber(10);
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;

        span.addNumber(120);
        span.addNumber(130);
        span.addNumber(140);
        span.addNumber(150);
        span.addNumber(160);
        span.addNumber(170);
        try {
            span.addNumber(200);
        } catch (const Span::SpanException &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            span.addNumber(200);
        } catch (const Span::SpanException &e) {
            std::cerr << e.what() << std::endl;
        }
    } catch (const Span::SpanException &e) {
        std::cerr << "unexpected Exception: " << e.what() << std::endl;
    }

    // Test with a large number of elements
    try {
        std::srand(std::time(NULL));
        Span emptySpan(1000000);
        std::vector<int> values(100000);
        for (int i = 0; i < 100000; ++i) {
            int value = std::rand();
            emptySpan.addNumber(value);
            values[i] = value;
        }
        for (int i = 0; i < 100000; ++i) {
            emptySpan.shortestSpan();
            emptySpan.longestSpan();
        }
        for (int i = 0; i < 50000; ++i) {
            emptySpan.deleteNumber(values[i]);
        }
        for (int i = 0; i < 100000; ++i) {
            emptySpan.shortestSpan();
            emptySpan.longestSpan();
        }
    } catch (const Span::SpanException &e) {
        std::cerr << "unexpected Exception: " << e.what() << std::endl;
    }

    // Test with a test case that should throw exceptions
    try {
        Span emptySpan(5);
        try {
            emptySpan.shortestSpan();
        } catch (const Span::SpanException &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            emptySpan.longestSpan();
        } catch (const Span::SpanException &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            emptySpan.deleteNumber(1);
        } catch (const Span::SpanException &e) {
            std::cerr << e.what() << std::endl;
        }
        emptySpan.addNumber(1);
        try {
            emptySpan.shortestSpan();
        } catch (const Span::SpanException &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            emptySpan.longestSpan();
        } catch (const Span::SpanException &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            emptySpan.deleteNumber(2);
        } catch (const Span::SpanException &e) {
            std::cerr << e.what() << std::endl;
        }
    } catch (const Span::SpanException &e) {
        std::cerr << "unexpected Exception: " << e.what() << std::endl;
    }

    return 0;
}
