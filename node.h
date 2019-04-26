#pragma once
#include <string>
#include "comparison.h"
#include "date.h"

struct Node{
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

struct EmptyNode : public Node {
    bool Evaluate(const Date& date, const string& event) const override {
        return true;
    }
};

struct DateComparisonNode : public Node {
    bool Evaluate(const Date& date, const string& event) const override {
        return true;

    }
    DateComparisonNode(const Comparison& cmp, const Date& date);
};

struct LogicalOperationNode : public Node {
    bool Evaluate(const Date& date, const string& event) const override {
        return true;

    }
};

struct EventComparisonNode : public Node {
    bool Evaluate(const Date& date, const string& event) const override {

        return true;
    }
};
