valgrind --tool=memcheck --leak-check=summary --show-leak-kinds=all --log-file=log --trace-children=yes ./t

### valgrind suppressions
###### generate suppressions rule:
> --gen-suppressions=all
##### apply suppressions rule:
> --suppressions=XXX_rule.supp
