### package modules to wheel
python setup.py bdist_wheel  --universal

### package modules to egg 
python setup.py bdist_egg

## pip install from code
pip install . 
