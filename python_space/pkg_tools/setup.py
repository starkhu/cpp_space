import setuptools
from setuptools import find_packages, Extension

PACKAGE_DIR={'kellopkg':'hellopkg'}
PACKAGE = ['kellopkg']

EXT_MODULES = [Extension(name='myprint',
                         sources=['csrc/my_print.cc'],
                         include_dirs = ['csrc'])]

setuptools.setup(
  name="kelloo", #app name
  version="0.2.0", #version
  #packages=find_packages(exclude=['build', 'dist']),
  package_dir = PACKAGE_DIR, 
  packages = PACKAGE,
  include_package_data=True,
  exclude_package_data={'':['.gitignore']},
  ext_modules = EXT_MODULES,
  author="starkhu",
  #install_requires=[
  #  'numpy==1.19.5'
  #]
  #pymodules=["hello"],
  #entry_points={'console_scripts': ['pyhello = hello:main']}
)


