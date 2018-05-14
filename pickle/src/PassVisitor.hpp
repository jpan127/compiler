#pragma once

#include <iostream>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "Pcl2BaseVisitor.h"
#include "antlr4-runtime.h"
#include "Pcl2Visitor.h"

#include "common.hpp"

using namespace wci;
using namespace wci::intermediate;



class PassVisitor
{
protected:

    PassVisitor() : scope_counter(0) { }

    virtual ~PassVisitor() { }

    /// Just a tab character
    static const char TAB = '\t';

    static const map <string, TypeSpec **> type_map;

    static const unordered_map <TypeSpec **, char> letter_map;

    uint64_t scope_counter;

    TypeSpec * resolve_expression_type(TypeSpec * lhs_type, TypeSpec * rhs_type);

    char letter_map_lookup(const TypeSpec * type) const;

    /**
     *  Prints the current visit context information if [debug_flag] is true
     *  @param context   : Current context or parser rule
     *  @param rule_name : Name of current rule
     */
    void print_debug_context(const uint8_t pass_num, antlr4::ParserRuleContext * context, const std::string & rule_name) const;

    static bool is_digit(const string & identifier)
    {
        return std::isdigit(identifier[0]);
    }
};