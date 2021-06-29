# add introduction for cyclomatic_complexity




## Status
- enum表征不同的状态： ok, invalid_arguments
- status不ok时，
  - 保持不ok的状态返回。
  - 由调用者决定如何处理不ok的状态。
  - 不ok时，至少答应error_code + msg
  - 
- status是ok时， 继续执行，为了方便创建status状态，应该支持Status::OK();
 凡是status的对象，必须进行检查，通过__attribute__机制保证
