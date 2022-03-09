from setuptools import setup
from torch.utils.cpp_extension import BuildExtension, CppExtension

setup(
    name="quantum_torch_ops",
    packages=["quantum_torch_ops"],
    ext_modules=[
        CppExtension(
            "quantum_ops",
            ["circuit.cpp"],
        )
    ],
    cmdclass={"build_ext": BuildExtension.with_options(no_python_abi_suffix=True)},
)