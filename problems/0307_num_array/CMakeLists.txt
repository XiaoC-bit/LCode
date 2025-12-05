# 获取父工程的公共 src
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(p0307
    main.cpp
    solution.hpp
    ${COMMON_SRC}   # 引入公共代码（如 utils.cpp）
)
