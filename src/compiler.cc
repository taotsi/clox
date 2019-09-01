#include "compiler.hh"
#include <iomanip>

namespace loxpp
{

Chunk Compiler::compile(std::string &src)
{
  size_t line = -1;
  scanner_.load_source(src);
  while(true)
  {
    scanner_.load_source(src);
    auto token = scanner_.scan_token();
    if(token.line() != line)
    {
      std::cout << std::setw(4) << line;
      line = token.line();
    }
    else
    {
      std::cout << "  | ";
    }
    std::cout << std::setw(20) << token.type() << "  " << token.lenght() << "  " << token.start() << "\n";
    if(token.type() == TokenType::EOF)
    {
      break;
    }
  }
  return Chunk{};
}

}