// RUN: standalone-opt %s | FileCheck %s

module {
    // CHECK-LABEL: @bar
    func.func @bar(%arg0: !standalone.int, %arg1: !standalone.int) {
        %res = standalone.add %arg0 %arg0 : (!standalone.int, !standalone.int) -> !standalone.int
        return
    }
}
