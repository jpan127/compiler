// #include "IntermediateCodeNode.hpp"

// #include <cassert>



// template <typename T>
// IntermediateCodeNode::IntermediateCodeNode(IntermediateCodeNode * parent, const IntermediateCodeNodeType type) : type(type)
//                                                                                                                  parent(parent)
// {

// }

// template <typename T>
// IntermediateCodeNode::~IntermediateCodeNode(void)
// {
//     // Release the children!!!
//     for (auto & node : children)
//     {
//         delete node;
//     }
// }

// template <typename T>
// IntermediateCodeNode * IntermediateCodeNode::get_parent_node(void) const
// {
//     return parent;
// }

// template <typename T>
// const IntermediateCodeNodeType IntermediateCodeNode::get_node_type(void) const
// {
//     return type;
// }

// template <typename T>
// vector <IntermediateCodeNode *> & IntermediateCodeNode::get_child_nodes(void) const
// {
//     return children;
// }

// template <typename T>
// bool IntermediateCodeNode::get_attribute(const IntermediateCodeNodeAttribute attribute, data_S <T> & data) const
// {
//     bool found = false;

//     if (attributes.count(attribute) > 0)
//     {
//         data  = attributes[attribute];
//         found = true;
//     }

//     return found;
// }

// template <typename T>
// void IntermediateCodeNode::set_parent(IntermediateCodeNode & node)
// {
//     node.parent = this;
// }

// template <typename T>
// void IntermediateCodeNode::add_child_node(IntermediateCodeNode * child_node)
// {
//     if (nullptr != child_node)
//     {
//         assert(child_node);
//         children.push_back(child_node);
//         set_parent(*child_node);
//     }
// }

// template <typename T>
// void IntermediateCodeNode::set_attribute(const IntermediateCodeNodeAttribute attribute, const data_S <T> & data)
// {
//     /// Can I copy something passed by reference? I forgot
//     attributes[attribute] = data;
// }
