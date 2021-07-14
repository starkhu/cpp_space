from contextlib import contextmanager


# case1
@contextmanager
def ctx_manager(name):
  print ("call before {}".format(name))
  yield
  print ("call after {}".format(name))


def print_func():
  print("**********call print function")

with ctx_manager("print_func"):
  print_func()

#case 2
@contextmanager
def ctx_manager(name):
  print ("call before {}".format(name))
  yield name
  print ("call after {}".format(name))


def print_func():
  print("**********call print function")

with ctx_manager("print_func") as  func_name:
  print_func()
  print("func name is: {}".format(func_name))
