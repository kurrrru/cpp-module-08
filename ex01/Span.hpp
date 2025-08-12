#pragma once

#include <set>
#include <exception>
#include <string>

class Span {
 public:
    Span();
    explicit Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int value);
    void deleteNumber(int value);
    int shortestSpan() const;
    int longestSpan() const;

    class SpanException : public std::exception {
     public:
        explicit SpanException(const std::string &message);
        const char *what() const throw();
        virtual ~SpanException() throw();
     private:
        std::string _message;
    };

 private:
    std::multiset<int> _numbers;
    std::multiset<int> _adjs_spans;
    unsigned int _maxSize;
};
