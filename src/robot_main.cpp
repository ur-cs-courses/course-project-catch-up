#include <fmt/core.h>

#include "libclean/robot.hpp"

namespace hello {
auto say_hello() noexcept -> void { fmt::print("hello!\n"); }
} // namespace hello
