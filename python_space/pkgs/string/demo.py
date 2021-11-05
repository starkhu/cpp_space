list_ = [1,2,3]
print(list_, f'has a length of {len(list_)}.')
# [1,2,3] has a length of 3.

print(list_, f'has a length of {{len(list_)}}.')
# [1,2,3] has a length of {len(list_)}.

print(list_, f'has a length of {{{len(list_)}}}.')
# [1,2,3] has a length of {3}.
