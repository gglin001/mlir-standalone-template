//===- StandaloneOps.td - Standalone dialect ops -----------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef STANDALONE_OPS
#define STANDALONE_OPS

include "StandaloneDialect.td"
include "StandaloneTypes.td"
include "/mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

def Standalone_FooOp : Standalone_Op<"foo", [NoSideEffect,
                                             SameOperandsAndResultType]> {
    let summary = "Illustrates how to define an operation.";
    let description = [{
        The `standalone.foo` operation illustrates how to define a new
        operation in a dialect. It uses an operation trait to declare that it
        has no side effects.

        This operation takes an integer argument and returns an integer.

        Example:

        ```mlir
        %0 = constant 2 : i32
        // Apply the foo operation to %0
        %1 = standalone.foo %0 : i32
        ```
    }];

    let arguments = (ins I32:$input);
    let results = (outs I32:$res);

    let assemblyFormat = [{
        $input attr-dict `:` type($input)
    }];
}

def Standalone_Foo2Op : Standalone_Op<"foo2", [NoSideEffect,
                                             SameOperandsAndResultType]> {
    let summary = "Illustrates how to define an operation.";
    let description = [{
        ```mlir
        func.func @bar(%arg0: !standalone.int) {
            %res = standalone.foo2 %arg0 : !standalone.int
            return
        }
        ```
    }];
    let arguments = (ins Standalone_IntType:$input);
    let results = (outs Standalone_IntType:$res);
    let assemblyFormat = [{
        $input attr-dict `:` type($input)
    }];
}

def Standalone_AddOp : Standalone_Op<"add", [NoSideEffect]> {
    let summary = "Illustrates how to define an operation.";
    let description = [{
        ```mlir
        func.func @bar(%arg0: !standalone.int, %arg1: !standalone.int) {
            %res = standalone.add %arg0 %arg0 : (!standalone.int, !standalone.int) -> !standalone.int
            return
        }
        ```
    }];
    let arguments = (ins Standalone_IntType:$x, Standalone_IntType:$y);
    let results = (outs Standalone_IntType:$res);
    let assemblyFormat = [{
        $x $y attr-dict `:` functional-type(operands, results)
    }];
}

#endif // STANDALONE_OPS
