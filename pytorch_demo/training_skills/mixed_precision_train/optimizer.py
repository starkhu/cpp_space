from loss_scaler import DynamicLossScaler



class FP16_Optimizer:
    def __init__(self, optimizer):
        self.optimizer = optimizer
        self.dynamic_loss_scale = True
        self.loss_scaler = DynamicLossScaler()

        self.overflow = False

    def backward(self, loss):
        self.loss_scaler.backward(loss)
        
    def _check_overflow(self):
        params = []
        for group in self.optimizer.param_groups:
            for param in group['params']:
                params.append(param)
        self.overflow = self.loss_scaler.has_overflow(params)


    def _get_loss_scale(self):
        return self.loss_scaler.cur_scale

    def _set_loss_scale(self, value):
        self.loss_scaler.cur_scale = value

    loss_scale = property(_get_loss_scale, _set_loss_scale)

    def _downscale_master(self):
        import pdb
        #pdb.set_trace()
        if self.loss_scale != 1.0:
            for group in self.optimizer.param_groups:
                for param in group['params']:
                    if param.grad is not None:
                        param.grad.data.mul_(1. / self.loss_scale)

    def update_master_grads(self):
        if self.dynamic_loss_scale:
            self._check_overflow()
            if self.overflow:
                return
        #self._model_grads_to_master_grads()
        self._downscale_master()

    def step(self):
        #print("loss scale is: ", self.loss_scale)
        self.loss_scaler.update_scale(self.overflow)
        if not self.overflow:
            self.optimizer.step()
      
