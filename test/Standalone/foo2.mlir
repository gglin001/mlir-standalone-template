// RUN: standalone-opt %s | FileCheck %s

module {
    // CHECK-LABEL: @bar
    func.func @bar(%arg0: !standalone.int) {
        %res = standalone.foo2 %arg0 : !standalone.int
        return
    }
}
