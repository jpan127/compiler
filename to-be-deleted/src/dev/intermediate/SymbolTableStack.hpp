#pragma once



/**
 *  This class acts as a stack for ordered push and pop, and random lookups
 *  Symbol tables are added to the stack as the scopes enter and popped from the stack
 *  as the scopes exit
 */

class SymbolTableStack
{
public:

    /// Constructor
    SymbolTableStack(void);

    /// Get level of current stack
    uint32_t get_current_stack_level(void) const;

    /// Get local symbol table (top of stack)
    SymbolTable * get_local_table(void) const;

    /**
     *  Add a new scope
     *  @param scope     : Name of the new table
     *  @param new_table : New table to copy into the stack
     */
    void push_new_table(const string scope, SymbolTable * new_table);

    /**
     *  Look up symbol table from a local scope
     *  @param scope : Name of the table to look up
     *  @param table : Pass in the table to modify
     *  @returns     : True for found, false for not found
     */
    bool lookup_local_table(const string scope, SymbolTable & table) const;

    /**
     *  Look up a symbol table outside of the local scope
     *  @param scope : Name of the table to look up
     *  @param table : Pass in the table to modify
     *  @returns     : True for found, false for not found
     */
    bool lookup_global_table(const string scope, SymbolTable & table) const;

private:

    /// Tracks the current stack level
    uint32_t level;

    /// Vector implemented as stack so that random lookup is possible
    vector <SymbolTable *> stack;

};