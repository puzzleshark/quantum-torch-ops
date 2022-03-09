from setuptools import setup
from torch.utils.cpp_extension import BuildExtension, CppExtension

setup(
    name="quantum_torch_ops",
    py_modules=['foo'],
    ext_modules=[
        CppExtension(
            "quantum_ops",
            ["quantum_torch_ops/circuit.cpp"],
        )
    ],
    cmdclass={"build_ext": BuildExtension.with_options(no_python_abi_suffix=True)},
)