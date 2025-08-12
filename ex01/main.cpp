#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

#include <ex01/Span.hpp>

// It may be better to add more test cases.
int main() {
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
    } catch (const Span::SpanException &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::srand(std::time(NULL));
        Span emptySpan(1000000);
        for (int i = 0; i < 100000; ++i) {
            emptySpan.addNumber(std::rand());
        }
        for (int i = 0; i < 100000; ++i) {
            emptySpan.shortestSpan();
            emptySpan.longestSpan();
        }
    } catch (const Span::SpanException &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Span emptySpan(5);
        emptySpan.longestSpan();
    } catch (const Span::SpanException &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Span emptySpan(5);
        emptySpan.shortestSpan();
    } catch (const Span::SpanException &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
