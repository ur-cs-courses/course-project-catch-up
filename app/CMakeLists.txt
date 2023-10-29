add_executable(Room_Test
  Room_Test.cpp
)

target_link_libraries(Room_Test
  PRIVATE
    libRoom
)

target_compile_features(Room_Test PRIVATE cxx_std_20)
