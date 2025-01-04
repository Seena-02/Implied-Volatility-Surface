from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import subprocess
import os

class CMakeBuild(build_ext):
    def run(self):
        # Ensure the build directory exists
        build_dir = os.path.abspath('build')
        os.makedirs(build_dir, exist_ok=True)
        
        # Run CMake and Make
        subprocess.check_call(['cmake', '..'], cwd=build_dir)
        subprocess.check_call(['make'], cwd=build_dir)
        
        # Find the built .so file
        so_file = None
        for root, _, files in os.walk(build_dir):
            for file in files:
                if file.endswith('.so'):
                    so_file = os.path.join(root, file)
        
        if not so_file:
            raise RuntimeError("Could not find the built .so file")
        
        # Move the .so file to the expected output location
        output_dir = os.path.abspath(self.build_lib)
        os.makedirs(output_dir, exist_ok=True)
        output_path = os.path.join(output_dir, os.path.basename(so_file))
        self.copy_file(so_file, output_path)

setup(
    name="model_options",
    version="0.1",
    ext_modules=[Extension("model_options", sources=[])],  # Empty sources for placeholder
    cmdclass={"build_ext": CMakeBuild},
    zip_safe=False,
)
