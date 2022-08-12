get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS ${dialect_libs} ${conversion_libs} MLIRLspServerLib MLIRStandalone)
add_llvm_executable(standalone-lsp-server standalone-lsp-server.cpp)

llvm_update_compile_flags(standalone-lsp-server)
target_link_libraries(standalone-lsp-server PRIVATE ${LIBS})
