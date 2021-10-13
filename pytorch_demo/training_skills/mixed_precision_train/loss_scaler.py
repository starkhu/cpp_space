

class DynamicLossScaler:
    def __init__(self, loss_scale=2**16, scale_factor=2, scale_window=10, min_scale=1):
        self.cur_scale = loss_scale
        self.scale_factor = scale_factor
        self.scale_window = scale_window
        self.min_scale = min_scale
        self.cur_iter = 0
        self.last_overflow_iter = -1

    def backward(self, loss):
        scaled_loss = loss * self.cur_scale
        scaled_loss.backward(retain_graph=False)

    def update_scale(self, overflow):
        if overflow:
            self.cur_scale = self.cur_scale / self.scale_factor
            self.last_overflow_iter = self.cur_iter
            print("half loss scale is: ", self.cur_scale)
        else:
            self.cur_iter += 1
            if (self.cur_iter-self.last_overflow_iter) % self.scale_window == 0:
                self.cur_scale *= self.scale_factor
                print("double loss scale is: ", self.cur_scale)

    def has_overflow(self, params):
        for p in params:
            if p.grad is not None and self._has_inf_or_nan(p.grad.data):
                return True
        return False

    def _has_inf_or_nan(self, x):
        try:
            cpu_sum = float(x.float().sum())
        except RuntimeError as instance:
            if "value cannot be converted" not in instance.args[0]:
                raise
            return True
        else:
            if cpu_sum == float('inf') or cpu_sum == -float('inf') or cpu_sum != cpu_sum:
                return True
            return False

