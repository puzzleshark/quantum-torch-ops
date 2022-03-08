#include <torch/script.h>
#include <torch/custom_class.h>



#include <string>
#include <vector>

struct QuantumOp : torch::CustomClassHolder {
    std::vector<torch::Tensor> data;
    std::string name;
    std::vector<int8_t> wires;

    void add_data(torch::Tensor datum) {
        data.push_back(datum);
    }

    void add_wire(int8_t wire) {
        wires.push_back(wire);
    }
};

struct QuantumCircuit : torch::CustomClassHolder {
    int8_t num_wires;
    std::vector<QuantumOp> ops;
}

// template <class T>
// struct MyStackClass : torch::CustomClassHolder {
//   std::vector<T> stack_;
//   MyStackClass(std::vector<T> init) : stack_(init.begin(), init.end()) {}

//   void push(T x) {
//     stack_.push_back(x);
//   }
//   T pop() {
//     auto val = stack_.back();
//     stack_.pop_back();
//     return val;
//   }

//   c10::intrusive_ptr<MyStackClass> clone() const {
//     return c10::make_intrusive<MyStackClass>(stack_);
//   }

//   void merge(const c10::intrusive_ptr<MyStackClass>& c) {
//     for (auto& elem : c->stack_) {
//       push(elem);
//     }
//   }
// };