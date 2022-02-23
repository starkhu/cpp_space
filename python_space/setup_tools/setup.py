import setuptools
from setuptools import find_packages, Extension
from setuptools.command.install_scripts import install_scripts
import shutil


class InstallScripts(install_scripts):

    def run(self):
        setuptools.command.install_scripts.install_scripts.run(self)

        # Rename some script files
        for script in self.get_outputs():
            print(f"+++ script is: {script}")
            if script.endswith(".py") or script.endswith(".sh"):
                dest = script[:-3]
            else:
                continue
            print("moving %s to %s" % (script, dest))
            shutil.move(script, dest)

PACKAGE_DIR={'kellopkg':'hellopkg'}
PACKAGE = ['kellopkg']

EXT_MODULES = [Extension(name='myprint',
                         sources=['csrc/my_print.cc'],
                         include_dirs = ['csrc'])]

setuptools.setup(
  name="kelloo", #module name
  version="0.3.0", #version
  description='Build a demo test',
  packages=find_packages(exclude=['build', 'dist']),
  #package_dir = PACKAGE_DIR,
  #packages = PACKAGE,
  include_package_data=True,
  exclude_package_data={'':['.gitignore']},
  ext_modules = EXT_MODULES,
  author="AncientMoon",

  scripts=['bin/forever.sh'],
  cmdclass = {
      "install_scripts":InstallScripts
  }

  #install_requires=[
  #  'numpy==1.19.5'
  #]
  #pymodules=["hello"],
  #entry_points={'console_scripts': ['pyhello = hello:main']}
)


