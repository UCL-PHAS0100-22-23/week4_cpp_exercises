add_executable(Templates Templates.cpp Polynomial.cpp Fraction.cpp)
target_include_directories(Templates PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(Templates PUBLIC cxx_std_17)
set_target_properties(Templates PROPERTIES CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)