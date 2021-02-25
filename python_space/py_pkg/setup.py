import setuptools
from setuptools import find_packages

setuptools.setup(
  name="hellopkg",
  version="0.1.0",
  packages=find_packages(),
  #pymodules=["hello"],
  #entry_points={'console_scripts': ['pyhello = hello:main']}
)


