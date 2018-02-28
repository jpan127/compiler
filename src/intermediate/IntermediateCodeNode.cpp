#include "IntermediateCodeNode.hpp"

#include <cassert>



IntermediateCodeNode::IntermediateCodeNode(IntermediateCodeNode * parent, const IntermediateCodeNodeType type) : type(type)
                                                                                                                 parent(parent)
{

}

IntermediateCodeNode::~IntermediateCodeNode(void)
{
    // Release the children!!!
    for (auto & node : children)
    {
        delete node;
    }
}

IntermediateCodeNode * IntermediateCodeNode::get_parent_node(void) const
{
    return parent;
}

const IntermediateCodeNodeType IntermediateCodeNode::get_node_type(void) const
{
    return type;
}

vector <IntermediateCodeNode *> & IntermediateCodeNode::get_child_nodes(void) const
{
    return children;
}

bool IntermediateCodeNode::get_attribute(const IntermediateCodeNodeAttribute attribute, node_data_S & data) const
{
    bool found = false;

    if (attributes.count(attribute) > 0)
    {
        data  = attributes[attribute];
        found = true;
    }

    return found;
}

void IntermediateCodeNode::set_parent(IntermediateCodeNode & node)
{
    node.parent = this;
}

void IntermediateCodeNode::add_child_node(IntermediateCodeNode * child_node)
{
    if (nullptr != child_node)
    {
        assert(child_node);
        children.push_back(child_node);
        set_parent(*child_node);
    }
}

void IntermediateCodeNode::set_attribute(const IntermediateCodeNodeAttribute attribute, const node_data_S & data)
{
    /// Can I copy something passed by reference? I forgot
    attributes[attribute] = data;
}
