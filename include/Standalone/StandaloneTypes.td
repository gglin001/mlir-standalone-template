#ifndef STANDALONETYPES
#define STANDALONETYPES

include "mlir/IR/AttrTypeBase.td"
include "StandaloneDialect.td"

class Standalone_Type<string name, string typeMnemonic, list<Trait> traits = []>
    : TypeDef<Standalone_Dialect, name, traits> {
  let mnemonic = typeMnemonic;
}

def Standalone_IntType : Standalone_Type<"Int", "int"> {
  let summary = "Standalone IntType";
  let description = [{
    Integer type.
  }];
}

#endif // STANDALONETYPES
