#include "common.hpp"


std::ostream & operator << (std::ostream & out, const InvalidCase & e)            { out << "[InvalidCase] "            << e.error; return out; }
std::ostream & operator << (std::ostream & out, const FileOpenError & e)          { out << "[FileOpenError] "          << e.error; return out; }
std::ostream & operator << (std::ostream & out, const InvalidOperator & e)        { out << "[InvalidOperator] "        << e.error; return out; }
std::ostream & operator << (std::ostream & out, const MissingSymbol & e)          { out << "[MissingSymbol] "          << e.error; return out; }
std::ostream & operator << (std::ostream & out, const InvalidType & e)            { out << "[InvalidType] "            << e.error; return out; }
std::ostream & operator << (std::ostream & out, const AntlrParsedIncorrectly & e) { out << "[AntlrParsedIncorrectly] " << e.error; return out; }
