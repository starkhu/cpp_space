# -*- coding: utf-8 -*                                                                                                                                                                                      
import argparse
import tqdm
import sys


def collect_suppression(log_file, suppression_file):
  supp_count = 0
  write_flag = False
  with open(log_file, "r") as fr, open(suppression_file, "w") as fw:
    for line in fr:
      #line = line.strip()
      if line.find("insert_a_suppression_name_here") != -1:
        supp_count += 1
        write_flag = True
        fw.write("{")
        fw.write("\n")
        fw.write("  ignore_suppression_"+str(supp_count))
        fw.write("\n")
        continue
      if write_flag:
        if line != "}\n":
          fw.write(line)
        else:
          fw.write("}")
          fw.write("\n\n")
          write_flag = False

def parse_args():
  parser = argparse.ArgumentParser()
  parser.add_argument("-s", "--log_file",
                      help="path to log file")
  parser.add_argument("-d", "--suppression_file",
                      default = "suppression_rule.supp",
                      help="suppression file")
 
  args = parser.parse_args()
  if not args.log_file:
    parser.print_usage(sys.stderr)
    sys.exit(-1)
  return args

if __name__ == "__main__":
  args = parse_args()
  log_file=args.log_file
  suppression_file=args.suppression_file
  collect_suppression(log_file, suppression_file)

