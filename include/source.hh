#ifndef SOURCE_HH
#define SOURCE_HH

#include <string>
#include <iostream>
#include "utility.hh"

namespace loxpp{

class Source
{
public:
  Source(){}
  DEFAULT_SPECIAL_FUNCTIONS(Source);
  inline std::string data() const;
  friend std::ostream& operator<<(std::ostream &os, const Source &src);
private:
  std::string data_;
};

} // namespace loxpp

#endif // SOURCE_HH