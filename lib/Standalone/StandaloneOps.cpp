//===- StandaloneOps.cpp - Standalone dialect ops ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Standalone/StandaloneOps.h"
#include "Standalone/StandaloneDialect.h"
#include "mlir/IR/OpImplementation.h"

#define GET_OP_CLASSES
#include "Standalone/StandaloneOps.cpp.inc"

using namespace mlir;
using namespace mlir::standalone;

/*
void AddOp::getCanonicalizationPatterns(::mlir::RewritePatternSet &results,
                                        ::mlir::MLIRContext *context) {}

::mlir::OpFoldResult AddOp::fold(::llvm::ArrayRef<::mlir::Attribute> operands) {
  return nullptr;
}

::mlir::ParseResult AddOp::parse(::mlir::OpAsmParser &parser,
                                 ::mlir::OperationState &result) {
  return success();
}
void AddOp::print(::mlir::OpAsmPrinter &p) {}
*/
