#ifndef INCLUDE_INJA_MODEL_HPP_
#define INCLUDE_INJA_MODEL_HPP_

#include <filesystem>
#include <fstream>

#include "exceptions.hpp"
#include "json.hpp"
#include "throw.hpp"

namespace inja {

class json_metamodel {
public:
  using model_type = json;

  static model_type load(const std::filesystem::path& filename) {
    std::ifstream file;
    file.open(filename);
    if (file.fail()) {
      INJA_THROW(FileError("failed accessing file at '" + filename.string() + "'"));
    }
    return json::parse(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
  }
};

} // namespace inja

#endif // INCLUDE_INJA_MODEL_HPP_
