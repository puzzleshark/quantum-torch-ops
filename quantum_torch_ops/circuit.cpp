#include <string>
#include <vector>

#include <torch/script.h>
#include <torch/custom_class.h>

struct QuantumOp : torch::CustomClassHolder {
    std::vector<torch::Tensor> data;
    std::string name;
    std::vector<int8_t> wires;

    // QuantumOp() {
    // }

    void add_data(torch::Tensor datum) {
        data.push_back(datum);
    }

    // void add_wire(int8_t wire) {
    //     wires.push_back(wire);
    // }
};


torch::Tensor myadd(QuantumOp ok);

// // struct QuantumCircuit : torch::CustomClassHolder {
// //     int8_t num_wires;
// //     std::vector<QuantumOp> ops;

// //     void add_op(QuantumOp op) {
// //         ops.push_back(op);
// //     }
// // };

// TORCH_LIBRARY(my_classes, m) {
//   m.class_<QuantumOp>("QuantumOp")
//     .def(torch::init<std::string>())
//     .def("add_data", &QuantumOp::add_data)
//     .def("add_wire", &QuantumOp::add_wire);
// }

TORCH_LIBRARY(my_ops, m) {
  m.class_<QuantumOp>("QuantumOp")
    .def(torch::init())
    .def("add_data", &QuantumOp::add_data);
  // m.def("myadd", &myadd);
  m.def("myadd(__torch__.torch.classes.my_ops.QuantumOp circ) -> Tensor");
}