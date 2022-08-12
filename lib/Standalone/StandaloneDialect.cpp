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

#include "Standalone/StandaloneDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Tablegen Type Definitions
//===----------------------------------------------------------------------===//

#define GET_TYPEDEF_CLASSES
#include "Standalone/StandaloneTypes.cpp.inc"

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
