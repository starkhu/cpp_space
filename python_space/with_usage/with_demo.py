from contextlib import contextmanager


# case1
@contextmanager
def ctx_manager(name):
  print ("---enter function {}".format(name))
  yield
  print ("---exit function {}".format(name))


def print_func():
  print("      ***call with body")

with ctx_manager("foo1"):
  print_func()

print("")

#case 2
@contextmanager
def ctx_manager(name):
  print ("---enter_function {}".format(name))
  yield name
  print ("---exit function {}".format(name))


def print_func():
  print("      ***call with-body")

with ctx_manager("foo2") as  func_name:
  print_func()
  print("      ***func name is: {}".format(func_name))
