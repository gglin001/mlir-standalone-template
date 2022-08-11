//===- StandaloneDialect.cpp - Standalone dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Standalone/StandaloneDialect.h"
#include "Standalone/StandaloneOps.h"
#include "Standalone/StandaloneTypes.h"
#include "mlir/IR/DialectImplementation.h"
#include "mlir/Support/LLVM.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace mlir;
using namespace mlir::standalone;
using namespace mlir::standalone::Standalone;

#include "Standalone/StandaloneDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Tablegen Type Definitions
//===----------------------------------------------------------------------===//

#define GET_TYPEDEF_CLASSES
#include "Standalone/StandaloneTypes.cpp.inc"

Type Standalone::parseStandaloneDialectType(AsmParser &parser) {
  SMLoc const typeLoc = parser.getCurrentLocation();
  StringRef mnemonic;
  Type genType;
  auto parseResult = generatedTypeParser(parser, &mnemonic, genType);
  if (parseResult.has_value())
    return genType;
  parser.emitError(typeLoc) << "unknown  type `" << mnemonic << "` in dialect `"
                            << StandaloneDialect::getDialectNamespace() << "`";
  return {};
}

void Standalone::printStandaloneDialectType(Type type, AsmPrinter &printer) {
  if (succeeded(generatedTypePrinter(type, printer)))
    return;
}

//===----------------------------------------------------------------------===//
// Standalone dialect parseType/printType methods.
//===----------------------------------------------------------------------===//

// Parse a type registered to this dialect.
Type StandaloneDialect::parseType(DialectAsmParser &parser) const {
  return parseStandaloneDialectType(parser);
}

// Print a type registered to this dialect.
void StandaloneDialect::printType(Type type, DialectAsmPrinter &printer) const {
  printStandaloneDialectType(type, printer);
}

//===----------------------------------------------------------------------===//
// Dialect initialize method.
//===----------------------------------------------------------------------===//

void StandaloneDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Standalone/StandaloneOps.cpp.inc"
      >();
  addTypes<
#define GET_TYPEDEF_LIST
#include "Standalone/StandaloneTypes.cpp.inc"
      >();
}
