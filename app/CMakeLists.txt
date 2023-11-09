add_executable(test
  Test.cpp
)

target_link_libraries(test
  PRIVATE
    libClean
)

target_compile_features(test PRIVATE cxx_std_20)
