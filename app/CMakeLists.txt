add_executable(slay
  Test.cpp
)

target_link_libraries(slay
  PRIVATE
    libClean
)

target_compile_features(slay PRIVATE cxx_std_20)
