#include <string>
#include <vector>

#include <torch/script.h>
#include <torch/custom_class.h>

struct QuantumOp : torch::CustomClassHolder {
    std::vector<torch::Tensor> data;
    std::string name;
    std::vector<int64_t> wires;

    // QuantumOp() {
    // }

    void add_data(torch::Tensor datum) {
        data.push_back(datum);
    }

    void add_wire(int64_t wire) {
        wires.push_back(wire);
    }
};


struct QuantumCircuit : torch::CustomClassHolder {
    
    int64_t num_wires;
    std::vector<c10::intrusive_ptr<QuantumOp>> ops;

    void add_op(c10::intrusive_ptr<QuantumOp>& op) {
        ops.push_back(op);
    }
};

TORCH_LIBRARY(pennylane, m) {
  m.class_<QuantumOp>("QuantumOp")
    .def(torch::init())
    .def("add_data", &QuantumOp::add_data)
    .def("add_wire", &QuantumOp::add_wire);
  m.class_<QuantumCircuit>("QuantumCircuit")
    .def(torch::init());
    // .def("add_op(__torch__.torch.classes.pennylane.QuantumOp op) -> None", &QuantumCircuit::add_op);
  m.def("run_quantum_circuit(__torch__.torch.classes.pennylane.QuantumOp circuit) -> Tensor");
}