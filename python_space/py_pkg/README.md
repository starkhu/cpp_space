### package modules to wheel
python setup.py bdist_wheel  --universal

### package modules to egg 
python setup.py bdist_egg

### pip install from code
pip install . 

### pip install from github
pip install git+https://github.com/starkhu/cpp_space.git@master#subdirectory=python_space/py_pkg

### difference between apt_get install and pip install
apt_get：

apt-get is pre-compiled, which installs much faster than pip.
To install numpy, matplotlib, pandas, and other scipy-related modules, apt-get only takes seconds; pip can easily consume 10min+.

need root access

outdated version
can not special version of package


pip install
you're getting the latest version at the time you install it,
can special version of package

