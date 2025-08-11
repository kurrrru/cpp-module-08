#include <ex01/Span.hpp>

#include <exception>
#include <algorithm>
#include <iterator>
#include <set>

namespace {
std::multiset<int>::iterator previt(std::multiset<int>::iterator it) {
    std::advance(it, -1);
    return it;
}

std::multiset<int>::iterator nextit(std::multiset<int>::iterator it) {
    std::advance(it, 1);
    return it;
}
}  // namespace

Span::Span() : _maxSize(0) {
}

Span::Span(unsigned int n) : _maxSize(n) {
}

Span::Span(const Span &other) : _numbers(other._numbers),
    _adjs_spans(other._adjs_spans), _maxSize(other._maxSize) {
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _numbers = other._numbers;
        _adjs_spans = other._adjs_spans;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int value) {
    if (_numbers.size() >= _maxSize) {
        throw SpanException("Span::addNumber failed: "
            "Maximum size reached, cannot add more numbers.");
    }
    std::multiset<int>::iterator it = _numbers.insert(value);
    if (it != _numbers.begin() && nextit(it) != _numbers.end()) {
        std::multiset<int>::iterator prev = previt(it);
        std::multiset<int>::iterator next = nextit(it);
        _adjs_spans.erase(_adjs_spans.find(std::abs(*next - *prev)));
    }
    if (it != _numbers.begin()) {
        std::multiset<int>::iterator prev = previt(it);
        _adjs_spans.insert(std::abs(value - *prev));
    }
    if (nextit(it) != _numbers.end()) {
        std::multiset<int>::iterator next = nextit(it);
        _adjs_spans.insert(std::abs(*next - value));
    }
}

void Span::deleteNumber(int value) {
    if (_numbers.empty()) {
        throw SpanException("Span::deleteNumber failed: "
            "No numbers to delete.");
    }
    std::multiset<int>::iterator it = _numbers.find(value);
    if (it == _numbers.end()) {
        throw SpanException("Span::deleteNumber failed: "
            "Value not found in the span.");
    }
    if (it != _numbers.begin()) {
        _adjs_spans.erase(_adjs_spans.find(std::abs(*it - *previt(it))));
    }
    if (nextit(it) != _numbers.end()) {
        _adjs_spans.erase(_adjs_spans.find(std::abs(*nextit(it) - *it)));
    }
    if (it != _numbers.begin() && nextit(it) != _numbers.end()) {
        std::multiset<int>::iterator prev = previt(it);
        std::multiset<int>::iterator next = nextit(it);
        _adjs_spans.insert(std::abs(*next - *prev));
    }
    _numbers.erase(it);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw SpanException("Span::shortestSpan failed:"
            " Not enough numbers to calculate span.");
    }
    return *(_adjs_spans.begin());
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw SpanException("Span::longestSpan failed:"
            " Not enough numbers to calculate span.");
    }
    return *(_numbers.rbegin()) - *(_numbers.begin());
}
