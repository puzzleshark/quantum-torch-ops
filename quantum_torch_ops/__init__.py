import os

from pathlib import Path

import torch

file_path = str(Path(__file__).resolve().parent.parent) + "/quantum_ops.so"

torch.ops.load_library(file_path)
