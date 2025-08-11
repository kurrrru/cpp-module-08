#include <exception>
#include <string>

#include <ex01/Span.hpp>

Span::SpanException::SpanException(const std::string &message)
    : _message(message) {
}

const char *Span::SpanException::what() const throw() {
    return _message.c_str();
}

Span::SpanException::~SpanException() throw() {
}
