// #pragma once

// #include "globals.hpp"



// /**
//  *  An intermediate code node belongs to an abstract syntax tree (AST)
//  *  Each node has its own attributes which specify the nodes operation and purpose
//  *  @TODO : Evaluate when these names get too long, verbosity is good, but not if it sacrifices readability
//  */

// /// Enumerate different intermediate code node types
// /// @TODO: Understand these
// enum class IntermediateCodeNodeType
// {
//     /// Structure
//     node_function,
//     /// Statements
//     node_compound,
//     node_assignment,
//     node_loop,
//     node_parameters,
//     node_if,
//     /// Relational
//     node_equal,
//     node_not_equal,
//     node_less_than,
//     node_greater_than,
//     node_less_than_or_equal,
//     node_greater_than_or_equal,
//     node_not,
//     /// Additive
//     node_add,
//     node_subtract,
//     node_or,
//     node_negate,
//     /// Multiplicative
//     node_multiply,
//     node_divide_int,
//     node_divide_fpoint,
//     node_modulus,
//     node_and,
//     /// Operands
//     node_variable,
//     node_mutable_int,
//     node_mutable_fpoint,
//     node_mutable_string,
//     node_mutable_bool,
// };

// /// Enumerate different attributes of a node
// enum class IntermediateCodeNodeAttribute
// {

// };

// template <typename T>
// class IntermediateCodeNode
// {
// public:

//     /**
//      *  Constructor
//      *  @param type : The type of node which specifies its action
//      */
//     IntermediateCodeNode(IntermediateCodeNode * parent, const IntermediateCodeNodeType type);

//     /// Destructor for [children]
//     ~ IntermediateCodeNode(void);

//     /// Returns a pointer to this node's parent node
//     IntermediateCodeNode * get_parent_node(void) const;

//     /// Returns the type of this node
//     const IntermediateCodeNodeType get_node_type(void) const;

//     /// Returns a vector of pointers to all the nodes that branch of this node
//     vector <IntermediateCodeNode *> & get_child_nodes(void) const;

//     /**
//      *  Retrieves the value of a specified attribute if it exists
//      *  @param attribute : The attribute to look up
//      *  @param data      : Pass in struct to retrieve data into
//      *  @returns         : True for found attribute, false for does not exist
//      */
//     bool get_attribute(const IntermediateCodeNodeAttribute attribute, data_S <T> & data) const;

//     /**
//      *  Sets the value of a specified attribute
//      *  @param attribute : The attribute to set
//      *  @param data      : Pass in struct to copy into [attributes]
//      */
//     void set_attribute(const IntermediateCodeNodeAttribute attribute, const data_S <T> & data);

//     /**
//      *  Sets the parent of the input node as this node
//      *  @param node : The node to modify
//      */
//     void set_parent(IntermediateCodeNode & node);

//     /**
//      *  Adds a node to [children]
//      *  @param child_node : A new already allocated node
//      */
//     void add_child_node(IntermediateCodeNode * child_node);

// private:

//     /// Type of this node
//     const IntermediateCodeNodeType type;

//     /// Pointer to parent node
//     IntermediateCodeNode * parent;

//     /// Child nodes that branch off this node
//     vector <IntermediateCodeNodeType *> children;

//     /// Various attributes and values that belong to this node
//     map <const IntermediateCodeNodeAttribute, const data_S <T>> attributes;

// };
