#ifndef DEBUG_HH
#define DEBUG_HH

#include <string>
#include <iostream>
#include <iomanip>
#include "chunk.hh"

class Debuger{
public:
  void Disassemble(const Chunk &chunk, std::string name) const
  {
    std::cout << "==== " << name << " ====\n";
    auto size_code = chunk.size();
    for (size_t offset = 0; offset < size_code;)
    {
      offset = DisassembleInstruction(chunk, offset);
    }
  }
private:
  size_t DisassembleInstruction(const Chunk &chunk, size_t offset) const
  {
    std::cout << std::setfill('0') << std::setw(4) << offset << "\t";
    auto instruction = chunk[offset];
    switch(instruction){
      case OpCode::OP_RETURN:
      {
        return SimpleInstruction("OP_RETURN", offset);
      }
      case OpCode::OP_UNKNOWN:
      {
        return SimpleInstruction("OP_UNKNOWN", offset);
      }
      case OpCode::OP_CONSTANT:
      {
        return ConstantInstruction(chunk, "OP_CONSTANT", offset);
      }
      default:
      {
        std::cout << "undefined operation\n";
        return ++offset;
      }
    }
  }
  size_t SimpleInstruction(std::string &&op_name, size_t offset) const
  {
    std::cout << op_name << "\n";
    return ++offset;
  }
  size_t ConstantInstruction(const Chunk &chunk, std::string &&op_name, size_t offset) const
  {
    auto pos = static_cast<size_t>(chunk[offset+1]);
    std::cout << op_name << "\t@" << pos << "\t";
    std::cout << chunk.constant(pos) << "\n";
    return offset + 2;
  }
};

#endif // DEBUG_HH
