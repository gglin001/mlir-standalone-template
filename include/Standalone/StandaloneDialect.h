//===- StandaloneDialect.h - Standalone dialect -----------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef STANDALONE_STANDALONEDIALECT_H
#define STANDALONE_STANDALONEDIALECT_H

#include "mlir/IR/Dialect.h"

#include "Standalone/StandaloneDialect.h.inc"

namespace mlir {
namespace standalone {
namespace Standalone {

// Parse a type registered to this dialect.
Type parseStandaloneDialectType(AsmParser &parser);

// Print a type registered to this dialect.
void printStandaloneDialectType(Type type, AsmPrinter &printer);

} // namespace Standalone
} // namespace standalone
} // namespace mlir

#endif // STANDALONE_STANDALONEDIALECT_H
